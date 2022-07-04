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

#define DP 0;
#define BTREE 0;
#define SORT 0;
#define LISTNODE 0;
#define CALLBACK 0;
#define BACKTRACK 1;

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
	LinkList l1(0);
	l1.insertByTail(3);
	l1.insertByTail(8);
	l1.insertByTail(1);
	l1.insertByTail(2);
	l1.insertByTail(6);
	Node * res = l1.my_reverse();
	int d = 0;

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
	//vector<int> nums{ 1,2};
	vector<int> nums{ 4,3,2,3,5,2,1 };
	//vector<vector<int>> res = permute(nums);
	bool res = canPartitionKSubsets(nums, 4);
	int a = 0;
	
#endif

}

