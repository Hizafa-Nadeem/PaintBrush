//#include<iostream>
#pragma once
#include <vector>
#include "GP142.H"

using namespace std;


struct Point {
	double x, y;
};
class Shape
{
protected:
	vector<Point> points;
	int color;
	int n;
	
public:
	Shape();
	Shape(vector<Point>, int , int);
	bool virtual contains(Point)=0;
	void virtual draw() = 0;
	void virtual fill(int , Point)=0;
	~Shape();
};

