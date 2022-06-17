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
	//树的直径
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
	//使用遍历的方式求解树的最大深度
	int maxdepthBaseLevel(BtreeNode<T> * p);
	/*给定一棵二叉树，你需要计算它的直径长度。一棵二叉树的直径长度是任意两个结点路径长度中的最大值。
    这条路径可能穿过根结点。注意：两结点之间的路径长度是以它们之间边的数目表示。
    节点a到b的直径实际上就是求他们两的父节点的两个子树的深度之和*/
	int maxDiameter(BtreeNode<T> * p);
	//递归的形式翻转二叉树
	BtreeNode<T> * inverseBtree(BtreeNode<T> * p);
	//以遍历的形式翻转二叉树
	BtreeNode<T> * inverseBtreeBaseItera(BtreeNode<T> * p);


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

//递归的方式求解树的最大深度
template<class T>
int Btree<T>::maxdepth(BtreeNode<T>* p)
{
	if (p == nullptr)
	{
		return 0;
	}
	int leftdepth = maxdepth(p->left);
	int rightdepth = maxdepth(p->right);
	//下面是求直径的代码
	//在后序位置更新直径的最大值
	//节点a到b的直径实际上就是求他们两的父节点的两个子树的深度之和
	int diameter = leftdepth + rightdepth;
	//更新直径
	
	max_diameter = max_diameter > diameter ? max_diameter : diameter;
	//返回树的最大深度
	return (leftdepth >= rightdepth ? leftdepth : rightdepth) + 1;
}

//利用层序遍历求解树的最大深度
//我可以利用层序遍历求解其他使用递归的问题
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
/*给定一棵二叉树，你需要计算它的直径长度。一棵二叉树的直径长度是任意两个结点路径长度中的最大值。
这条路径可能穿过根结点。注意：两结点之间的路径长度是以它们之间边的数目表示。
节点a到b的直径实际上就是求他们两的父节点的两个子树的深度之和*/
template<class T>
int Btree<T>::maxDiameter(BtreeNode<T>* p)
{
	maxdepth(p);
	return max_diameter;
}
//递归形式翻转二叉树
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
//遍历形式翻转二叉树
template<class T>
BtreeNode<T>* Btree<T>::inverseBtreeBaseItera(BtreeNode<T>* p)
{
	if (p == nullptr)
	{
		return nullptr;
	}
	//在遍历的前序位置做节点的交换，也可以在后序位置执行，但不能在中序位置
	BtreeNode<T> * temp = p->left;
	p->left = p->right;
	p->right = temp;
	//上一个节点已经交换完成了，开始遍历下一个节点
	//这里会一直遍历左节点，直到节点为空，就开始遍历右节点
	inverseBtreeBaseItera(p->left);
	inverseBtreeBaseItera(p->right);
	return p;
}
