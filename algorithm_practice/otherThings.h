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
//�жϵ��Ƿ����ڶ������
bool isPointInPolygon(my2DPoint p, vector<my2DPoint> &ps);

//�򵥶���β���
void simplePointTest();

/*����ƽ����n���θ������꣨��˳ʱ��˳�����������ö�������������ο���Ϊ�������*/
double caculatePolygonArea(vector<my2DPoint> &poly);



