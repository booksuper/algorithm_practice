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
//1 简单 两数之和
vector<int> twoSumSimple(vector<int>& nums, int target)
{
	//这个方法更通用，还能求解167的两数之和题目，时间复杂度也通过
	//使用map来构建一个已遍历的元素,因为不要求有序，使用underedmap
	//效率最高
	unordered_map<int, int> map;
	for (int i = 0; i < nums.size(); i++)
	{
		auto it = map.find(target - nums[i]);
		//如果找到了就返回
		if (it != map.end())
		{
			return {it->second,i};//这里使用了默认构造，将其转为vector
		}
		//没找到就把遍历过的放进map
		map.insert(pair<int, int>(nums[i], i));
		
	}
	//没有匹配的返回空
	return {};

}
//454 中等 四数相加II
int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4)
{
	/*1 首先定义 一个unordered_map，key放a和b两数之和，value 放a和b两数之和出现的次数。
      2 遍历大A和大B数组，统计两个数组元素之和，和出现的次数，放到map中。
      3 定义int变量count，用来统计 a+b+c+d = 0 出现的次数。
      4 在遍历大C和大D数组，找到如果 0-(c+d) 在map中出现过的话，就用count把map中key对应的value也就是出现次数统计出来。
      5 最后返回统计值 count 就可以了
	  只需要计算有多少个，并不需要求出具体的组合，给这题下降了一个level*/
	unordered_map<int, int> temp_map;//key是ab数组两数之和，value是和出现的次数
	int count = 0;//结果
	//将ab两数组的所有和求出来作为key
	//value就是次数
	//这里复杂度是n2
	for (auto a : nums1)
	{
		for (auto b : nums2)
		{
			temp_map[a + b]++;
		}
	}
	for (auto c : nums3)
	{
		for (auto d : nums4)
		{
			//这里的思路和两数之和一致
			if (temp_map.find(0 - (c + d)) != temp_map.end())
			{
				//找到了count就加上对应目标的次数
				count += temp_map[0 - (c + d)];

			}
		}
	}
	
	return count;
}
//15 中等 三数之和
vector<vector<int>> threeSum(vector<int>& nums)
{
	/*使用哈希表比较复杂，而且不好处理元素重复的问题
	使用双指针技巧比较好，可以将原本暴力解法的n3复杂度降低为n2
	首先对数组升序排序，这一步主要是为了使用双指针技巧
	然后可以外面设置一个循环，再将left设置为i+1，right设置为数组末尾
	*/
	
	/*sort函数是algorithm库下的一个函数，sort函数是不稳定的，
	即大小相同的元素在排序后相对顺序可能发生改变，如果某些场景需要
	保持相同元素间的相对顺序，可使用stable_sort函数
	sort函数指定的区间是左闭右开，默认升序，如果想要降序，可以在第三个参数中
	添加greater<int>().
	该函数并非只是普通的快排，除了对普通的快速排序进行优化，它还结合了插入排序和堆排序。
	根据不同的数量级别以及不同情况，能自动选用合适的排序方法
	所以无论元素初始时为何种状态，sort()的平均排序复杂度为均为O(N*log2(N)) 
	在刷算法题时，可以直接使用sort()来对数据进行排序
	由于在排序过程中涉及到元素交换等操作，所以sort函数仅支持可随机访问的
	容器，如数组， string、vector、deque等
	*/
	vector<vector<int>> out_res;
	
	
	if (nums.size() == 0) return out_res;
	sort(nums.begin(), nums.end());
	int left = 0;
	int right = 0;
	//外层控制轮数
	for (int i = 0; i < nums.size(); i++)
	{
		//排序之后第一个元素大于0肯定不符合情况
		if (nums[0] >= 0) return out_res;

		// 错误去重a方法，将会漏掉-1,-1,2 这种情况
		/*
		if (nums[i] == nums[i + 1]) {
			continue;
		}
		*/
		// 正确去重a方法
		if (i > 0 && nums[i] == nums[i - 1]) {
			continue;
		}
		//里面双指针技巧
		left = i + 1;
		right = nums.size() - 1;
		while (left < right)
		{
			if (nums[i] + nums[left] + nums[right] == 0)
			{
				
				out_res.push_back({ nums[i],nums[left],nums[right] });
				//这一次做完应该开始下一次
				//但有重复元素
				// 去重逻辑应该放在找到一个三元组之后，对b 和 c去重
				while (right > left && nums[right] == nums[right - 1]) right--;
				while (right > left && nums[left] == nums[left + 1]) left++;

				// 找到答案时，双指针同时收缩
				right--;
				left++;

			}
			//如果大于，就把right--，因为数组排序过了的
			else if(nums[i] + nums[left] + nums[right] > 0)
			{
				right--;
			}
			else
			{
				left++;
			}

		}

	}
	
	return out_res;
}
//18 中等 四数之和
vector<vector<int>> fourSum(vector<int>& nums, int target)
{
	vector<vector<int>> out_res;
	if (nums.size() < 4) return out_res;
	sort(nums.begin(), nums.end());
	int left = 0;
	int right = 0;
	for (size_t i = 0; i < nums.size(); i++)
	{
		//一级剪枝
		//不能第一个数大于target就直接返回，因为目标数可能小于0，比如-4>-10，但这样是
		//可以凑起来的
		if (nums[i] > target && nums[i] > 0 && target > 0) return out_res;

		//对第一个数去重,i>0是因为第二个条件中有i-1,防止越界
		//不能用nums[i] == nums[i+1]判断，这样会漏掉元组
		if ( i > 0 && nums[i] == nums[i-1])
		{
			continue;
		}
		//第二层循环
		for (size_t j = i+1; j < nums.size(); j++)
		{
			//二级剪枝
			if (nums[i] + nums[j] > target && nums[i] + nums[j] >= 0 && target >= 0) break;
			//对第二个数去重
			if (j > i + 1 && nums[j] == nums[j - 1])
			{
				continue;

			}
			//双指针
			left = j + 1;
			right = nums.size() - 1;
			while (left < right)
			{
				//为了防止整数溢出,将四数相加拆开,并且强转为long
				if ((long)nums[i] + nums[j] - target == (long)-(nums[left] + nums[right]))
				{
					out_res.push_back({ nums[i] ,nums[j] ,nums[left] ,nums[right] });
					//对第三个第四个数去重
					while (left < right && nums[left] == nums[left + 1])
					{
						left++;
					}
					while (left < right && nums[right] == nums[right - 1])
					{
						right--;
					}
					//双指针收缩
					left++;
					right--;
				}
				else if ((long)nums[i] + nums[j] - target < (long)-(nums[left] + nums[right]))
				{
					left++;
				}
				else
				{
					right--;
				}
			}
		}
	}

	return out_res;
}
//数组中出现的次数超过数组长度的一半
int majorityElement(vector<int>& nums)
{
	//基于哈希表实现的map，增删改查效率都是O(1)
	unordered_map<int, int> temp_map;
	int size = nums.size() / 2;
	for (auto var : nums)
	{
		temp_map[var]++;
	}
	for (auto it : temp_map)
	{
		if (it.second > size)
		{
			return it.first;
		}
	}
	//没有找到就返回-1
	return -1;
}
//数组中数字出现的次数
vector<int> singleNumbers(vector<int>& nums)
{
	unordered_map<int, int> temp_map;
	vector<int> res;
	for (auto var : nums)
	{
		temp_map[var]++;
	}
	for (auto it : temp_map)
	{
		if (it.second == 1)
		{
			res.push_back(it.first);

		}
	}
	sort(res.begin(), res.end());
	return res;
}
//41 缺失的第一个正整数 困难
int firstMissingPositive(vector<int>& nums)
{
	return 0;
}
//704:二分搜索
int binarySearch(vector<int>& nums, int target)
{
	int left = 0;
	int right = nums.size() - 1;//减一代表是有右边界的索引
	while (left <= right)//边界条件
	{
		//和(left+right)/2结果一样，只是防因为left或right太大而溢出
		int mid = left + (right - left) / 2;
		if (nums[mid] == target)
		{
			return mid;
		}
		else if (nums[mid] < target)
		{
			left = mid + 1;
		}
		else if (nums[mid] > target)
		{
			right = mid - 1;
		}
	}
	return -1;
}
//34在排序数组中查找元素的第一个和最后一个位置
vector<int> searchRange(vector<int>& nums, int target)
{
	vector<int> res{ -1,-1 };
	if (nums.size() == 0) return res;
	int left, right, mid;
	left = 0;
	right = nums.size() - 1;

	while (left <= right)
	{
		mid = left + (right - left) / 2;
		if (target == nums[mid])
		{
			//不返回，锁定左侧边界
			right = mid - 1;

		}
		else if (target > nums[mid])
		{
			left = mid + 1;
		}
		else if (target < nums[mid])
		{
			right = mid - 1;
		}
	}
	//先判断左边界到最后一个元素是不是还不等于target，不是的话，left就会加一，这时候就会越界，直接返回
	if (left == nums.size()) return res;
	//然后再判断是不是左边界是不是和target相等，不这样的顺序的话，会出现数组越界
	if (nums[left] != target) return res;
	//从左边界开始找右边界
	res[0] = left;
	for (int i = left; i < nums.size(); i++)
	{
		if (nums[i] != target)
		{
			res[1] = i - 1;
			break;
		}
		else if (i == nums.size() - 1)//左边界就是数组中最后一个数的情况
		{
			res[1] = i;
			break;
		}
	}
	return res;
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
//48旋转图像
void rotate(vector<vector<int>>& matrix)
{
	int size = matrix.size();
	//先沿正对角线镜像对称二维矩阵，其实就是装置
	for (int i = 0; i < size; i++)
	{
		for (int j = i; j < matrix[i].size(); j++)
		{
			int temp = matrix[i][j];
			matrix[i][j] = matrix[j][i];
			matrix[j][i] = temp;
		}
	}
	//反转矩阵的每一行
	for (vector<int>& var : matrix)
	{
		reverse_array(var);
	}

}
//反转一维数组
void reverse_array(vector<int>& arr)
{
	int i = 0;
	int j = 0;
	for ( i = arr.size() - 1; i > j; i--)
	{
		int temp = arr[j];
		arr[j] = arr[i];
		arr[i] = temp;
		j++;
	}
}
//54 中等 螺旋矩阵：给你一个 m 行 n 列的矩阵 matrix ，请按照 顺时针螺旋顺序 ，返回矩阵中的所有元素
vector<int> spiralOrder(vector<vector<int>>& matrix)
{
	//核心思路是按照右、下、左、上的顺序遍历数组，并使用四个变量圈定未遍历元素的边界：
	vector<int> res;
	int m = matrix.size();
	int n = matrix[0].size();
	int up_bound = 0; int low_bound = m - 1;
	int left_bound = 0; int right_bound = n - 1;
	while (res.size() < m * n)
	{
		//不先判断，会多输出数,注意！！！
		if (up_bound <= low_bound)
		{
			//先从第一行开始遍历，遍历完之后上界边界加1
			for (int i = left_bound; i <= right_bound; i++)
			{
				res.push_back(matrix[up_bound][i]);

			}
			up_bound++;

		}

		if (left_bound <= right_bound)
		{
			//再从最右侧开始从上往下遍历，遍历完之后右边界减一
			for (int i = up_bound; i <= low_bound; i++)
			{
				res.push_back(matrix[i][right_bound]);

			}
			right_bound--;
		}
		if (up_bound <= low_bound)
		{
			//再从最下侧开始从右往左遍历，遍历完之后下边界减一
			for (int i = right_bound; i >= left_bound; i--)
			{
				res.push_back(matrix[low_bound][i]);

			}
			low_bound--;

		}
		if (left_bound <= right_bound)
		{
			//最后从最下侧开始从下往上遍历，遍历完之后左边界加一
			for (int i = low_bound; i >= up_bound; i--)
			{
				res.push_back(matrix[i][left_bound]);

			}
			left_bound++;

		}

	}
	return res;
}
//59 螺旋矩阵2
vector<vector<int>> generateMatrix(int n)
{
	vector<vector<int>> res;
	//初始化
	res.resize(n);
	//记得每一个vector都要初始化，所以得用循环，只初始一个报错！！！
	for (int i = 0; i < n; i++)
	{
		res[i].resize(n);

	}
	
	int element = 1;
	int row = n;//行
	int cloumn = n;
	int up_bound = 0; int low_bound = row - 1;
	int left_bound = 0; int right_bound = cloumn - 1;
	while (element <= row * cloumn)
	{
		
		//不先判断，会多输出数,注意！！！
		if (up_bound <= low_bound)
		{
			//先从第一行开始遍历，遍历完之后上界边界加1
			for (int i = left_bound; i <= right_bound; i++)
			{
				 res[up_bound][i] = element;
				 element++;

			}
			up_bound++;

		}

		if (left_bound <= right_bound)
		{
			//再从最右侧开始从上往下遍历，遍历完之后右边界减一
			for (int i = up_bound; i <= low_bound; i++)
			{
				res[i][right_bound] = element;
				element++;

			}
			right_bound--;
		}
		if (up_bound <= low_bound)
		{
			//再从最下侧开始从右往左遍历，遍历完之后下边界减一
			for (int i = right_bound; i >= left_bound; i--)
			{
				res[low_bound][i] = element;
				element++;

			}
			low_bound--;

		}
		if (left_bound <= right_bound)
		{
			//最后从最下侧开始从下往上遍历，遍历完之后左边界加一
			for (int i = low_bound; i >= up_bound; i--)
			{
				res[i][left_bound] = element;
				element++;

			}
			left_bound++;

		}

	}
	return res;
}
//求两个数组交集
vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
{
	/*std::set和std::multiset底层实现都是红黑树，复杂度为O(logn),它的值
	不能修改，修改会导致红黑树错乱，set存储的元素去重了,multiset没有去重
	但他们都是有序的，默认从小到大
	std::unordered_set的底层实现是哈希表， 元素无序，但是去重了，
	使用unordered_set 读写效率是最高的，复杂度为O(1)
	并不需要对数据进行排序，而且还不要让数据重复
	注意！std::map 和std::multimap 的底层实现也是红黑树。仅仅是对key使用
	红黑树实现，value没有限制，所以kye是有序的，类比set
	std::unordered_map 底层实现为哈希表，类比unordered_set。
	时间复杂度和set类似
	所以在使用哈希表解题的时候，只要没要求元素排序，那就使用unordered_set
	或者unordered_map，因为他们的增删改查效率最高*/
	
	//本题可以使用set或者unordered_set,但为了效率最优，使用unordered_map
	unordered_set<int> res(nums1.begin(), nums1.end());//迭代器构造
	unordered_set<int> temp;
	for (auto var : nums2)
	{
		//find函数如果找到了指定元素就返回对应的迭代器，否则返回
		//最后一个元素的下一个位置，这个元素就是end（）
		if (res.find(var) != res.end())
		{
			temp.insert(var);
		}
	}
	return vector<int>(temp.begin(), temp.end());
}
//347 中等 前k个高频元素
vector<int> topKFrequent(vector<int>& nums, int k)
{
	//哈希表求解
	vector<int> res;
	unordered_map<int, int> myMap;
	//记录对应数字出现的次数
	for (auto var : nums)
	{
		myMap[var]++;
	}
	
	vector<int> v;
	for (auto it : myMap)
	{
		v.push_back(it.second);

	}
	//对map的值进行排序，找到前k个，这里是从大到小
	sort(v.begin(), v.end(), greater<int>());
	//记录找到的个数，大于k就退出
	int j = 0;
	for (unordered_map<int, int>::iterator it = myMap.begin(); it != myMap.end();)
	{
		if (j < k)
		{
			if (v[j] == it->second)
			{
				res.push_back(it->first);
				//res_temp.insert(it->first);
				j++;
				//找到一个删除一个，不然结果是一样的
				myMap.erase(it->first);
				//如果前面删除了，map正好为空了，那在使用迭代器会报错
				//防止容器没有元素了还循环，这会报错
				if (myMap.size() == 0)
				{
					break;
				}
				else
				{
					//重新循环，直接下一次，不要执行it++
					it = myMap.begin();
					continue;

				}


			}
			

		}
		//++操作不能放在循环体中，不然每次重新开始的时候，不是指向第一个元素，而是第二个
		it++;

	}
	return res;


}

//347 中等 前k个高频元素:使用优先级队列，也就是堆进行求解
vector<int> topKFrequentBaseHeap(vector<int>& nums, int k)
{
	vector<int> res;
	//构建小顶堆的仿函数
	class myCompare
	{
	public:
		bool operator()(const pair<int,int> &l,const pair<int,int> &r)
		{
			return l.second > r.second;
		}
		
	};
	//首先记录各个数出现的次数
	unordered_map<int, int> myMap;
	for (auto var : nums)
	{
		myMap[var]++;
	}
	//然后使用优先级队列（小顶堆的方式，不加参数默认是大顶堆）保存k个
	//频率最高的数
	priority_queue<pair<int, int>, vector<pair<int, int>>, myCompare> priQueue;
	//如果队列中的数超过k个，就弹出来最小的一个，保证里面的数的频率始终是前k个
	for (auto it : myMap)
	{
		priQueue.push(it);
		if (priQueue.size() > k)
		{
			//弹出的是队头，因为是小顶推，也就是从大到小构造，弹出的就是频率最小的数
			priQueue.pop();
		}
	}
	//找到了前k个数，然后还需要逆序打印
	res.resize(k);
	for (int i = k-1; i >= 0;)
	{
		res[i] = priQueue.top().first;
		priQueue.pop();
		i--;

	}
	return res;
}

//239 困难 滑动窗口最大值
vector<int> maxSlidingWindow(vector<int>& nums, int k)
{
	//暴力解法，时间复杂度是O(n x k)
	vector<int> res;
	int epoch = nums.size() - k + 1;
	//滑动多少次
	for (size_t i = 0; i < epoch; i++)
	{
		//vector<int> temp;
		int maxNum = -99999;
		for (size_t j = i; j < i + k; j++)
		{
			if (nums[j] > maxNum)
			{
				maxNum = nums[j];
			}
		
		}
		res.push_back(maxNum);
	}
	return res;
}

