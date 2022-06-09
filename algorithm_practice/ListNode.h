#pragma once
#include "sort_algorithm.h"

typedef struct listNode
{
	int data;
	listNode * next;
}Node;

//listNode * createList()
//{
//	listNode * head;
//	//head = (struct listNode*)malloc(sizeof(struct listNode));
//	head = new listNode;
//	head->next = nullptr;
//	return head;
//}
////根据数据创建一个节点
//listNode * createNode(int data)
//{
//	listNode * node = new listNode;
//	node->data = data;
//	node->next = nullptr;
//	return node;
//		 
//}
////插入一个节点。头插法
//void insert_node_by_head(listNode * head,int data)
//{
//	//给输入的数据创建一个节点
//	listNode * newnode = createNode(data);
//	//新节点得先连到头结点的下一个，不能先让头结点连新节点，不然顺序错了
//	newnode->next = head->next;
//	head->next = newnode;
//
//
//}
//打印节点信息
void printList2(Node * head);

////删除指定数据的节点
//void deleteNode(listNode * head,int data)
//{
//	//当前节点
//	listNode * frontNode = head;
//	//当前节点的下一个节点
//	listNode * postNode = head->next;
//
//	while (postNode->data != data)
//	{
//		frontNode = postNode;
//		postNode = postNode->next;
//
//		if (postNode == nullptr)
//		{
//			cout << "没有指定的数据" << endl;
//			break;
//		}
//	}
//	frontNode->next = postNode->next;
//	delete postNode;
//}


class LinkList
{
public:
	LinkList();
	LinkList(int data);
	int getSize();
	//增
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

	//清空
	void clearList();
	//反转
	void reverse();
	//析构函数
	~LinkList();

private:
	Node * head;
	
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


