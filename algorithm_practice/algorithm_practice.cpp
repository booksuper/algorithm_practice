
#include "dataStructrue_algorithm.h"
#include "ListUtil.h"
#include "MyStack.hpp"
#include "MyQueue.hpp"
#include "Btree.hpp"


int main()
{
	
	//MyStack<int> mysta;
	//MyQueue<int> mysta;
	//mysta.push(2);
	//mysta.push(3);
	//mysta.push(5);
	//mysta.push(4);
	//int s = mysta.size();
	//int f = mysta.front();
	//int b = mysta.back();
	////int c = mysta.capaticy();
	//int t = mysta.pop();
	//t = mysta.pop();
	// f = mysta.front();
	// b = mysta.back();
	//s = mysta.size();
	////c = mysta.capaticy();
	//mysta.push(4);
	//mysta.push(4);
	//mysta.push(4);
	//s = mysta.size();
	
	/*vector<int> arr{ 2,5,1,10,8};
	recursion_array_pre(arr, 0);*/

	/*LinkList l;
	l.insertByHead(2);
	l.insertByHead(3);
	l.insertByHead(4);
	l.printList();
	cout << "后续遍历" << endl;
	l.recursion_print_pre();*/

	Btree<int> tree;
	Btree<int> tree1;
	int flag;
	int arr[7]{6,4,8,1,5,7,9};
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
	int dia = tree.maxDiameter(tree.root);
	BtreeNode<int> * flat = tree.flatten(tree.root);
	int i = 1;




}

