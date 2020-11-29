#include "polygon.h"

float polygon::grad(Point a, Point b)
{
	float val = (a.y - b.y) / (a.x - b.x);
	return val;
}
bool polygon::checkVertex(Point p)
{
	bool found = false;
	for (int i = 0; i < points.size()&& found ==false; i++)
	{
		if (p.x == points[i].x && p.y == points[i].y)
			found = true;
	}
	return found;
}

void polygon::lineIntersection(Point A,Point B,Point C,Point D,int &intersection)
{
	double a1 = B.y - A.y;
	double b1 = A.x - B.x;
	double c1 = a1 * (A.x) + b1 * (A.y);

	double a2 = D.y- C.y;
	double b2 = C.x - D.x;
	double c2 = a2 * (C.x) + b2 * (C.y);

	double determinant = (a1 * b2) - (a2 * b1);
	if (determinant != 0)
	{
		double x = (b2 * c1 - b1 * c2) / determinant;
		double y = (a1 * c2 - a2 * c1) / determinant;
		Point intersect;
		intersect.x = x;
		intersect.y = y;
		int val1 = intersect.y - A.y;
		int val2 = grad(A, B) * (intersect.x - A.x);
		if (checkVertex(intersect) == false && val1==val2)
		{
			intersection++;
		}
	}
}

polygon::polygon(vector<Point> p, int col, int n, int fc)
	:Shape(p, col, n){}
void polygon::draw()
{
	for (int i = 0; i < points.size(); i++)
	{
		if (i == points.size() - 1)
		{
			GP142_lineXY(color, points[i].x, points[i].y, points[0].x, points[0].y, 3);
		}
		else
		{
			GP142_lineXY(color, points[i].x, points[i].y, points[i + 1].x, points[i + 1].y, 3);
		}
	}
}

bool polygon::contains(Point test)
{
	int intersection =0;
	Point end_p;
	end_p.x = 500;
	end_p.y = 400;
	for (int i = 0; i < points.size(); i++)
	{
		if (i == points.size() - 1)
			lineIntersection(points[0], points[i], test, end_p,intersection);
		else
			lineIntersection(points[i], points[i + 1], test, end_p,intersection);
	}
	if (intersection % 2 == 0)
		return false;
	else
		return true;
}
