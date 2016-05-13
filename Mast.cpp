#include "Mast.h"

using namespace std;
int Mast::counter=0;
Mast::Mast()
{
	_x=counter%10+1;
	_y=counter/10+1;
	_ActualStatus=nothing;
	counter++;
}
void Mast::damage()
{
	if(_ActualStatus==hidden)
	_ActualStatus=dead;
	if(_ActualStatus==nothing)
		_ActualStatus=missed;
}
void make_destroyer(direction dir,int xbegin,int ybegin,Mast **t,std::vector<Mast*> &v)
{
	
	int i=xbegin-1,j=ybegin-1;
	if(dir==vertical)
		for(;i<xbegin+3;i++)
			{
				t[i][j].change_status(hidden);
				v.push_back(&t[i][j]);
				
			}
	if(dir==horizontal)
		for(;j<ybegin+3;j++)
			{
				t[i][j].change_status(hidden);
				v.push_back(&t[i][j]);
			}
			
}
void make_cruiser(direction dir,int xbegin,int ybegin,Mast **t,std::vector<Mast*> &v)
{
	int i=xbegin-1,j=ybegin-1;
	if(dir==vertical)
		for(;i<xbegin+2;i++)
			{
				t[i][j].change_status(hidden);
				v.push_back(&t[i][j]);
			}
	if(dir==horizontal)
		for(;j<ybegin+2;j++)
			{
				t[i][j].change_status(hidden);
				v.push_back(&t[i][j]);
			}
}
void make_frigate(direction dir,int xbegin,int ybegin,Mast **t,std::vector<Mast*> &v)
{
	int i=xbegin-1,j=ybegin-1;
	if(dir==vertical)
		for(;i<xbegin+1;i++)
			{
				t[i][j].change_status(hidden);
				v.push_back(&t[i][j]);
			}
	if(dir==horizontal)
		for(;j<ybegin+1;j++)
		{
				t[i][j].change_status(hidden);
				v.push_back(&t[i][j]);
			}
}
Mast* make_pine(int xbegin,int ybegin,Mast **t)
{
	t[xbegin-1][ybegin-1].change_status(hidden);
	return &t[xbegin-1][ybegin-1];
}