#pragma once
#include "Shape.h"

class OpenShape :public Shape
{
protected:
	bool style;
	float grad(Point, Point);
public:
	OpenShape(vector<Point>, int, int, bool);
	bool contains(Point);
	//void virtual changecolor() = 0;


};
