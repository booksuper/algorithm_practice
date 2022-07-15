#pragma once
#include <iostream>
#include<queue>
using namespace std;

template<class T>
class MyStack
{
private:
	T* p;
	int _size;
	int _capacity;
public:
	//��ʼ���б��Ļ����żǵüӣ���Ȼ����
	MyStack() :p(nullptr), _size(0), _capacity(0){}
    ~MyStack() {delete[] p; _size = 0; _capacity = 0;}
	void checkCapacity();
	void push(T data);
	T top();
	T pop();
	bool empty();
	int size() { return _size; }
	int capaticy() { return _capacity; }

};

//������Ŀռ���м�⣬����Ǳ�֤�ܶ�̬������ڴ�Ĺؼ�
template<class T>
inline void MyStack<T>::checkCapacity()
{
	if (_size == _capacity)
	{
		//�������ϱ��
		_capacity = _capacity == 0 ? 4 : _capacity * 2;
		T* newp = new T[_capacity];//��̬�����ڴ�
		//��p�����ݸ��Ƶ�������ĸ�����ڴ���
		for (int i = 0; i < _size; i++)
		{
			newp[i] = p[i];
		}
		delete[] p;//�ͷžɵ�
		p = newp;//��pָ��������ĸ�����ڴ�
	}
}

//��ջ
template<class T>
inline void MyStack<T>::push(T data)
{
	//ÿ��pushǰ��Ҫ���һ����������������������ڴ�
	checkCapacity();
	p[_size++] = data;//�Ƚ����Ϊsize���ڴ��д���data��Ȼ��size�Լ�1��sizeʼ��ָ��ջ��
}

//����ջ��Ԫ��
template<class T>
inline T MyStack<T>::top()
{
	
	return p[_size-1];
}
//��ջ
template<class T>
inline T MyStack<T>::pop()
{
	_size -= 1;
	return p[_size];
}

template<class T>
inline bool MyStack<T>::empty()
{
	if (_size == 0)
	{
		return true;
	}
	return false;
}
//225:�ö���ʵ��ջ
class MyStack2 {
public:

	void push(int x) {
		int s = q.size();
		q.push(x);
		for (int i = 0; i < s; i++)
		{
			//��ͷԪ����ѹ�������������ͱ����β
			q.push(q.front());
			//�Ѹո�ѹ������ͷԪ�ص���
			q.pop();
		}
		//�ҵķ���
		//q.push(x);


	}

	int pop() {

		int r = q.front();
		q.pop();
		return r;
#if 0 
		//�ҵķ���
		int t = 0;
		if (q.size() == 1)
		{
			t = q.front();
			q.pop();
			return t;
		}

		//���������С�����ó���,ʹ��ָ��Ϳ��Զ�̬�仯��С
		int size = q.size() - 1;
		int * tem = new int[size];
		for (int i = 0; i < size ; i++)
		{
			t = q.front();
			q.pop();
			tem[i] = t;
			//temp.push(t);

		}
		t = q.front();
		q.pop();
		for (int i = 0; i < size ; i++)
		{
			q.push(tem[i]);

		}
		delete[] tem;
		return t;
#endif



	}

	int top() {
		return q.front();

#if 0
		//�ҵķ���
		if (q.size() == 1)
		{
			return q.front();
		}
		int t = 0;
		int size = q.size() - 1;
		int * tem = new int[size];
		//ѭ����q.size��䡣����Ҫ�������ó���
		for (int i = 0; i < size; i++)
		{
			t = q.front();
			q.pop();
			tem[i] = t;
			//temp.push(t);

		}
		t = q.front();
		q.pop();
		for (int i = 0; i < size ; i++)
		{
			q.push(tem[i]);

		}
		q.push(t);
		delete[] tem;
		return t;
#endif

	}

	bool empty() {
		return q.empty();

	}
private:
	queue<int> q;
};
