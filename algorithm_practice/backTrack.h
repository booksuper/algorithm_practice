#pragma once
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

//78 子集 中等：给你一个整数数组 nums ，数组中的元素 互不相同 。返回该数组所有可能的子集（幂集）。
//解集 不能 包含重复的子集。你可以按 任意顺序 返回解集
vector<vector<int>> subsets(vector<int>& nums);
//所有可能子集回溯函数
void backtrack_subsets(vector<int>& nums, int n, vector<vector<int>>& res,vector<int> track);

/*90 子集II 中等：给你一个整数数组 nums ，
其中可能包含重复元素，请你返回该数组所有可能的子集（幂集）。
解集 不能 包含重复的子集。返回的解集中，子集可以按 任意顺序 排列
*/
vector<vector<int>> subsetsWithDup(vector<int>& nums);
////子集II的回调函数
void subsetsDupBackTrack(vector<vector<int>> &res, vector<int> &path, vector<int> & nums, int startIndex,vector<bool> &used);;

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

/*93 复原ip地址 中等：有效 IP 地址 正好由四个整数】
（每个整数位于 0 到 255 之间组成，且不能含有前导 0），
整数之间用 '.' 分隔。例如："0.1.2.201" 和 "192.168.1.1" 是 
有效 IP 地址，但是 "0.011.255.245"、"192.168.1.312" 和 
"192.168@1.1" 是 无效 IP 地址。给定一个只包含数字的字符串 s 
，用以表示一个 IP 地址，返回所有可能的有效 IP 地址，
这些地址可以通过在 s 中插入 '.' 来形成。
你 不能 重新排序或删除 s 中的任何数字。
你可以按 任何 顺序返回答案
。*/
vector<string> restoreIpAddresses(string s);
//复原ip地址回调函数
void restoreIpBackTrack(vector<string> & res,vector<string> &path,string & s,int startIndex);
//验证是否是有效ip
bool isValidIp(const vector<string> & Ip);

/*491 递增子序列 中等：给你一个整数数组 nums ，找出并返回所有该数组中不同的递增子序列，
递增子序列中 至少有两个元素 。你可以按 任意顺序 返回答案。
数组中可能含有重复元素，如出现两个整数相等，也可以视作递增序列的一种特殊情况。
*/
vector<vector<int>> findSubsequences(vector<int>& nums);
//递增子序列的回溯函数
void findSubsetsBackTrack(vector<vector<int>> &res, vector<int>& paths, vector<int>& nums, int startIndex);
//是不是递增序列
bool isIncreasingSeq(vector<int> &path);