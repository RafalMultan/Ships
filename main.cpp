#include <iostream>
#include "Board.h"
#include "Mast.h"
#include <iterator>
#include <vector>
using namespace std;


void manual_shipyard(Board &,std::vector<Mast*> &v1,std::vector<Mast*> &v,std::vector<Mast*> &v3,std::vector<Mast*> &);
	

int main(int argc,char **argv)
{
	std::vector<Mast*> destroyer,cruiser,frigate,occupiedSlots;
	Board player1,player2;	
	std::vector<Mast*>::iterator v;
	manual_shipyard(player1,destroyer,cruiser,frigate,occupiedSlots);
	cout<<endl;
	player1.show();
		cout<<endl;	
	
	/*test for(int i=0;i<10;i++)
		for(int j=0;j<10;j++)
		(*(player1.play_board()+i)+j)->damage();
		for(v=occupiedSlots.begin();v!=occupiedSlots.end();v++)
		cout<<(*v)->actual_status()<<endl;
	cout<<occupiedSlots.size()<<endl;
	player1.show();
	cout<<endl;*/
	

}
void manual_shipyard(Board &player1,std::vector<Mast*> &v1,std::vector<Mast*> &v2,std::vector<Mast*> &v3,std::vector<Mast*> &all)
{
	std::vector<Mast*>::iterator vs;
	make_destroyer(horizontal,1,2,player1.play_board(),v1);
	make_cruiser(vertical,4,5,player1.play_board(),v2);
	make_frigate(horizontal,10,1,player1.play_board(),v3);
	for(vs=v1.begin();vs!=v1.end();vs++)
		all.push_back((*vs));
	for(vs=v2.begin();vs!=v2.end();vs++)
		all.push_back((*vs));
	for(vs=v3.begin();vs!=v3.end();vs++)
		all.push_back(*vs);
	all.push_back(make_pine(8,8,player1.play_board()));

}