#include "stdafx.h"
#include "Tree_2.h"





void flatten(TreeNode *root)
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
	each ListNode's right child points to the next ListNode of a pre-order traversal.
	*/

	if (!root)
	{
		return;
	}

	stack<TreeNode *> st;
	TreeNode *sp = NULL;
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
			sp->right = st.top();
		}
		sp = st.top();
		st.pop();

		while (sp->left)
		{
			if (sp->right) st.push(sp->right);
			sp->right = sp->left;
			sp = sp->left;
		}
		if (sp->right) st.push(sp->right);

	}

	return;
}

TreeNode *buildTree1(TreeNode ** pr, TreeNode ** in, int count)
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

		(*pr)->right = NULL;
		(*pr)->left = NULL;
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
	(*pr)->left = buildTree1(pr + 1, in, lcount);
	(*pr)->right = buildTree1(pr + lcount + 1, in + lcount + 1, count - lcount - 1);

	return *pr;
}

TreeNode *buildTree1(vector<int> &preorder, int pstart, int pend, vector<int> &inorder, int istart, int iend)
{
	assert(iend - istart == pend - pstart);//个数相同
	if (pend < pstart || iend < istart)
	{
		return NULL;
	}

	if (pend == pstart)//只有一个元素
	{
		return new TreeNode(preorder[pstart]);
	}

	int count;
	for (count = istart; count <= iend; count += 1)
	{
		if (inorder[count] == preorder[pstart]) break;
	}
	count -= istart;
	TreeNode *root = new TreeNode(preorder[pstart]);

	root->left = buildTree1(preorder, pstart + 1, pstart + count, inorder, istart, istart + count - 1);
	root->right = buildTree1(preorder, pstart + count + 1, pend, inorder, istart + count + 1, iend);

	return root;
}

TreeNode *buildTree1(vector<int> &preorder, vector<int> &inorder)
{
	/*
	Given preorder and inorder traversal of a tree, construct the binary tree.

	Note:
	You may assume that duplicates do not exist in the tree.
	*/
	assert(inorder.size() == preorder.size());
	if (inorder.size() == 0)
	{
		return NULL;
	}

	return  buildTree1(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
}



TreeNode *buildTree2(TreeNode ** in, TreeNode ** po, int count)
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

		(*in)->right = NULL;
		(*in)->left = NULL;
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
	(po[count - 1])->left = buildTree2(in, po, lcount);
	(po[count - 1])->right = buildTree2(in + lcount + 1, po + lcount, count - lcount - 1);

	return po[count - 1];
}

TreeNode *buildTree2(vector<int> &inorder, int istart, int iend, vector<int> &postorder, int pstart, int pend)
{
	/*
	inorder的istart到iend和posterorder的pstart到pend，两个数组为中序遍历和后序遍历
	4个int为下标
	*/

	assert(iend - istart == pend - pstart);//个数相同
	if (pend < pstart || iend < istart)
	{
		return NULL;
	}
	if (pend == pstart)//只有一个元素
	{
		return new TreeNode(postorder[pend]);
	}

	int count;
	for (count = istart; count <= iend; count += 1)
	{
		if (inorder[count] == postorder[pend]) break;
	}

	count -= istart;
	TreeNode *root = new TreeNode(postorder[pend]);

	root->left = buildTree2(inorder, istart, istart + count - 1, postorder, pstart, pstart + count - 1);
	root->right = buildTree2(inorder, istart + count + 1, iend, postorder, pstart + count, pend - 1);
	return root;
}



TreeNode *buildTree2(vector<int> &inorder, vector<int> &postorder)
{
	/*
	Given inorder and postorder traversal of a tree, construct the binary tree.

	Note:
	You may assume that duplicates do not exist in the tree.
	*/
	assert(inorder.size() == postorder.size());
	if (inorder.size() == 0)
	{
		return NULL;
	}

	return  buildTree2(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
}



void connect1(TreeNode *root)
{

	TreeNode * leftMost = root;
	TreeNode * nextLeftMost;
	TreeNode * nextLayerP;

	while (leftMost)//为层循环
	{
		nextLeftMost = NULL;
		nextLayerP = NULL;

		do//层内循环，至少leftMost是存在
		{
			if (leftMost->left)
			{
				if (nextLayerP == NULL)
				{
					nextLeftMost = nextLayerP = leftMost->left;
				}
				else
				{
					nextLayerP = nextLayerP->next = leftMost->left;
				}
			}

			if (leftMost->right)
			{
				if (nextLayerP == NULL)
				{
					nextLeftMost = nextLayerP = leftMost->right;
				}
				else
				{
					nextLayerP = nextLayerP->next = leftMost->right;
				}
			}

		} while (leftMost = leftMost->next);//nextright会有意义，至少是一个NULL
		//退出循环，leftmost已经到达最右端NULL
		if (nextLayerP != NULL)
		{
			nextLayerP->next = NULL;
		}

		leftMost = nextLeftMost;
	}

	/*
	//要使用常数阶的空间
	if (root == NULL)
	{
	return;
	}
	queue<TreeNode *> layer;
	int layer_count;
	TreeNode * pre;

	layer.push(root);
	layer_count = 1;

	while (layer_count)
	{
	pre = layer.front();//至少有一个元素
	layer.pop();//取出头部

	if (pre->left) layer.push(pre->left);
	if (pre->right) layer.push(pre->right);

	for (int i = 1; i < layer_count; i += 1)//处理剩下的layer_count
	{
	pre->next = layer.front();
	pre = layer.front();
	if (pre->left) layer.push(pre->left);
	if (pre->right) layer.push(pre->right);
	layer.pop();
	}
	pre->next = NULL;
	layer_count = layer.size();
	}
	*/
}

inline TreeNode *whohaschild(TreeNode *start)
{
	while (start)
	{
		if (start->left || start->right)
		{
			break;
		}
		start = start->next;
	}

	return start;
}

void connect2(TreeNode *root)
{
	/*
	Follow up for problem "Populating Next Right Pointers in Each ListNode".

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

	TreeNode *upleft = root;
	TreeNode *upr;
	TreeNode *start = root;

loop:
	while (true) //1次循环 只处理一行
	{
		//upleft 是有子节点中的最左的
		if (upleft->left != NULL)
		{
			start = upleft->left;
			upleft->left->next = upleft->right;
		}
		else
		{
			start = upleft->right;
		}

		if (upr = whohaschild(upleft->next))
		{
			upleft->right->next = upr->left == NULL ? upr->right : upr->left;
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

TreeNode *sortedArrayToBST(vector<int> &num, int start, int end)
{
	/*
	将num start到end位置(含)
	*/
	if (start > end)
	{
		return NULL;
	}

	if (start == end)
	{
		return new TreeNode(num[start]);
	}

	int mid = (start + end) / 2;
	TreeNode * root = new TreeNode(num[mid]);

	root->left = sortedArrayToBST(num, start, mid - 1);
	root->right = sortedArrayToBST(num, mid + 1, end);

	return root;

}

TreeNode *sortedArrayToBST(vector<int> &num)
{
	/*
	Given an array where elements are sorted in ascending order,
	convert it to a height balanced BST.
	*/

	return sortedArrayToBST(num, 0, num.size() - 1);

	return NULL;
}

TreeNode *sortedArrayToBST(int *arr, unsigned int n)
{
	if (arr == NULL || n<1)
	{
		return NULL;
	}

	if (n == 1)
	{
		return new TreeNode(arr[0]);
	}

	TreeNode *root = new TreeNode(arr[n / 2]);

	root->left = sortedArrayToBST(arr, n / 2);
	root->right = sortedArrayToBST(arr + n / 2 + 1, n - n / 2 - 1);

	return root;
}

int Depth(TreeNode *root)
{

	if (root == NULL)
	{
		return 0;
	}

	int l = Depth(root->left);
	int r = Depth(root->right);

	return  1 + (l>r ? l : r);

}

bool isBalanced(TreeNode *root)
{
	/*
	Given a binary tree, determine if it is height-balanced.

	For this problem, a height-balanced binary tree is defined as a binary tree
	in which the depth of the two subtrees of every ListNode never differ by more than 1.
	*/

	/*

	*/

	if (root == NULL)
		return true;
	int v = Depth(root->left) - Depth(root->right);
	if (v>1 || v<-1)
		return false;
	else
		return isBalanced(root->left) && isBalanced(root->right);

	return false;
}

vector<TreeNode *>  morritra(TreeNode *root)
{

	/*
	1. Initialize current as root
	2. While current is not NULL
	If current does not have left child
	a) Print current’s data
	b) Go to the right, i.e., current = current->right
	Else
	a) Make current as right child of the rightmost ListNode in current's left subtree
	b) Go to this left child, i.e., current = current->left
	*/
	vector<TreeNode *> vt;
	TreeNode *curr = root;
	TreeNode *pre = NULL;

	while (curr != NULL)
	{
		if (!curr->left)
		{
			vt.push_back(curr);
			curr = curr->right; //回到curr的根
		}
		else
		{
			pre = curr->left;
			while (pre->right && pre->right != curr)//找到左子树中最右侧点pre
			{
				pre = pre->right;
			}

			if (!pre->right)//最右侧点指向 子树的根，
			{
				pre->right = curr;
				curr = curr->left;
			}
			else//pre->right == curr	左子树已经遍历完 恢复 访问 子树上层的根
			{
				pre->right = NULL;
				vt.push_back(curr);
				curr = curr->right;
			}
		}
	}

	return vt;
}

TreeNode * searchinbst(TreeNode *root, int target)
{
	//L <= root 
	//R >  root

	while (root)
	{
		if (root->val == target)
		{
			break;
		}

		if (root->val < target)
		{
			root = root->right;
		}
		else
		{
			root = root->left;
		}
	}

	return root;
}

void insert_bst(TreeNode *root, int target)
{

	if (root == NULL)
	{
		return;
	}

	TreeNode *p = NULL;
	while (root)
	{
		if (root->val == target)
		{
			return;
		}

		p = root;
		if (root->val  < target)
		{
			root = root->right;
		}
		else
		{
			root = root->left;
		}

	}

	if (p->val > target)
	{
		p->left = new TreeNode(target);
	}
	else
	{
		p->right = new TreeNode(target);
	}

}

TreeNode *  delete_bst(TreeNode *t, int target)
{

	TreeNode *root = t;
	TreeNode *p = NULL;
	while (root)
	{
		if (root->val == target)
		{
			break;
		}

		p = root;
		root = root->val < target
			? root->right
			: root->left
			;
	}

	if (root == NULL)
	{
		return t;
	}

	if (root->left == NULL && root->right == NULL)
	{
		p == NULL
			? t = NULL
			: p->left == root ? p->left = NULL : p->right = NULL
			;

		delete root;
		return t;
	}


	if (root->right == NULL)
	{
		p == NULL
			? t = root->left
			: p->left == root ? p->left = root->left : p->right = root->left
			;

		delete root;
		return t;
	}

	if (root->left == NULL)
	{
		p == NULL
			? t = root->right
			: p->right == root ? p->right = root->right : p->left = root->right
			;

		delete root;
		return t;
	}

	TreeNode *newroot = root->right;
	TreeNode *pn = NULL;

	while (newroot->left)
	{
		pn = newroot;
		newroot = newroot->left;
	}

	if (pn == NULL)		//newroot就是右子树中的最小点
	{
		newroot->left = root->left;
		p == NULL
			? t = newroot
			: p->left == root ? p->left = newroot : p->right = newroot
			;

		delete root;
		return t;
	}
	else
	{
		pn->left = newroot->right;
		newroot->right = root->right;

		newroot->left = root->left;
		p == NULL
			? t = newroot
			: p->left == root ? p->left = newroot : p->right = newroot
			;

		delete root;
		return t;
	}

}

void  print(vector<TreeNode *> v)
{
	cout << '\n';
	for (unsigned int j = 0; j < v.size(); j++)
	{
		cout.width(4);
		cout << left << v[j]->val;
	}
}



void detect(pair<TreeNode*, TreeNode*>& broken, TreeNode* prev, TreeNode* current)
{
	if (prev != nullptr && prev->val > current->val)
	{
		if (broken.first == nullptr)
		{
			broken.first = prev;
		}
		broken.second = current;
	}
}


void recoverTree(TreeNode* root)
{
	pair<TreeNode *, TreeNode *> broken;
	TreeNode* prev = nullptr;
	TreeNode* cur = root;
	while (cur != nullptr) //morris
	{
		if (cur->left == nullptr)//左支空，访问根节点
		{
			detect(broken, prev, cur);
			prev = cur;
			cur = cur->right;
		}
		else
		{
			auto node = cur->left;
			while (node->right != nullptr && node->right != cur)
			{
				node = node->right;
			}

			if (node->right == nullptr)//node在cur左子树的最右侧点，中序左子树最后一个点
			{
				node->right = cur;
				cur = cur->left;
			}
			else //node->right == cur ,第二次访问
			{
				detect(broken, prev, cur);
				node->right = nullptr;
				prev = cur;
				cur = cur->right;
			}
		}
	}
	swap(broken.first->val, broken.second->val);
}



int max_sum;

int dfs(const TreeNode *root)
{
	if (root == nullptr) return 0;

	int l = dfs(root->left);
	int r = dfs(root->right);
	int sum = root->val;

	if (l > 0) sum += l;
	if (r > 0) sum += r;

	max_sum = max(max_sum, sum);
	return max(r, l) > 0 ? max(r, l) + root->val : root->val;
}
int maxPathSum(TreeNode *root)
{
	max_sum = INT_MIN;
	dfs(root);
	return max_sum;
}


vector<vector<int> > levelOrder1(TreeNode *root)
{
	/*
	Given a binary tree, return the level order traversal of its ListNodes' values.
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
	queue<TreeNode *> qt;//存放一层的节点
	TreeNode *	qf;
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
			vl.push_back(qf->val);

			if (qf->left) qt.push(qf->left);
			if (qf->right) qt.push(qf->right);
		}

		vt.push_back(vl);
	}


	return vt;

}


vector<vector<int> > levelOrder2(TreeNode *root)
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
	queue<TreeNode *> qt;//存放一层的节点
	TreeNode *	qf;
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
			vl.push_back(qf->val);

			if (qf->right) qt.push(qf->right);
			if (qf->left) qt.push(qf->left);
		}

		vt.insert(vt.begin(), vl);
	}

	return vt;

}