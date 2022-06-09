
#include "dataStructrue_algorithm.h"
#include "ListUtil.h"
#include "MyStack.hpp"
#include "MyQueue.hpp"


int main()
{
	/*vector<int> arr{2,5,1,10,8,9,5,4,11,3};
	vector<int> reslut;
	vector<vector<int>> opera_num{ {1,3,2},{2,4,3},{0,2,-2} };
	vector<int> in_arr{ 0,0,0,0,0 };
	vector<vector<int>> res_arr;
	Solution s(in_arr);
	res_arr = s.getModifiedArray(in_arr, opera_num);*/
	//bubbleSort(arr);
	//selectSort(arr);
	/*reslut = quickSort(arr);
	for (int i = 0; i < reslut.size(); i++)
	{
		cout << reslut[i] << endl;
	}*/
	//listNode * head = createList();
	//insert_node_by_head(head, 1);
	//insert_node_by_head(head, 2);
	//insert_node_by_head(head, 3);
	//deleteNode(head, 2);
	//printList(head);
	/*LinkList l;
	l.insertByHead(2);
	l.insertByHead(3);
	l.insertByHead(4);
	LinkList l2;
	l2.insertByTail(1);
	l2.insertByTail(2);
	l2.insertByTail(3);
	l2.insertByTail(4);
	l2.reverse();
	int a = 0;
	l2.printList();*/
	
	//MyStack<int> mysta;
	MyQueue<int> mysta;
	mysta.push(2);
	mysta.push(3);
	mysta.push(5);
	mysta.push(4);
	int s = mysta.size();
	int f = mysta.front();
	int b = mysta.back();
	//int c = mysta.capaticy();
	int t = mysta.pop();
	t = mysta.pop();
	 f = mysta.front();
	 b = mysta.back();
	s = mysta.size();
	//c = mysta.capaticy();
	mysta.push(4);
	mysta.push(4);
	mysta.push(4);
	s = mysta.size();
	//c = mysta.capaticy();



	

	

	


}

