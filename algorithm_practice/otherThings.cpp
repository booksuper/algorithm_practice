#include "otherThings.h"
//判断点是否落在多边形内
bool isPointInPolygon(my2DPoint vtPoint, vector<my2DPoint>& vecPoints)
{
	/*方法1：面积法
		判断目标点与多边形的每条边组成的三角形面积和是否等于该多边形，
		相等则在多边形内部。

	方法2：角度法
		判断目标点与所有边的夹角和是否为360度，为360度则在多边形内部。

	方法3：射线法
		从目标点出发引一条射线，看这条射线和多边形所有边的交点数目。
			如果有奇数个交点，则说明在内部
			如果有偶数个交点，则说明在外部
	本例实现方法3：
	点是否在多边形内的算法逻辑：
		如果从点P作水平向左的射线的话
			（1）若射线与多边形的交点为奇数，则P在多边形内部；
			（1）若射线与多边形的交点为偶数，则P在多边形外部。

		特殊情况（若边为（P1,P2））：
			（1）如果射线正好穿过P1或者P2,那么这个交点会被算作2次，
			     处理办法是如果P的从坐标与P1,P2中较小的纵坐标相同，则直接忽略这种情况；
			（2）如果射线水平，则射线要么与其无交点，要么有无数个，
			     这种情况也直接忽略；
			（3）如果射线竖直，而P的横坐标小于P1,P2的横坐标，则必然相交；
			（4）再判断相交之前，先判断P是否在边(P1,P2)的上面，如果在，则直接得出结论：P再多边形内部。

    */

	//方法一
	int count = 0;
	int edge_size = vecPoints.size();
	for (int i = 0; i < edge_size; i++)
	{
		//一个边的两点
		my2DPoint p1 = vecPoints[i];
		my2DPoint p2 = vecPoints[(i + 1) % edge_size];
		//两点纵坐标一样，说明这个边是个水平线，也就是情况（2）
		if (p1.Y == p2.Y)
			continue;
		//第一种情况，点的y小于边的最小y，说明它们不能相交（可能和边的延长线相交，但我们不考虑这个情况）
		if (vtPoint.Y < min(p1.Y, p2.Y))
		{
			continue;
		}
		//第一种情况，点的y大于边的最大y，说明它们不能相交，和上面的一样
		if (vtPoint.Y > max(p1.Y, p2.Y))
		{
			continue;
		}
		//求点与边的交点x值，根据两点式方程
		//x = x1 +  (y - y1) * (x2 - x1) / (y2 - y1);
		double x = p1.X + (vtPoint.Y - p1.Y) / (p2.Y - p1.Y) * (p2.X - p1.X);
		// 只统计p1p2与p向右射线的交点 
		if (x > vtPoint.X)
		{
			count++;
		}


	}
	// 交点为偶数，点在多边形之外  
	// 交点为奇数，点在多边形之内
	if (count % 2 == 1)
	{
		return true;
	}
	else
	{
		return false;
	}

	//方法二
	//bool bResult = false; //判断结果（true；点落在多边形内；false:点未落在多边形内）
	//int nSize = vecPoints.size();
	//int j = nSize - 1;//nSize -1 是多边形的最后一个顶点
	//for (int i = 0; i < nSize; i++)
	//{
	//	//判断点是否在线段的两侧
	//	if ((vecPoints[i].Y < vtPoint.Y && vecPoints[j].Y >= vtPoint.Y) || (vecPoints[j].Y < vtPoint.Y && vecPoints[i].Y >= vtPoint.Y))
	//	{
	//		//根据两点式方程计算出过点P且平行于X轴的直线与线段的交点，两点式方程：x = x1 +  (y - y1) * (x2 - x1) / (y2 - y1);
	//		if (vecPoints[i].X + (vtPoint.Y - vecPoints[i].Y) * (vecPoints[j].X - vecPoints[i].X) / (vecPoints[j].Y - vecPoints[i].Y) < vtPoint.X)
	//			bResult = !bResult;
	//	}

	//	//进行下一线段判断
	//	j = i;
	//}

	//return bResult;
	
}
//简单多边形测试
void simplePointTest()
{
	
		vector<my2DPoint> vecPoints;//简单多边形
		my2DPoint vtPoint(1, 1);//构成多边形的顶点
		vtPoint.X = 1;
		vtPoint.Y = 1;
		vecPoints.push_back(vtPoint);

		vtPoint.X = 5;
		vtPoint.Y = 1;
		vecPoints.push_back(vtPoint);

		vtPoint.X = 5;
		vtPoint.Y = 2;
		vecPoints.push_back(vtPoint);

		vtPoint.X = 6;
		vtPoint.Y = 2;
		vecPoints.push_back(vtPoint);

		vtPoint.X = 6;
		vtPoint.Y = 4;
		vecPoints.push_back(vtPoint);

		vtPoint.X = 5;
		vtPoint.Y = 4;
		vecPoints.push_back(vtPoint);

		vtPoint.X = 5;
		vtPoint.Y = 5;
		vecPoints.push_back(vtPoint);

		vtPoint.X = 1;
		vtPoint.Y = 5;
		vecPoints.push_back(vtPoint);

		vtPoint.X = 1;
		vtPoint.Y = 4;
		vecPoints.push_back(vtPoint);

		vtPoint.X = 0.5;
		vtPoint.Y = 4;
		vecPoints.push_back(vtPoint);

		vtPoint.X = 0.5;
		vtPoint.Y = 2;
		vecPoints.push_back(vtPoint);

		vtPoint.X = 1;
		vtPoint.Y = 2;
		vecPoints.push_back(vtPoint);

		my2DPoint vtPointIn(2.5, 2.5);//落在多边形内的点
		bool bResultIn = isPointInPolygon(vtPointIn, vecPoints);

		my2DPoint vtPointOut(5.5, 1.5);//落在多边形外的点
		bool bResultOut = isPointInPolygon(vtPointOut, vecPoints);

		if (!bResultOut && bResultIn)
			cout << "Success:Point in polygon!" << endl;
		else
			cout << "Fail:Point is not in polygon!" << endl;
	
}
/*给定平面中n边形各点坐标（按顺时针顺序给出）求出该多边形面积，多边形可能为凹多边形*/
double caculatePolygonArea(vector<my2DPoint>& poly)
{
	/*采用向量的叉乘的方法，不管坐标原点怎样选取，只要顺序输入多边形每个顶点的坐标
	按同样的顺序（顺时针或反时针）两两叉乘。这些叉乘的和的绝对值的一半
	就是该多边形面积。这就是所谓的“鞋带公式”
	比如当n为3时候，多边形为三角形，那计算公式就是
	0.5（op0 X op1 + op1 X op2 + op2 X op0）这里面代表的含义就是一个大三角形
	减去两个小三角形面积等于我们要求的，不需要手动判断正负，因为顺时针的就是负数
	比如po X p1
	*/
	double area = 0.0;
	for (size_t i = 0; i<poly.size();i++)
	{
		//(i + 1) % poly.size()是为了当i为最后一个元素时，i+1能转变为第一个元素
		area += poly[i].X * poly[(i + 1) % poly.size()].Y - poly[i].Y * poly[(i + 1) % poly.size()].X;

	}
	return 0.5 * (area > 0 ? area : -area);
}
//168 简单 excel表列名称
string convertToTitle(int columnNumber)
{
	//实际可以使用进制转换，这就是一个十进制转26进制，但需要注意的是这里是从1开始
	//不是从0开始
	string res;
	while (columnNumber)
	{
		--columnNumber;//因为从1开始，所以先减一
		res += columnNumber % 26 + 'A';
		columnNumber /= 26;
	}
	reverse(res.begin(), res.end());//不要忘记反转一下
	return res;
}
