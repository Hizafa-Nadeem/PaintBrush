#include "text.h"



text::text(vector<Point>p, int c, int n,vector <char> t)
	:Shape(p, c, n)
{
	int ind;
	name = new char[t.size()+1];
	for (int i = 0; i < t.size(); i++)
	{
		name[i] = t[i];
		ind = i;
	}
	name[ind+1] = '\0';
}

void text::draw()
{
	GP142_textXY(color, points[0].x, points[0].y, 15,name);
}

bool text::contains(Point p)
{
	int* height = new int;
	int* width = new int;
	*height = 0;
	*width = 0;
	GP142_getDimensions(15, height, width, name);

	if (p.x < *width && p.x < *height);
		return true;
	return false;
}




