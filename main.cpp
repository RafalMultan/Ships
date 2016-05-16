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

	player1.show();
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
	}
			make_destroyer(dir,b,a,player1.play_board(),v1);
			counter++;
			for(vs=v1.begin();vs!=v1.end();vs++)
			all.push_back((*vs));
		
	//cruiser 
		counter=0;
		while(counter<2)
		{
			safeToWork=true;
			choose=rand()%2;
			if(choose==0)dir=vertical;
			else dir=horizontal;
			if(dir==horizontal)
			{
				a=1+rand()%8;
				b=1+rand()%10;
			}
			if(dir==vertical)
				{
					a=1+rand()%10;
					b=1+rand()%8;
				}
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
				counter++;
			}
		}
		for(vs=v2.begin();vs!=v2.end();vs++)
			all.push_back((*vs));
	
	//frigate 

		counter=0;
		while(counter<3)
		{
			safeToWork=true;
			choose=rand()%2;
			if(choose==0)dir=vertical;
			else dir=horizontal;
			if(dir==horizontal)
			{
				a=1+rand()%9;
				b=1+rand()%10;
			}
			if(dir==vertical)
				{
					a=1+rand()%10;
					b=1+rand()%9;
				}
			if(dir==horizontal)
			for(int i=0;i<3;i++)
			{	
				for(vs=all.begin();vs!=all.end();vs++)
						if((*vs)->x()==a+i && (*vs)->y()==b)
						{
						safeToWork=false;
						break;
						}
			}
			if(dir==vertical)
			for(int i=0;i<3;i++)
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
				make_frigate(dir,b,a,player1.play_board(),v3);
							counter++;
			}
		}
		for(vs=v3.begin();vs!=v3.end();vs++)
			all.push_back((*vs));
		
	counter=0;
	while(counter<4)
	{
		safeToWork=true;
		a=1+rand()%10;
		b=1+rand()%10;
		for(vs=all.begin();vs!=all.end();vs++)
						if((*vs)->x()==a && (*vs)->y()==b)
						{
						safeToWork=false;
						break;
						}
		if(safeToWork)
			{
				all.push_back(make_pine(b,a,player1.play_board()));
				counter++;
			}
	}

}