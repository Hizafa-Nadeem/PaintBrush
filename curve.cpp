#include "curve.h"

curve::curve(vector<Point> p, int col, int n, bool s)
	:OpenShape(p, col, n, s)
{

}
void curve::draw()
{
	for (int i = 0; i < points.size(); i++)
	{
		if (i != points.size()-1)
		{
			GP142_lineXY(color, points[i].x, points[i].y, points[i + 1].x, points[i + 1].y, 3);
		}
	}
}
bool curve::contain_point_inline(Point p, int i)
{
	int val1 = p.y - points[i].y;
	int val2 = grad(points[i], points[i+1]) * (p.x - points[i].x);
	if (val1 - val2 <= 3 && val1 - val2 >= 0)
		return true;
	else
		return false;
}
bool curve:: contains(Point p)
{
	bool found = false;
	for (int i = 0; i < points.size()&& found ==false; i++)
	{
		if (i != points.size())
		{
			if (contain_point_inline(p, i) == true)
				found = true;
		}
	}
	return found;
}
