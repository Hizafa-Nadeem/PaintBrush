#pragma once
#include"Shape.h"
class polygon :public Shape{
protected:
	int fillcolor;
	float grad(Point a, Point b);
	//if not filled contains exceptional value
	bool checkVertex(Point);
	void lineIntersection(Point, Point, Point, Point, int &intersection);
public:
	polygon(vector <Point>, int, int, int);
	void draw();
	//fill(int color);
	bool contains(Point);

};
