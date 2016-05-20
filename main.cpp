#include <iostream>
#include "Board.h"
#include "Mast.h"
#include "Coords.h"
#include <iterator>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

void auto_shipyard(Board &,std::vector<Mast*> &v1,std::vector<Mast*> &v,std::vector<Mast*> &v3,std::vector<Mast*> &);
	

int main(int argc,char **argv)
{
	std::vector<Mast*> destroyer1,cruiser1,frigate1,occupiedSlots1,destroyer2,cruiser2,frigate2,occupiedSlots2;
	Board player1,player2;	
	srand(time(NULL));
	auto_shipyard(player1,destroyer1,cruiser1,frigate1,occupiedSlots1);
	auto_shipyard(player2,destroyer2,cruiser2,frigate2,occupiedSlots2);
		cout<<endl;	
	
	std::vector<Coords> shotsFiredPlayerCPU;
	std::vector<Coords>::iterator shots_it;
	int xCpuTarget,yCpuTarget;// walka
	while(occupiedSlots1.size() && occupiedSlots2.size())
	{
		cout<<"Z"<<endl;
		bool freshCoordinates;
		do
		{
			do
			{cout<<"Y"<<endl;   //cos sie sypie nieskonczona petla czasami
				freshCoordinates=true;
				xCpuTarget=rand()%10;
				yCpuTarget=rand()%10;
				if(shotsFiredPlayerCPU.size())for(shots_it=shotsFiredPlayerCPU.begin();shots_it!=shotsFiredPlayerCPU.end();shots_it++)
					if(shots_it->x()==xCpuTarget && shots_it->y()==yCpuTarget)freshCoordinates=false;
				if(freshCoordinates)shotsFiredPlayerCPU.push_back(Coords(xCpuTarget,yCpuTarget));
			}while(!freshCoordinates && shotsFiredPlayerCPU.size()!=100);
				(*(player1.play_board()+yCpuTarget)+xCpuTarget)->damage();
				
				cout<<"X"<<endl;
				if((*(player1.play_board()+yCpuTarget)+xCpuTarget)->actual_status()==dead_mine)(*(player2.play_board()+yCpuTarget)+xCpuTarget)->damage();
				for(int i=0;i<occupiedSlots1.size();i++)
					if(occupiedSlots1[i]->x()==xCpuTarget+1 && occupiedSlots1[i]->y()==yCpuTarget+1)
						occupiedSlots1.erase(occupiedSlots1.begin()+i);
		}while((*(player1.play_board()+yCpuTarget)+xCpuTarget)->actual_status()==dead);		


	}
	cout<<shotsFiredPlayerCPU.size()<<endl;
	player1.show();
	player2.show();
	
	

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

	counter=0;
	while(counter<6)
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
				all.push_back(make_mine(b,a,player1.play_board()));
				counter++;
			}
	}
	all.erase(all.begin()+20,all.end());
}