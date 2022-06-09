#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

//稳定排序：如果 a 原本在 b 的前面，且 a == b，排序之后 a 仍然在 b 的前面，则为稳定排序
//非稳定排序：如果 a 原本在 b 的前面，且 a == b，排序之后 a 可能不在 b 的前面，则为非稳定排序

/// @brief 冒泡排序
/// @details 算法原理为从左到右，数组中相邻的两个元素进行比较，将较大的放到后面。算法复杂度为O(n2)
/// 它是一种稳定排序算法
template<class T>
void bubbleSort(vector<T> & arr)
{
	for (int i = 0; i < arr.size()-1; i++)
	{
		for (int j = 0; j < arr.size()-1-i; j++)
		{
			if (arr[j] > arr[j+1])
			{
				T tem = arr[j+1];
				arr[j+1] = arr[j];
				arr[j] = tem;
			}
			
		}
	}
}


/// @brief 直接选择排序
/// @details 算法复杂度为O(n2),但交换次数比冒泡排序少多了，n值较小时，选择排序比冒泡排序快
/// 选择排序在排序过程中，元素两两交换时，相同元素的前后顺序会发生改变 （比如：序列5 5 7 2 9，
/// 第一遍选择第1个元素5会和2交换，那么原序列中两个5的相对前后顺序就被破坏了，而冒泡排序不会），
/// 所以选择排序是一种不稳定的排序算法
template<class T>
void selectSort(vector<T> & arr)
{
	for (int i = 0; i < arr.size() - 1; i++)
	{
		for (int j = i + 1; j < arr.size(); j++)
		{
			if (arr[i] > arr[j])
			{
				T tem = arr[i];
				arr[i] = arr[j];
				arr[j] = tem;
			}

		}
	}

}

/// @brief 快速排序
/// @details 快速排序是一种不稳定排序算法，算法复杂度是nlogn,在众多排序算法中速度算是最优的
/// 算法原理：首先选择一个基准值，一般选择第一个元素作为基准值，然后以基准值为界将数组分为两个子数组，比基准值小的
/// 在左边，比基准值大的在右边。然后在对子数组重复类似的操作，最终实现排序
/// 快速排序的本质思想是递归，本代码是用递归实现的，但也可以不用递归实现快速排序
template<class T>
vector<T> quickSort(vector<T> arr)
{
	//这一句是递归的终止条件，没有这一句整个程序会陷入死循环
	if (arr.size() <= 1)
		return arr;
	T pivot = arr[0];
	vector<T> left;
	vector<T> right;
	//比基准值小的在left，大的在right中
	for (int i = 1; i < arr.size(); i++)
	{
		if (arr[i] <= pivot)
		{
			left.push_back(arr[i]);
		}
		else
		{
			right.push_back(arr[i]);
		}
	}
	vector<T> res1, res2,res;
	//对子数组递归
	res1 = quickSort(left);
	res2 = quickSort(right);
	//拼接
	res.insert(res.end(), res1.begin(), res1.end());
	res.insert(res.end(),pivot);
	res.insert(res.end(), res2.begin(), res2.end());
	return res;
}

