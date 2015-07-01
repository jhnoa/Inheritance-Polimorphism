#ifndef SHAPE_H
#define SHAPE_H
#include "func.h"

class shape
{
	public:
		shape();
		virtual bool operator < (shape);// buat sorting list
		virtual shape operator = (list<shape>::iterator);
		bool operator == (shape);// buat sorting list
		~shape();
//		virtual void setValue(int x, int y){width = x; height = y;}
		virtual void setValue(){return;}
		virtual void luas(){return;}
		virtual void keliling(){return;}
		string getBentuk();
//		virtual string getBentuk1();
		string getAttr();
		float getArea(){return area;}
		float getArea() const {return area;}
		float getPerimeter(){return perimeter;}
		float getPerimeter() const {return perimeter;}
		int getT(){return type;}
		int mode(int); 
		int getW() {return width;}
		int getH() {return height;}
	protected:
		int width = 0, height = 0, type = 0;// type buat nentuin dia lingkaran, kotak, atau persegi
		float perimeter, area;
};

#endif
