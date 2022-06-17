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
	//����ֱ��
	int max_diameter;
	


public:
	BtreeNode<T> * root;
	Btree(T val)
	{
		max_diameter = 0;
		root = new BtreeNode<T>;
		root->data = val;
		root->left = nullptr;
		root->right = nullptr;
	}
	Btree()
	{
		max_diameter = 0;
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
	//ʹ�ñ����ķ�ʽ�������������
	int maxdepthBaseLevel(BtreeNode<T> * p);
	/*����һ�ö�����������Ҫ��������ֱ�����ȡ�һ�ö�������ֱ�������������������·�������е����ֵ��
    ����·�����ܴ�������㡣ע�⣺�����֮���·��������������֮��ߵ���Ŀ��ʾ��
    �ڵ�a��b��ֱ��ʵ���Ͼ������������ĸ��ڵ���������������֮��*/
	int maxDiameter(BtreeNode<T> * p);
	//�ݹ����ʽ��ת������
	BtreeNode<T> * inverseBtree(BtreeNode<T> * p);
	//�Ա�������ʽ��ת������
	BtreeNode<T> * inverseBtreeBaseItera(BtreeNode<T> * p);


};
//�ݹ鷽ʽ�����ڵ�
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
//ǰ�����
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
//ǰ�������������ʽ��Ŀǰ���в��ɹ�6.14
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
//�������
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
//��������
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
//�������
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

//�ݹ�ķ�ʽ�������������
template<class T>
int Btree<T>::maxdepth(BtreeNode<T>* p)
{
	if (p == nullptr)
	{
		return 0;
	}
	int leftdepth = maxdepth(p->left);
	int rightdepth = maxdepth(p->right);
	//��������ֱ���Ĵ���
	//�ں���λ�ø���ֱ�������ֵ
	//�ڵ�a��b��ֱ��ʵ���Ͼ������������ĸ��ڵ���������������֮��
	int diameter = leftdepth + rightdepth;
	//����ֱ��
	
	max_diameter = max_diameter > diameter ? max_diameter : diameter;
	//��������������
	return (leftdepth >= rightdepth ? leftdepth : rightdepth) + 1;
}

//���ò�������������������
//�ҿ������ò�������������ʹ�õݹ������
template<class T>
int Btree<T>::maxdepthBaseLevel(BtreeNode<T>* p)
{
	if (p == nullptr)
	{
		return 0;
	}
	
	queue<BtreeNode<T>*> q;
	q.push(p);
	int count = 0;
	while (!q.empty())
	{
		//size�ǹؼ�������size����ÿһ��Ľڵ���
		int size = q.size();//��ȡ��һ���м����ڵ�
		//�ڲ�ѭ������ÿһ�������sizeС��0�ʹ�����һ����������������ͼ�һ
		while (size > 0)
		{
			BtreeNode<T> * temp = q.front();//��ȡ��ͷԪ��
			if (temp->left != nullptr)//��ڵ㲻Ϊ�գ������
			{
				q.push(temp->left);
			}
			if (temp->right != nullptr)
			{
				q.push(temp->right);
			}
			size -= 1;//����һ��ѭ����size��һ
			q.pop();//�����˰Ѹոձ������Ľڵ����
		}
		count += 1;//һ�����֮�󣬲����ͼ�1

	}
	return count;
}
/*����һ�ö�����������Ҫ��������ֱ�����ȡ�һ�ö�������ֱ�������������������·�������е����ֵ��
����·�����ܴ�������㡣ע�⣺�����֮���·��������������֮��ߵ���Ŀ��ʾ��
�ڵ�a��b��ֱ��ʵ���Ͼ������������ĸ��ڵ���������������֮��*/
template<class T>
int Btree<T>::maxDiameter(BtreeNode<T>* p)
{
	maxdepth(p);
	return max_diameter;
}
//�ݹ���ʽ��ת������
template<class T>
BtreeNode<T>* Btree<T>::inverseBtree(BtreeNode<T>* p)
{
	if (p == nullptr)
	{
		return nullptr;
	}
	BtreeNode<T> * left = inverseBtree(p->left);
	BtreeNode<T> * right = inverseBtree(p->right);
	p->left = right;
	p->right = left;

	return p;
}
//������ʽ��ת������
template<class T>
BtreeNode<T>* Btree<T>::inverseBtreeBaseItera(BtreeNode<T>* p)
{
	if (p == nullptr)
	{
		return nullptr;
	}
	//�ڱ�����ǰ��λ�����ڵ�Ľ�����Ҳ�����ں���λ��ִ�У�������������λ��
	BtreeNode<T> * temp = p->left;
	p->left = p->right;
	p->right = temp;
	//��һ���ڵ��Ѿ���������ˣ���ʼ������һ���ڵ�
	//�����һֱ������ڵ㣬ֱ���ڵ�Ϊ�գ��Ϳ�ʼ�����ҽڵ�
	inverseBtreeBaseItera(p->left);
	inverseBtreeBaseItera(p->right);
	return p;
}
