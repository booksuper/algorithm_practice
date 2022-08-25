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
//78 子集 中等：
vector<vector<int>> subsets(vector<int>& nums)
{
	vector<vector<int>> res;
	vector<int> track;
	backtrack_subsets(nums, 0, res, track);
	return res;
}
//78 子集回溯函数
void backtrack_subsets(vector<int>& nums, int start, vector<vector<int>>& res, vector<int> track)
{
	//子集是要收集所有的节点，而组合和分割只是收割叶子节点
	//所以子集收集元素的时候是放在if外面，这代表不需要判断就收集，如果在里面会漏掉自己
	res.push_back(track);
	for (int i = start; i < nums.size(); i++)
	{
		track.push_back(nums[i]);
		// 通过 start 参数控制树枝的遍历，避免产生重复的子集
		backtrack_subsets(nums, i + 1, res, track);
		track.pop_back();
	}
}

//90 子集II 中等
vector<vector<int>> subsetsWithDup(vector<int>& nums)
{
	vector<vector<int>> res;
	vector<int> path;
	vector<bool> used(nums.size(), false);
	sort(nums.begin(),nums.end());
	subsetsDupBackTrack(res,path,nums,0,used);
	return res;
}
//子集II的回调函数
void subsetsDupBackTrack(vector<vector<int>>& res, vector<int>& path, vector<int>& nums, int startIndex, vector<bool> &used)
{
	//这和子集问题区别在于集合里面有重复的元素，所以需要去重
	res.push_back(path);
	if (startIndex >= nums.size()) return;
	for (size_t i = startIndex; i < nums.size(); i++)
	{
		//去重,和组合II问题的去重一样，也是在树层去重，树枝不需要去重
		if (i > 0 && nums[i] == nums[i - 1] && used[i-1] == false) continue;
		path.push_back(nums[i]);
		used[i] = true;
		subsetsDupBackTrack(res, path, nums, i + 1,used);
		path.pop_back();
		used[i] = false;
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
	//可以剪枝优化,在for循环的终止条件做剪枝
	//for (int i = startIndex; i <= n - (k - path.size()) + 1; i++)
	for (int i = startIndex; i <= n; i++)//横向遍历
	{
		path.push_back(i);//收集路径上的值
		backTrackCombine(res, path, n, k, i + 1);//递归，也就是纵向遍历
		path.pop_back();//回溯操作
	}
}
//216 组合总和III 中等
vector<vector<int>> combinationSum3(int k, int n)
{
	vector<vector<int>> res;
	vector<int> path;
	backTrackCombinationSum3(res,path,k,n,1);
	return res;
}
//组合总和的回调函数
void backTrackCombinationSum3(vector<vector<int>>& res, vector<int>& path, int k, int n, int startIndex)
{
	if (path.size() == k)
	{
		//相加之和为n
		if (accumulate(path.begin(), path.end(), 0) == n)
		{
			res.push_back(path);
			return;
		}
		return;
	}

	for (int i = startIndex; i <= 9; i++)
	{
		path.push_back(i);
		//如果索引是startIndex+1,则数组中会有重复数字
		backTrackCombinationSum3(res, path, k, n, i + 1);
		path.pop_back();
	}
}

//组合总和
vector<vector<int>> combinationSum(vector<int>& candidates, int target)
{
	vector<vector<int>> res;
	vector<int> path;
	backTrackcombinationSum(res, path,candidates, target, 0);
	return res;
}
//组合总和回调函数
void backTrackcombinationSum(vector<vector<int>>& res, vector<int>& path, vector<int>& candidate, int target, int startIndex)
{
	//如果一直没有符合条件的就是空
	if (accumulate(path.begin(),path.end(),0) == target)
	{
		res.push_back(path);
		return;
	}
	else if (accumulate(path.begin(), path.end(), 0) > target)//没有这个就会一直递归
	{
		return;
	}
	for (int i = startIndex; i < candidate.size(); i++)
	{
		path.push_back(candidate[i]);
		//可以有重复元素，所以索引都从0开始
		//// 关键点:不用i+1了，表示可以重复读取当前的数
		backTrackcombinationSum(res, path, candidate, target, i);
		path.pop_back();
	}

}
//40 组合总和II 中等
//和I的区别在于它的输入里面有重复的数字，而且同一个数不能被重复使用，难点在于去重
vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
{
	vector<bool> used(candidates.size(), false);
	vector<vector<int>> res;
	vector<int> path;
	// 首先把给candidates排序，让其相同的元素都挨在一起。用于去重
	sort(candidates.begin(), candidates.end());
	backTrackcombinationSum2(res, path, candidates, target, 0,used);
	return res;
}
//组合总和II回调
void backTrackcombinationSum2(vector<vector<int>>& res, vector<int>& path, vector<int>& candidate, int target, int startIndex, vector<bool> & used)
{
	if (accumulate(path.begin(), path.end(), 0) == target)
	{
		res.push_back(path);
		return;
	}
	//和大于目标数，得返回，不然会一直递归
	else if(accumulate(path.begin(), path.end(), 0) > target)
	{
		return;
	}

	for (int i = startIndex; i < candidate.size(); i++)
	{
		//还不是很理解
		// used[i - 1] == true，说明同一树枝candidates[i - 1]使用过
		// used[i - 1] == false，说明同一树层candidates[i - 1]使用过
		// 要对同一树层使用过的元素进行跳过
		if (i > 0 && candidate[i] == candidate[i - 1] && used[i - 1] == false) {
			continue;
		}
		path.push_back(candidate[i]);
		used[i] = true;
		backTrackcombinationSum2(res, path, candidate, target, i + 1,used);
		used[i] = false;
		path.pop_back();
	}
}
//131 分割回文串 中等
vector<vector<string>> partition(string s)
{
	vector<vector<string>> res;
	vector<string> path;
	backTrackPartition(res, path, s, 0);
	return res;
}
//分割回文串的回溯函数
void backTrackPartition(vector<vector<string>>& res, vector<string>& path, string s, int startIndex)
{
	// 如果起始位置已经大于s的大小，说明已经找到了一组分割方案了，再判断其是不是回文
	if (vectorIsPalindrome(path) && startIndex >= s.size())
	{
		res.push_back(path);
		return;
	}
	for (int i = startIndex; i < s.size(); i++)
	{
		//这一步关键，怎截取字符串
		path.push_back(s.substr(startIndex, i - startIndex + 1));
		backTrackPartition(res, path, s, i + 1);
		path.pop_back();
	}
}
//判断字符串是不是回文的辅助函数
bool vectorIsPalindrome(vector<string>& str)
{
	for (size_t i = 0; i < str.size(); i++)
	{
		int right = str[i].size() - 1;
		int left = 0;
		while (left < right)
		{
			if (str[i][left] != str[i][right]) return false;
			left++;
			right--;
		}
	}
	return true;
}
//93 复原ip地址 中等
vector<string> restoreIpAddresses(string s)
{
	vector<string> res;
	vector<string> path;
	restoreIpBackTrack(res, path, s, 0);
	return res;
}
//复原ip地址回调函数
void restoreIpBackTrack(vector<string>& res, vector<string>& path, string & s, int startIndex)
{
	//一定不要忘了加起始位置大于字符串s的大小这个条件
	//不然没把字符串s用完就输出结果了
	if (path.size() == 4 && isValidIp(path) && startIndex >= s.size())
	{
		string r;
		//转成ip形式
		for (size_t i = 0; i < path.size() - 1; i++)
		{
			r = r + path[i] + ".";
		}
		r = r + path[3];//最后一个不用加.
		res.push_back(r);
		return;
	}
	else if(path.size() > 4)
	{
		return;
	}

	for (int i = startIndex; i < s.size(); i++)
	{
		path.push_back(s.substr(startIndex, i - startIndex + 1));
		restoreIpBackTrack(res, path, s, i + 1);
		path.pop_back();

	}
}
//验证是否是有效ip
bool isValidIp(const vector<string>& Ip)
{
	for (size_t i = 0; i < Ip.size(); i++)
	{
		if (Ip[i].size() > 1)
		{
			//第一位不能是0
			if (Ip[i][0] == '0') return false;
		}
		//不能大于255
		if (Ip[i].size() == 3)
		{
			//先将其转为数字
			int sum = 0;
			int k = 2;
			for (size_t j = 0; j < 3; j++)
			{
				sum += (Ip[i][j] - '0') * pow(10, k--);
			}
			if (sum > 255) return false;
		}
		if (Ip[i].size() > 3) return false;
	}
	return true;
}
//491 递增子序列 中等
vector<vector<int>> findSubsequences(vector<int>& nums)
{
	vector<vector<int>> res;
	vector<int> paths;
	findSubsetsBackTrack(res, paths, nums, 0);
	return res;
}
//使用set进行去重，简单粗暴，耗时是剪枝的4倍
vector<vector<int>> findSubsequencesBaseSet(vector<int>& nums)
{
	set<vector<int>> set_res;
	vector<vector<int>> res;
	vector<int> paths;
	findSubsetsBackTrack(set_res, paths, nums, 0);
	for (auto it : set_res)
	{
		res.push_back(it);
	}
	return res;
}
//递增子序列的回溯函数,集合去重版本
void findSubsetsBackTrack(set<vector<int>>& res, vector<int>& paths, vector<int>& nums, int startIndex)
{
	//一定要大小的判断在前面，不然如果paths是空的话，先执行判断是不是递增子序列，
	//将会报越界错误
	if (paths.size() > 1 && isIncreasingSeq(paths))
	{
		//集合会自动去重，这种方法简单粗暴，不需要思考如何剪枝
		//但时间复杂度会长四倍，因为集合是用一个红黑树进行去重的
		res.insert(paths);
		// 注意这里不要加return，因为要取树上的所有节点
	}

	if (startIndex >= nums.size())
	{
		return;
	}
	
	for (int i = startIndex; i < nums.size(); i++)
	{
		paths.push_back(nums[i]);
		findSubsetsBackTrack(res, paths, nums, i + 1);
		paths.pop_back();
	}
}
//递增子序列的回溯函数
void findSubsetsBackTrack(vector<vector<int>>& res, vector<int>& paths, vector<int>& nums, int startIndex)
{
	//一定要大小的判断在前面，不然如果paths是空的话，先执行判断是不是递增子序列，
	//将会报越界错误
	if (paths.size() > 1 && isIncreasingSeq(paths) )
	{
		res.push_back(paths);
		// 注意这里不要加return，因为要取树上的所有节点
	}
	//需要去重
	if (startIndex >= nums.size())
	{
		return;
	}
	int used[201] = { 0 }; // 这里使用数组来进行去重操作，题目说数值范围[-100, 100]
	for (int i = startIndex; i < nums.size(); i++)
	{
		if (used[nums[i] + 100] == 1) continue;
		used[nums[i] + 100] = 1; // 记录这个元素在本层用过了，本层后面不能再用了	
		paths.push_back(nums[i]);
		findSubsetsBackTrack(res,paths,nums,i+1);
		paths.pop_back();
	}
}
//是不是递增序列
bool isIncreasingSeq(vector<int>& path)
{
	int ori = path[0];
	for (size_t i = 1; i < path.size(); i++)
	{
		if (ori <= path[i])
		{
			ori = path[i];
		}
		else
		{
			return false;
		}
	}
	return true;
}
//全排列II 中等 给定一个可包含重复数字的序列 nums ，按任意顺序 返回所有不重复的全排列
vector<vector<int>> permuteUnique(vector<int>& nums)
{
	vector<vector<int>> res;
	vector<bool> used(nums.size(), false);
	//这里不能使用set去重，因为set认为112和121是一样的，但它两实际上不是一个排列
	//set<vector<int>> set_res;
	vector<int> path;
	sort(nums.begin(), nums.end());
	permuteIIBackTrack(res, path, nums, used);

	return res;

}
//全排列II的回溯函数
void permuteIIBackTrack(vector<vector<int>>& set_res, vector<int>& path, vector<int>& nums, vector<bool> & used)
{

	if (path.size() == nums.size())
	{
		set_res.push_back(path);
		return;
	}

	for (int i = 0; i < nums.size(); i++)
	{
		//去重
		if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false) continue;
		//还得加个这个判断， 不然会重复使用一个元素
		if (used[i] == false)
		{
			path.push_back(nums[i]);
			used[i] = true;
			permuteIIBackTrack(set_res, path, nums, used);
			path.pop_back();
			used[i] = false;

		}


	}
}
