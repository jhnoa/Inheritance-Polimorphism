#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.h"

class circle : public shape
{
	public:
		circle();
		~circle();
		void setValue(int a){width = a;}
		
	protected:
};

#endif
