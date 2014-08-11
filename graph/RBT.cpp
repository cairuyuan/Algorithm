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
	return root->P->P;
}


RBT *un(RBT *root)
{
	if (root->P == gp(root)->left)
	{
		return gp(root)->right;
	}
	else
	{
		return gp(root)->left;
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

	if (root == root->P->right && root->P == gp(root)->left)
	{
		//rote_left(root->p)
		ROOT = rotate_L(ROOT, root->P);
		root = root->left;
	}
	else
		if (root == root->P->left && root->P == gp(root)->right)
		{
		//rote_right(root->p)
		ROOT = rotate_R(ROOT, root->P);
		root = root->right;
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

	if (root == root->P->left && root->P == gp(root)->left)
	{
		return rotate_R(ROOT, gp(root));
		//rote_right(gp(root))
	}

	if (root == root->P->right && root->P == gp(root)->right)
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

	RBT * rootR = root->right;
	RBT * rp = root->P;

	if (rp == NULL)
	{

		root->P = rootR;
		root->right = rootR->left;
		//(root->left)
		if (root->right != NULL)
		{
			root->right->P = root;
		}
		rootR->P = rp;
		rootR->left = root;
		//(root->right)

		return rootR;
	}

	if (rp->left == root)
	{
		rp->left = rootR;
	}
	else
	{
		rp->right = rootR;
	}
	rootR->P = rp;

	root->P = rootR;
	root->right = rootR->left;
	//(root->left)
	if (root->right != NULL)
	{
		root->right->P = root;
	}

	rootR->left = root;
	//rootE->right
	//rootR->P

	return ROOT;
}



RBT * rotate_R(RBT *ROOT, RBT *root)
{
	/*
	�����������ʹ��root-��Lȡ��root��Ϊ�µĸ��ڵ�
	*/

	RBT * rootL = root->left;
	RBT * rp = root->P;

	if (rp == NULL)
	{
		root->P = rootL;
		root->left = rootL->right;
		//root->right

		if (root->left != NULL)
		{
			root->left->P = root;
		}

		rootL->P = rp;
		rootL->right = root;
		//(rootL->left)

		return rootL;
	}

	if (rp->left == root)
	{
		rp->left = rootL;
	}
	else
	{
		rp->right = rootL;
	}
	rootL->P = rp;

	root->P = rootL;
	root->left = rootL->right;
	//root->right
	if (root->left != NULL)
	{
		root->left->P = root;
	}

	rootL->right = root;
	//rootL->P
	//rootL->left

	return ROOT;
}


inline RBT *SUCCESSOR(RBT * Z)
{
	//�����߱�֤Z���գ�����������
	Z = Z->right;
	while (Z->left)
	{
		Z = Z->left;
	}

	return Z;
}


inline RBT *PRECEDENT(RBT * Z)
{
	//�����߱�֤Z���գ�����������
	Z = Z->left;
	while (Z->right)
	{
		Z = Z->right;
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
		if (Z->val == target)
		{
			break;
		}

		if (Z->val > target)
		{
			Z = Z->left;
		}
		else
		{
			Z = Z->right;
		}
	}

	if (Z == NULL)
	{
		return ROOT;//û�ҵ�
	}
	//�����ҵ�target�Ľڵ�Z


	RBT *Y;
	if (Z->left == NULL || Z->right == NULL)
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
	if (Y->left)
	{
		X = Y->left;
	}
	else
	{
		X = Y->right;
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
		if (Y == Y->P->left)
		{
		Y->P->left = X;
		}
		else
		{
			Y->P->right = X;
		}
	//���Ͻ�Y������ȡ������������:Y->P,X:�� ���ӹ�ϵ

	if (Y != Z)//Y==Z�����ڣ�Zֻ����ڵ����ֻ���ҽڵ㣬Y��=Z˵��Y�������ӽڵ�
	{
		//copy y's value to z
		Z->val = Y->val;
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
		if (X == X->P->left)
		{
			W = X->P->right;

			if (W->color == red)//case 1
			{
				W->color = black;
				X->P->color = red;
				ROOT = rotate_L(ROOT, X->P);
				W = X->P->right;
			}

			if (W->left->color == black &&  W->right->color == black)//case 2
			{
				W->color = red;
				X = X->P;
			}
			else
			{
				if (W->right->color == black)//case 3
				{
					W->left->color = black;
					W->color = red;
					ROOT = rotate_R(ROOT, W);
					W = X->P->right;
				}

				W->color = X->P->color;//case 4
				X->P->color = black;
				W->right->color = black;
				ROOT = rotate_L(ROOT, X->P);
				X = ROOT;
			}
		}
		else//X==X->P->left
		{
			W = X->P->left;

			if (W->color == red)//case 1
			{
				W->color = black;
				X->P->color = red;
				ROOT = rotate_R(ROOT, X->P);
				W = X->P->left;
			}

			if (W->right->color == black &&  W->left->color == black)//case 2
			{
				W->color = red;
				X = X->P;
			}
			else
			{
				if (W->left->color == black)//case 3
				{
					W->right->color = black;
					W->color = red;
					ROOT = rotate_L(ROOT, W);
					W = X->P->left;
				}

				W->color = X->P->color;//case 4
				X->P->color = black;
				W->left->color = black;
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
	if (N == N->P->left)
	{
		return N->P->right;
	}
	else
	{
		return N->P->left;
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



