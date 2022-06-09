#include "ListUtil.h"

Node * mergeList(Node * list1, Node * list2)
{
	//控制两个链表的移动指针
	Node * p1 = list1;
	Node * p2 = list2;
	//最后返回的指针
	Node * dumpy = new Node;
	dumpy->data = -1;
	dumpy->next = nullptr;
	//一个临时指针，直接使用dumpy的话，最后dumpy会指向末尾，所以得用一个临时指针
	Node * ptr = dumpy;
	//两个指针都不为空，就继续往下移动
	//要是有一个为空，就说明有一个指针走到了末尾，就可以把ptr->next直接指向另一个链
	while (p1 != nullptr && p2 != nullptr)
	{
		//谁更小，就把谁加到ptr后面，同时这个指针还要往后移动
		if (p1->data <= p2->data)
		{
			ptr->next = p1;
			p1 = p1->next;
		}
		else
		{
			ptr->next = p2;
			p2 = p2->next;
		}
		ptr = ptr->next;
	}

	if (p1 == nullptr)
	{
		ptr->next = p2;
	}
	else
	{
		ptr->next = p1;
	}
	dumpy = dumpy->next;
	return dumpy;
}
