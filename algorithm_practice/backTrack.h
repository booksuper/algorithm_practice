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

//����һ���������� nums �������е�Ԫ�� ������ͬ �����ظ��������п��ܵ��Ӽ����ݼ�����
//�⼯ ���� �����ظ����Ӽ�������԰� ����˳�� ���ؽ⼯
vector<vector<int>> subsets(vector<int>& nums);
//���п����Ӽ����ݺ���
void backtrack_subsets(vector<int>& nums, int n, vector<vector<int>>& res,vector<int> track);