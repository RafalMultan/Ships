#pragma once
#include <cstdlib>


class Mast
{
	int _x;
	int _y;
	bool _IsAlive;
public:
	Mast();
	Mast(int,int);
	int x(){return _x;}
	int y(){return _y;}
	void damage(){_IsAlive=false;}
	bool IsAlive(){return _IsAlive;}


};