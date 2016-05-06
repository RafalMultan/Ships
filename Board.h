#pragma once

enum field{A='A',B,C,D,E,F,G,H,I,J};
class Board
{
	static const int size;
	char **_play_board;
public:
	
	Board();
	~Board();
	void show();
	char** play_board(){return _play_board;}

	
};