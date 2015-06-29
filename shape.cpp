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
	if(this->getH() == param.getH() && this->getW() == param.getW()) return true;
	else return false;
}

string shape::getBentuk() {
	if(type == 1) return "Circle";
	if(type == 2) return "Rectangle";
	if(type == 3) return "Square";
}

string shape::getAttr()
{
	char *buffer = new char[1000];
	string s;
	
	if(type == 2) { //rectangle
		s = "Panjang = ";
		itoa(height,buffer,10);
		s += buffer;
		s += "\tLebar = ";
		itoa(width,buffer,10);
		s += buffer;
	}
	else {
		if(type == 1) {
			s = "Jari-jari = ";
			
		}
		else if(type == 3) {
			s = "Sisi = ";
			
		}
		itoa(width,buffer,10);
		s += buffer;
	}
	delete[] buffer;
	return s;
}
