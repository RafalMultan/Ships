#pragma once

class Sail
{
	int _x;
	int _y;
	
public:
	Sail();
	~Sail();
	void show();
	int x(){return _x;}
	int y(){return _y;}
};