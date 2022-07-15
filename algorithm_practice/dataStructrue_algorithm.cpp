#include "dataStructrue_algorithm.h"

Solution::Solution(vector<int> arr)
{
	//构造差分数组
	diffe.resize(arr.size());
	diffe[0] = arr[0];
	for (int i = 1; i < diffe.size(); i++)
	{
		diffe[i] = arr[i] - arr[i - 1];	
	}
}

vector<vector<int>> Solution::getModifiedArray(vector<int> arr, vector<vector<int>> operate_arr)
{
	vector<vector<int>> res;
	res.resize(operate_arr.size());
	
	int opera_nums = operate_arr.size();
	for (int i = 0; i < opera_nums; i++)
	{
		res[i].resize(diffe.size());
		//修改差分数组
		//从起始区间i开始对差分数组加一个数k，相当于对原始数组的i以后的数都加了k
		diffe[operate_arr[i][0]] += operate_arr[i][2];
		//当 j+1 >= diff.length 时，说明是对 nums[i] 及以后的整个数组都进⾏修改，那么就不需要再给 diff
		//数组减 val 了
		if ((operate_arr[i][1] + 1) < diffe.size())
		{
			////从终止区间j+1开始对差分数组减一个数k，相当于对原始数组的j+1以后的数都减了k
			diffe[operate_arr[i][1] + 1] -= operate_arr[i][2];
		}
		//根据修改后的差分数组反推结果数组
		res[i][0] = diffe[0];
		for (int j = 1; j < diffe.size(); j++)
		{
			res[i][j] = diffe[j] + res[i][j - 1];
		}
		
	}
	return res;
}
//原地删除数组中重复元素
int removeDuplicates(vector<int>& nums)
{
	if (nums.size() == 0)
	{
		return 0;
	}
	int slow = 0;
	int fast = 0;
	while (fast < nums.size())
	{
		if (nums[slow] != nums[fast])
		{
			slow++;
			nums[slow] = nums[fast];
		}
		fast++;

	}
	return slow+1;
}
/*给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素，并返回移除后数组的新长度*/
int removeElement(vector<int>& nums, int val)
{
	if (nums.size() == 0)
	{
		return 0;
	}
	int slow = 0;
	int fast= 0;
	while (fast <= nums.size()-1)
	{
		if (val != nums[fast])
		{
			nums[slow] = nums[fast];
			slow++;
		}
		fast++;
	}
	return slow;
	
}
//给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序
void moveZeroes(vector<int>& nums)
{
	if (nums.size() == 0)
	{
		return;
	}
	int slow = 0;
	int fast = 0;
	//先把0全部移除，保证其他元素的相对顺序
	while (fast < nums.size())
	{
		if (0 != nums[fast])
		{
			nums[slow] = nums[fast];
			slow++;
		}
		fast++;
	}
	//把末端元素置0
	for (int i = slow; i < nums.size(); i++)
	{
		nums[i] = 0;
	}
}
//两数之和
vector<int> twoSum(vector<int>& numbers, int target)
{
	// //时间复杂度on2，不行
		// vector<int> res;
		// if(numbers.size() == 0)
		// {
		//     return res;
		// }

		// for(int i = 0;i<numbers.size();i++)
		// {
		//     for(int j = i+1;j<numbers.size();j++)
		//     {
		//         if(numbers[i] + numbers[j] == target)
		//         {
		//             res.push_back(i+1);
		//             res.push_back(j+1);
		//             break;

		//         }
		//     }
		//     if(res.size() == 2)
		//     {
		//         break;
		//     }
		// }
		// return res;

		//使用二分搜索的框架，因为这是个有序数组
	vector<int> res;
	int left = 0;
	int right = numbers.size() - 1;
	//int mid = left + (right - left) / 2;
	int sum = 0;
	while (left < right)
	{
		sum = numbers[left] + numbers[right];
		if (sum == target)
		{
			res.push_back(left + 1);
			res.push_back(right + 1);
			break;
		}
		else if (sum < target)
		{
			left++;
		}
		else if (sum > target)
		{
			right--;
		}
	}
	return res;
}
//二分搜索
int binarySearch(vector<int>& nums, int target)
{
	return 0;
}
//回文串判断
bool isPalindrome(const char * s)
{
	if (s == "")
	{
		return true;
	}
	int left = 0;
	int right = strlen(s) - 1;
	while (left < right)
	{
		if (s[left] != s[right])
		{
			return false;
		}
		left++;
		right--;
	}
	return true;
}

//给你一个字符串 s，找到 s 中最长的回文子串
string longestPalindrome(string s)
{
	string res = "";
	for (int i = 0; i < s.length(); i++)
	{
		//字符串长度为奇数时。只有一个中心
		string res1 = palindrome(s, i, i);
		//字符串长度为偶数时。有两个中心
		string res2 = palindrome(s, i, i+1);
		string res3 = res1.length() > res2.length() ? res1 : res2;
		res = res.length() > res3.length() ? res : res3;

	}
	return res;
}
//找到以每个字符为中心的回文串
string palindrome(string s, int l, int r)
{
	while (l >= 0 && r < s.length() && s[l] == s[r])
	{
		//从中心向两边扩展
		l--;
		r++;
	}
	//第一个参数是起始位置，第二个参数是跨越的字符长度，包括起始位置
	return s.substr(l+1,r-l-1);
}

