#include <iostream>
#include "Board.h"
#include "Mast.h"
using namespace std;

void put(Board & player,Mast &pine)
{
	int i,j;
	i=pine.x();
	j=pine.y();
	*(*(player.play_board()+j)+i)='1';
}


int main(int argc,char **argv)
{
	Board player1;
	Mast test(2,5);
	player1.show();
	put(player1,test);
	player1.show();
	cout<<endl;
}
