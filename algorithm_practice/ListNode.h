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
////�������ݴ���һ���ڵ�
//listNode * createNode(int data)
//{
//	listNode * node = new listNode;
//	node->data = data;
//	node->next = nullptr;
//	return node;
//		 
//}
////����һ���ڵ㡣ͷ�巨
//void insert_node_by_head(listNode * head,int data)
//{
//	//����������ݴ���һ���ڵ�
//	listNode * newnode = createNode(data);
//	//�½ڵ��������ͷ������һ������������ͷ������½ڵ㣬��Ȼ˳�����
//	newnode->next = head->next;
//	head->next = newnode;
//
//
//}
//��ӡ�ڵ���Ϣ
void printList2(Node * head);

////ɾ��ָ�����ݵĽڵ�
//void deleteNode(listNode * head,int data)
//{
//	//��ǰ�ڵ�
//	listNode * frontNode = head;
//	//��ǰ�ڵ����һ���ڵ�
//	listNode * postNode = head->next;
//
//	while (postNode->data != data)
//	{
//		frontNode = postNode;
//		postNode = postNode->next;
//
//		if (postNode == nullptr)
//		{
//			cout << "û��ָ��������" << endl;
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
	//��
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

	//���
	void clearList();
	//��ת
	void reverse();
	//��������
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


