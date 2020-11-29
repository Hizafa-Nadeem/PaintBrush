#include "Shape.h"

Shape::Shape(){}

Shape::Shape(vector<Point> p, int col, int no)
{
	points = p;
	color = col;
	n = no;
}
Shape::~Shape(){}

