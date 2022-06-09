#pragma once
#include <iostream>

using namespace std;

template<class T>
class Queue_Node
{
public:
	T data;
	Queue_Node<T> * next;
	Queue_Node(T val) :data(val), next(nullptr) { ; }
};

template <class T>
class MyQueue
{
private:
	int num;
	Queue_Node<T> * head;
	//Queue_Node<T> * tail;
public:
	MyQueue()
	{
		head = new Queue_Node<T>(0);
		//tail = head;
		num = 0;
	}
	
	void push(T data);

	T pop();

	T front();

	T back();

	bool empty();

	int size();

};

template<class T>
inline void MyQueue<T>::push(T data)
{
	//申请新内存存放数据
	Queue_Node<T>* newnode = new Queue_Node<T>(data);
	//头插法插入新的元素
	newnode->next = head->next;
	head->next = newnode;
	num += 1;
	//tail = newnode;

}

template<class T>
inline T MyQueue<T>::pop()
{
	Queue_Node<T>* temp = head;
	while (temp->next->next)
	{
		temp = temp->next;
	}
	T res = temp->next->data;
	
	temp->next = temp->next->next;
	
	num -= 1;
	return res;
}
//返回头部元素
template<class T>
inline T MyQueue<T>::front()
{
	return head->next->data;
}
//返回尾部元素
template<class T>
inline T MyQueue<T>::back()
{
	Queue_Node<T>* temp = head;
	while (temp->next->next)
	{
		temp = temp->next;
	}
	return temp->next->data;
}

template<class T>
inline bool MyQueue<T>::empty()
{
	if (num == 0)
	{
		return true;
	}
	return false;
}

template<class T>
inline int MyQueue<T>::size()
{
	return num;
}
