#pragma once

class Mine
{
	int _x;
	int _y;
public:
	int x(){return _x;}
	int y(){return _y;}
	bool hit(int,int);
};