#pragma once
#include"OpenShape.h"

class line :public OpenShape {


public:
	line(vector<Point>, int, int, bool);
	bool terminator(GP142_point p1, GP142_point p2);
	void draw();
	// changecolor();
	bool contains(Point);
};
