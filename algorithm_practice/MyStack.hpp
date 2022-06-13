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
