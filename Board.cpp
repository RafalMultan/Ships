#include "Board.h"
#include <iostream>
#include <iomanip>
using namespace std;
const int Board::_size=10;
Board::Board()
{
	int i;
	_play_board=new Mast*[_size];
	for(i=0;i<_size;i++)
		_play_board[i]=new Mast[_size];
		
}
	

Board::~Board()
{
	for(int i=0;i<_size;i++)
	delete [] _play_board[i];
	delete [] _play_board;	
}
void Board::show()
{

	cout<<endl;
	cout<<setw(15)<<"OŚ X"<<endl;
	cout<<"   1 ";
	for(int i=2;i<_size+1;i++)
		cout<<i<<" ";
	cout<<endl;
	for(int i=0;i<_size;i++)
	{	cout<<setw(2)<<i+1<<" ";
		for(int j=0;j<_size;j++)
			{
				if(_play_board[i][j].actual_status()==hidden || _play_board[i][j].actual_status()==nothing || _play_board[i][j].actual_status()==mine)cout<<"0 ";
				if(_play_board[i][j].actual_status()==dead)cout<<"X ";
				if(_play_board[i][j].actual_status()==missed)cout<<"P ";
				if(_play_board[i][j].actual_status()==dead_mine)cout<<"T ";
			}		
		cout<<endl;
	}
}