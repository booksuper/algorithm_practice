#include "dynamic_programming.h"

int fib(int n)
{
	if (n == 0 || n == 1)
	{
		return n;
	}
	int res1 = fib(n - 1);
	int res2 = fib(n - 2);
	return res1 + res2;

}

int modified_fib(int memo[], int n)
{
	if (n == 0 || n == 1)
	{
		return n;
	}
	//���ǰ���Ѿ�������ˣ��Ͳ���Ҫ�ټ����ˣ����������
	if (memo[n] != 0)
	{
		return memo[n];
	}
	memo[n] = modified_fib(memo, n - 1) + modified_fib(memo, n - 2);

	return memo[n];
}
//��������쳲�����
int fib_itera(int n)
{
	if (n == 0 || n == 1)
	{
		return n;
	}
	int * dp = new int[n+1];
	dp[0] = 0;
	dp[1] = 1;
	//����
	for (int i = 2; i <= n; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	return dp[n];
}
//����Ǯ����
int coinChange(vector<int>& coins, int amount)
{
	//dp������ֵ����Ҫ�յ���Ǯ�������������Ҫ���ٵ�Ӳ����
	//vector<int> dp;
	//dp.resize(amount + 1);
	int * dp = new int[amount + 1]();
	dp[0] = 0;
	int res = INT_MAX;
	//i�Ǵյ���Ǯ��ֵ��j��Ӳ����ֵ
	for (int i = 1; i <= amount; i++)
	{
		for (int j = 0; j < coins.size(); j++)
		{
			if (i - coins[j] >= 0)
			{
				//���ƽ������ʽΪdp[i] = 1+dp[i-Ӳ��ֵ]
				res = res < dp[i - coins[j]] + 1 ? res : dp[i - coins[j]] + 1;
			}
		}
		//û�з�������Ľ��������dp���е�ֵ�ܴ󣬱��ں����ж�
		if (res == INT_MAX)
		{
			dp[i] = INT_MAX - 1;
		}
		else
		{
			dp[i] = res;
			//����һ����Ǯ��Ҫ����Ӳ��֮����Ҫ��res���ã���Ȼres��һֱ��ȫ����Сֵ
			res = INT_MAX;
		}
		
	}
	//�����õĽ����һ���ܴ��ֵ����˵��û�з��������Ľ��������-1
	if (dp[amount] > INT_MAX - 10)
	{
		return -1;
	}
	else
	{
		return dp[amount];
	}
	
}
