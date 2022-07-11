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
	
	//析构函数
	~LinkList();

private:
	Node * head;
	Node * tempPointer;
	
};


//struct Node
//{
//	int date;
//	struct Node* next;
//};
//struct Node*creatlist()
//{
//	struct Node* headNode = (struct Node*)malloc(sizeof(struct Node));
//	headNode->next = NULL;
//	return headNode;
//};
//struct Node*creatNode(int date)
//{
//	struct Node*newNode = (struct Node*)malloc(sizeof(struct Node));
//	newNode->date = date;
//	newNode->next = NULL;
//	return newNode;
//};
//void printList(struct Node*headNode)
//{
//	struct Node*Pmove = headNode->next;
//	while (Pmove)
//	{
//		printf("%d", Pmove->date);
//		Pmove = Pmove->next;
//	}
//	printf("\n");
//
//}
//void insert_Node_By_HeadNode(struct Node*headNode, int date)
//{
//	struct Node*newNode = creatNode(date);
//	newNode->next = headNode->next;
//	headNode->next = newNode;
//}

//void deleteNodebyAppoint(struct Node* HeadNode, int data)
//{
//	struct Node* postNodeFront = HeadNode;
//	struct Node* postNode = HeadNode->next;
//	while (postNode->data != data)
//	{
//		postNodeFront = postNode;
//		postNode = postNodeFront->next;
//		if (postNode == NULL)
//		{
//			printf("not find data\n");
//			return;
//		}
//	}
//	postNodeFront->next = postNode->next;
//	free(postNode);
//}
//int main()
//{
//	struct Node*list = creatlist();
//	insert_Node_By_HeadNode(list, 1);
//	insert_Node_By_HeadNode(list, 2);
//	insert_Node_By_HeadNode(list, 3);
//	printList(list);
//}


