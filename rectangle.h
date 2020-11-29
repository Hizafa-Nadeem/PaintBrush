#pragma once
#include "polygon.h"

class rectangle:public polygon {
	int get_pixel(int x, int y);
	void floodFill(int x, int y, int oldcolor, int newcolor);
public:
	rectangle(vector<Point>, int, int,int fc);
	void draw();
	bool contains(Point);
	void fill(int col,Point);
	
};
