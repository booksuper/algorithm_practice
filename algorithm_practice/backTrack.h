#pragma once
#include <iostream>
#include <vector>

using namespace std;

//����һ����������  nums ��һ�������� k���ҳ��Ƿ��п��ܰ��������ֳ� k ���ǿ��Ӽ������ܺͶ���ȡ�
bool canPartitionKSubsets(vector<int>& nums, int k);
//���ݺ���
bool backtrack_KSubsets(vector<int>& nums,int index,vector<int> bucket,int target);

//����һ�������ظ����ֵ����� nums �������� ���п��ܵ�ȫ���� ������� ������˳�� ���ش�
vector<vector<int>> permute(vector<int>& nums);
//���ݺ���
void backtrack_permute(vector<int> nums, vector<int> track, bool* used, vector<vector<int>>& out_res);