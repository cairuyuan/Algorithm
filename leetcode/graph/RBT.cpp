#include "stdafx.h"
#include "RBT.h"

RBT * nil = new RBT();


void  print4_(RBT *root)
{

	if (root == nil)
	{
		return;
	}

	RBT *t1[1] = { nil };
	RBT *t2[2] = { nil, nil };
	RBT *t3[4] = { nil, nil, nil, nil };
	RBT *t4[8] = { nil, nil, nil, nil, nil, nil, nil, nil };

	t1[0] = root;
	for (int i = 0; i<1; i += 1)
	{
		cout << "               ";
		if (t1[i] != nil)
		{
			cout.width(3);
			cout << t1[i]->val;

			if (t1[i]->color == black)
			{
				cout << 'b';
			}
			else
			{
				cout << 'r';
			}
			t2[2 * i] = t1[i]->left;
			t2[2 * i + 1] = t1[i]->right;
		}
	}
	cout << "\n";



	for (int i = 0; i<2; i += 1)
	{
		if (t2[i] != nil)
		{
			cout << "      ";
			cout.width(3);
			cout << t2[i]->val;
			if (t2[i]->color == black)
			{
				cout << 'b';
			}
			else
			{
				cout << 'r';
			}
			cout << "       ";
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

		if (t3[i] != nil)
		{
			cout << "  ";
			cout.width(3);
			cout << t3[i]->val;
			if (t3[i]->color == black)
			{
				cout << 'b';
			}
			else
			{
				cout << 'r';
			}
			cout << "   ";

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

		if (t4[i] != nil)
		{
			cout.width(3);
			cout << t4[i]->val;
			if (t4[i]->color == black)
			{
				cout << 'b';
			}
			else
			{
				cout << 'r';
			}
			cout << " ";
		}
		else
		{
			cout << "    ";
		}

	}
	cout << "\n";

}


void  print4(RBT *root)
{

	if (!root)
	{
		return;
	}

	RBT *t1[1] = { NULL };
	RBT *t2[2] = { NULL };
	RBT *t3[4] = { NULL };
	RBT *t4[8] = { NULL };

	t1[0] = root;
	for (int i = 0; i<1; i += 1)
	{
		cout << "               ";
		if (t1[i] != NULL)
		{
			cout.width(3);
			cout << t1[i]->val;

			if (t1[i]->color == black)
			{
				cout << 'b';
			}
			else
			{
				cout << 'r';
			}
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
			cout << t2[i]->val;
			if (t2[i]->color == black)
			{
				cout << 'b';
			}
			else
			{
				cout << 'r';
			}
			cout << "       ";
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
			cout << t3[i]->val;
			if (t3[i]->color == black)
			{
				cout << 'b';
			}
			else
			{
				cout << 'r';
			}
			cout << "   ";

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
			cout << t4[i]->val;
			if (t4[i]->color == black)
			{
				cout << 'b';
			}
			else
			{
				cout << 'r';
			}
			cout << " ";
		}
		else
		{
			cout << "    ";
		}

	}
	cout << "\n";

}







RBT *gp(RBT *root)
{
	return  (root && root->P) ? root->P->P : NULL;
}


RBT *un(RBT *root)
{
	RBT * grand = gp(root);
	if (grand )//grand parent 存在时才会有uncle
	{
		return (root->P == grand->left) ? grand->right : grand->left;
	}

	return NULL;// root 或root->P为NULL，则不可能有uncle
}


inline RBT *br(RBT *root)
{
	if (root && root->P)
	{
		return (root == root->P->left) ? root->P->right : root->P->left;
	}
	else
	{
		return NULL;
	}
}

//首先要使用BST的插入法插入新节点，然后涂成红色  插入点肯定在底层，或至多有“侄子”
void insert_case1(RBT *N)
{
	if (N->P == NULL)
	{
		N->color = black;
		return;
	}
	insert_case2(N);
}


void insert_case2(RBT *N)
{
	if (N->P->color == black)
	{
		return;
	}
	insert_case3(N);//case 3 中root->P->color != black,ie, red
}
/*
下面假定新节点的父节点为红色，所以它有祖父节点
*/
void insert_case3( RBT *N)
{
	/*
	父节点P是红色
	叔父节点是红色

	将它们两个重绘为黑色并重绘祖父节点G为红色
	在祖父节点 递归处理
	*/

	if (un(N) != NULL && un(N)->color == red)
	{
		N->P->color = black;
		un(N)->color = black;
		gp(N)->color = red;

		insert_case1(gp(N));
		return;
	}
	insert_case4(N);//uncle 为黑色或NULL
}


void insert_case4(RBT *N)
{
	if (N == N->P->right && N->P == gp(N)->left)
	{
		//rote_left(root->p)								gp					   gp
		rotate_L(N->P);		//			 P      U    -->	   root    U
		N = N->left; //		  br  root				 P     r2
	}										//           r1  r2           br  r1		
	else if (N == N->P->left && N->P == gp(N)->right)
	{
		//rote_right(root->p)
		rotate_R(N->P);
		N = N->right;
	}
	//要变成 root P  （gp）  root P都是左或都是右
	insert_case5(N);
}

void insert_case5(RBT *N)
{
	/*
	P是红，U是黑
	root和P 同左或同右
	*/
	N->P->color = black;
	gp(N)->color = red;

	if (N == N->P->left && N->P == gp(N)->left)
	{
		rotate_R(gp(N));
	}

	if (N == N->P->right && N->P == gp(N)->right)
	{
		rotate_L(gp(N));
	}
}



void rotate_L(RBT *root)
{
	/*
		P                      root
	 B    root    -->	    P     c2   
		c1  c2           B    c1
	root 向左旋转
	*/

	RBT *pr = root->P, *grand = gp(root);

	if (grand)
	{
		if (pr == grand->left)
		{
			grand->left = root;
		}
		else
		{
			grand->right = root;
		}
		root->P = grand;
	}
	else
	{
		root->P = NULL;
	}

	pr->right = root->left;
	if (root->left)
	{
		root->left->P = pr;
	}

	root->left = pr;
	pr->P = root;
}



void rotate_R(RBT *root)
{
	/*
	     P                    root
	root    B      -->	    c1     P
   c1  c2                       c2   B
	root 向左旋转
	*/
	RBT * grand = gp(root), *pr = root->P;

	if (grand)
	{
		if (pr == grand->left)
		{
			grand->left = root;
		}
		else
		{
			grand->right = root;
		}
		root->P = grand;
	}
	else//之前的parent为顶部根
	{
		root->P = NULL;
	}

	pr->left = root->right;
	if (root->right)
	{
		root->right->P = pr;
	}

	root->right = pr;
	pr->P = root;
}


RBT * delete_rbt(RBT * root, int target)
{
	RBT *p = root;
	RBT *s = NULL;
	RBT *N = NULL;
	while (p && p->val != target)
	{
		p = (target > p->val) ? p->right : p = p->left;
	}
	if (!p) return root;//没找到

	//找到p的替代,左子树的最右，右子树的最左
	s = p;
	if (s->left)
	{
		s = s->left;
		while (s->right) s = s->right;
		p->val = s->val;
	}
	//删除点为s,最多有左子树，右子树是空
	//s必是父亲的右子树
	N = s->left;
	s->P->right = N;
	N->P = s->P;
	s->left = NULL;
	s->P = NULL;
	//以上完成替换

	if (s->color == red )
	{
		delete s;
		return;
	}

	if (N->color == red)
	{
		N->color == black;
		delete s;
		return;
	}
	
	return delete_fix(root,N);
}

void inline eh_color(RBT * rbt1, RBT * rbt2)
{
	int tmp = rbt1->color;
	rbt1->color = rbt2->color;
	rbt2->color = tmp;
}

RBT * delete_fix(RBT * root, RBT * N)
{
	RBT *b = br(N);
	RBT *p = N->P;
	
	if (b->color == red)
	{
		if (N == p->left)
		{
			rotate_L(p);
		}
		else
		{
			rotate_R(p);
		}
	}

	if (b->left->color == black && b->right->color == black )
	{
		b->color == red;
		delete_fix(root, p);
	}
	//b 的两个儿子异色，或同红
	if (N == p->left)
	{
		if (b->right->color == black)//  黑，黑（已截留）    红 黑
		{
			eh_color(b, b->left);
			rotate_R(b);
		}

		eh_color(p, b);
		b->right->color = black;
		rotate_L(p);
	}
	else
	{
		if (b->left->color == black)
		{
			eh_color(b, b->right);
			rotate_L(b);
		}

		eh_color(p, b);
		b->left->color = black;
		rotate_R(p);
	}

	return root;
}

void postra(RBT *root)
{
	if (root)
	{
		postra(root->left);
		postra(root->right);
		cout.width(4);
		cout << root->val;
		if (root->color == black)
		{
			cout << 'b';
		}
		else
		{
			cout << 'r';
		}
	}
}



void  pretra(RBT *root)
{
	if (root)
	{
		cout.width(4);
		cout << root->val;
		if (root->color == black)
		{
			cout << 'b';
		}
		else
		{
			cout << 'r';
		}

		pretra(root->left);

		pretra(root->right);
	}
}



void  midtra(RBT *root)
{
	if (root)
	{
		midtra(root->left);

		cout.width(4);
		cout << root->val;
		if (root->color == black)
		{
			cout << 'b';
		}
		else
		{
			cout << 'r';
		}
		midtra(root->right);
	}
}

int Depth(RBT *root)
{

	if (root == NULL)
	{
		return 0;
	}

	int l = Depth(root->left);
	int r = Depth(root->right);

	return  1 + (l>r ? l : r);

}




bool isBalanced(RBT *root)
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



RBT *insert_rbt(RBT * root, int target)
{
	/*
	root	要插入的树
	target	要插入的值

	返回插入的新节点；
	*/

	if (root == NULL)
	{
		return new RBT(target, black);
	}

	RBT *p = NULL;//记录插入点的parent
	while (root)
	{
		if (root->val == target)
		{
			return NULL;//无需插入
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

	RBT *tmp = new RBT(target, red);
	if (p->val > target)
	{
		p->left = tmp;
	}
	else
	{
		p->right = tmp;
	}

	tmp->P = p;
	return tmp;
}



