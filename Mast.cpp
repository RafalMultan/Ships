#include "Mast.h"

using namespace std;
Mast::Mast(int size_of_board)
{
	_x=rand()%size_of_board;
	_y=rand()%size_of_board;
}
