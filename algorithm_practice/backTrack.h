﻿#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
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

/*216 组合总和III 中等：找出所有相加之和为 n 的 k 个数的组合，且满足下列条件：
只使用数字1到9每个数字 最多使用一次 
返回 所有可能的有效组合的列表 。该列表不能包含相同的组合两次，组合可以以任何顺序返回
*/
vector<vector<int>> combinationSum3(int k, int n);
//组合总和的回调函数
void backTrackCombinationSum3(vector<vector<int>> &res, vector<int> & path, int k, int n, int startIndex);

/*39 组合总和 中等：给你一个 无重复元素 的整数数组 candidates 和一个目标整数 target ，找出 candidates 
中可以使数字和为目标数 target 的 所有 不同组合 ，并以列表形式返回。你可以按 任意顺序 返回这些组合。
candidates 中的 同一个 数字可以 无限制重复被选取 。如果至少一个数字的被选数量不同，则两种组合是不同的。 
对于给定的输入，保证和为 target 的不同组合数少于 150 个
*/
vector<vector<int>> combinationSum(vector<int>& candidates, int target);
//组合总和回调函数
void backTrackcombinationSum(vector<vector<int>> &res, vector<int> & path, vector<int> &candidate, int target, int startIndex);

/*40 组合总和II 中等：给定一个候选人编号的集合 candidates 和一个目标数 target ，
找出 candidates 中所有可以使数字和为 target 的组合。
candidates 中的每个数字在每个组合中只能使用 一次 。
*/
vector<vector<int>> combinationSum2(vector<int>& candidates, int target);
//组合总和II回调
void backTrackcombinationSum2(vector<vector<int>> &res, vector<int> & path, vector<int> &candidate, int target, int startIndex,vector<bool> & used);

/*131 分割回文串 中等：给你一个字符串 s，请你将 s 分割成一些子串，使每个子串都是 回文串 。
返回 s 所有可能的分割方案。
回文串 是正着读和反着读都一样的字符串。*/
vector<vector<string>> partition(string s);
//分割回文串的回溯函数
void backTrackPartition(vector<vector<string>> &res,vector<string> &path,string s,int startIndex);
//判断字符串是不是回文的辅助函数
bool vectorIsPalindrome(vector<string> &str);