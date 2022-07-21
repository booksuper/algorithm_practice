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
void simplePointTest();

/*给定平面中n边形各点坐标（按顺时针顺序给出）求出该多边形面积，多边形可能为凹多边形*/
double caculatePolygonArea(vector<my2DPoint> &poly);



