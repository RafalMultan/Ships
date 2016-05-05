#pragma once

class Board
{
	int size;
public:
	Board();
	~Board();
	void show();
	void destroyer(Sail &);
	void cruiser();
	void regular();
	void pine();
}