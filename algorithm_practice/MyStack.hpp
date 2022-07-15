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
	//初始化列表后的花括号记得加，不然报错
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

//对数组的空间进行检测，这个是保证能动态申请的内存的关键
template<class T>
inline void MyStack<T>::checkCapacity()
{
	if (_size == _capacity)
	{
		//容量不断变大
		_capacity = _capacity == 0 ? 4 : _capacity * 2;
		T* newp = new T[_capacity];//动态申请内存
		//将p中内容复制到新申请的更大的内存中
		for (int i = 0; i < _size; i++)
		{
			newp[i] = p[i];
		}
		delete[] p;//释放旧的
		p = newp;//将p指向新申请的更大的内存
	}
}

//入栈
template<class T>
inline void MyStack<T>::push(T data)
{
	//每次push前需要检查一下容量，不够就申请更多内存
	checkCapacity();
	p[_size++] = data;//先将序号为size的内存中存入data，然后size自加1，size始终指向栈顶
}

//返回栈顶元素
template<class T>
inline T MyStack<T>::top()
{
	
	return p[_size-1];
}
//出栈
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
//225:用队列实现栈
class MyStack2 {
public:

	void push(int x) {
		int s = q.size();
		q.push(x);
		for (int i = 0; i < s; i++)
		{
			//把头元素再压进来，这样它就变成了尾
			q.push(q.front());
			//把刚刚压进来的头元素弹出
			q.pop();
		}
		//我的方法
		//q.push(x);


	}

	int pop() {

		int r = q.front();
		q.pop();
		return r;
#if 0 
		//我的方法
		int t = 0;
		if (q.size() == 1)
		{
			t = q.front();
			q.pop();
			return t;
		}

		//定义数组大小必须用常量,使用指针就可以动态变化大小
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
		//我的方法
		if (q.size() == 1)
		{
			return q.front();
		}
		int t = 0;
		int size = q.size() - 1;
		int * tem = new int[size];
		//循环中q.size会变。所以要把其先拿出来
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
