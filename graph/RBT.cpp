#include "stdafx.h"
#include "RBT.h"

using namespace std;









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
			cout << t1[i]->var;

			if (t1[i]->color == black)
			{
				cout << 'b';
			}
			else
			{
				cout << 'r';
			}
			t2[2 * i] = t1[i]->L;
			t2[2 * i + 1] = t1[i]->R;
		}
	}
	cout << "\n";



	for (int i = 0; i<2; i += 1)
	{
		if (t2[i] != nil)
		{
			cout << "      ";
			cout.width(3);
			cout << t2[i]->var;
			if (t2[i]->color == black)
			{
				cout << 'b';
			}
			else
			{
				cout << 'r';
			}
			cout << "       ";
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

		if (t3[i] != nil)
		{
			cout << "  ";
			cout.width(3);
			cout << t3[i]->var;
			if (t3[i]->color == black)
			{
				cout << 'b';
			}
			else
			{
				cout << 'r';
			}
			cout << "   ";

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

		if (t4[i] != nil)
		{
			cout.width(3);
			cout << t4[i]->var;
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
			cout << t1[i]->var;

			if (t1[i]->color == black)
			{
				cout << 'b';
			}
			else
			{
				cout << 'r';
			}
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
			cout << t2[i]->var;
			if (t2[i]->color == black)
			{
				cout << 'b';
			}
			else
			{
				cout << 'r';
			}
			cout << "       ";
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
			cout << t3[i]->var;
			if (t3[i]->color == black)
			{
				cout << 'b';
			}
			else
			{
				cout << 'r';
			}
			cout << "   ";

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
			cout << t4[i]->var;
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
	return root->P->P;
}


RBT *un(RBT *root)
{
	if (root->P == gp(root)->L)
	{
		return gp(root)->R;
	}
	else
	{
		return gp(root)->L;
	}
}

//������Ĭ�Ϻ�ɫ
RBT * insert_case1(RBT *ROOT, RBT *root)
{
	/*
	�½ڵ�Nλ�����ĸ��ϣ�û�и��ڵ㡣
	*/
	if (root->P == NULL)
	{
		root->color = black;
		return ROOT;
	}
	else
	{
		return insert_case2(ROOT, root);
	}
}


RBT * insert_case2(RBT *ROOT, RBT *root)
{
	/*
	�½ڵ�ĸ��ڵ�P�Ǻ�ɫ
	*/
	if (root->P->color == black)
	{
		return ROOT;
	}
	else
	{
		return insert_case3(ROOT, root);
	}
}

/*
����ٶ��½ڵ�ĸ��ڵ�Ϊ��ɫ�����������游�ڵ㣻
��Ϊ������ڵ��Ǹ��ڵ㣬��ô���ڵ��Ӧ���Ǻ�ɫ��
�����½ڵ�����һ���常�ڵ㣬�п�����Ҷ�� nil
*/
RBT * insert_case3(RBT *ROOT, RBT *root)
{
	/*
	���ڵ�P�Ǻ�ɫ
	�常�ڵ��Ǻ�ɫ

	�����������ػ�Ϊ��ɫ���ػ��游�ڵ�GΪ��ɫ
	���游�ڵ� �ݹ鴦��
	*/

	if (un(root) != NULL && un(root)->color == red)
	{
		root->P->color = black;
		un(root)->color = black;
		gp(root)->color = red;

		return insert_case1(ROOT, gp(root));
	}
	else
	{
		return insert_case4(ROOT, root);
	}
}


RBT * insert_case4(RBT *ROOT, RBT *root)
{
	/*
	���ڵ�P�Ǻ�ɫ(Ĭ��)
	�常�ڵ�U�Ǻ�ɫ��ȱ�٣�

	�����½ڵ�N���丸�ڵ�P�����ӽڵ�����ڵ�P�����丸�ڵ�����ӽڵ�
	�Գ����

	����һ������ת�����½ڵ���丸�ڵ�Ľ�ɫ
	*/

	if (root == root->P->R && root->P == gp(root)->L)
	{
		//rote_left(root->p)
		ROOT = rotate_L(ROOT, root->P);
		root = root->L;
	}
	else
		if (root == root->P->L && root->P == gp(root)->R)
		{
		//rote_right(root->p)
		ROOT = rotate_R(ROOT, root->P);
		root = root->R;
		}

	return insert_case5(ROOT, root);
}



RBT * insert_case5(RBT *ROOT, RBT *root)
{
	/*
	���ڵ�P�Ǻ�ɫ���常�ڵ�U �Ǻ�ɫ��ȱ�٣�

	�½ڵ�N ���丸�ڵ�����ӽڵ㣬
	�����ڵ�P�����游�ڵ�G�����ӽڵ�
	*/

	root->P->color = black;
	gp(root)->color = red;

	if (root == root->P->L && root->P == gp(root)->L)
	{
		return rotate_R(ROOT, gp(root));
		//rote_right(gp(root))
	}

	if (root == root->P->R && root->P == gp(root)->R)
	{
		return rotate_L(ROOT, gp(root));
		//rote_left(gp(root))
	}

	cout << "error";
	return ROOT;
}



RBT * rotate_L(RBT *ROOT, RBT *root)
{
	/*
	���������:ʹ��root-��Rȡ��root��Ϊ�µĸ��ڵ�
	*/

	//root ->p==null ��ô��

	RBT * rootR = root->R;
	RBT * rp = root->P;

	if (rp == NULL)
	{

		root->P = rootR;
		root->R = rootR->L;
		//(root->L)
		if (root->R != NULL)
		{
			root->R->P = root;
		}
		rootR->P = rp;
		rootR->L = root;
		//(root->R)

		return rootR;
	}

	if (rp->L == root)
	{
		rp->L = rootR;
	}
	else
	{
		rp->R = rootR;
	}
	rootR->P = rp;

	root->P = rootR;
	root->R = rootR->L;
	//(root->L)
	if (root->R != NULL)
	{
		root->R->P = root;
	}

	rootR->L = root;
	//rootE->R
	//rootR->P

	return ROOT;
}



RBT * rotate_R(RBT *ROOT, RBT *root)
{
	/*
	�����������ʹ��root-��Lȡ��root��Ϊ�µĸ��ڵ�
	*/

	RBT * rootL = root->L;
	RBT * rp = root->P;

	if (rp == NULL)
	{
		root->P = rootL;
		root->L = rootL->R;
		//root->R

		if (root->L != NULL)
		{
			root->L->P = root;
		}

		rootL->P = rp;
		rootL->R = root;
		//(rootL->L)

		return rootL;
	}

	if (rp->L == root)
	{
		rp->L = rootL;
	}
	else
	{
		rp->R = rootL;
	}
	rootL->P = rp;

	root->P = rootL;
	root->L = rootL->R;
	//root->R
	if (root->L != NULL)
	{
		root->L->P = root;
	}

	rootL->R = root;
	//rootL->P
	//rootL->L

	return ROOT;
}


inline RBT *SUCCESSOR(RBT * Z)
{
	//�����߱�֤Z���գ�����������
	Z = Z->R;
	while (Z->L)
	{
		Z = Z->L;
	}

	return Z;
}


inline RBT *PRECEDENT(RBT * Z)
{
	//�����߱�֤Z���գ�����������
	Z = Z->L;
	while (Z->R)
	{
		Z = Z->R;
	}

	return Z;
}


RBT * deletetarget(RBT *ROOT, int target)
{
	/*
	ROOT ������
	target Ҫɾ����ֵ
	����ɾ����ĸ�
	*/

	RBT *Z = ROOT;

	while (Z)
	{
		if (Z->var == target)
		{
			break;
		}

		if (Z->var > target)
		{
			Z = Z->L;
		}
		else
		{
			Z = Z->R;
		}
	}

	if (Z == NULL)
	{
		return ROOT;//û�ҵ�
	}
	//�����ҵ�target�Ľڵ�Z


	RBT *Y;
	if (Z->L == NULL || Z->R == NULL)
	{
		//Z�У����ҡ��޶��ӽڵ�
		Y = Z;
	}
	else
	{
		//Z�������ӽڵ�
		Y = SUCCESSOR(Z);//Y��X���������е�������
	}
	//Y����һ���ӽڵ��û���ӽڵ�
	//Y��ֵ�������Ƶ�Z��Y���ڴ����Ҫ���ͷ�

	RBT *X;//X��Y���е��ӽڵ�
	if (Y->L)
	{
		X = Y->L;
	}
	else
	{
		X = Y->R;
	}

	//X������NULL ��1 successor�з���	2 y==z����û���ӽڵ�

	if (X == NULL)
	{
		;
	}
	else
	{
		X->P = Y->P;
	}


	if (Y->P == NULL)
	{
		ROOT = X;//��ɾ����Z==Y Ҫɾ�����Ǹ��ڵ㣬
	}
	else
		if (Y == Y->P->L)
		{
		Y->P->L = X;
		}
		else
		{
			Y->P->R = X;
		}
	//���Ͻ�Y������ȡ������������:Y->P,X:�� ���ӹ�ϵ

	if (Y != Z)//Y==Z�����ڣ�Zֻ����ڵ����ֻ���ҽڵ㣬Y��=Z˵��Y�������ӽڵ�
	{
		//copy y's value to z
		Z->var = Y->var;
	}

	if (Y->color == black)//���Ҫɾ����Y�Ǻ�ɫ������û�иı�
	{
		ROOT = deletefixup(ROOT, X);
		//ROOT=delete_case1(ROOT,X);
	}

	delete Y;
	return ROOT;
}


RBT *prefixup(RBT *ROOT, RBT *XP)
{
	//X is NULL

	if (XP->color == black)
	{

	}

	return NULL;
}



RBT * deletefixup(RBT *ROOT, RBT *X)
{
	/*
	����ROOTɾ����X��Parent����������
	*/

	if (ROOT == NULL)
	{
		//˵��ɾ���Ľڵ㣬û���ӽڵ�
		return ROOT;
	}
	RBT *W;
	while (X != ROOT && X->color == black)
	{
		if (X == X->P->L)
		{
			W = X->P->R;

			if (W->color == red)//case 1
			{
				W->color = black;
				X->P->color = red;
				ROOT = rotate_L(ROOT, X->P);
				W = X->P->R;
			}

			if (W->L->color == black &&  W->R->color == black)//case 2
			{
				W->color = red;
				X = X->P;
			}
			else
			{
				if (W->R->color == black)//case 3
				{
					W->L->color = black;
					W->color = red;
					ROOT = rotate_R(ROOT, W);
					W = X->P->R;
				}

				W->color = X->P->color;//case 4
				X->P->color = black;
				W->R->color = black;
				ROOT = rotate_L(ROOT, X->P);
				X = ROOT;
			}
		}
		else//X==X->P->L
		{
			W = X->P->L;

			if (W->color == red)//case 1
			{
				W->color = black;
				X->P->color = red;
				ROOT = rotate_R(ROOT, X->P);
				W = X->P->L;
			}

			if (W->R->color == black &&  W->L->color == black)//case 2
			{
				W->color = red;
				X = X->P;
			}
			else
			{
				if (W->L->color == black)//case 3
				{
					W->R->color = black;
					W->color = red;
					ROOT = rotate_L(ROOT, W);
					W = X->P->L;
				}

				W->color = X->P->color;//case 4
				X->P->color = black;
				W->L->color = black;
				ROOT = rotate_R(ROOT, X->P);
				X = ROOT;
			}
		}
	}

	X->color = black;

	return ROOT;
}


inline RBT * brather(RBT * N)
{
	if (N == N->P->L)
	{
		return N->P->R;
	}
	else
	{
		return N->P->L;
	}
}


RBT * deletefixup2(RBT *ROOT, RBT *XP, RBT * X)
{


	return NULL;
}


RBT * delete_case1(RBT *ROOT, RBT *n)
{
	return NULL;
}
RBT * delete_case2(RBT *ROOT, RBT *n)
{
	return NULL;
}
RBT * delete_case3(RBT *ROOT, RBT *n)
{
	return NULL;
}
RBT * delete_case4(RBT *ROOT, RBT *n)
{
	return NULL;
}
RBT * delete_case5(RBT *ROOT, RBT *n)
{
	return NULL;
}
RBT * delete_case6(RBT *ROOT, RBT *n)
{
	return NULL;
}

void   postra(RBT *root)
{
	if (root)
	{
		postra(root->L);

		postra(root->R);

		cout.width(4);
		cout << root->var;
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
		cout << root->var;
		if (root->color == black)
		{
			cout << 'b';
		}
		else
		{
			cout << 'r';
		}

		pretra(root->L);

		pretra(root->R);
	}
}



void  midtra(RBT *root)
{
	if (root)
	{
		midtra(root->L);

		cout.width(4);
		cout << root->var;
		if (root->color == black)
		{
			cout << 'b';
		}
		else
		{
			cout << 'r';
		}
		midtra(root->R);
	}
}

int Depth(RBT *root)
{

	if (root == NULL)
	{
		return 0;
	}

	int l = Depth(root->L);
	int r = Depth(root->R);

	return  1 + (l>r ? l : r);

}




bool isBalanced(RBT *root)
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
		if (root->var == target)
		{
			return NULL;//�������
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

	RBT *tmp = new RBT(target, red);
	if (p->var > target)
	{
		p->L = tmp;
	}
	else
	{
		p->R = tmp;
	}

	tmp->P = p;
	return tmp;
}



