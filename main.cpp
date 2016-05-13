#include <iostream>
#include "Board.h"
#include "Mast.h"

using namespace std;



int main(int argc,char **argv)
{
	Board player1;	
	player1.show();
	cout<<endl;
	make_destroyer(horizontal,1,2,player1.play_board());
	make_cruiser(vertical,4,5,player1.play_board());
	make_frigate(horizontal,10,1,player1.play_board());
	make_pine(8,8,player1.play_board());
	player1.show();
	//	(*(player1.play_board()+i)+j)->damage();
	cout<<endl;
	

}