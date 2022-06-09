#include "ListUtil.h"

Node * mergeList(Node * list1, Node * list2)
{
	//��������������ƶ�ָ��
	Node * p1 = list1;
	Node * p2 = list2;
	//��󷵻ص�ָ��
	Node * dumpy = new Node;
	dumpy->data = -1;
	dumpy->next = nullptr;
	//һ����ʱָ�룬ֱ��ʹ��dumpy�Ļ������dumpy��ָ��ĩβ�����Ե���һ����ʱָ��
	Node * ptr = dumpy;
	//����ָ�붼��Ϊ�գ��ͼ��������ƶ�
	//Ҫ����һ��Ϊ�գ���˵����һ��ָ���ߵ���ĩβ���Ϳ��԰�ptr->nextֱ��ָ����һ����
	while (p1 != nullptr && p2 != nullptr)
	{
		//˭��С���Ͱ�˭�ӵ�ptr���棬ͬʱ���ָ�뻹Ҫ�����ƶ�
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
