#pragma once
#include "ListNode.h"
//将两个升序链表合并到一个新的升序链表
Node * mergeList(Node * list1, Node * list2);

//递归遍历数组

template<class T>
void recursion_array_post(vector<T> data, int i);

template<class T>
void recursion_array_pre(vector<T> data, int i);
//数组后序递归遍历
template<class T>
inline void recursion_array_post(vector<T> data, int i)
{
	//终止条件
	if (i == data.size())
	{
		return;
	}
	i += 1;
	recursion_array_post(data, i );
	cout << data[i-1] << endl;
}

//数组后序递归遍历
template<class T>
inline void recursion_array_pre(vector<T> data, int i)
{
	//终止条件
	if (i == data.size())
	{
		return;
	}
	
	cout << data[i] << endl;
	recursion_array_pre(data, i+1);
	
}
