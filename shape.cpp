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
	if(x != 0) return mode = x;
	return mode;
}

bool shape::operator < (shape param)
{
	if (mode(0) == 1)
	{
		if(this->getArea() < param.getArea()) return true;
		else return false;
	}
	else if(mode(0) == 2)
	{
		if (this->getPerimeter() < param.getPerimeter()) return true;
		else return false;
	}
//	return false;
}

shape shape::operator = (list<shape>::iterator param)
{
	shape temp;
	temp.width = param->width;
	temp.height = param->height;
	temp.area = param->area;
	temp.perimeter = param->perimeter;
	temp.type = param->type;
	return temp;
//	return false;
}

bool shape::operator == (shape param)
{
	shape temp;
	if(temp.getH() == param.getH() && temp.getW() == param.getW()) return true;
	else return false;
}
