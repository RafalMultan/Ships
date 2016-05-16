#include <iostream>
#include "Board.h"
#include "Mast.h"
#include <iterator>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;


void auto_shipyard(Board &,std::vector<Mast*> &v1,std::vector<Mast*> &v,std::vector<Mast*> &v3,std::vector<Mast*> &);
	

int main(int argc,char **argv)
{
	std::vector<Mast*> destroyer,cruiser,frigate,occupiedSlots;
	Board player1,player2;	


	std::vector<Mast*>::iterator v;
	srand(time(NULL));
	auto_shipyard(player1,destroyer,cruiser,frigate,occupiedSlots);
		cout<<endl;	
		for(int i=0;i<10;i++)
		for(int j=0;j<10;j++)
		(*(player1.play_board()+i)+j)->damage();
		//for(v=occupiedSlots.begin();v!=occupiedSlots.end();v++)
		//cout<<(*v)->actual_status()<<endl;
	cout<<destroyer.size()<<endl;
	cout<<cruiser.size()<<endl;
	cout<<frigate.size()<<endl;
	cout<<occupiedSlots.size()<<endl;
	player1.show();
	cout<<endl;
	

}
void auto_shipyard(Board &player1,std::vector<Mast*> &v1,std::vector<Mast*> &v2,std::vector<Mast*> &v3,std::vector<Mast*> &all)
{
	std::vector<Mast*>::iterator vs;
	int a,b,counter=0,choose;
	direction dir;
	bool safeToWork=true;

	//destroyer
	choose=rand()%2;
	if(choose==0)dir=vertical;
		else dir=horizontal;
		if(dir==horizontal)
		{
		a=1+rand()%7;
		b=1+rand()%10;
		}
	if(dir==vertical)
	{
		a=1+rand()%10;
		b=1+rand()%7;
	}cout<<a<<" tworze destr "<<b<<"w kierunku "<<dir<<endl;
			make_destroyer(dir,b,a,player1.play_board(),v1);
			counter++;
			for(vs=v1.begin();vs!=v1.end();vs++)
			all.push_back((*vs));
		
	//cruiser 0 to vertical
		counter=0;
		while(counter<2)
		{
			safeToWork=true;
			choose=rand()%2;
			if(choose==0)dir=vertical;
			else dir=horizontal;
			if(dir==horizontal)
			{
				a=1+rand()%7;
				b=1+rand()%10;
			}
			if(dir==vertical)
				{
					a=1+rand()%10;
					b=1+rand()%7;
				}
				cout<<a<<" dzialam "<<b<<" w kierunku "<<dir<<endl;
			
			if(dir==horizontal)
			for(int i=0;i<4;i++)
			{	
				for(vs=all.begin();vs!=all.end();vs++)
						if((*vs)->x()==a+i && (*vs)->y()==b)
						{
						safeToWork=false;
						break;
						}
			}
			if(dir==vertical)
			for(int i=0;i<4;i++)
			{
				for(vs=all.begin();vs!=all.end();vs++)
					{
						if((*vs)->x()==a && (*vs)->y()==b+i)
						{
						safeToWork=false;
						break;
						}
					}
			}
		if(safeToWork)
			{
				make_cruiser(dir,b,a,player1.play_board(),v2);
				cout<<"tworze"<<" w kierunku "<<dir<<endl;
				counter++;
			}
		}
		for(vs=v2.begin();vs!=v2.end();vs++)
			all.push_back((*vs));

	for(vs=all.begin();vs!=all.end();vs++)
			cout<<(*vs)->x()<<" "<<(*vs)->y()<<endl;
	

	//make_frigate(horizontal,a,b,player1.play_board(),v3);
	
	
	
		//all.push_back(*vs);
	//all.push_back(make_pine(8,8,player1.play_board()));*/

}