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
	//尝试使用遍历的方式求解树的最大深度，还没想好6.14
	int maxdepthBaseLevel(BtreeNode<T> * p);

};
//递归方式创建节点
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
//前序遍历
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
//前序遍历，迭代方式，目前运行不成功6.14
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
//中序遍历
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
//后续遍历
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
//层序遍历
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
//利用层序遍历求解树的最大深度
//我可以利用层序遍历求解其他使用递归的问题
template<class T>
inline int Btree<T>::maxdepthBaseLevel(BtreeNode<T>* p)
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
		//size是关键，利用size控制每一层的节点数
		int size = q.size();//获取这一层有几个节点
		//内层循环控制每一层遍历，size小于0就代表这一层遍历结束，层数就加一
		while (size > 0)
		{
			BtreeNode<T> * temp = q.front();//获取队头元素
			if (temp->left != nullptr)//左节点不为空，就入队
			{
				q.push(temp->left);
			}
			if (temp->right != nullptr)
			{
				q.push(temp->right);
			}
			size -= 1;//做完一层循环，size减一
			q.pop();//别忘了把刚刚遍历过的节点出队
		}
		count += 1;//一层结束之后，层数就加1

	}
	return count;
}
