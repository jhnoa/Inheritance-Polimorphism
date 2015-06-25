#ifndef SQUARE_H
#define SQUARE_H

#include "shape.h"

class square : public shape
{
	public:
		square();
		~square();
		void setValue(int a){
			width = a;
		}
	protected:
};

#endif
