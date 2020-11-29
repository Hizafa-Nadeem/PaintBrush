

#include"line.h"

line::line(vector<Point> p, int col, int n, bool s)
	:OpenShape(p,col,n,s)
{

}
bool line:: terminator(GP142_point p1, GP142_point p2)
{
	if (points[0].x > points[points.size() - 1].x&& points[0].y > points[points.size() - 1].y)
	{
		if (p1.x > points[0].x && p1.y > points[0].y)
			return true;
	}
	else if (points[0].x < points[points.size() - 1].x && points[0].y > points[points.size() - 1].y)
	{
		if (p1.x < points[0].x && p1.y < points[0].y)
			return true;
	}
	return false;
}
void line::draw() {
if (style == true)
	GP142_lineXY(color, points[0].x, points[0].y, points[1].x,points[1].y, 3);
else
{
	float t = 0.1;
	int  col;
	GP142_point p1;
	p1.x = points[points.size() - 1].x;
	p1.y = points[points.size() - 1].y;
	GP142_point p2;
	p2.x = points[points.size()-1].x + t * (points[0].x - points[points.size() - 1].x);
	p2.y = points[points.size()-1].y + t * (points[0].y - points[points.size() - 1].y);

	for(int count =1;count<10 && terminator(p1,p2)==false;)
	{
		if (count % 2 == 0)
		{
			col = 0;
		}
		else
			col = color;
		count++;
		GP142_lineP( col,p1,p2,3);  
		p1.x = p2.x;
		p1.y = p2.y;
		t = t + 0.1;
		p2.x= points[points.size() - 1].x + t * (points[0].x - points[points.size() - 1].x);
		p2.y = points[points.size() - 1].y + t * (points[0].y - points[points.size() - 1].y);

	}
}

}

bool line::contains(Point p)
{
	int val1 = p.y- points[0].y;
	int val2 = grad(points[0], points[1]) * (p.x - points[0].x);
	if (val1 - val2 <=3 && val1-val2 >=0)
		return true;
	else
		return false;
}
