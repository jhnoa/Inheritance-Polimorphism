#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "func.h"
#include "shape.h"

class rectangle : public shape
{
	public:
		rectangle();
		rectangle(int, int);
		~rectangle();
		bool operator < (rectangle);// buat sorting list
		rectangle operator = (list<rectangle>::iterator);
		void setValue(int a, int b){width = a; height = b; type = 3; rectangle::luas(); rectangle::keliling();}
		void luas(){area = width * height;}
		void keliling(){perimeter = 2 * (width + height);}
		
//		string getBentuk() {return "Rectangle";}
	protected:
};

#endif
