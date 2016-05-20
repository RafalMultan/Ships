#pragma once
#include "Mast.h"
enum field{A='A',B,C,D,E,F,G,H,I,J};
class Board
{
	static const int _size;
	Mast ** _play_board;
public:

	Board();
	~Board();
	void show();
	void show_my();
	Mast** play_board(){return _play_board;}
	

	
};