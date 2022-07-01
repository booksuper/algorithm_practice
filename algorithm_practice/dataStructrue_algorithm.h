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

//给你一个 升序排列 的数组 nums ，请你 原地 删除重复出现的元素，使每个元素 只出现一次 ，
//返回删除后数组的新长度。元素的 相对顺序 应该保持 一致

int removeDuplicates(vector<int>& nums);

//给定一个 n 个元素有序的（升序）整型数组 nums 和一个目标值 target  ，写一个函数搜索 nums 中的 target，
//如果目标值存在返回下标，否则返回 -1。

int binarySearch(vector<int>& nums, int target);


