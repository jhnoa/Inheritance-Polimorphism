#include "shape.h"

shape::shape()
{
}

shape::~shape()
{
}

int shape::mode(int x = 0)
{
	static int mode;
	if(x == 0) return mode;
	else mode = x;
	
	return mode;
}

bool shape::operator < (shape param)
{
	shape temp;
	if (mode() == 1)
	{
		if(temp.area < param.area) return true;
		else return false;
	}
	else if(mode() == 2)
	{
		if (temp.perimeter < param.perimeter) return true;
		else return false;
	}
}

bool shape::operator == (shape param)
{
	shape temp;
	if(temp.getH() == param.getH() && temp.getW() == param.getW()) return true;
	else return false;
}
