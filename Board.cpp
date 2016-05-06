#include "Board.h"
#include <iostream>
#include <iomanip>
using namespace std;
const int Board::size=10;
Board::Board()
{
	int i;
	_play_board=new char*[size+1];
	for(i=0;i<size+1;i++)
	{	_play_board[i]=new char[size+1];
		for(int j=0;j<size;j++)
			_play_board[i][j]='0';
}
	
}
Board::~Board()
{
	for(int i=0;i<size;i++)
	delete [] _play_board[i];
	delete [] _play_board;	
}
void Board::show()
{

	cout<<endl;
	for(int i=0;i<size;i++)
	{	cout<<setw(2)<<i+1<<" ";
		for(int j=0;j<size;j++)
			{
				
				cout<<_play_board[i][j]<<" ";
			}		
		cout<<endl;
	}
}