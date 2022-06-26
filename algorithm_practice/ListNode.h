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
	//ͷ�巨
	void insertByHead(int data);
	//β�巨
	void insertByTail(int data);
	//ɾ
	void deleteList(int data);
	//��
	void changeList(int pos, int data);
	//��
	void getData(int pos,int & data);
	//��ӡ
	void printList();
	//�ݹ�ǰ�����
	void recursion_print_pre();

	//���
	void clearList();
	//������ʽ��ת
	void reverse();
	//�Լ�д�ķ�ת��������ʽ
	Node * my_reverse();
	//�ݹ���ʽ��ת������
	Node * reverseBaserecursion(Node * node);
	//��������
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


