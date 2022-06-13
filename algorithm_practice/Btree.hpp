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
	//创建二叉树
	void createTree(BtreeNode<T> * &p, BtreeNode<T> *& temp);
	//先序遍历
	void pre_traverse(BtreeNode<T> * p);
	//先序遍历迭代方式
	vector<T> pre_traverse_itera(BtreeNode<T> * p);
	//中序遍历
	void in_traverse(BtreeNode<T> * p);
	//后序遍历
	void post_traverse(BtreeNode<T> * p);
	//层序遍历
	void level_traverse(BtreeNode<T> * p);
	//树的最大深度
	int maxdepth(BtreeNode<T> * p);
	//learn分支

};

template<class T>
inline void Btree<T>::createTree(BtreeNode<T> *& p, BtreeNode<T> *& temp)
{
	//保证二叉树满足 左子树小于根节点，右子树大于根节点
   //p是新的节点，temp是从root开始遍历的节点
	if (temp == nullptr)
	{
		temp = p;
	}
	else
	{
		//根节点有值了，判断大小
		if (temp->data == p->data)
		{
			cout << "the same value is not allowed" << endl;
		}
		else if (p->data < temp->data) //新节点比根节点小，就去左边递归
		{
			createTree(p, temp->left);
		}
		else //p->data > root->data //反之去右边递归
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
	//这里报错
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
		cout << "树为空" << endl;
		return;
	}
	queue<BtreeNode<T> *> q;
	q.push(p);//将根节点压入队列
	while (!q.empty())//队列不为空就一直循环
	{
		BtreeNode<T> * temp = q.front();//弹出队列的第一个元素，需要打印这个元素值
		cout << temp->data << endl;
		if (temp->left != nullptr)
		{
			q.push(temp->left);//左节点不为空就入队，必须先左后右
		}
		if (temp->right != nullptr)
		{
			q.push(temp->right);//右节点不为空就入队，必须先左后右
		}
		q.pop();//第一个元素已经打印了，所以将其出队

	}


}
//递归的方式解决
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
