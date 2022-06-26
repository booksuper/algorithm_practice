#pragma once
#include <iostream>
#include <vector>
#include <map>

using namespace std;

//普通递归求解斐波那契数列
//该数列由 0 和 1 开始，后面的每一项数字都是前面两项数字的和。
//时间复杂度是指数级2^n
int fib(int n);

//使用备忘录技巧去除冗余节点求解斐波那契数列,时间复杂度降低为n
//备忘录技巧用处挺多，可以避免重复计算
int modified_fib(int memo[], int n);
//