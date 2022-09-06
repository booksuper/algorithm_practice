#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
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

/*70 爬楼梯 简单：假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？*/
int climbStairs(int n);

/*746 使用最小花费爬楼梯 简单：
给你一个整数数组 cost ，其中 cost[i] 是从楼梯第 i 个台阶向上爬需要支付的费用。
一旦你支付此费用，即可选择向上爬一个或者两个台阶。
你可以选择从下标为 0 或下标为 1 的台阶开始爬楼梯。
请你计算并返回达到楼梯顶部的最低花费。
。*/
int minCostClimbingStairs(vector<int>& cost);

/*62 不同路径 中等：
一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为 “Start” ）。
机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为 “Finish” ）。
问总共有多少条不同的路径？
*/
int uniquePaths(int m, int n);

/*63 不同路径II 中等：
一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为 “Start” ）。
机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为 “Finish”）。
现在考虑网格中有障碍物。那么从左上角到右下角将会有多少条不同的路径？
网格中的障碍物和空位置分别用 1 和 0 来表示。
*/
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid);

/*72 编辑距离 困难：
给你两个单词 word1 和 word2， 请返回将 word1 转换成 word2 所使用的最少操作数 。
你可以对一个单词进行如下三种操作：
插入一个字符
删除一个字符
替换一个字符

*/
int minDistance(string word1, string word2);

//647 回文子串 中等：
/*给你一个字符串 s ，请你统计并返回这个字符串中 回文子串 的数目。
回文字符串 是正着读和倒过来读一样的字符串。
子字符串 是字符串中的由连续字符组成的一个序列。
具有不同开始位置或结束位置的子串，即使是由相同的字符组成，也会被视作不同的子串。
*/
int countSubstrings(string s);

//回文子串的dp解法,超出时间限制了
int countSubStrDp(string s);

/*516 最长回文子序列 中等：
给你一个字符串 s ，找出其中最长的回文子序列，并返回该序列的长度。
子序列定义为：不改变剩余字符顺序的情况下，删除某些字符或者不删除
任何字符形成的一个序列。
*/
int longestPalindromeSubseq(string s);
