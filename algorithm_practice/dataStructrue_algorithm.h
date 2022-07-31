#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <algorithm>

using namespace std;
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

/*1 简单 两数之和：给定一个整数数组 nums 和一个整数目标值 target，
请你在该数组中找出 和为目标值 target  的那 两个 整数，并返回它们的数组下标。
你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现
这和上面一题不一样，这里的元素没有排序，这一题很经典，使用哈希表解决，和167题类似
167也可以用这个方法解决，复杂度符合要求，使用哈希表解决更具一般性
*/
vector<int> twoSumSimple(vector<int>& nums, int target);

/*454 中等 四数相加II:给你四个整数数组 nums1、nums2、nums3 和 nums4 ，
数组长度都是 n ，请你计算有多少个元组 (i, j, k, l) 能满足*/
int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4);

/*15 中等 三数之和：给你一个包含 n 个整数的数组 nums，判断 nums 中
是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？请你找出所有和为 0 且不重复的三元组
*/
vector<vector<int>> threeSum(vector<int>& nums);

/*18 中等 四数之和：给你一个由 n 个整数组成的数组 nums ，和一个目标值 target 。
请你找出并返回满足下述全部条件且不重复的四元组 [nums[a], nums[b], nums[c], nums[d]]
（若两个四元组元素一一对应，则认为两个四元组重复
*/
vector<vector<int>> fourSum(vector<int>& nums, int target);

/*剑指offer39 数组中出现的次数超过数组长度的一半，找出这个数字 简单：数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
你可以假设数组是非空的，并且给定的数组总是存在多数元素*/
int majorityElement(vector<int>& nums);

/*剑指offer56 中等 数组中数字出现的次数：一个整型数组 nums 里除两个数字之外，其他数字都出现了两次。请写程序找出这两个只出现一次的数字
。要求时间复杂度是O(n)，空间复杂度是O(1)。*/
vector<int> singleNumbers(vector<int>& nums);

/*41 缺失的第一个正整数 困难：给你一个未排序的整数数组 nums ，请你找出其中没有出现的最小的正整数。
请你实现时间复杂度为 O(n) 并且只使用常数级别额外空间的解决方案*/
int firstMissingPositive(vector<int>& nums);

//704:给定一个 n 个元素有序的（升序）整型数组 nums 和一个目标值 target  ，写一个函数搜索 nums 中的 target，
//如果目标值存在返回下标，否则返回 -1。
int binarySearch(vector<int>& nums, int target);

/*34在排序数组中查找元素的第一个和最后一个位置:给你一个按照非递减顺序排列的整数数组 nums，
和一个目标值 target。请你找出给定目标值在数组中的开始位置和结束位置。
如果数组中不存在目标值 target，返回 [-1, -1]
*/
vector<int> searchRange(vector<int>& nums, int target);

//回文串判断
bool isPalindrome(const char * s);

//给你一个字符串 s，找到 s 中最长的回文子串。
string longestPalindrome(string s);
//找到以每个字符为中心的回文串
string palindrome(string s,int l,int r);

/*48旋转图像：给定一个 n × n 的二维矩阵 matrix 表示一个图像。请你将图像顺时针旋转 90 度。
你必须在 原地 旋转图像，这意味着你需要直接修改输入的二维矩阵。请不要 使用另一个矩阵来旋转图像
*/
void rotate(vector<vector<int>>& matrix);
//反转一维数组
void reverse_array(vector<int> & arr);

//54 中等 螺旋矩阵：给你一个 m 行 n 列的矩阵 matrix ，请按照 顺时针螺旋顺序 ，返回矩阵中的所有元素
vector<int> spiralOrder(vector<vector<int>>& matrix);

 /*59 螺旋矩阵2：给你一个正整数 n ，生成一个包含 1 到 n2 所有元素，
 且元素按顺时针顺序螺旋排列的 n x n 正方形矩阵 matrix*/
vector<vector<int>> generateMatrix(int n);

/*349 简单 两个数组的交集：给定两个数组 nums1 和 nums2 ，返回 它们的交集 。
输出结果中的每个元素一定是 唯一 的。我们可以 不考虑输出结果的顺序 */
vector<int> intersection(vector<int>& nums1, vector<int>& nums2);