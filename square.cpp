#include "square.h"

square::square()
{
}

square::square(int a)
{
	width = a;
	type = 2;
	square::luas();
	square::keliling();
}


square::~square()
{
}
bool square::operator < (square param)
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

square square::operator = (list<square>::iterator param)
{
	square temp;
	temp.width = param->width;
	temp.height = param->height;
	temp.area = param->area;
	temp.perimeter = param->perimeter;
	temp.type = param->type;
	return temp;
//	return false;
}
