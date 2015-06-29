#ifndef SQUARE_H
#define SQUARE_H
#include "func.h"
#include "shape.h"

class square : public shape
{
	public:
		square();
		~square();
		bool operator < (square);// buat sorting list
		square operator = (list<square>::iterator);
		void setValue(int a){width = a; type = 3; square::luas(); square::keliling();}
		void luas(){area = width * width;}
		void keliling(){perimeter = width *4;}
		
//		string getBentuk() {return "Square";}
	protected:
};

#endif
