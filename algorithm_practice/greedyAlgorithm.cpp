#include "greedyAlgorithm.h"
//455 �ַ����� ��
int findContentChildren(vector<int>& g, vector<int>& s)
{
	if (s.size() == 0) return 0;
	int res = 0;
	int count = 0;
	//�����Ƕ��Ӵ�С����
	sort(g.begin(), g.end(), greater<int>());
	sort(s.begin(), s.end(), greater<int>());
	//�Ժ��ӵ�������Ϊ��ѭ��
	for (int i = 0; i < g.size(); i++)
	{
		//������������Ѿ�����ĩβ�ˣ�ֱ������ѭ������ֹ����Խ��
		if (count < s.size())
		{
			//���ߴ����ı��ɣ���������θ�����ĺ��ӣ����㲻�˾�����θ�ڴδ��
			if (s[count] >= g[i])
			{
				res++;
				count++;
			}
			else
			{

				continue;
			}
		}
		else
		{
			break;
		}
		
	}
	return res;
}
