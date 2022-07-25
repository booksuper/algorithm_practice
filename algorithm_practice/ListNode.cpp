
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
		//����д���ᵼ��headͷֱ��ָ���˿�ָ�룬�����ᵼ�º������
		//Ӧ���½�һ������ָ�룬����head
		node = node->next;
	}
	return count;
}
//ͷ�巨
void LinkList::insertByHead(int data)
{
	Node * newNode = new Node;
	newNode->data = data;
	newNode->next = nullptr;

	newNode->next = head->next;
	head->next = newNode;
}
//β�巨
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
//ɾ��ָ������
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
//���������ı�����ֵ
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
//����������ȡ����
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
//����������ӡ
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
//ǰ�������ӡ
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
//���
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
//������ת����
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
//������ת����˼·����һ��ûɶ���ֻ���Լ���д�Ķ���
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
//�ݹ���ʽ��ת������������
Node * LinkList::reverseBaserecursionMain()
{
	Node * t = head;
	Node * tail = reverseBaserecursion(t, t->next);
	head->next = nullptr;
	return tail;

}
//�ݹ���ʽ��ת������
Node * LinkList::reverseBaserecursion(Node * node,Node * node2)
{
	//��ֹ����
	if (node2 == nullptr) return node;
	Node * temp = node;
	//ÿһ��ڵ�Ҫ�����߼�
	Node * p = node2;
	Node * q = p->next;
	p->next = temp;
	//return reverseBaserecursion(p, q);
	Node * res = reverseBaserecursion(p,q);
	//��Ϊ�ڵݹ麯������û���������Ĳ���������ֱ�ӷ��أ����Է��ص�һֱ���һ��β��Ԫ��
	return res;
}
//��ת��λ�� left ��λ�� right ������ڵ㣬���� ��ת�������
Node * LinkList::reverseBetween(int left, int right)
{
	if (head == nullptr || head->next == nullptr || left == right)
	{
		return head;
	}
	Node * p = head;
	int count = 0;
	Node * left_node = nullptr;//������ָ��
	Node * left_node_pre = nullptr;//������֮ǰ��һ��ָ��
	Node * right_node = nullptr;//������ָ��
	Node * right_node_next = nullptr;//������֮���һ��ָ��
	//��������ǵ�һ��ָ�룬��ǰ��û��ָ����
	//����д��ѭ�������棬���д�����棬left_node�᲻��ˢ��
	if (left - 1 == 0)
	{
		left_node_pre = p;
		left_node = p;
	}
	//ȷ����Ҫ��ת��ָ������
	while (p != nullptr)
	{
		count++;
		
		//�ҵ��������ָ��
	    if (count == left - 1)
		{
			left_node_pre = p;
			left_node = p->next;
		}
		//�ҵ��������ָ��
		if (count == right)
		{
			right_node = p;
			right_node_next = p->next;
		}
		p = p->next;
	}
	//ȷ������֮��ʼ��ת���ͷ�װ�����������
	//Ϊ�˱���������ֹ��������������ָ���ÿ�
	right_node->next = nullptr;
	//��תʱ��Ҫ����ʱָ��
	Node * temp1 = left_node;
	Node * temp2 = left_node->next;
	//ָ�����䷴ת
	while (temp2 != nullptr)
	{
		Node * temp3 = temp2->next;
		temp2->next = temp1;
		temp1 = temp2;
		temp2 = temp3;

	}
	//����������Ǵ�ͷ��ʼ�ģ��Ͳ���Ҫƴ��������֮ǰ��
	if (left == 1)
	{
		//��һ��ָ����һ��Ӧ���ÿգ��൱��ƴ��������֮���ָ��
		left_node->next = right_node_next;
		return temp1;
	}
	else
	{
		//ƴ��������֮ǰ��ָ��
		//���������һ��ָ�����һ��ָ��תʱ������һ��
		left_node_pre->next = temp1;
		//ƴ��������֮���ָ��
		//��תʱ���ʼָ�����һ��ָ�����������һ��
		left_node->next = right_node_next;
		return head;
	}
}
/*����һ���������ͷ�ڵ� head �������жϸ������Ƿ�Ϊ������������ǣ����� true �����򣬷��� false
  ֱ�ӽ��䷴ת����ת�������ͷ�תǰ��һ���ǿ϶����ǻ���������������ʱ�临�Ӷ���O(n2)*/
//��������Ǹ������������ڵݹ�
//�ܲ����ڵݹ��оͰ��ж����ˣ����͸��Ӷ�
void pre_back_order(Node * p, vector<int> & pre_order, vector<int> & back_order)
{
	if (p == nullptr)
	{
		return;
	}
	pre_order.push_back(p->data);//ǰ��λ�õݹ飬��������������ִ�����
	pre_back_order(p->next, pre_order, back_order);
	back_order.push_back(p->data);//����λ�õݹ飬�ѵ�����������ִ�����
	
}
//�ڵݹ��оͰ��ж����ˣ����͸��Ӷ�
void pre_back_order(Node * p, vector<int> & pre_order, vector<int> & back_order,int& count,int &n)
{
	if (p == nullptr)
	{
		return;
	}
	pre_order.push_back(p->data);//ǰ��λ�õݹ飬��������������ִ�����
	pre_back_order(p->next, pre_order, back_order,count,n);
	back_order.push_back(p->data);//����λ�õݹ飬�ѵ�����������ִ�����
	if (back_order.back() != pre_order[n])
	{
		count++;
		
	}
	n++;
	

}
//k��һ�鷭ת����
Node * LinkList::reverseKGroup(Node* h,int k)
{
	int size = getSize() / k;
	//k��һ����з�ת
	for (size_t i = 0; i < size ; i++)
	{
		//ָ�����䷴ת������������ұ�
		h = reverseBetweenK(h,i * k + 1,i * k + k);
	}
	return h;
	
}
//k����ת����ĸ�������
Node* LinkList::reverseBetweenK(Node* head, int left, int right)
{
	if (head == nullptr || head->next == nullptr || left == right)
	{
		return head;
	}
	Node * p = head;
	int count = 0;
	Node * left_node = nullptr;//������ָ��
	Node * left_node_pre = nullptr;//������֮ǰ��һ��ָ��
	Node * right_node = nullptr;//������ָ��
	Node * right_node_next = nullptr;//������֮���һ��ָ��
	//��������ǵ�һ��ָ�룬��ǰ��û��ָ����
	//����д��ѭ�������棬���д�����棬left_node�᲻��ˢ��
	if (left - 1 == 0)
	{
		left_node_pre = p;
		left_node = p;
	}
	//ȷ����Ҫ��ת��ָ������
	while (p != nullptr)
	{
		count++;

		//�ҵ��������ָ��
		if (count == left - 1)
		{
			left_node_pre = p;
			left_node = p->next;
		}
		//�ҵ��������ָ��
		if (count == right)
		{
			right_node = p;
			right_node_next = p->next;
		}
		p = p->next;
	}
	//ȷ������֮��ʼ��ת���ͷ�װ�����������
	//Ϊ�˱���������ֹ��������������ָ���ÿ�
	right_node->next = nullptr;
	//��תʱ��Ҫ����ʱָ��
	Node * temp1 = left_node;
	Node * temp2 = left_node->next;
	//ָ�����䷴ת
	while (temp2 != nullptr)
	{
		Node * temp3 = temp2->next;
		temp2->next = temp1;
		temp1 = temp2;
		temp2 = temp3;

	}
	//����������Ǵ�ͷ��ʼ�ģ��Ͳ���Ҫƴ��������֮ǰ��
	if (left == 1)
	{
		//��һ��ָ����һ��Ӧ���ÿգ��൱��ƴ��������֮���ָ��
		left_node->next = right_node_next;
		return temp1;
	}
	else
	{
		//ƴ��������֮ǰ��ָ��
		//���������һ��ָ�����һ��ָ��תʱ������һ��
		left_node_pre->next = temp1;
		//ƴ��������֮���ָ��
		//��תʱ���ʼָ�����һ��ָ�����������һ��
		left_node->next = right_node_next;
		return head;
	}
}
//�жϻ�������
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
	//	//����͵�������������һһ��Ӧ����һ������ȾͲ��ǻ�������
	//	if (pre_order[i] != back_order[i])
	//	{
	//		return false;
	//	}
	//}
	//return true;
}
//����һ��������������ͷ head �� ɾ�������ظ���Ԫ�أ�ʹÿ��Ԫ��ֻ����һ�� ������ �����������
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
	//��һ���ر���Ҫ��û����һ��ͻᵼ������ĩ�˿��ܻ������ظ�Ԫ��
	//��fast�ߵ��յ�ʱ��˵���ж����ˣ���ʱ���Ҫ�ѽ����������һ��Ԫ��ָ���
	res_temp->next = nullptr;
	return res;
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