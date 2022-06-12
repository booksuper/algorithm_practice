#pragma once
#include "ListNode.h"
//��������������ϲ���һ���µ���������
Node * mergeList(Node * list1, Node * list2);

//�ݹ��������

template<class T>
void recursion_array_post(vector<T> data, int i);

template<class T>
void recursion_array_pre(vector<T> data, int i);
//�������ݹ����
template<class T>
inline void recursion_array_post(vector<T> data, int i)
{
	//��ֹ����
	if (i == data.size())
	{
		return;
	}
	i += 1;
	recursion_array_post(data, i );
	cout << data[i-1] << endl;
}

//�������ݹ����
template<class T>
inline void recursion_array_pre(vector<T> data, int i)
{
	//��ֹ����
	if (i == data.size())
	{
		return;
	}
	
	cout << data[i] << endl;
	recursion_array_pre(data, i+1);
	
}
