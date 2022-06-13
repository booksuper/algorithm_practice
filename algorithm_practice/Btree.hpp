#pragma once
#include <iostream>
#include <math.h>
#include <vector>
#include <queue>
using namespace std;

template <class T>
class BtreeNode
{
public:
	T data;
	BtreeNode<T> * left;
	BtreeNode<T> * right;
};

template <class T>
class Btree
{
private:
	
	


public:
	BtreeNode<T> * root;
	Btree(T val)
	{
		root = new BtreeNode<T>;
		root->data = val;
		root->left = nullptr;
		root->right = nullptr;
	}
	Btree()
	{
		root = nullptr;
	}
	//����������
	void createTree(BtreeNode<T> * &p, BtreeNode<T> *& temp);
	//�������
	void pre_traverse(BtreeNode<T> * p);
	//�������������ʽ
	vector<T> pre_traverse_itera(BtreeNode<T> * p);
	//�������
	void in_traverse(BtreeNode<T> * p);
	//�������
	void post_traverse(BtreeNode<T> * p);
	//�������
	void level_traverse(BtreeNode<T> * p);
	//����������
	int maxdepth(BtreeNode<T> * p);
	//learn��֧

};

template<class T>
inline void Btree<T>::createTree(BtreeNode<T> *& p, BtreeNode<T> *& temp)
{
	//��֤���������� ������С�ڸ��ڵ㣬���������ڸ��ڵ�
   //p���µĽڵ㣬temp�Ǵ�root��ʼ�����Ľڵ�
	if (temp == nullptr)
	{
		temp = p;
	}
	else
	{
		//���ڵ���ֵ�ˣ��жϴ�С
		if (temp->data == p->data)
		{
			cout << "the same value is not allowed" << endl;
		}
		else if (p->data < temp->data) //�½ڵ�ȸ��ڵ�С����ȥ��ߵݹ�
		{
			createTree(p, temp->left);
		}
		else //p->data > root->data //��֮ȥ�ұߵݹ�
		{
			createTree(p, temp->right);
		}

	}

}

template<class T>
inline void Btree<T>::pre_traverse(BtreeNode<T> * p)
{
	if (p == nullptr)
	{
		return;
	}
	cout << p->data << endl;
	pre_traverse(p->left);
	pre_traverse(p->right);
}

template<class T>
inline vector<T> Btree<T>::pre_traverse_itera(BtreeNode<T>* p)
{
	vector<T> res;
	if (p == nullptr)
	{
		return res;
	}
	res.push_back(p->data);
	//���ﱨ��
	//res.push_back(pre_traverse_itera(p->left));
	//res.pop_back(pre_traverse_itera(p->right));

	return res;
}

template<class T>
inline void Btree<T>::in_traverse(BtreeNode<T>* p)
{
	if (p == nullptr)
	{
		return;
	}
	in_traverse(p->left);
	cout << p->data << endl;
	in_traverse(p->right);
}

template<class T>
inline void Btree<T>::post_traverse(BtreeNode<T>* p)
{
	if (p == nullptr)
	{
		return;
	}
	post_traverse(p->left);
	post_traverse(p->right);
	cout << p->data << endl;
}
template<class T>
void Btree<T>::level_traverse(BtreeNode<T>* p)
{
	if (p == nullptr)
	{
		cout << "��Ϊ��" << endl;
		return;
	}
	queue<BtreeNode<T> *> q;
	q.push(p);//�����ڵ�ѹ�����
	while (!q.empty())//���в�Ϊ�վ�һֱѭ��
	{
		BtreeNode<T> * temp = q.front();//�������еĵ�һ��Ԫ�أ���Ҫ��ӡ���Ԫ��ֵ
		cout << temp->data << endl;
		if (temp->left != nullptr)
		{
			q.push(temp->left);//��ڵ㲻Ϊ�վ���ӣ������������
		}
		if (temp->right != nullptr)
		{
			q.push(temp->right);//�ҽڵ㲻Ϊ�վ���ӣ������������
		}
		q.pop();//��һ��Ԫ���Ѿ���ӡ�ˣ����Խ������

	}


}
//�ݹ�ķ�ʽ���
template<class T>
inline int Btree<T>::maxdepth(BtreeNode<T>* p)
{
	if (p == nullptr)
	{
		return 0;
	}
	int leftdepth = maxdepth(p->left);
	int rightdepth = maxdepth(p->right);
	int res = leftdepth >= rightdepth ? leftdepth : rightdepth;
	res += 1;
	return res;
}
