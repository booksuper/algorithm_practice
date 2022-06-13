
#include "ListNode.h"



LinkList::LinkList()
{
	head = new Node;
	head->data = 0;
	head->next = nullptr;
	tempPointer = head;
}

LinkList::LinkList(int data)
{
	head = new Node;
	head->data = data;
	head->next = nullptr;
	tempPointer = head;
}

int LinkList::getSize()
{
	Node * node = head;
	int count = 0;
	while (node)
	{
		count++;
		//����д���ᵼ��headͷֱ��ָ���˿�ָ�룬�����ᵼ�º������
		//Ӧ���½�һ������ָ�룬����head
		node = node->next;
	}
	return count;
}

void LinkList::insertByHead(int data)
{
	Node * newNode = new Node;
	newNode->data = data;
	newNode->next = nullptr;

	newNode->next = head->next;
	head->next = newNode;
}

void LinkList::insertByTail(int data)
{
	Node * newNode = new Node;
	newNode->data = data;
	newNode->next = nullptr;
	//��ʱָ��
	Node * p = head;
	Node * q = p->next;
	//ͨ��ѭ������ʱָ��Ū������ĩβ
	while (q)
	{
		p = q;
		q = q->next;
	}
	p->next = newNode;


}

void LinkList::deleteList(int data)
{
	Node * frontNode = head;
	Node * posNode = head->next;
	//�����һ��������Ҫɾ��������������������������⿼��
	if (frontNode->data == data)
	{
		head = posNode;
		delete frontNode;
	}
	else
	{
		while (posNode->data != data)
		{
			//û�ҵ�ָ��������һֱ�ƶ����������ڵ�ָ��
				frontNode = posNode;
				posNode = posNode->next;
				//����ڶ���ָ���Ѿ��ǿ��ˣ�˵���Ѿ������������֣�������û�ҵ�ָ������
				if(!posNode)
				{
					cout << "û��ָ�������֣�ɾ��ʧ��" << endl;
					return;
				}

		}
		frontNode->next = posNode->next;
		delete posNode;
	}
	
	

}

void LinkList::changeList(int pos, int data)
{
	Node * node = head;
	int count = 0;
	while (node)
	{
		if (count == pos)
		{
			node->data = data;
			break;
		}
		count++;
		node = node->next;
	}
}

void LinkList::getData(int pos,int & data)
{
	Node * node = head;
	int count = 0;
	while (node)
	{
		if (count == pos)
		{
			data = node->data;
		}
		count++;
		//��getsize������һ�������⣬����һ������ָ�룬��Ȼ����������head��ָ���
		node = node->next;

	}
	
}

void LinkList::printList()
{
	//����ָ��head����һ������Ҫ����Ϊ�ڳ�ʼ����ʱ����һ��ͷָ�룬ͷָ������������ǲ���Ҫ��
	Node * node = head;
	while (node)
	{
		cout << node->data << endl;
		node = node->next;
	}

}

void LinkList::recursion_print_pre()
{
	
	if (tempPointer == nullptr)
	{
		return;
	}
	cout << tempPointer->data << endl;
	tempPointer = tempPointer->next;
	LinkList::recursion_print_pre();
	
	
}

void LinkList::clearList()
{
	Node * node = head;
	
	while (head)
	{
		//node����head����һ��ָ��
		node = head;
		head = head->next;
		delete node;
	
	}
	cout << "��ճɹ�" << endl;
}

void LinkList::reverse()
{
	//��ʱָ��
	Node * p = head;
	Node * q = p->next;
	if (p == nullptr || q == nullptr)
	{
		return;
	}
	while (q)
	{
		//��ʱָ�뱣��q����һ��λ�õ�ַ
		Node * r = q->next;
		//q����һ��λ��ָ��ǰ���p
		q->next = p;
		//��ʱָ������
		p = q;
		q = r;
	}
	//��һ�䲻�Ӿͻᵼ�±�����ʱ��������ѭ������Ϊ���һ��Ԫ�ص�next��Ϊ��
	head->next = nullptr;
	head = p;
	
}

LinkList::~LinkList()
{
	Node * node = head;

	while (head)
	{
		//node����head����һ��ָ��
		node = head;
		head = head->next;
		delete node;

	}
}

void printList2(Node * head)
{
	while (head)
	{
		cout << head->data << endl;
		head = head->next;

	}
}