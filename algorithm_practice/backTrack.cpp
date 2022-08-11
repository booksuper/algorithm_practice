#include "backTrack.h"

//划分k个相等的子集和
bool canPartitionKSubsets(vector<int>& nums, int k)
{
	//排除一些基本情况
	if(k > nums.size())
	{
		return false;
	}
	int sum = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		sum += nums[i];
	}
	if (sum % k != 0)
	{
		return false;
	}
	int target = sum / k;
	vector<int> backet;
	backet.resize(k);
	return backtrack_KSubsets(nums, 0, backet, target);


}
//k个相等子集和的回溯函数
bool backtrack_KSubsets(vector<int>& nums, int index, vector<int> bucket, int target)
{
	//base case
	//以数字的视角，所以base case应该是nums的数字遍历完了一遍
	if (index == nums.size())
	{
		//判断每个桶中的数字是否一样
		for (int i = 0; i < bucket.size(); i++)
		{
			if(bucket[i] != target)
			{
				return false;
			}

		}
		return true;
	}
	//遍历每个桶
	for (int i = 0; i < bucket.size(); i++)
	{
		//剪枝
	   //当桶中的数字新加一个数之后，其和大于target，直接下一次循环
		if (bucket[i] + nums[index] > target)
		{
			continue;
		}
		//做选择：把当前nums加入桶中
		bucket[i] += nums[index];
		//回溯
		if (backtrack_KSubsets(nums, index + 1, bucket, target))
		{
			return true;
		}
		//撤销选择
		bucket[i] -= nums[index];
	}
	// nums[index] 装入哪个桶都不行
	return false;


}
//给定一个不含重复数字的数组 nums ，返回其 所有可能的全排列 。你可以 按任意顺序 返回答案
vector<vector<int>> permute(vector<int>& nums)
{
	//记录排列路径
	vector<int> track;
	//结果
	vector<vector<int>> res;
	// 「路径」中的元素会被标记为 true，避免重复使用,一开始要初始化为0，全为false
	bool* used = new bool[nums.size()]{};
    //结果必须引用传参，不然错误
	backtrack_permute(nums, track, used,res);
	return res;
}
//回溯函数
// 路径：记录在 track 中
// 选择列表：nums 中不存在于 track 的那些元素（used[i] 为 false）
// 结束条件：nums 中的元素全都在 track 中出现
void backtrack_permute(vector<int> nums, vector<int> track, bool * used, vector<vector<int>>& out_res)
{
	// 触发结束条件
	if (track.size() == nums.size()) {
		out_res.push_back(track);
		return ;
	}
	for (int i = 0; i < nums.size(); i++) {
		// 排除不合法的选择
		if (used[i]) {
			// nums[i] 已经在 track 中，跳过
			continue;
		}
		// 做选择
		track.push_back(nums[i]);
		used[i] = true;
		// 进入下一层决策树
		backtrack_permute(nums, track, used, out_res);
		// 取消选择
		track.pop_back();
		used[i] = false;
	}

}
//所有可能子集
vector<vector<int>> subsets(vector<int>& nums)
{
	vector<vector<int>> res;
	vector<int> track;
	backtrack_subsets(nums, 0, res, track);

	return res;
}

void backtrack_subsets(vector<int>& nums, int start, vector<vector<int>>& res, vector<int> track)
{
	// 前序位置，每个节点的值都是一个子集
	res.push_back(track);
	for (int i = start; i < nums.size(); i++)
	{
		track.push_back(nums[i]);
		// 通过 start 参数控制树枝的遍历，避免产生重复的子集
		backtrack_subsets(nums, i + 1, res, track);
		track.pop_back();
	}
}
//77 组合 中等
vector<vector<int>> combine(int n, int k)
{
	vector<vector<int>> res;
	vector<int> path;
	backTrackCombine(res, path, n, k, 1);
	return res;
}
//组合的回溯函数
void backTrackCombine(vector<vector<int>>& res, vector<int>& path, int n, int k, int startIndex)
{
	//终止条件
	if (path.size() == k)
	{
		res.push_back(path);
		return;
	}

	for (int i = startIndex; i <= n; i++)//横向遍历
	{
		path.push_back(i);//收集路径上的值
		backTrackCombine(res, path, n, k, i + 1);//递归，也就是纵向遍历
		path.pop_back();//回溯操作
	}
}
