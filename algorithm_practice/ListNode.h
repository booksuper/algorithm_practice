#pragma once
#include "sort_algorithm.hpp"

typedef struct listNode
{
	int data;
	listNode * next;
}Node;

class LinkList
{
public:
	LinkList();
	LinkList(int data);
	int getSize();
	//头插法
	void insertByHead(int data);
	//尾插法
	void insertByTail(int data);
	//删
	void deleteList(int data);
	//改
	void changeList(int pos, int data);
	//查
	void getData(int pos,int & data);
	//打印
	void printList();
	//递归前序遍历
	void recursion_print_pre();

	//清空
	void clearList();
	//迭代形式反转
	void reverse();
	//自己写的反转，迭代形式
	Node * my_reverse();
	//递归形式反转单链表
	Node * reverseBaserecursion(Node * node);
	//给你单链表的头指针 head 和两个整数 left 和 right ，其中 left <= right 。
	//请你反转从位置 left 到位置 right 的链表节点，返回 反转后的链表
	Node* reverseBetween(int left, int right);
	/*给你一个单链表的头节点 head ，请你判断该链表是否为回文链表。如果是，返回 true ；否则，返回 false*/
	bool isPalindrome();
	//析构函数
	~LinkList();

private:
	Node * head;
	Node * tempPointer;
	
};



