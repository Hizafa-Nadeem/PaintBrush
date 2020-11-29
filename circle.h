#pragma once
#include "Shape.h"
class circle :public Shape
{
	double  radius;
public:
	circle();
	circle(vector<Point>, int, int, double);
	void draw();
	bool contains(Point);
	// fill(int);
};

