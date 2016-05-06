#pragma once
#include <cstdlib>
enum status{alive='a',dead='d'};

class Mast
{
	int _x;
	int _y;
	status _ActualStatus;
public:
	Mast(int);
	int x(){return _x;}
	int y(){return _y;}
	status ActualStatus(){return _ActualStatus;}
	status damage(){_ActualStatus=dead;}

};