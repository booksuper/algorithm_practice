#include "dataStructrue_algorithm.h"
#include "ListUtil.h"
#include "MyStack.hpp"
#include "MyQueue.hpp"
#include "Btree.hpp"
#include <iostream>
#include "ListNode.h"
#include "dynamic_programming.h"
#include "callback_practice.h"
#include "backTrack.h"
#include "otherThings.h"
#include "str_algorithm.h"

#define DP 0;
#define BTREE 0;
#define SORT 0;
#define LISTNODE 0;
#define CALLBACK 0;
#define BACKTRACK 0;
#define ARRAY 1;
#define STACK 0;
#define STR 0;
#define OTHERTHING 0;





int main(int argc,char * argv[])
{
#if BTREE
	
	Btree<int> tree;
	Btree<int> tree1;
	int flag;
	int arr[7]{6,4,8,1,5,7,9};
	vector<int> treenums{6,4,8,1,5,7,9};
	BtreeNode<int> * newtree = tree.createTreeBaseLevel(treenums, 0);
	//创建树
	for(flag=0;flag<7;flag++)
	{
		BtreeNode<int> * p = new BtreeNode<int>;
		p->data = arr[flag];
		p->left = nullptr;
		p->right = nullptr;
		tree.createTree(p, tree.root);
	}//1062734
	//tree.pre_traverse(tree.root);//1062347
	//tree.in_traverse(tree.root);//0123467
	//tree.post_traverse(tree.root);//0432761
	//tree.level_traverse(tree.root);
	//int d = tree.maxdepthBaseLevel(tree.root);
	//int d1 = tree.maxdepth(tree.root);
	//BtreeNode<int> * inversetree = tree.inverseBtree(tree.root);
	//BtreeNode<int> * inversetree2 = tree.inverseBtreeBaseItera(tree.root);
	//int dia = tree.maxDiameter(tree.root);
	//BtreeNode<int> * flat = tree.flatten(tree.root);
	string res = tree.serialize(newtree);
	cout << res << endl;
	int i = 1;
#endif

#if SORT
	vector<int> nums{ 3,1,2,8,4,6,7 };
	vector<int> res = quickSort(nums);
	int num[5]{ 3,1,2,4,5 };
	int res_num[5];
	merge_sort(num, 0, 4, res_num);
	int d = 0;
#endif

#if LISTNODE
	LinkList l1(1);
	l1.insertByTail(2);
	l1.insertByTail(3);
	l1.insertByTail(4);
	l1.insertByTail(5);
	Node * res = l1.reverseKGroup(l1.head,2);
	
	//l1.insertByTail(1);
	//bool pa = l1.isPalindrome();
	//Node * res = l1.deleteDuplicates();
	//Node * res = l1.my_reverse();
	int d = 0;

#endif

#if STACK
	queue<int> qu;
	qu.push(1);
	qu.push(2);

	int t = qu.front();
	int u = qu.size();
	MyStack2 s2;
	s2.push(1);
	s2.push(2);
	s2.push(3);
	int g = s2.top();
	int r = 0;
#endif

#if ARRAY
	/*vector<int> nums{ 0,1,0,3,12 };
	moveZeroes(nums);
	int r = 0;*/
	/*const char * s = "abbac";
	string d = "sdada";
	bool res = isPalindrome(d.c_str());*/
	
	vector<int> in{ 1,3,-1,-3,5,3,6,7 };
	vector<int> in2{ 1 };
	vector<int> res_vec = maxSlidingWindow(in2, 1);
	//vector<int> res = searchRange(in, 3);
	int h = 0;
	
	
#endif

#if DP
	int f = fib(10);
	int r1 = rfact(4);
	int* m = new int[11]{};
	int f1 = modified_fib(m,10);
	int f2 = fib_itera(10);
	//凑零钱
	vector<int> coins{ 2 };
	int r = coinChange(coins, 3);

#endif

#if CALLBACK
	int call_res = 0;
	Add(add, 3, 4, call_res);
#endif

#if BACKTRACK
	//vector<int> nums1{ 1,2,3};
	//vector<int> nums2{ 4,3,2,3,5,2,1 };
	////vector<vector<int>> res = permute(nums);
	////bool res = canPartitionKSubsets(nums2, 4);
	//vector<vector<int>> r = subsets(nums1);
	//int a = 0;
	int res = rfact(3);
	cout << res;
	
#endif

#if STR
	//string结尾是否以0结尾，这个得看编译器，在我这个编译器中（msvc2017)是以0结尾的
	//而且c_str和data函数结果一样，没有区别。本来data输出的应该是不以0结尾的字符串，c_str输出的是
	//以0结尾的,但这我这个编译器中，没有区别
	//char []数组可以修改变量值，但是char * 不可以


	//set<string> res_str;
	/*unsigned char * s1 = new unsigned char[3];
	s1[0] = '1';
	s1[1] = '2';
	s1[2] = '\0';*/
	//unsigned char szSrc[] = { 0x32, 's', 'f', '2', 'h', 'g', 0x00 };
	//无符号可以直接强转为有符号，两者存储方式一样，只是读取方式不一样
	//char * sz = reinterpret_cast<char *>(szSrc);
	//int ilen = sizeof(szSrc) / sizeof(szSrc[0]);
	//直接强转会丢失后面的信息，因为在第二个位置就遇到了0
	//先确定整个buff大小，然后再用循环一个个加
	
	//const char * mystr = reinterpret_cast<const char *>(szSrc);
	//cout << sz;
	/*char s[] = "car Global View car desk View car View";
	const char *delimiter = " ";
	res_str = findRepeatStr(s, delimiter);
	cout << "===================\n";
	for (auto var : res_str)
	{
		cout << var << endl;
	}*/
	
	string res_str = removeDuplicateStr("abbaca");
	int a = 0;

	

#endif

#if OTHERTHING
	simplePointTest();
	vector<my2DPoint> input;
	my2DPoint pt(0,0);
	input.push_back(pt);
	pt.X = 2;
	input.push_back(pt);
	pt.Y = 2;
	input.push_back(pt);
	double res_area = caculatePolygonArea(input);
	int g = 0;


#endif




#if 0
		int n, m, temp;
		vector<int> in_nums;
		vector<vector<int>> range;
		cin >> n;
		for (int i = 0 ;i < n; i++)
		{
			cin >> temp;
			in_nums.push_back(temp);
		}
		cin >> m;
		int l, r;
		for (int i = 0 ;i < m; i++)
		{

			cin >> l >> r;
			range.push_back({ l,r });


		}
		
		for (int k = 0; k < m; k++)
		{
			int sum = 0;
			for (int j = range[k][0]; j <= range[k][1]; j++)
			{
				sum += in_nums[j - 1];

			}
			cout << sum << endl;

		}

#endif // 0

}

