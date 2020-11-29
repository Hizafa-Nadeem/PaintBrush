#include "circle.h"


circle::circle(){}

circle::circle(vector<Point>p, int col, int n, double r)
:Shape(p,col,n),radius(r){}

void circle::draw()
{
	//power(points[0].x,2)+ (points[0].x, 2)	
	GP142_circleXY(color,points[0].x,points[0].y,radius);               

}
bool circle::contains(Point p)
{
	double d = pow((points[0].x) - (p.x), 2) + pow(points[0].y - (p.y), 2);
	double dist = pow(d, 0.5);
	if (dist <= radius)
	{
		return true;
	}
	else
	return false;
}




