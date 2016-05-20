#pragma once
class Coords
{
	int _x;
	int _y;
public:
	int x(){return _x;}
	int y(){return _y;}
	Coords(int a,int b){_x=a;_y=b;}
};