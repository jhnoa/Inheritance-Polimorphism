#ifndef SHAPE_H
#define SHAPE_H

class shape
{
	public:
		shape();
		bool operator < (shape);
		bool operator == (shape);
		~shape();
//		virtual void setValue(int x, int y){width = x; height = y;}
		virtual void setValue(){return;}
		virtual int luas(){return 0;}
		virtual int keliling(){return 0;}
		int getArea(){return area;}
		int mode(int); 
		int getW() {return width;}
		int getH() {return height;}
	protected:
		int width = 0, height = 0, area, perimeter, type;
};

#endif
