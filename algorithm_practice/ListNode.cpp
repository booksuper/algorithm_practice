
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
//size
int LinkList::getSize()
{
	Node * node = head;
	int count = 0;
	while (node)
	{
		count++;
		//这种写法会导致head头直接指向了空指针，这样会导致后面错误
		//应该新建一个辅助指针，代替head
		node = node->next;
	}
	return count;
}
//头插法
void LinkList::insertByHead(int data)
{
	Node * newNode = new Node;
	newNode->data = data;
	newNode->next = nullptr;

	newNode->next = head->next;
	head->next = newNode;
}
//尾插法
void LinkList::insertByTail(int data)
{
	Node * newNode = new Node;
	newNode->data = data;
	newNode->next = nullptr;
	//临时指针
	Node * p = head;
	Node * q = p->next;
	//通过循环把临时指针弄到链的末尾
	while (q)
	{
		p = q;
		q = q->next;
	}
	p->next = newNode;


}
//删除指定的数
void LinkList::deleteList(int data)
{
	Node * frontNode = head;
	Node * posNode = head->next;
	//如果第一个数就是要删除的数，这是种特殊情况，另外考虑
	if (frontNode->data == data)
	{
		head = posNode;
		delete frontNode;
	}
	else
	{
		while (posNode->data != data)
		{
			//没找到指定数，就一直移动这两个相邻的指针
				frontNode = posNode;
				posNode = posNode->next;
				//如果第二个指针已经是空了，说明已经遍历所有数字，但还是没找到指定的数
				if(!posNode)
				{
					cout << "没有指定的数字，删除失败" << endl;
					return;
				}

		}
		frontNode->next = posNode->next;
		delete posNode;
	}
	
	

}
//根据索引改变链表值
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
//根据索引获取数据
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
		//和getsize函数中一样的问题，得用一个辅助指针，不然函数结束后，head又指向空
		node = node->next;

	}
	
}
//正常迭代打印
void LinkList::printList()
{
	//这里指向head的下一个，主要是因为在初始化的时候有一个头指针，头指针的数据是我们不需要的
	Node * node = head;
	while (node)
	{
		cout << node->data << endl;
		node = node->next;
	}

}
//前序遍历打印
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
//清空
void LinkList::clearList()
{
	Node * node = head;
	
	while (head)
	{
		//node代替head的上一个指针
		node = head;
		head = head->next;
		delete node;
	
	}
	cout << "清空成功" << endl;
}
//迭代反转链表
void LinkList::reverse()
{
	//临时指针
	Node * p = head;
	Node * q = p->next;
	if (p == nullptr || q == nullptr)
	{
		return;
	}
	while (q)
	{
		//临时指针保存q的下一个位置地址
		Node * r = q->next;
		//q的下一个位置指向前面的p
		q->next = p;
		//临时指针右移
		p = q;
		q = r;
	}
	//这一句不加就会导致遍历的时候跳不出循环，因为最后一个元素的next不为空
	head->next = nullptr;
	head = p;
	
}
//迭代反转链表，思路和上一个没啥差别，只是自己手写的而已
Node * LinkList::my_reverse()
{
	
	Node* p = head;
	Node* q = head->next;
	if (p == nullptr || q == nullptr)
	{
		return nullptr;
	}
	while (q != nullptr)
	{
			Node * r = q->next;
			q->next = p;
			p = q;
			q = r;
		
	}
	head->next = nullptr;
	return p;
}
//递归形式反转单链表
Node * LinkList::reverseBaserecursion(Node * node)
{
	return nullptr;
}

LinkList::~LinkList()
{
	Node * node = head;

	while (head)
	{
		//node代替head的上一个指针
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