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
	//�������ڴ�������
	Queue_Node<T>* newnode = new Queue_Node<T>(data);
	//ͷ�巨�����µ�Ԫ��
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
//����ͷ��Ԫ��
template<class T>
inline T MyQueue<T>::front()
{
	return head->next->data;
}
//����β��Ԫ��
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


/*232 ��ջʵ�ֶ��� �򵥣������ʹ������ջʵ�������ȳ����С�����Ӧ��֧��һ�����֧�ֵ����в�����push��pop��peek��empty����
ʵ�� MyQueue �ࣺ
void push(int x) ��Ԫ�� x �Ƶ����е�ĩβ
int pop() �Ӷ��еĿ�ͷ�Ƴ�������Ԫ��
int peek() ���ض��п�ͷ��Ԫ��
boolean empty() �������Ϊ�գ����� true �����򣬷��� false
*/
class MyQueueBaseStack {
public:

	MyQueueBaseStack() {

	}

	void push(int x) {
		temp1.push(x);
	}

	int pop() {
		// ֻ�е�temp2Ϊ�յ�ʱ���ٴ�temp1�ﵼ�����ݣ�����temp1ȫ�����ݣ�
		if (temp2.empty())
		{
			//��temp1����ȫ������temp2
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