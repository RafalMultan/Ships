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
void manual_shipyard(Board &,std::vector<Mast*> &v1,std::vector<Mast*> &v,std::vector<Mast*> &v3,std::vector<Mast*> &);

int main(int argc,char **argv)
{
	std::vector<Mast*> destroyer1,cruiser1,frigate1,occupiedSlots1,destroyer2,cruiser2,frigate2,occupiedSlots2;
	Board player1,player2;	
	srand(time(NULL));
	cout<<"sam chcesz ustawic statki? y/n"<<endl;
	char choice;
	do
	{
		cin>>choice;
	}while(choice!='y' && choice!='n');
	if(choice=='n')auto_shipyard(player1,destroyer1,cruiser1,frigate1,occupiedSlots1);
		else manual_shipyard(player1,destroyer1,cruiser1,frigate1,occupiedSlots1);
	auto_shipyard(player2,destroyer2,cruiser2,frigate2,occupiedSlots2);
		cout<<endl;	
	
	std::vector<Coords> shotsFiredPlayerCPU;
	std::vector<Coords>::iterator shots_it;
	int aim;
	std::vector<Mast*>::iterator check;
	int xCpuTarget,yCpuTarget;// walka
	while(occupiedSlots1.size() && occupiedSlots2.size())
	{
		
		for(check=frigate1.begin();check!=frigate1.end();check++)
			if((*check)->actual_status()==hidden)
				{
					aim=2;
					break;
				}
		for(check=cruiser1.begin();check!=cruiser1.end();check++)
			if((*check)->actual_status()==hidden)
				{
					aim=3;
					break;
				}
		for(check=destroyer1.begin();check!=destroyer1.end();check++)
			if((*check)->actual_status()==hidden)
			{
				aim=4;
				break;
			}
			
		bool freshCoordinates;
	switch(aim)
	{

	default:
		do
		{

			do
			{
   
				freshCoordinates=true;
				xCpuTarget=rand()%10;
				yCpuTarget=rand()%10;
				if(shotsFiredPlayerCPU.size())for(shots_it=shotsFiredPlayerCPU.begin();shots_it!=shotsFiredPlayerCPU.end();shots_it++)
					if(shots_it->x()==xCpuTarget && shots_it->y()==yCpuTarget)freshCoordinates=false;
				if(freshCoordinates)shotsFiredPlayerCPU.push_back(Coords(xCpuTarget,yCpuTarget));
			}while(!freshCoordinates && shotsFiredPlayerCPU.size()!=100);
				(*(player1.play_board()+yCpuTarget)+xCpuTarget)->damage();
	
				if((*(player1.play_board()+yCpuTarget)+xCpuTarget)->actual_status()==dead_mine)(*(player2.play_board()+yCpuTarget)+xCpuTarget)->damage();
				for(int i=0;i<occupiedSlots1.size();i++)
					if(occupiedSlots1[i]->x()==xCpuTarget+1 && occupiedSlots1[i]->y()==yCpuTarget+1)
						occupiedSlots1.erase(occupiedSlots1.begin()+i);
		}while((*(player1.play_board()+yCpuTarget)+xCpuTarget)->actual_status()==dead);		
	}
		do
		{
			cout<<endl<<"Podaj X [1,10]"<<endl;
		cin>>xCpuTarget;
		cout<<"Podaj Y [1,10]"<<endl;
		cin>>yCpuTarget;
		xCpuTarget--;yCpuTarget--;
			(*(player2.play_board()+yCpuTarget)+xCpuTarget)->damage();
			if((*(player2.play_board()+yCpuTarget)+xCpuTarget)->actual_status()==dead_mine)(*(player1.play_board()+yCpuTarget)+xCpuTarget)->damage();
		}while((*(player2.play_board()+yCpuTarget)+xCpuTarget)->actual_status()==dead);
	cout<<endl<<"Player 1 (Ty)"<<endl;
	player1.show_my();
	cout<<endl<<"Player 2 (Dumb af AI)"<<endl;
	player2.show();
	}
	
	
	

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

void manual_shipyard(Board &player1,std::vector<Mast*> &v1,std::vector<Mast*> &v2,std::vector<Mast*> &v3,std::vector<Mast*> &all)
{
	std::vector<Mast*>::iterator vs;
	int a,b,counter=0,choose;
	direction dir;
	bool safeToWork=true;

	//destroyer
	cout<<"tworzysz niszczyciel"<<endl;
	cout<<"Podaj kireunek (0=vertical,horizontal)"<<endl;
	cin>>choose;
	if(choose==0)dir=vertical;
		else dir=horizontal;
		if(dir==horizontal)
		{
		cin>>a;
		cin>>b;
		}
	if(dir==vertical)
	{
		cin>>a;
		cin>>b;
	}
			make_destroyer(dir,b,a,player1.play_board(),v1);
			counter++;
			for(vs=v1.begin();vs!=v1.end();vs++)
			all.push_back((*vs));
		player1.show_my();
		
	//cruiser 
		counter=0;
		while(counter<2)
		{
			cout<<"tworzysz krazownik"<<endl;
			safeToWork=true;
			cout<<"Podaj kireunek (0=vertical,horizontal)"<<endl;
			cin>>choose;
			if(choose==0)dir=vertical;
			else dir=horizontal;
			if(dir==horizontal)
			{
				cin>>a;
				cin>>b;
			}
			if(dir==vertical)
				{
					cin>>a;
					cin>>b;
				}
			if(dir==horizontal)
			for(int i=0;i<4;i++)
			{	
				for(vs=all.begin();vs!=all.end();vs++)
						if((*vs)->x()==a+i && (*vs)->y()==b)
						{
						safeToWork=false;
						cout<<"podales zle wspolrzedne"<<endl;

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
						cout<<"podales zle wspolrzedne"<<endl;
						break;
						}
					}
			}
		if(safeToWork)
			{
				make_cruiser(dir,b,a,player1.play_board(),v2);
				counter++;
			}
			player1.show_my();
		}
		for(vs=v2.begin();vs!=v2.end();vs++)
			all.push_back((*vs));
		
	
	//frigate 

		counter=0;
		while(counter<3)
		{
			cout<<"tworzysz fregaty"<<endl;
			safeToWork=true;
			cin>>choose;
			cout<<"podaj kierunek (0=vertical)"<<endl;
			if(choose==0)dir=vertical;
			else dir=horizontal;
			if(dir==horizontal)
			{
				cin>>a;
				cin>>b;
			}
			if(dir==vertical)
				{
					cin>>a;
					cin>>b;
				}
			if(dir==horizontal)
			for(int i=0;i<3;i++)
			{	
				for(vs=all.begin();vs!=all.end();vs++)
						if((*vs)->x()==a+i && (*vs)->y()==b)
						{
						safeToWork=false;
						cout<<"podales zle wspolrzedne"<<endl;
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
						cout<<"podales zle wspolrzedne"<<endl;
						break;
						}
					}
			}
		if(safeToWork)
			{
				make_frigate(dir,b,a,player1.play_board(),v3);
							counter++;
			}
			player1.show_my();
		}
		for(vs=v3.begin();vs!=v3.end();vs++)
			all.push_back((*vs));
		
	
		
	counter=0;
	while(counter<4)
	{
		cout<<"tworzysz miny"<<endl;
		safeToWork=true;
		cin>>a;
		cin>>b;
		for(vs=all.begin();vs!=all.end();vs++)
						if((*vs)->x()==a && (*vs)->y()==b)
						{
						safeToWork=false;
						cout<<"podales zle wspolrzedne"<<endl;
						break;
						}
		if(safeToWork)
			{
				all.push_back(make_pine(b,a,player1.play_board()));
				counter++;
			}
			player1.show_my();
	}
	
	//pines

	counter=0;
	while(counter<6)
	{
		cout<<"towrzysz lupiny"<<endl;
		safeToWork=true;
		a=1+rand()%10;
		b=1+rand()%10;
		for(vs=all.begin();vs!=all.end();vs++)
						if((*vs)->x()==a && (*vs)->y()==b)
						{
						safeToWork=false;
						cout<<"podales zle wspolrzedne"<<endl;
						break;
						}
		if(safeToWork)
			{
				all.push_back(make_mine(b,a,player1.play_board()));
				counter++;
			}
			player1.show_my();
	}
	
	all.erase(all.begin()+20,all.end());
}