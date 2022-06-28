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
	//如果前面已经计算过了，就不需要再计算了，降低冗余度
	if (memo[n] != 0)
	{
		return memo[n];
	}
	memo[n] = modified_fib(memo, n - 1) + modified_fib(memo, n - 2);

	return memo[n];
}
//迭代计算斐波那契
int fib_itera(int n)
{
	if (n == 0 || n == 1)
	{
		return n;
	}
	int * dp = new int[n+1];
	dp[0] = 0;
	dp[1] = 1;
	//递推
	for (int i = 2; i <= n; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	return dp[n];
}
//凑零钱问题
int coinChange(vector<int>& coins, int amount)
{
	//dp的索引值代表要凑的零钱数，结果代表需要最少的硬币数
	//vector<int> dp;
	//dp.resize(amount + 1);
	int * dp = new int[amount + 1]();
	dp[0] = 0;
	int res = INT_MAX;
	//i是凑的零钱数值，j是硬币面值
	for (int i = 1; i <= amount; i++)
	{
		for (int j = 0; j < coins.size(); j++)
		{
			if (i - coins[j] >= 0)
			{
				//递推结果，公式为dp[i] = 1+dp[i-硬币值]
				res = res < dp[i - coins[j]] + 1 ? res : dp[i - coins[j]] + 1;
			}
		}
		//没有符合情况的结果，就让dp表中的值很大，便于后面判断
		if (res == INT_MAX)
		{
			dp[i] = INT_MAX - 1;
		}
		else
		{
			dp[i] = res;
			//算完一个零钱需要多少硬币之后，需要把res重置，不然res将一直是全局最小值
			res = INT_MAX;
		}
		
	}
	//如果最好的结果是一个很大的值，就说明没有符合条件的结果，返回-1
	if (dp[amount] > INT_MAX - 10)
	{
		return -1;
	}
	else
	{
		return dp[amount];
	}
	
}
