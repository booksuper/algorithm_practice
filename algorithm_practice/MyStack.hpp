#pragma once
#include <iostream>

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
