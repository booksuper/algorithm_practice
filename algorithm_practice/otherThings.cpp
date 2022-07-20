#include "otherThings.h"
//�жϵ��Ƿ����ڶ������
bool isPointInPolygon(my2DPoint vtPoint, vector<my2DPoint>& vecPoints)
{
	/*����1�������
		�ж�Ŀ��������ε�ÿ������ɵ�������������Ƿ���ڸö���Σ�
		������ڶ�����ڲ���

	����2���Ƕȷ�
		�ж�Ŀ��������бߵļнǺ��Ƿ�Ϊ360�ȣ�Ϊ360�����ڶ�����ڲ���

	����3�����߷�
		��Ŀ��������һ�����ߣ����������ߺͶ�������бߵĽ�����Ŀ��
			��������������㣬��˵�����ڲ�
			�����ż�������㣬��˵�����ⲿ
	����ʵ�ַ���3��
	���Ƿ��ڶ�����ڵ��㷨�߼���
		����ӵ�P��ˮƽ��������ߵĻ�
			��1�������������εĽ���Ϊ��������P�ڶ�����ڲ���
			��1�������������εĽ���Ϊż������P�ڶ�����ⲿ��

		�������������Ϊ��P1,P2������
			��1������������ô���P1����P2,��ô�������ᱻ����2�Σ�
			     ����취�����P�Ĵ�������P1,P2�н�С����������ͬ����ֱ�Ӻ������������
			��2���������ˮƽ��������Ҫô�����޽��㣬Ҫô����������
			     �������Ҳֱ�Ӻ��ԣ�
			��3�����������ֱ����P�ĺ�����С��P1,P2�ĺ����꣬���Ȼ�ཻ��
			��4�����ж��ཻ֮ǰ�����ж�P�Ƿ��ڱ�(P1,P2)�����棬����ڣ���ֱ�ӵó����ۣ�P�ٶ�����ڲ���

    */

	//����һ
	int count = 0;
	int edge_size = vecPoints.size();
	for (int i = 0; i < edge_size; i++)
	{
		//һ���ߵ�����
		my2DPoint p1 = vecPoints[i];
		my2DPoint p2 = vecPoints[(i + 1) % edge_size];
		//����������һ����˵��������Ǹ�ˮƽ�ߣ�Ҳ���������2��
		if (p1.Y == p2.Y)
			continue;
		//��һ����������yС�ڱߵ���Сy��˵�����ǲ����ཻ�����ܺͱߵ��ӳ����ཻ�������ǲ�������������
		if (vtPoint.Y < min(p1.Y, p2.Y))
		{
			continue;
		}
		//��һ����������y���ڱߵ����y��˵�����ǲ����ཻ���������һ��
		if (vtPoint.Y > max(p1.Y, p2.Y))
		{
			continue;
		}
		//�����ߵĽ���xֵ����������ʽ����
		//x = x1 +  (y - y1) * (x2 - x1) / (y2 - y1);
		double x = p1.X + (vtPoint.Y - p1.Y) / (p2.Y - p1.Y) * (p2.X - p1.X);
		// ֻͳ��p1p2��p�������ߵĽ��� 
		if (x > vtPoint.X)
		{
			count++;
		}


	}
	// ����Ϊż�������ڶ����֮��  
	// ����Ϊ���������ڶ����֮��
	if (count % 2 == 1)
	{
		return true;
	}
	else
	{
		return false;
	}

	//������
	//bool bResult = false; //�жϽ����true�������ڶ�����ڣ�false:��δ���ڶ�����ڣ�
	//int nSize = vecPoints.size();
	//int j = nSize - 1;//nSize -1 �Ƕ���ε����һ������
	//for (int i = 0; i < nSize; i++)
	//{
	//	//�жϵ��Ƿ����߶ε�����
	//	if ((vecPoints[i].Y < vtPoint.Y && vecPoints[j].Y >= vtPoint.Y) || (vecPoints[j].Y < vtPoint.Y && vecPoints[i].Y >= vtPoint.Y))
	//	{
	//		//��������ʽ���̼��������P��ƽ����X���ֱ�����߶εĽ��㣬����ʽ���̣�x = x1 +  (y - y1) * (x2 - x1) / (y2 - y1);
	//		if (vecPoints[i].X + (vtPoint.Y - vecPoints[i].Y) * (vecPoints[j].X - vecPoints[i].X) / (vecPoints[j].Y - vecPoints[i].Y) < vtPoint.X)
	//			bResult = !bResult;
	//	}

	//	//������һ�߶��ж�
	//	j = i;
	//}

	//return bResult;
	
}
//�򵥶���β���
void SimplePointTest()
{
	
		vector<my2DPoint> vecPoints;//�򵥶����
		my2DPoint vtPoint(1, 1);//���ɶ���εĶ���
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

		my2DPoint vtPointIn(2.5, 2.5);//���ڶ�����ڵĵ�
		bool bResultIn = isPointInPolygon(vtPointIn, vecPoints);

		my2DPoint vtPointOut(5.5, 1.5);//���ڶ������ĵ�
		bool bResultOut = isPointInPolygon(vtPointOut, vecPoints);

		if (!bResultOut && bResultIn)
			cout << "Success:Point in polygon!" << endl;
		else
			cout << "Fail:Point is not in polygon!" << endl;
	
}
