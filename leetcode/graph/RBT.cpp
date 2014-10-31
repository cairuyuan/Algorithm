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

//插入点均默认红色
RBT * insert_case1(RBT *ROOT, RBT *root)
{
	/*
	新节点N位于树的根上，没有父节点。
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
	新节点的父节点P是黑色
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
下面假定新节点的父节点为红色，所以它有祖父节点；
因为如果父节点是根节点，那么父节点就应当是黑色。
所以新节点总有一个叔父节点，有可能是叶子 nil
*/
RBT * insert_case3(RBT *ROOT, RBT *root)
{
	/*
	父节点P是红色
	叔父节点是红色

	将它们两个重绘为黑色并重绘祖父节点G为红色
	在祖父节点 递归处理
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
	父节点P是红色(默认)
	叔父节点U是黑色或缺少，

	并且新节点N是其父节点P的右子节点而父节点P又是其父节点的左子节点
	对称情况

	进行一次左旋转调换新节点和其父节点的角色
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
	父节点P是红色而叔父节点U 是黑色或缺少，

	新节点N 是其父节点的左子节点，
	而父节点P又是祖父节点G的左子节点
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
	红黑树左旋:使得root-〉R取代root成为新的根节点
	*/

	//root ->p==null 怎么办

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
	红黑树右旋：使得root-〉L取代root成为新的根节点
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
	//调用者保证Z不空，且有右子树
	Z = Z->right;
	while (Z->left)
	{
		Z = Z->left;
	}

	return Z;
}


inline RBT *PRECEDENT(RBT * Z)
{
	//调用者保证Z不空，且有左子树
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
	ROOT 是树根
	target 要删除的值
	返回删除后的根
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
		return ROOT;//没找到
	}
	//以上找到target的节点Z


	RBT *Y;
	if (Z->left == NULL || Z->right == NULL)
	{
		//Z有：左、右、无儿子节点
		Y = Z;
	}
	else
	{
		//Z有两个子节点
		Y = SUCCESSOR(Z);//Y是X的右子树中的最左侧点
	}
	//Y仅有一个子节点或没有子节点
	//Y的值将被复制到Z，Y的内存对象将要被释放

	RBT *X;//X是Y仅有的子节点
	if (Y->left)
	{
		X = Y->left;
	}
	else
	{
		X = Y->right;
	}

	//X可能是NULL ，1 successor中发生	2 y==z本身没有子节点

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
		ROOT = X;//有删除点Z==Y 要删除的是根节点，
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
	//以上将Y从树中取出，并处理上:Y->P,X:下 连接关系

	if (Y != Z)//Y==Z发生于：Z只有左节点或者只有右节点，Y！=Z说明Y有两个子节点
	{
		//copy y's value to z
		Z->val = Y->val;
	}

	if (Y->color == black)//如果要删除的Y是红色，性质没有改变
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
	从树ROOT删除了X的Parent，调整属性
	*/

	if (ROOT == NULL)
	{
		//说明删除的节点，没有子节点
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



