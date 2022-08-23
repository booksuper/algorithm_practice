#include "greedyAlgorithm.h"
//455 分发饼干 简单
int findContentChildren(vector<int>& g, vector<int>& s)
{
	if (s.size() == 0) return 0;
	int res = 0;
	int count = 0;
	//将他们都从大到小排序
	sort(g.begin(), g.end(), greater<int>());
	sort(s.begin(), s.end(), greater<int>());
	//以孩子的数量作为大循环
	for (int i = 0; i < g.size(); i++)
	{
		//如果饼干数组已经到达末尾了，直接跳出循环，防止数组越界
		if (count < s.size())
		{
			//将尺寸最大的饼干，优先满足胃口最大的孩子，满足不了就满足胃口次大的
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
