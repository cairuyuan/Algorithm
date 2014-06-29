#include "stdafx.h"
#include "Tree.h"

using namespace std;






T   * maketree5(int a1[], int a2[], int a3[], int a4[], int a5[])
{
	if (!a1 || !a2 || !a3 || !a4 || !a5)
	{
		return NULL;
	}

	T *t1[1];
	T *t2[2];
	T *t3[4];
	T *t4[8];
	T *t5[16];

	//init 5 layer
	for (int i = 0; i<16; i += 1)
	{
		if (a5[i] != ~0)
		{
			t5[i] = new T(a5[i]);
		}
		else
		{
			t5[i] = NULL;
		}
	}

	//init 4 layer
	for (int i = 0; i<8; i += 1)
	{
		if (a4[i] != ~0)
		{
			t4[i] = new T(a4[i], t5[2 * i], t5[3 * i + 1]);
		}
		else
		{
			t4[i] = NULL;
		}
	}

	//init 3 layer
	for (int i = 0; i<4; i += 1)
	{
		if (a3[i] != ~0)
		{
			t3[i] = new T(a3[i], t4[2 * i], t4[2 * i + 1]);
		}
		else
		{
			t3[i] = NULL;
		}
	}

	//init 2 layer
	for (int i = 0; i<2; i += 1)
	{
		if (a2[i] != ~0)
		{
			t2[i] = new T(a2[i], t3[2 * i], t3[2 * i + 1]);
		}
		else
		{
			t2[i] = NULL;
		}
	}

	//init 1 layer
	if (a1[0] != ~0)
	{
		t1[0] = new T(a1[0], t2[0], t2[1]);
	}
	else
	{
		t1[0] = NULL;
	}

	return t1[0];
}


T   * maketree4(int a1[], int a2[], int a3[], int a4[])
{
	if (!a1 || !a2 || !a3 || !a4)
	{
		return NULL;
	}

	T *t1[1];
	T *t2[2];
	T *t3[4];
	T *t4[8];

	//init 4 layer
	for (int i = 0; i<8; i += 1)
	{
		if (a4[i] != ~0)
		{
			t4[i] = new T(a4[i]);
		}
		else
		{
			t4[i] = NULL;
		}
	}

	//init 3 layer
	for (int i = 0; i<4; i += 1)
	{
		if (a3[i] != ~0)
		{
			t3[i] = new T(a3[i], t4[2 * i], t4[2 * i + 1]);
		}
		else
		{
			t3[i] = NULL;
		}
	}

	//init 2 layer
	for (int i = 0; i<2; i += 1)
	{
		if (a2[i] != ~0)
		{
			t2[i] = new T(a2[i], t3[2 * i], t3[2 * i + 1]);
		}
		else
		{
			t2[i] = NULL;
		}
	}

	//init 1 layer
	if (a1[0] != ~0)
	{
		t1[0] = new T(a1[0], t2[0], t2[1]);
	}
	else
	{
		t1[0] = NULL;
	}

	return t1[0];
}


void  print4(T *root)
{

	if (!root)
	{
		return;
	}

	T *t1[1] = { NULL };
	T *t2[2] = { NULL };
	T *t3[4] = { NULL };
	T *t4[8] = { NULL };

	t1[0] = root;
	for (int i = 0; i<1; i += 1)
	{
		cout << "               ";
		if (t1[i] != NULL)
		{
			cout.width(3);
			cout << t1[i]->var;
			t2[2 * i] = t1[i]->L;
			t2[2 * i + 1] = t1[i]->R;
		}
	}
	cout << "\n";



	for (int i = 0; i<2; i += 1)
	{
		if (t2[i] != NULL)
		{
			cout << "      ";
			cout.width(3);
			cout << t2[i]->var << "       ";
			t3[2 * i] = t2[i]->L;
			t3[2 * i + 1] = t2[i]->R;
		}
		else
		{
			cout << "                ";
		}
	}
	cout << "\n";


	for (int i = 0; i<4; i += 1)
	{

		if (t3[i] != NULL)
		{
			cout << "  ";
			cout.width(3);
			cout << t3[i]->var << "   ";

			t4[2 * i] = t3[i]->L;
			t4[2 * i + 1] = t3[i]->R;
		}
		else
		{
			cout << "        ";
		}
	}
	cout << "\n";



	for (int i = 0; i<8; i += 1)
	{

		if (t4[i] != NULL)
		{
			cout.width(3);
			cout << t4[i]->var << " ";
		}
		else
		{
			cout << "    ";
		}

	}
	cout << "\n";

}




void   postra(T *root)
{
	if (root)
	{
		postra(root->L);

		postra(root->R);

		cout.width(4);
		cout << left << root->var;
	}
}






void  pretra(T *root)
{
	if (root)
	{
		cout.width(4);
		cout << left << root->var;

		pretra(root->L);

		pretra(root->R);
	}
}




void  midtra(T *root)
{
	if (root)
	{
		midtra(root->L);

		cout.width(4);
		cout << left << root->var;

		midtra(root->R);
	}
}





vector<T *>  itpostra(T *root)
{
	/*
	迭代完成post-order遍历
	*/
	vector<T *> vt;
	if (!root)
	{
		return vt;
	}
	cout << '\n';
	stack<T *> st;
	st.push(root);

	T *sp;
	bool tag;

	while (!st.empty())
	{
		tag = true;

		if (st.top() == NULL)
		{
			tag = false;
			st.pop();
		}

		sp = st.top();

		if (haschild(sp) && tag)//有子节点，而且子节点未入栈
		{
			st.push(NULL);
			if (sp->R)	st.push(sp->R);
			if (sp->L)	st.push(sp->L);
		}
		else //is-a leaf or previous is NULL
		{
			vt.push_back(sp);
			cout.width(4);
			cout << left << sp->var;
			st.pop();
		}

	}


	return vt;
}


vector<T *>  itpretra(T *root)
{
	/*
	迭代完成prev-order遍历
	root - L - R
	*/
	vector<T *> vt;
	if (!root)
	{
		return vt;
	}

	cout << '\n';
	stack<T *> st;
	st.push(root);

	T *sp;

	while (!st.empty())
	{
		sp = st.top();

		vt.push_back(sp);
		cout.width(4);
		cout << left << sp->var;

		st.pop();
		if (sp->R)	st.push(sp->R);
		if (sp->L)	st.push(sp->L);
	}

	return vt;
}


vector<T *>  itmidtra(T *root)
{
	/*
	迭代完成mid-order遍历
	*/
	vector<T *> vt;
	if (!root)
	{
		return vt;
	}
	cout << '\n';
	stack<T *> st;

	T * sp;
	st.push(root);
	bool tag;

	while (!st.empty())
	{
		tag = true;
		if (st.top() == NULL)
		{
			st.pop();
			tag = false;
		}

		sp = st.top();
		if (haschild(sp) && tag)
		{
			if (sp->R)
			{
				st.pop();
				st.push(sp->R);
				st.push(sp);
				st.push(NULL);
			}

			if (sp->L)
			{
				if (st.top() != NULL)
				{
					st.push(NULL);
				}
				st.push(sp->L);
			}
			continue;
		}

		vt.push_back(sp);
		cout.width(4);
		cout << left << sp->var;
		st.pop();

	}


	return vt;
}


bool  haschild(T *root)
{
	if (!root)
	{
		return false;
	}

	return root->R || root->L ? true : false;
}


unsigned int mdbt(T * root)
{
	/*
	Given a binary tree, find its minimum depth.
	The minimum depth is the number of nodes along the shortest path
	from the root node down to the nearest leaf node.
	*/


	/*
	迭代完成post-order遍历
	*/

	if (!root)
	{
		return 0;
	}

	stack<T *> st;
	st.push(root);

	T *sp;
	bool tag;
	unsigned int depth = 1;
	unsigned int i = 0;

	while (!st.empty())
	{
		tag = true;

		if (st.top() == NULL)
		{
			tag = false;
			st.pop();
			depth -= 1;
		}
		sp = st.top();

		if (haschild(sp) && tag) //1/2 child && never enter st
		{
			st.push(NULL);
			if (sp->R)	st.push(sp->R);
			if (sp->L)	st.push(sp->L);
			depth += 1;
			continue;
		}

		if (!tag)
		{
			st.pop();
			continue;
		}

		if (!haschild(sp))//0 child :leaf
		{
			st.pop();
			if (i == 0)
			{
				i = depth;
			}
			else
			{
				i = depth<i ? depth : i;
			}

			continue;
		}

	}


	return i;
}


unsigned int mdbt2(T * root)
{
	if (!root)
	{
		return 0;
	}

	stack<T *> st;
	st.push(root);

	T *sp;
	bool tag;
	unsigned int depth = 1;
	unsigned int i = 0;

	while (!st.empty())
	{
		tag = true;

		if (st.top() == NULL)
		{
			tag = false;
			st.pop();
			depth -= 1;
		}
		sp = st.top();

		if (haschild(sp) && tag) //1/2 child && never enter st
		{
			st.push(NULL);
			if (sp->R)	st.push(sp->R);
			if (sp->L)	st.push(sp->L);
			depth += 1;
			continue;
		}

		if (!tag)
		{
			st.pop();
			continue;
		}

		if (!haschild(sp))//0 child :leaf
		{
			st.pop();
			if (i == 0)
			{
				i = depth;
			}
			else
			{
				i = depth<i ? i : depth;
			}

			continue;
		}

	}


	return i;
}


unsigned  int btmps(T *root)
{
	/*
	Given a binary tree, find the maximum path sum.
	The path may start and end at any node in the tree.
	For example:
	Given the below binary tree,

	1
	/ \
	2   3
	Return 6.
	*/

	/*
	两个节点之间的路径存在且唯一
	排列
	*/

	//unsigned int i=postra(root);

	//return i==0 ? -1 :i*(i-1);
	return 0;
}





int sr2ln(T *root)
{

	/*
	Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.
	An example is the root-to-leaf path 1->2->3 which represents the number 123.
	Find the total sum of all root-to-leaf numbers.
	For example,
	1
	/ \
	2   3
	The root-to-leaf path 1->2 represents the number 12.
	The root-to-leaf path 1->3 represents the number 13.

	Return the sum = 12 + 13 = 25.
	*/

	if (!root)
	{
		return ~0;
	}

	stack<T *> st;
	int		   v = 0;
	int		   s = 0;
	T	     *sp = NULL;

	st.push(root);
	while (!st.empty())
	{
		sp = st.top();
		if (sp == NULL)
		{
			st.pop();
			v /= 10;
			continue;
		}

		if (haschild(sp))
		{
			v = v * 10 + sp->var;
			st.pop();

			st.push(NULL);
			if (sp->R) st.push(sp->R);
			if (sp->L) st.push(sp->L);
		}
		else//leaf
		{
			cout << "$:" << v * 10 + sp->var << "\n";//get a path value
			s += v * 10 + sp->var;
			st.pop();
		}
	}



	return s;
}


vector<vector<int> > ps2(T *root, const int sum)
{
	/*
	Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

	For example:
	Given the below binary tree and sum = 22,
	5
	/ \
	4   8
	/   / \
	11  13  4
	/  \    / \
	7    2  5   1
	return
	[
	[5,4,11,2],
	[5,8,4,5]
	]
	*/


	vector<vector<int> > vv;
	if (!root)
	{
		return vv;
	}

	vector<int> vi;
	stack<T *> st;
	int		   v = 0;
	int		   spv;
	T	     *sp = NULL;

	st.push(root);
	while (!st.empty())
	{
		sp = st.top();
		if (sp == NULL)
		{
			st.pop();
			v -= vi.back();
			vi.pop_back();
			continue;
		}

		spv = sp->var;

		if (haschild(sp))
		{

			st.pop();
			vi.push_back(spv);
			v += spv;

			st.push(NULL);
			if (sp->R) st.push(sp->R);
			if (sp->L) st.push(sp->L);
		}
		else//leaf
		{
			cout << "$:" << v + spv << "\n";//get a path value

			vi.push_back(spv);
			if ((v + spv) == sum)
			{
				vv.push_back(vi);
				cout << "\tOK\n";
			}
			st.pop();
			vi.pop_back();
		}
	}




	return vv;
}


bool ps(T *root, const int sum)
{

	/*
	Given a binary tree and a sum,
	determine if the tree has a root-to-leaf path
	such that
	adding up all the values along the path equals the given sum.

	For example:
	Given the below binary tree and sum = 22,
	5
	/ \
	4   8
	/   / \
	11  13  4
	/  \      \
	7    2      1
	return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
	*/

	if (!root)
	{
		return false;
	}

	stack<T *> st;
	int		   v = 0;
	T	     *sp = NULL;

	st.push(root);
	while (!st.empty())
	{
		sp = st.top();
		if (sp == NULL)
		{
			st.pop();
			v /= 10;
			continue;
		}

		if (haschild(sp))
		{
			v = v * 10 + sp->var;
			st.pop();

			st.push(NULL);
			if (sp->L) st.push(sp->L);
			if (sp->R) st.push(sp->R);
		}
		else//leaf
		{
			if ((v * 10 + sp->var) == sum)
				return true;

			st.pop();
		}
	}

	return false;
}


vector<vector<int> > levelOrder1(T *root)
{
	/*
	Given a binary tree, return the level order traversal of its nodes' values.
	(ie, from left to right, level by level).

	For example:
	Given binary tree {3,9,20,#,#,15,7},
	3
	/ \
	9  20
	/  \
	15   7
	return its level order traversal as:
	[
	[3],
	[9,20],
	[15,7]
	]

	*/
	vector<vector<int> > vt;//所有
	vector<int> vl;//存放一层的数据
	queue<T *> qt;//存放一层的节点
	T *	qf;
	unsigned int ln;

	if (!root)
	{
		return vt;
	}

	qt.push(root);
	ln = 1;
	while (!qt.empty())
	{
		ln = qt.size();
		vl.clear();
		for (unsigned int i = 0; i < ln; i += 1)
		{
			qf = qt.front();
			qt.pop();
			vl.push_back(qf->var);

			if (qf->L) qt.push(qf->L);
			if (qf->R) qt.push(qf->R);
		}

		vt.push_back(vl);
	}


	return vt;

}


vector<vector<int> > levelOrder2(T *root)
{
	/*
	[
	[15,7]
	[9,20],
	[3],
	]
	bottom-up
	先输出最底层，再输出最顶层
	*/

	vector<vector<int> > vt;//所有
	vector<int> vl;//存放一层的数据
	queue<T *> qt;//存放一层的节点
	T *	qf;
	unsigned int ln;

	if (!root)
	{
		return vt;
	}

	qt.push(root);
	ln = 1;
	while (!qt.empty())
	{
		ln = qt.size();
		vl.clear();
		for (unsigned int i = 0; i < ln; i += 1)
		{
			qf = qt.front();
			qt.pop();
			vl.push_back(qf->var);

			if (qf->R) qt.push(qf->R);
			if (qf->L) qt.push(qf->L);
		}

		vt.insert(vt.begin(), vl);
	}

	return vt;

}


void flatten(T *root)
{
	//待优化
	//递归版
	/*
	Given a binary tree, flatten it to a linked list in-place.

	For example,
	Given
	1
	/ \
	2   5
	/ \   \
	3   4   6
	The flattened tree should look like:
	1
	\
	2
	\
	3
	\
	4
	\
	5
	\
	6
	click to show hints.

	Hints:
	If you notice carefully in the flattened tree,
	each node's right child points to the next node of a pre-order traversal.
	*/

	if (!root)
	{
		return;
	}

	stack<T *> st;
	T *sp = NULL;
	/*
	1
	/ \
	2   5
	/ \   \
	3   4   6
	*/
	st.push(root);
	while (!st.empty())
	{
		if (sp != NULL)
		{
			sp->R = st.top();
		}
		sp = st.top();
		st.pop();

		while (sp->L)
		{
			if (sp->R) st.push(sp->R);
			sp->R = sp->L;
			sp = sp->L;
		}
		if (sp->R) st.push(sp->R);

	}

	return;
}


T *buildTree1(vector<int> &inorder, vector<int> &postorder)
{
	/*
	Given inorder and postorder traversal of a tree, construct the binary tree.

	Note:
	You may assume that duplicates do not exist in the tree.
	*/


	return NULL;
}


T *buildTree2(vector<int> &preorder, vector<int> &inorder)
{
	/*
	Given preorder and inorder traversal of a tree, construct the binary tree.

	Note:
	You may assume that duplicates do not exist in the tree.
	*/
	return NULL;
}






bool isSameTree(T *t1, T *t2)
{
	/*
	Given two binary trees, write a function to check if they are equal or not.
	Two binary trees are considered equal if they are structurally identical and
	the nodes have the same value.
	*/
	vector<T *> vint1 = itmidtra(t1);
	vector<T *> vint2 = itmidtra(t2);

	vector<T *> vpot1 = itpostra(t1);
	vector<T *> vpot2 = itpostra(t2);

	int n = vint1.size();
	if (n != vint2.size())
	{
		return false;
	}


	for (int i = 0; i < n; i += 1)
	{
		if (vint1[i]->var != vint2[i]->var)
		{
			return false;
		}

		if (vpot1[i]->var != vpot2[i]->var)
		{
			return false;
		}

	}

	return true;
}


bool isValidBST(T *root)
{

	vector<T *> vt = itmidtra(root);

	int n = vt.size();
	if (n == 0 || n == 1)
	{
		return true;
	}

	for (int i = 0; i <= n - 2; i += 1)
	{
		//cout <<"\n"<<vt[i]->var <<" <= "<<vt[i+1]->var;
		if (vt[i]->var > vt[i + 1]->var) return false;
	}

	return true;
}


bool isSymmetric(T *root)
{
	if (root == NULL)
	{
		return true;
	}

	if (isSameTree(root->L, root->R))
	{
		return true;
	}
	else
	{
		return false;
	}

}




T *buildTree1(T ** pr, T ** in, int count)
{
	/*
	Given inorder and postorder traversal of a tree, construct the binary tree.

	Note:
	You may assume that duplicates do not exist in the tree.
	*/

	if (pr == NULL || in == NULL)//参数有误
	{
		return NULL;
	}
	if (count == 0)
	{
		return NULL;
	}
	if (count == 1)
	{
		assert(*pr);
		assert(*pr == *in);

		(*pr)->R = NULL;
		(*pr)->L = NULL;
		return *pr;
	}

	int lcount = 0;
	for (lcount = 0; lcount < count; lcount += 1)
	{
		if (*pr == in[lcount])
		{
			break;
		}
	}

	//左子树的节点数：lcount  
	//右子树的节点数：count-lcount-1
	(*pr)->L = buildTree1(pr + 1, in, lcount);
	(*pr)->R = buildTree1(pr + lcount + 1, in + lcount + 1, count - lcount - 1);

	return *pr;
}


T *buildTree2(T ** in, T ** po, int count)
{
	/*
	Given preorder and inorder traversal of a tree, construct the binary tree.
	Note:
	You may assume that duplicates do not exist in the tree.
	*/

	if (in == NULL || po == NULL)//参数有误
	{
		return NULL;
	}
	if (count == 0)
	{
		return NULL;
	}

	if (count == 1)
	{
		assert(*in);
		assert(*in == *po);

		(*in)->R = NULL;
		(*in)->L = NULL;
		return *in;
	}

	int lcount = 0;
	for (lcount = 0; lcount < count; lcount += 1)
	{
		if (po[count - 1] == in[lcount])
		{
			break;
		}
	}

	//左子树的节点数：lcount  
	//右子树的节点数：count-lcount-1
	(po[count - 1])->L = buildTree2(in, po, lcount);
	(po[count - 1])->R = buildTree2(in + lcount + 1, po + lcount, count - lcount - 1);

	return po[count - 1];
}






void connect1(T *root)
{
	/*

	Given a binary tree

	struct TreeLinkNode {
	TreeLinkNode *left;
	TreeLinkNode *right;
	TreeLinkNode *next;
	}
	Populate each next pointer to point to its next right node.
	If there is no next right node, the next pointer should be set to NULL.

	Initially, all next pointers are set to NULL.

	Note:

	You may only use constant extra space.
	You may assume that it is a perfect binary tree (ie, all leaves are at the same level,
	and every parent has two children).
	For example,
	Given the following perfect binary tree,
	1
	/  \
	2    3
	/ \  / \
	4   56   7
	After calling your function, the tree should look like:
	1 -> NULL
	/  \
	2 -> 3 -> NULL
	/ \  / \
	4->5->6->7 -> NULL
	*/

	T * upleft = root;
	T * tp;
	while (upleft->L) //要处理行的上一层 最左端点
	{
		tp = upleft;
		while (tp)//逐点
		{
			tp->L->next = tp->R;
			if (tp->next == NULL)
			{
				tp->R->next = NULL;
				break;
			}
			tp->R->next = tp->next->L;

			tp = tp->next;
		}

		upleft = upleft->L;
	}

}


inline T *whohaschild(T *start)
{
	while (start)
	{
		if (start->L || start->R)
		{
			break;
		}
		start = start->next;
	}

	return start;
}


void connect2(T *root)
{
	/*
	Follow up for problem "Populating Next Right Pointers in Each Node".

	What if the given tree could be any binary tree? Would your previous solution still work?

	Note:

	You may only use constant extra space.
	For example,
	Given the following binary tree,
	1
	/  \
	2    3
	/ \    \
	4   5    7
	After calling your function, the tree should look like:
	1 -> NULL
	/  \
	2 -> 3 -> NULL
	/ \    \
	4-> 5 -> 7 -> NULL

	*/

	T *upleft = root;
	T *upr;
	T *start = root;

loop:
	while (true) //1次循环 只处理一行
	{
		//upleft 是有子节点中的最左的
		if (upleft->L != NULL)
		{
			start = upleft->L;
			upleft->L->next = upleft->R;
		}
		else
		{
			start = upleft->R;
		}

		if (upr = whohaschild(upleft->next))
		{
			upleft->R->next = upr->L == NULL ? upr->R : upr->L;
		}
		else
		{
			break;//之前的右节点不用处理 默认NULL
		}

		upleft = upr;
	}



	if (upleft = whohaschild(start))
	{
		goto loop;
	}

	return;
}



T *sortedArrayToBST(vector<int> &num)
{
	/*
	Given an array where elements are sorted in ascending order,
	convert it to a height balanced BST.
	*/


	return NULL;
}


T *sortedArrayToBST(int *arr, unsigned int n)
{
	if (arr == NULL || n<1)
	{
		return NULL;
	}

	if (n == 1)
	{
		return new T(arr[0]);
	}

	T *root = new T(arr[n / 2]);

	root->L = sortedArrayToBST(arr, n / 2);
	root->R = sortedArrayToBST(arr + n / 2 + 1, n - n / 2 - 1);

	return root;
}





int Depth(T *root)
{

	if (root == NULL)
	{
		return 0;
	}

	int l = Depth(root->L);
	int r = Depth(root->R);

	return  1 + (l>r ? l : r);

}



bool isBalanced(T *root)
{
	/*
	Given a binary tree, determine if it is height-balanced.

	For this problem, a height-balanced binary tree is defined as a binary tree
	in which the depth of the two subtrees of every node never differ by more than 1.
	*/

	/*

	*/

	if (root == NULL)
		return true;
	int v = Depth(root->L) - Depth(root->R);
	if (v>1 || v<-1)
		return false;
	else
		return isBalanced(root->L) && isBalanced(root->R);

	return false;
}



vector<T *>  morritra(T *root)
{

	/*
	1. Initialize current as root
	2. While current is not NULL
	If current does not have left child
	a) Print current’s data
	b) Go to the right, i.e., current = current->right
	Else
	a) Make current as right child of the rightmost node in current's left subtree
	b) Go to this left child, i.e., current = current->left
	*/
	vector<T *> vt;
	T *curr = root;
	T *pre = NULL;

	while (curr != NULL)
	{
		if (!curr->L)
		{
			vt.push_back(curr);
			curr = curr->R; //回到curr的根
		}
		else
		{
			pre = curr->L;
			while (pre->R && pre->R != curr)//找到左子树中最右侧点pre
			{
				pre = pre->R;
			}

			if (!pre->R)//最右侧点指向 子树的根，
			{
				pre->R = curr;
				curr = curr->L;
			}
			else//pre->R == curr	左子树已经遍历完 恢复 访问 子树上层的根
			{
				pre->R = NULL;
				vt.push_back(curr);
				curr = curr->R;
			}
		}
	}

	return vt;
}



T * searchinbst(T *root, int target)
{
	//L <= root 
	//R >  root

	while (root)
	{
		if (root->var == target)
		{
			break;
		}

		if (root->var < target)
		{
			root = root->R;
		}
		else
		{
			root = root->L;
		}
	}

	return root;
}



void insert_bst(T *root, int target)
{

	if (root == NULL)
	{
		return;
	}

	T *p = NULL;
	while (root)
	{
		if (root->var == target)
		{
			return;
		}

		p = root;
		if (root->var  < target)
		{
			root = root->R;
		}
		else
		{
			root = root->L;
		}

	}

	if (p->var > target)
	{
		p->L = new T(target);
	}
	else
	{
		p->R = new T(target);
	}

}


T *  delete_bst(T *t, int target)
{

	T *root = t;
	T *p = NULL;
	while (root)
	{
		if (root->var == target)
		{
			break;
		}

		p = root;
		root = root->var < target
			? root->R
			: root->L
			;
	}

	if (root == NULL)
	{
		return t;
	}

	if (root->L == NULL && root->R == NULL)
	{
		p == NULL
			? t = NULL
			: p->L == root ? p->L = NULL : p->R = NULL
			;

		delete root;
		return t;
	}


	if (root->R == NULL)
	{
		p == NULL
			? t = root->L
			: p->L == root ? p->L = root->L : p->R = root->L
			;

		delete root;
		return t;
	}

	if (root->L == NULL)
	{
		p == NULL
			? t = root->R
			: p->R == root ? p->R = root->R : p->L = root->R
			;

		delete root;
		return t;
	}

	T *newroot = root->R;
	T *pn = NULL;

	while (newroot->L)
	{
		pn = newroot;
		newroot = newroot->L;
	}

	if (pn == NULL)		//newroot就是右子树中的最小点
	{
		newroot->L = root->L;
		p == NULL
			? t = newroot
			: p->L == root ? p->L = newroot : p->R = newroot
			;

		delete root;
		return t;
	}
	else
	{
		pn->L = newroot->R;
		newroot->R = root->R;

		newroot->L = root->L;
		p == NULL
			? t = newroot
			: p->L == root ? p->L = newroot : p->R = newroot
			;

		delete root;
		return t;
	}

}




void  print(vector<T *> v)
{
	cout << '\n';
	for (unsigned int j = 0; j < v.size(); j++)
	{
		cout.width(4);
		cout << left << v[j]->var;
	}
}