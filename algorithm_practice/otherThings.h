#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct my2DPoint
{
	double X;
	double Y;
	my2DPoint(double dx, double dy)
	{
		X = dx;
		Y = dy;
	}

};
//判断点是否落在多边形内
bool isPointInPolygon(my2DPoint p, vector<my2DPoint> &ps);

//简单多边形测试
void SimplePointTest();

