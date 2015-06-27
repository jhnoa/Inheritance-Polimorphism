#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.h"

class rectangle : public shape
{
	public:
		rectangle();
		rectangle(int, int);
		~rectangle();
		void setValue(int a, int b){width = a; height = b;}
	protected:
};

#endif
