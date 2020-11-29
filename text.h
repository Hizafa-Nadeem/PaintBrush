#pragma once
#include "Shape.h"
class text :public Shape
{
	char* name;
public:
	text(vector<Point>, int, int,vector<char>);
	void draw();
	bool contains(Point);

	
};

