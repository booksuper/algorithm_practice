
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
//递归形式反转单链表，主函数
Node * LinkList::reverseBaserecursionMain()
{
	Node * t = head;
	Node * tail = reverseBaserecursion(t, t->next);
	head->next = nullptr;
	return tail;

}
//递归形式反转单链表
Node * LinkList::reverseBaserecursion(Node * node,Node * node2)
{
	//终止条件
	if (node2 == nullptr) return node;
	Node * temp = node;
	//每一层节点要做的逻辑
	Node * p = node2;
	Node * q = p->next;
	p->next = temp;
	//return reverseBaserecursion(p, q);
	Node * res = reverseBaserecursion(p,q);
	//因为在递归函数后面没有做其他的操作，就是直接返回，所以返回的一直最后一个尾部元素
	return res;
}
//反转从位置 left 到位置 right 的链表节点，返回 反转后的链表
Node * LinkList::reverseBetween(int left, int right)
{
	if (head == nullptr || head->next == nullptr || left == right)
	{
		return head;
	}
	Node * p = head;
	int count = 0;
	Node * left_node = nullptr;//左区间指针
	Node * left_node_pre = nullptr;//左区间之前的一个指针
	Node * right_node = nullptr;//右区间指针
	Node * right_node_next = nullptr;//右区间之后的一个指针
	//左区间就是第一个指针，它前面没有指针了
	//不能写在循环体里面，如果写在里面，left_node会不断刷新
	if (left - 1 == 0)
	{
		left_node_pre = p;
		left_node = p;
	}
	//确定需要反转的指针区间
	while (p != nullptr)
	{
		count++;
		
		//找到左区间的指针
	    if (count == left - 1)
		{
			left_node_pre = p;
			left_node = p->next;
		}
		//找到右区间的指针
		if (count == right)
		{
			right_node = p;
			right_node_next = p->next;
		}
		p = p->next;
	}
	//确定区间之后开始反转，和反装链表代码类似
	//为了便于设置终止条件，将右区间指针置空
	right_node->next = nullptr;
	//反转时需要的临时指针
	Node * temp1 = left_node;
	Node * temp2 = left_node->next;
	//指定区间反转
	while (temp2 != nullptr)
	{
		Node * temp3 = temp2->next;
		temp2->next = temp1;
		temp1 = temp2;
		temp2 = temp3;

	}
	//如果左区间是从头开始的，就不需要拼接左区间之前的
	if (left == 1)
	{
		//第一个指针下一个应该置空，相当于拼接右区间之后的指针
		left_node->next = right_node_next;
		return temp1;
	}
	else
	{
		//拼接左区间之前的指针
		//左区间最后一个指针的下一个指向反转时候的最后一个
		left_node_pre->next = temp1;
		//拼接右区间之后的指针
		//反转时候最开始指针的下一个指向右区间最后一个
		left_node->next = right_node_next;
		return head;
	}
}
/*给你一个单链表的头节点 head ，请你判断该链表是否为回文链表。如果是，返回 true ；否则，返回 false
  直接将其反转，反转后的链表和反转前的一样那肯定就是回文链表，不过这样时间复杂度有O(n2)*/
//这个函数是辅助函数，用于递归
//能不能在递归中就把判断做了，降低复杂度
void pre_back_order(Node * p, vector<int> & pre_order, vector<int> & back_order)
{
	if (p == nullptr)
	{
		return;
	}
	pre_order.push_back(p->data);//前序位置递归，把正序遍历的数字存起来
	pre_back_order(p->next, pre_order, back_order);
	back_order.push_back(p->data);//后序位置递归，把倒序遍历的数字存起来
	
}
//在递归中就把判断做了，降低复杂度
void pre_back_order(Node * p, vector<int> & pre_order, vector<int> & back_order,int& count,int &n)
{
	if (p == nullptr)
	{
		return;
	}
	pre_order.push_back(p->data);//前序位置递归，把正序遍历的数字存起来
	pre_back_order(p->next, pre_order, back_order,count,n);
	back_order.push_back(p->data);//后序位置递归，把倒序遍历的数字存起来
	if (back_order.back() != pre_order[n])
	{
		count++;
		
	}
	n++;
	

}
//k个一组翻转链表
Node * LinkList::reverseKGroup(Node* h,int k)
{
	int size = getSize() / k;
	//k个一组进行翻转
	for (size_t i = 0; i < size ; i++)
	{
		//指定区间反转，区间是左闭右闭
		h = reverseBetweenK(h,i * k + 1,i * k + k);
	}
	return h;
	
}
//k个反转数组的辅助函数
Node* LinkList::reverseBetweenK(Node* head, int left, int right)
{
	if (head == nullptr || head->next == nullptr || left == right)
	{
		return head;
	}
	Node * p = head;
	int count = 0;
	Node * left_node = nullptr;//左区间指针
	Node * left_node_pre = nullptr;//左区间之前的一个指针
	Node * right_node = nullptr;//右区间指针
	Node * right_node_next = nullptr;//右区间之后的一个指针
	//左区间就是第一个指针，它前面没有指针了
	//不能写在循环体里面，如果写在里面，left_node会不断刷新
	if (left - 1 == 0)
	{
		left_node_pre = p;
		left_node = p;
	}
	//确定需要反转的指针区间
	while (p != nullptr)
	{
		count++;

		//找到左区间的指针
		if (count == left - 1)
		{
			left_node_pre = p;
			left_node = p->next;
		}
		//找到右区间的指针
		if (count == right)
		{
			right_node = p;
			right_node_next = p->next;
		}
		p = p->next;
	}
	//确定区间之后开始反转，和反装链表代码类似
	//为了便于设置终止条件，将右区间指针置空
	right_node->next = nullptr;
	//反转时需要的临时指针
	Node * temp1 = left_node;
	Node * temp2 = left_node->next;
	//指定区间反转
	while (temp2 != nullptr)
	{
		Node * temp3 = temp2->next;
		temp2->next = temp1;
		temp1 = temp2;
		temp2 = temp3;

	}
	//如果左区间是从头开始的，就不需要拼接左区间之前的
	if (left == 1)
	{
		//第一个指针下一个应该置空，相当于拼接右区间之后的指针
		left_node->next = right_node_next;
		return temp1;
	}
	else
	{
		//拼接左区间之前的指针
		//左区间最后一个指针的下一个指向反转时候的最后一个
		left_node_pre->next = temp1;
		//拼接右区间之后的指针
		//反转时候最开始指针的下一个指向右区间最后一个
		left_node->next = right_node_next;
		return head;
	}
}
//判断回文链表
bool LinkList::isPalindrome()
{
	
	vector<int> pre_order;
	vector<int> back_order;
	Node * p = head;
	int count = 0;
	int n = 0;
	pre_back_order(p, pre_order, back_order,count,n);
	if (count == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
	//for (int i = 0; i < pre_order.size(); i++)
	//{
	//	//正序和倒叙的数必须必须一一对应，有一个不相等就不是回文链表
	//	if (pre_order[i] != back_order[i])
	//	{
	//		return false;
	//	}
	//}
	//return true;
}
//给定一个已排序的链表的头 head ， 删除所有重复的元素，使每个元素只出现一次 。返回 已排序的链表
Node * LinkList::deleteDuplicates()
{
	if (head == nullptr)
	{
		return nullptr;
	}
	Node * res = new Node();
	res->data = head->data;
	Node * res_temp = res;
	Node * slow = head;
	Node * fast = head;
	while (fast != nullptr)
	{
		if (slow->data != fast->data)
		{
			res_temp->next = fast;
			res_temp = res_temp->next;
			slow = fast;
		}
		fast = fast->next;

	}
	//这一句特别重要，没有这一句就会导致链表末端可能还会有重复元素
	//在fast走到空的时候，说明判断完了，这时候就要把结果链表的最后一个元素指向空
	res_temp->next = nullptr;
	return res;
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