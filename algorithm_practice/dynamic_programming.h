#pragma once
#include <iostream>
#include <vector>
#include <map>

using namespace std;

//普通递归求解斐波那契数列
//该数列由 0 和 1 开始，后面的每一项数字都是前面两项数字的和。
//时间复杂度是指数级2^n
int fib(int n);

//计算阶乘
int rfact(int n);

//使用备忘录技巧去除冗余节点求解斐波那契数列,时间复杂度降低为n
//备忘录技巧用处挺多，可以避免重复计算
int modified_fib(int memo[], int n);

//使用迭代（递归）形式求解斐波那契数列

int fib_itera(int n);

/*凑零钱问题:给你一个整数数组 coins ，表示不同面额的硬币；以及一个整数 amount ，表示总金额。
计算并返回可以凑成总金额所需的 最少的硬币个数 。如果没有任何一种硬币组合能组成总金额，返回 -1 。
你可以认为每种硬币的数量是无限的。*/

int coinChange(vector<int>& coins, int amount);

//递归解决凑零钱问题
int coinChangeBaseRecursion(vector<int>& coins, int amount);