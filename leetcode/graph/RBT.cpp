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
	if (grand )//grand parent ����ʱ�Ż���uncle
	{
		return (root->P == grand->left) ? grand->right : grand->left;
	}

	return NULL;// root ��root->PΪNULL���򲻿�����uncle
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

//����Ҫʹ��BST�Ĳ��뷨�����½ڵ㣬Ȼ��Ϳ�ɺ�ɫ  �����϶��ڵײ㣬�������С�ֶ�ӡ�
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
	insert_case3(N);//case 3 ��root->P->color != black,ie, red
}
/*
����ٶ��½ڵ�ĸ��ڵ�Ϊ��ɫ�����������游�ڵ�
*/
void insert_case3( RBT *N)
{
	/*
	���ڵ�P�Ǻ�ɫ
	�常�ڵ��Ǻ�ɫ

	�����������ػ�Ϊ��ɫ���ػ��游�ڵ�GΪ��ɫ
	���游�ڵ� �ݹ鴦��
	*/

	if (un(N) != NULL && un(N)->color == red)
	{
		N->P->color = black;
		un(N)->color = black;
		gp(N)->color = red;

		insert_case1(gp(N));
		return;
	}
	insert_case4(N);//uncle Ϊ��ɫ��NULL
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
	//Ҫ��� root P  ��gp��  root P�����������
	insert_case5(N);
}

void insert_case5(RBT *N)
{
	/*
	P�Ǻ죬U�Ǻ�
	root��P ͬ���ͬ��
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
	root ������ת
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
	root ������ת
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
	else//֮ǰ��parentΪ������
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
	if (!p) return root;//û�ҵ�

	//�ҵ�p�����,�����������ң�������������
	s = p;
	if (s->left)
	{
		s = s->left;
		while (s->right) s = s->right;
		p->val = s->val;
	}
	//ɾ����Ϊs,��������������������ǿ�
	//s���Ǹ��׵�������
	N = s->left;
	s->P->right = N;
	N->P = s->P;
	s->left = NULL;
	s->P = NULL;
	//��������滻

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
	//b ������������ɫ����ͬ��
	if (N == p->left)
	{
		if (b->right->color == black)//  �ڣ��ڣ��ѽ�����    �� ��
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
	root	Ҫ�������
	target	Ҫ�����ֵ

	���ز�����½ڵ㣻
	*/

	if (root == NULL)
	{
		return new RBT(target, black);
	}

	RBT *p = NULL;//��¼������parent
	while (root)
	{
		if (root->val == target)
		{
			return NULL;//�������
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



