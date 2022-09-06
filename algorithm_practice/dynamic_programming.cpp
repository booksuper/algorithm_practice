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
				//递推结果，公式为dp[i] = 1+dp[i-硬币值]，加的1代表当前硬币，硬币值是coins[j]
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

int coinChangeBaseRecursion(vector<int>& coins, int amount)
{
	return 0;
}
/*70 爬楼梯 简单：假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？*/
int climbStairs(int n)
{
	/*首先要先确定dp[i]的意义，本题中dp[i]:爬第i层楼梯时有dp[i]种方法
	 *然后可以自己举例推导，确定递推公式，因为本题中n为正整数，所以不需要考虑n为0情况
	 dp[1] = 1,dp[2] = 2,dp[3] = 3,dp[4] = 5,可以发现这其实就是一个斐波那契数列
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
//746 使用最小花费爬楼梯 简单：
int minCostClimbingStairs(vector<int>& cost)
{
	vector<int> dp(cost.size());
	dp[0] = cost[0];
	dp[1] = cost[1];
	for (int i = 2; i < cost.size(); i++)
	{
		dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i];
	}
	// 注意最后一步可以理解为不用花费，所以取倒数第一步，第二步的最少值
	return min(dp[cost.size() - 1],dp[cost.size() - 2]);
}
//62 不同路径 中等
int uniquePaths(int m, int n)
{
	//dp[i][j]定义：从（0,0）到（i,j）有dp[i][j]种路径
	vector<vector<int>> dp(m, vector<int>(n, 0));
	//初始化，dp[0][j]肯定只有一种方法，dp[i][0]同理
	for (int i = 0; i < m; i++) dp[i][0] = 1;
	for (int j = 0; j < n; j++) dp[0][j] = 1;
	//开始递归
	for (int i = 1; i < m; i++)
	{
		for (int j = 1; j < n; j++)
		{
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
		}
	}
	return dp[m-1][n-1];
}
//63 不同路径II 中等
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
{
	int m = obstacleGrid.size();
	int n = obstacleGrid[0].size();
	if (obstacleGrid[m - 1][n - 1] == 1 || obstacleGrid[0][0] == 1) //如果在起点或终点出现了障碍，直接返回0
		return 0;
	vector<vector<int>> dp(m, vector<int>(n, 0));
	//初始化，只有当路径中一个障碍都没有的时候，dp[0][j]才有一种方法，dp[i][0]同理
	for (int i = 0; i < m && obstacleGrid[i][0] == 0; i++)
	{
		
		dp[i][0] = 1;
	}
	for (int j = 0; j < n && obstacleGrid[0][j] == 0; j++)
	{
		
		dp[0][j] = 1;
	}
	//递推
	for (int i = 1; i < m; i++)
	{
		for (int j = 1; j < n; j++)
		{
			//有障碍物就跳过这一次，这个值就会被默认为0
			if (obstacleGrid[i][j] == 1)
			{
				continue;
			}
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			
		}
	}
	return dp[m - 1][n - 1];
	
}
//72 编辑距离 困难。文本纠错的核心步骤
int minDistance(string word1, string word2)
{
	//dp[i][j] 表示以下标i-1为结尾的字符串word1，
	//和以下标j-1为结尾的字符串word2，最近编辑距离为dp[i][j]。
	int m = word1.size();
	int n = word2.size();

	vector<vector<int>> dp(m+1,vector<int>(n+1,0));
	//初始化
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
			//以下标i-1结尾的word1和以下标j-1结尾的word2相等
			if (word1[i - 1] == word2[j - 1])
			{
				//以下标i-1结尾的word1和以下标j-1结尾的word2相等
				//就可以递推出
				dp[i][j] = dp[i - 1][j - 1];
			}
			else
			{
				//不相等，需要做删除、替换、增加三种操作;增加和删除相当于一个操作
				//然后需要从这三种操作选择操作数最小的再加1就行
				//word1删除：dp[i][j] = dp[i-1][j] + 1
				//word2删除：dp[i][j] = dp[i][j-1] + 1
				//word2添加一个元素，相当于word1删除一个元素，所以不需要增加操作公式
				//替换元素，word1替换word1[i - 1]，使其与word2[j - 1]相同
				//dp[i][j] = dp[i-1][j-1] + 1
				dp[i][j] = min({ dp[i - 1][j - 1],dp[i][j - 1],dp[i - 1][j] }) + 1;
			}
		}
	}
	return dp[m][n];
}
//647 回文子串 中等：
int countSubstrings(string s)
{
	//中心拓展法求解，只要遍历字符串中的每个中心，然后向两边拓展即可
	//难点在于，拓展中心并不只是单个字符的，还有可能是两个字符，所以中心就不仅仅是
	//字符串的大小，而是2n-1，也就是单字符的有n个，双字符的有n-1个
	int n = s.size();
	int res = 0;
	for (size_t i = 0; i < 2 * n - 1; i++)
	{
		//初始化左右指针
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
//回文子串的dp解法
int countSubStrDp(string s)
{
	int n = s.size();
	vector<vector<bool>> dp(n, vector<bool>(n, false));
	int res = 0;
	// 注意遍历顺序
	for (int i = n-1; i >= 0; i--)
	{
		for (int j = i; j < n; j++)
		{
			if (s[i] == s[j])
			{
				/*情况一：下标i 与 j相同，同一个字符例如a，当然是回文子串
                  情况二：下标i 与 j相差为1，例如aa，也是回文子串*/
				if (j - i <= 1)
				{
					res++;
					dp[i][j] = true;
				}
				/*情况三：下标：i 与 j相差大于1的时候，例如cabac，
				此时s[i]与s[j]已经相同了，我们看i到j区间是不是回文子串
				就看aba是不是回文就可以了，那么aba的区间就是 i+1 与 
				j-1区间，这个区间是不是回文就看dp[i + 1][j - 1]是否
				为true。*/
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
//516 最长回文子序列 中等
int longestPalindromeSubseq(string s)
{
	//没法使用回溯，因为他要求的是不连续的
	//dp[i][j]：字符串s在[i, j]范围内最长的回文子序列的长度为dp[i][j]。
	//如果s[i]与s[j]相同，那么dp[i][j] = dp[i + 1][j - 1] + 2;
	int n = s.size();
	vector<vector<int>> dp(n, vector<int>(n, 0));
	//初始化
	for (size_t i = 0; i < n; i++)
	{
		dp[i][i] = 1;
	}
	//遍历顺序从下到上
	for (int i = n - 1; i >= 0; i--)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (s[i] == s[j])
			{
				//如果s[i]与s[j]相同，那么dp[i][j] = dp[i + 1][j - 1] + 2;
				dp[i][j] = dp[i + 1][j - 1] + 2;
			}
			else
			{
				/*如果s[i]与s[j]不相同，说明s[i]和s[j]的同时加入 
				并不能增加[i,j]区间回文子串的长度，那么分别加入s[i]、
				s[j]看看哪一个可以组成最长的回文子序列。
                加入s[j]的回文子序列长度为dp[i + 1][j]。
                加入s[i]的回文子序列长度为dp[i][j - 1]*/
				dp[i][j] = max(dp[i+1][j],dp[i][j-1]);
			}
		}

	}
	return dp[0][n-1];
}
