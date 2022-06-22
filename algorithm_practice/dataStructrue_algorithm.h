#pragma once
#include "sort_algorithm.hpp"

/// @brief 使用差分数组求解区间和
/// @details 假设你有一个长度为 n 的数组，初始情况下所有的数字均为 0，你将会被给出 k​​​​​​​ 个更新的操作。
/// 其中，每个操作会被表示为一个三元组：[startIndex, endIndex, inc]，你需要将子数组 A[startIndex … endIndex]
///（包括 startIndex 和 endIndex）增加 inc。
/// 请你返回 k 次操作后的数组

class Solution
{
public:
	Solution(vector<int> arr);
	vector<vector<int>> getModifiedArray(vector<int> arr, vector<vector<int>> operate_arr);
	

private:
	vector<int> diffe;
};



