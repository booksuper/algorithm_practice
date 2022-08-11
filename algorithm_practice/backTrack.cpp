#include "backTrack.h"

//����k����ȵ��Ӽ���
bool canPartitionKSubsets(vector<int>& nums, int k)
{
	//�ų�һЩ�������
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
//k������Ӽ��͵Ļ��ݺ���
bool backtrack_KSubsets(vector<int>& nums, int index, vector<int> bucket, int target)
{
	//base case
	//�����ֵ��ӽǣ�����base caseӦ����nums�����ֱ�������һ��
	if (index == nums.size())
	{
		//�ж�ÿ��Ͱ�е������Ƿ�һ��
		for (int i = 0; i < bucket.size(); i++)
		{
			if(bucket[i] != target)
			{
				return false;
			}

		}
		return true;
	}
	//����ÿ��Ͱ
	for (int i = 0; i < bucket.size(); i++)
	{
		//��֦
	   //��Ͱ�е������¼�һ����֮����ʹ���target��ֱ����һ��ѭ��
		if (bucket[i] + nums[index] > target)
		{
			continue;
		}
		//��ѡ�񣺰ѵ�ǰnums����Ͱ��
		bucket[i] += nums[index];
		//����
		if (backtrack_KSubsets(nums, index + 1, bucket, target))
		{
			return true;
		}
		//����ѡ��
		bucket[i] -= nums[index];
	}
	// nums[index] װ���ĸ�Ͱ������
	return false;


}
//����һ�������ظ����ֵ����� nums �������� ���п��ܵ�ȫ���� ������� ������˳�� ���ش�
vector<vector<int>> permute(vector<int>& nums)
{
	//��¼����·��
	vector<int> track;
	//���
	vector<vector<int>> res;
	// ��·�����е�Ԫ�ػᱻ���Ϊ true�������ظ�ʹ��,һ��ʼҪ��ʼ��Ϊ0��ȫΪfalse
	bool* used = new bool[nums.size()]{};
    //����������ô��Σ���Ȼ����
	backtrack_permute(nums, track, used,res);
	return res;
}
//���ݺ���
// ·������¼�� track ��
// ѡ���б�nums �в������� track ����ЩԪ�أ�used[i] Ϊ false��
// ����������nums �е�Ԫ��ȫ���� track �г���
void backtrack_permute(vector<int> nums, vector<int> track, bool * used, vector<vector<int>>& out_res)
{
	// ������������
	if (track.size() == nums.size()) {
		out_res.push_back(track);
		return ;
	}
	for (int i = 0; i < nums.size(); i++) {
		// �ų����Ϸ���ѡ��
		if (used[i]) {
			// nums[i] �Ѿ��� track �У�����
			continue;
		}
		// ��ѡ��
		track.push_back(nums[i]);
		used[i] = true;
		// ������һ�������
		backtrack_permute(nums, track, used, out_res);
		// ȡ��ѡ��
		track.pop_back();
		used[i] = false;
	}

}
//���п����Ӽ�
vector<vector<int>> subsets(vector<int>& nums)
{
	vector<vector<int>> res;
	vector<int> track;
	backtrack_subsets(nums, 0, res, track);

	return res;
}

void backtrack_subsets(vector<int>& nums, int start, vector<vector<int>>& res, vector<int> track)
{
	// ǰ��λ�ã�ÿ���ڵ��ֵ����һ���Ӽ�
	res.push_back(track);
	for (int i = start; i < nums.size(); i++)
	{
		track.push_back(nums[i]);
		// ͨ�� start ����������֦�ı�������������ظ����Ӽ�
		backtrack_subsets(nums, i + 1, res, track);
		track.pop_back();
	}
}
//77 ��� �е�
vector<vector<int>> combine(int n, int k)
{
	vector<vector<int>> res;
	vector<int> path;
	backTrackCombine(res, path, n, k, 1);
	return res;
}
//��ϵĻ��ݺ���
void backTrackCombine(vector<vector<int>>& res, vector<int>& path, int n, int k, int startIndex)
{
	//��ֹ����
	if (path.size() == k)
	{
		res.push_back(path);
		return;
	}

	for (int i = startIndex; i <= n; i++)//�������
	{
		path.push_back(i);//�ռ�·���ϵ�ֵ
		backTrackCombine(res, path, n, k, i + 1);//�ݹ飬Ҳ�����������
		path.pop_back();//���ݲ���
	}
}
