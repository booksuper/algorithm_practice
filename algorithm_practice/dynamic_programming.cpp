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
