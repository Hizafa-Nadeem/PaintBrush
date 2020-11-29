#pragma once
#include "OpenShape.h"
class curve:public OpenShape
{
	bool contain_point_inline(Point, int);
public:
	curve(vector<Point> , int , int , bool );
	void draw();
	bool contains(Point);

};

