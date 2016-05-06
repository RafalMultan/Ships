#pragma once
struct coordinates
{
	int x;
	int y;
};
class Mine
{
	coordinates _whereAmI;
public:
	coordinates whereAmI(){return _whereAmI;}
	bool Hit();
};