#pragma once
#include <cstdlib>
#include <vector>
using namespace std;
enum direction{vertical,horizontal};
enum status{nothing,hidden,dead,missed,mine,dead_mine};
class Mast
{

	int _x;
	int _y;
	status _ActualStatus;
	static int counter;
public:
	Mast();
	status actual_status(){return _ActualStatus;}
	int x(){return _x;}
	int y(){return _y;}
	void damage();
	void change_status(status new_status){_ActualStatus=new_status;}
	friend void make_destroyer(direction,int,int,Mast **,std::vector<Mast*> &);
	friend void make_cruiser(direction,int,int,Mast **,std::vector<Mast*> &v);
	friend void make_frigate(direction,int,int,Mast **,std::vector<Mast*> &v);
	friend Mast* make_pine(int,int,Mast **);
	friend Mast* make_mine(int,int,Mast **);
};