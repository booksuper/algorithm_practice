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

#define DP 0;
#define BTREE 0;
#define SORT 0;
#define LISTNODE 0;
#define CALLBACK 0;
#define BACKTRACK 0;
#define ARRAY 1;
#define STACK 0;
#define STR 0;
#define OTHERTHING 1;


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
	l1.insertByTail(1);
	l1.insertByTail(2);
	l1.insertByTail(3);
	l1.insertByTail(3);
	
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
	
	vector<int> in{ 2,2 };
	vector<int> res = searchRange(in, 3);
	
	
#endif

#if DP
	int f = fib(10);
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
	char s[] = "Golden Global   View,disk * desk";
	const char *d = " ,*";
	char *p;
	char* ptr = nullptr;
	p = strtok_s(s, d, &ptr);
	while (p)
	{
		printf("%s\n", p);
		p = strtok_s(NULL, d, &ptr);
	}
	int h = 0;
	//string结尾是否以0结尾，这个得看编译器，在我这个编译器中（msvc2017)是以0结尾的
	//而且c_str和data函数结果一样，没有区别。本来data输出的应该是不以0结尾的字符串，c_str输出的是
	//以0结尾的,但这我这个编译器中，没有区别
	//char []数组可以修改变量值，但是char * 不可以

	//const char * s = "sddd";
	//char s2[] = "sdhu";

	//s2[1] = '2';
	//string s3 = "defr";
	//const char * t = s3.c_str();
	//const char * t1 = s3.data();
	//cout << t << endl;
	//cout << t1 << endl;

	//int l = strlen(t);
	//int l2 = strlen(t1);
	//int l3 = s3.length();
	//char r;
	//char r2;
	//char r3;
	//for (int i = 0; i < 5; i++)
	//{

	//	r = t[i];
	//	r2 = t1[i];
	//	r3 = s3[i];
	//	//printf("%s", s[i]);
	//}
	/*cout << s<<endl;
	cout << l;*/

#endif

#if OTHERTHING
	SimplePointTest();

#endif
}

