#include "rectangle.h"

rectangle::rectangle(vector<Point> p, int col, int n,int fc)
:polygon{p,col,n,fc}{}

void rectangle::draw() {
	GP142_lineXY(color, points[0].x, points[0].y, points[0].x, points[1].y, 3);
	GP142_lineXY(color, points[0].x, points[0].y, points[1].x, points[0].y, 3);
	GP142_lineXY(color, points[1].x, points[0].y, points[1].x, points[1].y, 3);
	GP142_lineXY(color, points[1].x, points[1].y, points[0].x, points[1].y, 3);
}

bool rectangle::contains(Point p)
{
	if ( (p.x > points[0].x && p.x < points[1].x && p.y > points[0].y && p.y < points[1].y) || 
		(p.x > points[1].x && p.x < points[0].x && p.y > points[1].y && p.y < points[0].y))
		return true;
	else
		return false;
}

void rectangle::fill(int col, Point p)
{

		int old = get_pixel(p.x, p.y);
		floodFill(p.x, p.y, old, col);
}

int rectangle:: get_pixel(int x, int y)
{
	COLORREF temp = Z_getPixel(0, 0);
	return real_shade(temp);
	
}
void rectangle::floodFill(int x, int y, int oldcolor, int newcolor)
{
	if( get_pixel(x, y) == oldcolor)
	{
		GP142_pixelXY( newcolor,x,y);
		floodFill(x + 1, y, oldcolor, newcolor);
		floodFill(x, y + 1, oldcolor, newcolor);
		floodFill(x - 1, y, oldcolor, newcolor);
		floodFill(x, y - 1, oldcolor, newcolor);
	}
}
//void rectangle::fill(int col,Point p )
//{
//}
