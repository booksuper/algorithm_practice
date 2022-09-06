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

int rfact(int n)
{
	int ans;
	if (n > 1)
	{
		int temp = rfact(n - 1);
		ans = n * temp;
		//ans = n * rfact(n - 1);
	}
	else
	{
		ans = 1;
	}
	return ans;
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
				//���ƽ������ʽΪdp[i] = 1+dp[i-Ӳ��ֵ]���ӵ�1����ǰӲ�ң�Ӳ��ֵ��coins[j]
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

int coinChangeBaseRecursion(vector<int>& coins, int amount)
{
	return 0;
}
/*70 ��¥�� �򵥣�������������¥�ݡ���Ҫ n ������ܵ���¥����
ÿ��������� 1 �� 2 ��̨�ס����ж����ֲ�ͬ�ķ�����������¥���أ�*/
int climbStairs(int n)
{
	/*����Ҫ��ȷ��dp[i]�����壬������dp[i]:����i��¥��ʱ��dp[i]�ַ���
	 *Ȼ������Լ������Ƶ���ȷ�����ƹ�ʽ����Ϊ������nΪ�����������Բ���Ҫ����nΪ0���
	 dp[1] = 1,dp[2] = 2,dp[3] = 3,dp[4] = 5,���Է�������ʵ����һ��쳲���������
	 */
	if (n <= 2) return n;
	vector<int> dp(n + 1);
	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i <= n; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2];

	}
	return dp[n];
}
//746 ʹ����С������¥�� �򵥣�
int minCostClimbingStairs(vector<int>& cost)
{
	vector<int> dp(cost.size());
	dp[0] = cost[0];
	dp[1] = cost[1];
	for (int i = 2; i < cost.size(); i++)
	{
		dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i];
	}
	// ע�����һ���������Ϊ���û��ѣ�����ȡ������һ�����ڶ���������ֵ
	return min(dp[cost.size() - 1],dp[cost.size() - 2]);
}
//62 ��ͬ·�� �е�
int uniquePaths(int m, int n)
{
	//dp[i][j]���壺�ӣ�0,0������i,j����dp[i][j]��·��
	vector<vector<int>> dp(m, vector<int>(n, 0));
	//��ʼ����dp[0][j]�϶�ֻ��һ�ַ�����dp[i][0]ͬ��
	for (int i = 0; i < m; i++) dp[i][0] = 1;
	for (int j = 0; j < n; j++) dp[0][j] = 1;
	//��ʼ�ݹ�
	for (int i = 1; i < m; i++)
	{
		for (int j = 1; j < n; j++)
		{
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
		}
	}
	return dp[m-1][n-1];
}
//63 ��ͬ·��II �е�
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
{
	int m = obstacleGrid.size();
	int n = obstacleGrid[0].size();
	if (obstacleGrid[m - 1][n - 1] == 1 || obstacleGrid[0][0] == 1) //����������յ�������ϰ���ֱ�ӷ���0
		return 0;
	vector<vector<int>> dp(m, vector<int>(n, 0));
	//��ʼ����ֻ�е�·����һ���ϰ���û�е�ʱ��dp[0][j]����һ�ַ�����dp[i][0]ͬ��
	for (int i = 0; i < m && obstacleGrid[i][0] == 0; i++)
	{
		
		dp[i][0] = 1;
	}
	for (int j = 0; j < n && obstacleGrid[0][j] == 0; j++)
	{
		
		dp[0][j] = 1;
	}
	//����
	for (int i = 1; i < m; i++)
	{
		for (int j = 1; j < n; j++)
		{
			//���ϰ����������һ�Σ����ֵ�ͻᱻĬ��Ϊ0
			if (obstacleGrid[i][j] == 1)
			{
				continue;
			}
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			
		}
	}
	return dp[m - 1][n - 1];
	
}
//72 �༭���� ���ѡ��ı�����ĺ��Ĳ���
int minDistance(string word1, string word2)
{
	//dp[i][j] ��ʾ���±�i-1Ϊ��β���ַ���word1��
	//�����±�j-1Ϊ��β���ַ���word2������༭����Ϊdp[i][j]��
	int m = word1.size();
	int n = word2.size();

	vector<vector<int>> dp(m+1,vector<int>(n+1,0));
	//��ʼ��
	for (size_t i = 0; i <= m; i++)
	{
		dp[i][0] = i;
	}
	for (size_t j = 0; j <= n; j++)
	{
		dp[0][j] = j;
	}
	for (size_t i = 1; i <= m; i++)
	{
		for (size_t j = 1; j <= n; j++)
		{
			//���±�i-1��β��word1�����±�j-1��β��word2���
			if (word1[i - 1] == word2[j - 1])
			{
				//���±�i-1��β��word1�����±�j-1��β��word2���
				//�Ϳ��Ե��Ƴ�
				dp[i][j] = dp[i - 1][j - 1];
			}
			else
			{
				//����ȣ���Ҫ��ɾ�����滻���������ֲ���;���Ӻ�ɾ���൱��һ������
				//Ȼ����Ҫ�������ֲ���ѡ���������С���ټ�1����
				//word1ɾ����dp[i][j] = dp[i-1][j] + 1
				//word2ɾ����dp[i][j] = dp[i][j-1] + 1
				//word2���һ��Ԫ�أ��൱��word1ɾ��һ��Ԫ�أ����Բ���Ҫ���Ӳ�����ʽ
				//�滻Ԫ�أ�word1�滻word1[i - 1]��ʹ����word2[j - 1]��ͬ
				//dp[i][j] = dp[i-1][j-1] + 1
				dp[i][j] = min({ dp[i - 1][j - 1],dp[i][j - 1],dp[i - 1][j] }) + 1;
			}
		}
	}
	return dp[m][n];
}
//647 �����Ӵ� �еȣ�
int countSubstrings(string s)
{
	//������չ����⣬ֻҪ�����ַ����е�ÿ�����ģ�Ȼ����������չ����
	//�ѵ����ڣ���չ���Ĳ���ֻ�ǵ����ַ��ģ����п����������ַ����������ľͲ�������
	//�ַ����Ĵ�С������2n-1��Ҳ���ǵ��ַ�����n����˫�ַ�����n-1��
	int n = s.size();
	int res = 0;
	for (size_t i = 0; i < 2 * n - 1; i++)
	{
		//��ʼ������ָ��
		int l = i / 2;
		int r = i / 2 + i % 2;
		while (l >= 0 && r < n && s[l] == s[r])
		{
			res++;
			l--;
			r++;
		}
	}
	return res;
}
//�����Ӵ���dp�ⷨ
int countSubStrDp(string s)
{
	int n = s.size();
	vector<vector<bool>> dp(n, vector<bool>(n, false));
	int res = 0;
	// ע�����˳��
	for (int i = n-1; i >= 0; i--)
	{
		for (int j = i; j < n; j++)
		{
			if (s[i] == s[j])
			{
				/*���һ���±�i �� j��ͬ��ͬһ���ַ�����a����Ȼ�ǻ����Ӵ�
                  ��������±�i �� j���Ϊ1������aa��Ҳ�ǻ����Ӵ�*/
				if (j - i <= 1)
				{
					res++;
					dp[i][j] = true;
				}
				/*��������±꣺i �� j������1��ʱ������cabac��
				��ʱs[i]��s[j]�Ѿ���ͬ�ˣ����ǿ�i��j�����ǲ��ǻ����Ӵ�
				�Ϳ�aba�ǲ��ǻ��ľͿ����ˣ���ôaba��������� i+1 �� 
				j-1���䣬��������ǲ��ǻ��ľͿ�dp[i + 1][j - 1]�Ƿ�
				Ϊtrue��*/
				else if (dp[i + 1][j - 1])
				{
					res++;
					dp[i][j] = true;
				}
			}
		}
	}
	return res;
}
//516 ����������� �е�
int longestPalindromeSubseq(string s)
{
	//û��ʹ�û��ݣ���Ϊ��Ҫ����ǲ�������
	//dp[i][j]���ַ���s��[i, j]��Χ����Ļ��������еĳ���Ϊdp[i][j]��
	//���s[i]��s[j]��ͬ����ôdp[i][j] = dp[i + 1][j - 1] + 2;
	int n = s.size();
	vector<vector<int>> dp(n, vector<int>(n, 0));
	//��ʼ��
	for (size_t i = 0; i < n; i++)
	{
		dp[i][i] = 1;
	}
	//����˳����µ���
	for (int i = n - 1; i >= 0; i--)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (s[i] == s[j])
			{
				//���s[i]��s[j]��ͬ����ôdp[i][j] = dp[i + 1][j - 1] + 2;
				dp[i][j] = dp[i + 1][j - 1] + 2;
			}
			else
			{
				/*���s[i]��s[j]����ͬ��˵��s[i]��s[j]��ͬʱ���� 
				����������[i,j]��������Ӵ��ĳ��ȣ���ô�ֱ����s[i]��
				s[j]������һ�����������Ļ��������С�
                ����s[j]�Ļ��������г���Ϊdp[i + 1][j]��
                ����s[i]�Ļ��������г���Ϊdp[i][j - 1]*/
				dp[i][j] = max(dp[i+1][j],dp[i][j-1]);
			}
		}

	}
	return dp[0][n-1];
}
