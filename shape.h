#ifndef SHAPE_H
#define SHAPE_H

class shape
{
	public:
		shape();
		~shape();
		virtual void setValue(int a, int b){
			return;
		}
	protected:
		int width, height, area, keliling;
};

#endif
