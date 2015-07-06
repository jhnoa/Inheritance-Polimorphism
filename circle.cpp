#include "circle.h"

circle::circle()
{
}

circle::circle(int a)
{
	width = a;
	type = 1;
	circle::luas();
	circle::keliling();
	
}

circle::~circle()
{
}

bool circle::operator < (circle param)
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

circle circle::operator = (list<circle>::iterator param)
{
	circle temp;
	temp.width = param->width;
	temp.height = param->height;
	temp.area = param->area;
	temp.perimeter = param->perimeter;
	temp.type = param->type;
	return temp;
//	return false;
}

string circle::getAttr()
{
	char *buffer = new char[1000];
	string s = "Jari-jari = ";
	itoa(this->width,buffer,10);
	s = s + buffer;
	return s;
}
