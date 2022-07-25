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
	Node * head;
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
	//递归形式反转单链表，主函数
	Node * reverseBaserecursionMain();
	//递归形式反转单链表,辅助函数
	Node * reverseBaserecursion(Node * node, Node * node2);
	//给你单链表的头指针 head 和两个整数 left 和 right ，其中 left <= right 。
	//请你反转从位置 left 到位置 right 的链表节点，返回 反转后的链表
	Node* reverseBetween(int left, int right);
	/*25 困难:给你链表的头节点 head ，每 k 个节点一组进行翻转，请你返回修改后的链表。
	k 是一个正整数，它的值小于或等于链表的长度。如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。
	你不能只是单纯的改变节点内部的值，而是需要实际进行节点交换
	*/
	Node* reverseKGroup(Node* head,int k);
	//k个反转数组的辅助函数
	Node* reverseBetweenK(Node* head,int left, int right);
	/*给你一个单链表的头节点 head ，请你判断该链表是否为回文链表。如果是，返回 true ；否则，返回 false*/
	bool isPalindrome();
	//给定一个已排序的链表的头 head ， 删除所有重复的元素，使每个元素只出现一次 。返回 已排序的链表
	Node* deleteDuplicates();
	//析构函数
	~LinkList();

private:
	
	Node * tempPointer;
	
};



