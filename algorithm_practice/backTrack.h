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