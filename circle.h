#ifndef CIRCLE_H
#define CIRCLE_H
#include "func.h"
#include "shape.h"

class circle : public shape
{
	public:
		circle();
		~circle();
		bool operator < (circle);// buat sorting list
		circle operator = (list<circle>::iterator);
		void setValue(int a){width = a; type = 1; circle::luas(); circle::keliling();}
		void luas(){area = 3.14159 * width * width;}
		void keliling(){perimeter = 3.14159 * width *2;}
		
		virtual string getBentuk() {return "Circle";}
		string getAttr();
		
	protected:
};

#endif
