#pragma once
#include <iostream>
#include <vector>

using namespace std;

//给定一个整数数组  nums 和一个正整数 k，找出是否有可能把这个数组分成 k 个非空子集，其总和都相等。
bool canPartitionKSubsets(vector<int>& nums, int k);
//回溯函数
bool backtrack_KSubsets(vector<int>& nums,int index,vector<int> bucket,int target);

//给定一个不含重复数字的数组 nums ，返回其 所有可能的全排列 。你可以 按任意顺序 返回答案
vector<vector<int>> permute(vector<int>& nums);
//回溯函数
void backtrack_permute(vector<int> nums, vector<int> track, bool* used, vector<vector<int>>& out_res);

//给你一个整数数组 nums ，数组中的元素 互不相同 。返回该数组所有可能的子集（幂集）。
//解集 不能 包含重复的子集。你可以按 任意顺序 返回解集
vector<vector<int>> subsets(vector<int>& nums);
//所有可能子集回溯函数
void backtrack_subsets(vector<int>& nums, int n, vector<vector<int>>& res,vector<int> track);

/*77 组合 中等：给定两个整数 n 和 k，返回范围 [1, n] 中所有可能的 k 个数的组合。
你可以按 任何顺序 返回答案*/
vector<vector<int>> combine(int n, int k);
//组合的回溯函数
void backTrackCombine(vector<vector<int>> &res, vector<int> &path, int n, int k, int startIndex);