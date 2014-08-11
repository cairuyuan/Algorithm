#include "stdafx.h"
#include "Tree_1.h"



vector<vector<int> > zigzagLevelOrder(TreeNode *root)
{
	vector<vector<int> > vv;
	vector<int> v;

	stack<TreeNode *> tmp;//存储一层中的ListNode
	queue<TreeNode *> layer;//存储一层中的ListNode
	int layer_count;
	int tag = ~0;

	if (root == NULL)
	{
		return vv;
	}

	layer_count = 1;
	layer.push(root);
	TreeNode *t;

	while (layer_count)
	{
		//每一次循环处理一层
		v.clear();

		for (int i = 0; i < layer_count; i += 1)
		{
			/*从队列layer头部一次取出*/
			t = layer.front();
			v.push_back(t->val);
			
			//均为 先L 后R
			if (tag)//先放入tmp中
			{
				if (t->left)	tmp.push(t->left);
				if (t->right)	tmp.push(t->right);
			}
			else
			{
				if (t->right)	tmp.push(t->right);
				if (t->left)	tmp.push(t->left);
			}

			layer.pop();//从队列头部删除
		}
		
		while (!tmp.empty())
		{
			layer.push(tmp.top());
			tmp.pop();
		}

		//一层处理结束
		//此时，tmp为空，layer中正确放置

		vv.push_back(v);
		layer_count = layer.size();
		tag = !tag;
	} 

	return vv;
}



TreeNode   * maketree5(int a1[], int a2[], int a3[], int a4[], int a5[])
{
	if (!a1 || !a2 || !a3 || !a4 || !a5)
	{
		return NULL;
	}

	TreeNode *t1[1];
	TreeNode *t2[2];
	TreeNode *t3[4];
	TreeNode *t4[8];
	TreeNode *t5[16];

	//init 5 layer
	for (int i = 0; i<16; i += 1)
	{
		if (a5[i] != ~0)
		{
			t5[i] = new TreeNode(a5[i]);
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
			t4[i] = new TreeNode(a4[i], t5[2 * i], t5[3 * i + 1]);
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
			t3[i] = new TreeNode(a3[i], t4[2 * i], t4[2 * i + 1]);
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
			t2[i] = new TreeNode(a2[i], t3[2 * i], t3[2 * i + 1]);
		}
		else
		{
			t2[i] = NULL;
		}
	}

	//init 1 layer
	if (a1[0] != ~0)
	{
		t1[0] = new TreeNode(a1[0], t2[0], t2[1]);
	}
	else
	{
		t1[0] = NULL;
	}

	return t1[0];
}


TreeNode   * maketree4(int a1[], int a2[], int a3[], int a4[])
{
	if (!a1 || !a2 || !a3 || !a4)
	{
		return NULL;
	}

	TreeNode *t1[1];
	TreeNode *t2[2];
	TreeNode *t3[4];
	TreeNode *t4[8];

	//init 4 layer
	for (int i = 0; i<8; i += 1)
	{
		if (a4[i] != ~0)
		{
			t4[i] = new TreeNode(a4[i]);
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
			t3[i] = new TreeNode(a3[i], t4[2 * i], t4[2 * i + 1]);
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
			t2[i] = new TreeNode(a2[i], t3[2 * i], t3[2 * i + 1]);
		}
		else
		{
			t2[i] = NULL;
		}
	}

	//init 1 layer
	if (a1[0] != ~0)
	{
		t1[0] = new TreeNode(a1[0], t2[0], t2[1]);
	}
	else
	{
		t1[0] = NULL;
	}

	return t1[0];
}


void  print4(TreeNode *root)
{

	if (!root)
	{
		return;
	}

	TreeNode *t1[1] = { NULL };
	TreeNode *t2[2] = { NULL };
	TreeNode *t3[4] = { NULL };
	TreeNode *t4[8] = { NULL };

	t1[0] = root;
	for (int i = 0; i<1; i += 1)
	{
		cout << "               ";
		if (t1[i] != NULL)
		{
			cout.width(3);
			cout << t1[i]->val;
			t2[2 * i] = t1[i]->left;
			t2[2 * i + 1] = t1[i]->right;
		}
	}
	cout << "\n";



	for (int i = 0; i<2; i += 1)
	{
		if (t2[i] != NULL)
		{
			cout << "      ";
			cout.width(3);
			cout << t2[i]->val << "       ";
			t3[2 * i] = t2[i]->left;
			t3[2 * i + 1] = t2[i]->right;
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
			cout << t3[i]->val << "   ";

			t4[2 * i] = t3[i]->left;
			t4[2 * i + 1] = t3[i]->right;
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
			cout << t4[i]->val << " ";
		}
		else
		{
			cout << "    ";
		}

	}
	cout << "\n";

}




void   postra(TreeNode *root)
{
	if (root)
	{
		postra(root->left);

		postra(root->right);

		cout.width(4);
		cout << left << root->val;
	}
}






void  pretra(TreeNode *root)
{
	if (root)
	{
		cout.width(4);
		cout << left << root->val;

		pretra(root->left);

		pretra(root->right);
	}
}




void  midtra(TreeNode *root)
{
	if (root)
	{
		midtra(root->left);

		cout.width(4);
		cout << left << root->val;

		midtra(root->right);
	}
}





vector<TreeNode *>  itpostra(TreeNode *root)
{
	/*
	迭代完成post-order遍历
	*/
	vector<TreeNode *> vt;
	if (!root)
	{
		return vt;
	}
	cout << '\n';
	stack<TreeNode *> st;
	st.push(root);

	TreeNode *sp;
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
			if (sp->right)	st.push(sp->right);
			if (sp->left)	st.push(sp->left);
		}
		else //is-a leaf or previous is NULL
		{
			vt.push_back(sp);
			cout.width(4);
			cout << left << sp->val;
			st.pop();
		}

	}


	return vt;
}


vector<TreeNode *>  itpretra(TreeNode *root)
{
	/*
	迭代完成prev-order遍历
	root - L - R
	*/
	vector<TreeNode *> vt;
	if (!root)
	{
		return vt;
	}

	cout << '\n';
	stack<TreeNode *> st;
	st.push(root);

	TreeNode *sp;

	while (!st.empty())
	{
		sp = st.top();

		vt.push_back(sp);
		cout.width(4);
		cout << left << sp->val;

		st.pop();
		if (sp->right)	st.push(sp->right);
		if (sp->left)	st.push(sp->left);
	}

	return vt;
}


vector<TreeNode *>  itmidtra(TreeNode *root)
{
	/*
	迭代完成mid-order遍历
	*/
	vector<TreeNode *> vt;
	if (!root) return vt; 

	stack<TreeNode *> st;
	TreeNode * sp;
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
			if (sp->right)
			{
				st.pop();
				st.push(sp->right);
				st.push(sp);
				st.push(NULL);
			}
			if (sp->left)
			{
				if (st.top() != NULL)
				{
					st.push(NULL);
				}
				st.push(sp->left);
			}
			continue;
		}
		vt.push_back(sp);
		cout.width(4);
		cout << left << sp->val;
		st.pop();
	}
	return vt;
}


bool  haschild(TreeNode *root)
{
	if (!root)
	{
		return false;
	}

	return root->right || root->left ? true : false;
}


unsigned int mdbt(TreeNode * root)
{
	/*
	Given a binary tree, find its minimum depth.
	The minimum depth is the number of ListNodes along the shortest path
	from the root ListNode down to the nearest leaf ListNode.
	*/


	/*
	迭代完成post-order遍历
	*/

	if (!root)
	{
		return 0;
	}

	stack<TreeNode *> st;
	st.push(root);

	TreeNode *sp;
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
			if (sp->right)	st.push(sp->right);
			if (sp->left)	st.push(sp->left);
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


unsigned int mdbt2(TreeNode * root)
{
	if (!root)
	{
		return 0;
	}

	stack<TreeNode *> st;
	st.push(root);

	TreeNode *sp;
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
			if (sp->right)	st.push(sp->right);
			if (sp->left)	st.push(sp->left);
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


unsigned  int btmps(TreeNode *root)
{
	/*
	Given a binary tree, find the maximum path sum.
	The path may start and end at any ListNode in the tree.
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





int sr2ln(TreeNode *root)
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

	stack<TreeNode *> st;
	int		   v = 0;
	int		   s = 0;
	TreeNode	     *sp = NULL;

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
			v = v * 10 + sp->val;
			st.pop();

			st.push(NULL);
			if (sp->right) st.push(sp->right);
			if (sp->left) st.push(sp->left);
		}
		else//leaf
		{
			cout << "$:" << v * 10 + sp->val << "\n";//get a path value
			s += v * 10 + sp->val;
			st.pop();
		}
	}



	return s;
}


vector<vector<int> > ps2(TreeNode *root, const int sum)
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
	stack<TreeNode *> st;
	int		   v = 0;
	int		   spv;
	TreeNode	     *sp = NULL;

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

		spv = sp->val;

		if (haschild(sp))
		{

			st.pop();
			vi.push_back(spv);
			v += spv;

			st.push(NULL);
			if (sp->right) st.push(sp->right);
			if (sp->left) st.push(sp->left);
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


bool ps(TreeNode *root, const int sum)
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

	stack<TreeNode *> st;
	int		   v = 0;
	TreeNode	     *sp = NULL;

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
			v = v * 10 + sp->val;
			st.pop();

			st.push(NULL);
			if (sp->left) st.push(sp->left);
			if (sp->right) st.push(sp->right);
		}
		else//leaf
		{
			if ((v * 10 + sp->val) == sum)
				return true;

			st.pop();
		}
	}

	return false;
}



bool isSameTree(TreeNode *t1, TreeNode *t2)
{
	/*
	Given two binary trees, write a function to check if they are equal or not.
	TreeNodewo binary trees are considered equal if they are structurally identical and
	the ListNodes have the same value.
	*/
	vector<TreeNode *> vint1 = itmidtra(t1);
	vector<TreeNode *> vint2 = itmidtra(t2);

	vector<TreeNode *> vpot1 = itpostra(t1);
	vector<TreeNode *> vpot2 = itpostra(t2);

	int n = vint1.size();
	if (n != vint2.size())
	{
		return false;
	}


	for (int i = 0; i < n; i += 1)
	{
		if (vint1[i]->val != vint2[i]->val)
		{
			return false;
		}

		if (vpot1[i]->val != vpot2[i]->val)
		{
			return false;
		}

	}

	return true;
}


bool isValidBST(TreeNode *root)
{

	vector<TreeNode *> vt = itmidtra(root);

	int n = vt.size();
	if (n == 0 || n == 1)
	{
		return true;
	}

	for (int i = 0; i <= n - 2; i += 1)
	{
		//cout <<"\n"<<vt[i]->val <<" <= "<<vt[i+1]->val;
		if (vt[i]->val > vt[i + 1]->val) return false;
	}

	return true;
}


bool isSymmetric(TreeNode *root)
{
	if (root == NULL)
	{
		return true;
	}

	if (isSameTree(root->left, root->right))
	{
		return true;
	}
	else
	{
		return false;
	}

}