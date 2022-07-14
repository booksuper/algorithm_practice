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

/*给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素，并返回移除后数组的新长度*/
int removeElement(vector<int>& nums, int val);

/*给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。

请注意 ，必须在不复制数组的情况下原地对数组进行操作*/

void moveZeroes(vector<int>& nums);

/*167两数之和：给你一个下标从 1 开始的整数数组 numbers ，该数组已按 非递减顺序排列  ，
请你从数组中找出满足相加之和等于目标数 target 的两个数*/
vector<int> twoSum(vector<int>& numbers, int target);


//给定一个 n 个元素有序的（升序）整型数组 nums 和一个目标值 target  ，写一个函数搜索 nums 中的 target，
//如果目标值存在返回下标，否则返回 -1。

int binarySearch(vector<int>& nums, int target);


//回文串判断
bool isPalindrome(const char * s);

//给你一个字符串 s，找到 s 中最长的回文子串。
string longestPalindrome(string s);
