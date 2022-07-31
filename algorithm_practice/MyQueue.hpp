#pragma once
#include <iostream>
#include <stack>
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


/*232 用栈实现队列 简单：请你仅使用两个栈实现先入先出队列。队列应当支持一般队列支持的所有操作（push、pop、peek、empty）：
实现 MyQueue 类：
void push(int x) 将元素 x 推到队列的末尾
int pop() 从队列的开头移除并返回元素
int peek() 返回队列开头的元素
boolean empty() 如果队列为空，返回 true ；否则，返回 false
*/
class MyQueueBaseStack {
public:

	MyQueueBaseStack() {

	}

	void push(int x) {
		temp1.push(x);
	}

	int pop() {
		// 只有当temp2为空的时候，再从temp1里导入数据（导入temp1全部数据）
		if (temp2.empty())
		{
			//将temp1数据全部导入temp2
			while (!temp1.empty())
			{
				temp2.push(temp1.top());
				temp1.pop();
			}

		}
		int res = temp2.top();
		temp2.pop();
		return res;
	}

	int peek() {
		int res = this->pop();
		temp2.push(res);
		return res;

	}

	bool empty() {
		return temp1.empty() && temp2.empty();

	}
private:
	stack<int> temp1;
	stack<int> temp2;

};