
#include"OpenShape.h"

OpenShape::OpenShape(vector<Point> p, int col, int n, bool s)
	:Shape(p, col, n), style(s){}

bool OpenShape::contains(Point)
{
	return false;
}
float OpenShape::grad(Point a, Point b)
{
	float val = (a.y - b.y) / (a.x - b.x);
	return val;
}


