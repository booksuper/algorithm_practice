#pragma once
#include <iostream>
#include <math.h>
#include <vector>
#include <queue>
#include <string>
using namespace std;

#define PRE_ORDER 0;
#define IN_ORDER 1;
#define POST_ORDER 1;
#define LEVEL_ORDER 1;
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
	BtreeNode<T> * dumpy;
	BtreeNode<T> * temp_flat;
	string serialize_str;
	


public:
	BtreeNode<T> * root;
	Btree(T val)
	{
		
		//serialize_str = "#";
		max_diameter = 0;
		dumpy = new BtreeNode<T>;
		dumpy->data = -1;
		dumpy->left = nullptr;
		dumpy->right = nullptr;
		temp_flat = dumpy;

		root = new BtreeNode<T>;
		root->data = val;
		root->left = nullptr;
		root->right = nullptr;
	}
	Btree()
	{
		//serialize_str = "#";
		max_diameter = 0;
		dumpy = new BtreeNode<T>;
		dumpy->data = -1;
		dumpy->left = nullptr;
		dumpy->right = nullptr;
		temp_flat = dumpy;
		root = nullptr;
	}
	//根据二叉搜索树的形式插入二叉树节点
	void insertTreeNode(BtreeNode<T> * &p, BtreeNode<T> *& temp);
	//输入层序数组，根据层序数组构建二叉树
	BtreeNode<T> * createTreeBaseLevel(vector<T> nums, int start);
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
	//给faltten函数使用的遍历
	void traverse_flat(BtreeNode<T> * p);

	/*遍历方式解决：给你二叉树的根结点 root ，请你将它展开为一个单链表：
	展开后的单链表应该同样使用 TreeNode ，其中 right 子指针指向链表中下一个结点，而左子指针始终为 null 。
	展开后的单链表应该与二叉树 先序遍历 顺序相同*/
	BtreeNode<T> * flatten(BtreeNode<T> * p);
	/*给定一个不重复的整数数组 nums 。 最大二叉树 可以用下面的算法从 nums 递归地构建:
	创建一个根节点，其值为 nums 中的最大值。
	递归地在最大值 左边 的 子数组前缀上 构建左子树。
	递归地在最大值 右边 的 子数组后缀上 构建右子树。
	返回 nums 构建的 最大二叉树 。*/
	BtreeNode<T> * buildMaxBtree(vector<T> &nums,int lo,int hi);
	//将二叉树序列化字符串
	string serialize(BtreeNode<T> * root);
	//将字符串反序列化为二叉树
	BtreeNode<T> * deserialize(string str);
	//s形打印二叉树,输入一个数组，将其转为二叉树之后再s形打印
	vector<vector<T>> sPrintBtree(vector<T> &inVec);
	/*124 二叉树的最大路径和 困难：路径 被定义为一条从树中任意节点出发，
	沿父节点-子节点连接，达到任意节点的序列。同一个节点在一条路径序列中
	至多出现一次 。该路径 至少包含一个 节点，且不一定经过根节点。
	路径和 是路径中各节点值的总和。给你一个二叉树的根节点 root ，返回其 最大路径和 。*/
	int maxPathSum(BtreeNode<T> * p);
	//最大路径和辅助递归函数
	int maxPathSumTravese(BtreeNode<T> * p,int & maxNum);



};
//根据二叉搜索树的形式插入二叉树节点
template<class T>
inline void Btree<T>::insertTreeNode(BtreeNode<T> *& p, BtreeNode<T> *& temp)
{
	//保证二叉树满足 左子树小于根节点，右子树大于根节点，就是构建一个二叉搜索树
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
			insertTreeNode(p, temp->left);
		}
		else //p->data > root->data //反之去右边递归
		{
			insertTreeNode(p, temp->right);
		}

	}

}
//根据层序数组构建二叉树
template<class T>
BtreeNode<T>* Btree<T>::createTreeBaseLevel(vector<T> nums, int start)
{
	if (nums[start] == '#')return nullptr;//当根节点为空，即空树
	int n = nums.size();
	BtreeNode<T>* root = new BtreeNode<T>;//新建一个根结点
	root->data = nums[start];//给根结点root的成员变量data,lchild,rchild赋初值
	root->left = nullptr;
	root->right = nullptr;

	int lnode = 2 * start + 1;//用根节点确定左节点的位置
	int rnode = 2 * start + 2;//用根节点确定右节点的位置

	if (lnode > n - 1) root->left = nullptr;
	else root->left = createTreeBaseLevel(nums,lnode);//lnode替换start，为左子树的根节点

	if (rnode > n - 1) root->right = nullptr;
	else root->right = createTreeBaseLevel(nums, rnode);//rnode替换start，为右子树的根节点

	return root;
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
			//pop放前面可以减少内存
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

template<class T>
void Btree<T>::traverse_flat(BtreeNode<T>* p)
{
	if (p == nullptr)
	{
		return;
	}
	//栈溢出
	/*temp_flat->left = nullptr;
	temp_flat->right = p;
	temp_flat = temp_flat->right;*/
	//新建节点，可以
	BtreeNode<T>* newnode = new BtreeNode<T>;
	newnode->data = p->data;
	newnode->left = nullptr;
	newnode->right = nullptr;
	temp_flat->right = newnode;
	temp_flat = temp_flat->right;
	traverse_flat(p->left);
	traverse_flat(p->right);
}


//遍历方式将二叉树展开为单链表
template<class T>
BtreeNode<T>* Btree<T>::flatten(BtreeNode<T>* p)
{
	traverse_flat(p);
	return dumpy->right;
}
//构建最大二叉树
template<class T>
BtreeNode<T>* Btree<T>::buildMaxBtree(vector<T>& nums,int lo,int hi)
{
	/*if (lo > hi)
	{
		return;
	}
	T max_val;
	*/
}
//层序遍历形式序列化
template<class T>
string Btree<T>::serialize(BtreeNode<T>* root)
{
	//前序遍历
#if PRE_ORDER
	if (root == nullptr)
	{
		//#代表空指针
		return serialize_str.append("#").append(",");
	}
	string d = to_string(root->data);
	serialize_str.append(d).append(",");
	serialize(root->left);
	serialize(root->right);
	return serialize_str;
#endif
//层序遍历
#if LEVEL_ORDER
	if (root == nullptr)
	{
		//#代表空指针
		return serialize_str.append("#").append(",");
	}
	queue<BtreeNode<T> *> q;
	q.push(root);
	while (!q.empty())
	{
		BtreeNode<T> * p = q.front();
		string d = to_string(p->data);
		serialize_str.append(d).append(",");
		if (p->left != nullptr)
		{
			
			q.push(p->left);
		}
		else
		{
			serialize_str.append("#").append(",");
		}

		if(p->right != nullptr)
		{
			q.push(p->right);
		}
		else
		{
			serialize_str.append("#").append(",");
		}
		q.pop();

	}
	return serialize_str;
#endif


}
//将字符串反序列化为二叉树
template<class T>
BtreeNode<T>* Btree<T>::deserialize(string str)
{
	return NULL;
}
//s形打印二叉树,输入一个数组，将其转为二叉树之后再s形打印
template<class T>
vector<vector<T>> Btree<T>::sPrintBtree(vector<T>& inVec)
{
	
	vector<vector<T>> res;
	if (inVec.size() == 0) return res;
	//首先先构建一个二叉树
	BtreeNode<T> * head = createTreeBaseLevel(inVec, 0);
	//然后s形打印
	int count = 0;//用来判断是奇数还是偶数
	queue<BtreeNode<T> *> q;
	q.push(head);
	while (!q.empty())
	{
		vector<T> temp;
		int size = q.size();
		for (size_t i = 0; i < size; i++)
		{
			
				temp.push_back(q.front()->data);
				if (q.front()->left != nullptr) q.push(q.front()->left);
				if (q.front()->right != nullptr) q.push(q.front()->right);
				q.pop();
			

		}
		//判断该层是奇数层还是偶数层，奇数层就反转一下
		if (count % 2 != 0)
		{
			reverse(temp.begin(), temp.end());
		}
		res.push_back(temp);
		count++;
		
	}
	return res;
}
//124 二叉树的最大路径和 困难
template<class T>
int Btree<T>::maxPathSum(BtreeNode<T>* p)
{
	int maxSum = INT_MIN;
	maxPathSumTravese(p, maxSum);
	return maxSum;
}
//最大路径和辅助递归函数
template<class T>
int Btree<T>::maxPathSumTravese(BtreeNode<T>* p, int & maxNum)
{
	if (p == nullptr) return 0;
	// 递归计算左右子节点的最大贡献值
	// 只有在最大贡献值大于 0 时，才会选取对应子节点
	int leftGain = max(maxPathSumTravese(p->left, maxNum), 0);
	int rightGain = max(maxPathSumTravese(p->right，maxNum), 0);

	// 节点的最大路径和取决于该节点的值与该节点的左右子节点的最大贡献值
	int sum = p->data + leftGain + rightGain;
	//更新
	maxNum = max(maxNum, sum);
	//返回节点的最大贡献值
	return p->data + max(leftGain, rightGain);

}
