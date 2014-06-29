#ifndef __TREE_
#define __TREE_

#include <iostream>
#include <assert.h>
#include <ctime>
#include <stack>
#include <queue>
#include <map>

using namespace std;

class T
{
public:
	int var;
	T *L;
	T *R;
	T *next;

public:
	T(void) :var(0), L(NULL), R(NULL), next(NULL){};
	T(int x) :var(x), L(NULL), R(NULL), next(NULL){};
	T(int x, T *l, T *r) :var(x), L(l), R(r), next(NULL){};
	~T(void){ std::cout << "\ndelete :" << this->var << endl;; };
};


T *  searchinbst(T *root, int target);
void insert_bst(T *root, int target);
T *  delete_bst(T *root, int target);
bool isBalanced(T *root);//-------------------------------------------------------------------65
vector<T *>  morritra(T *root);//-------------------------------------------------------------80



T *sortedArrayToBST(int *arr, unsigned int n);//---------------------------------------------66
T *sortedArrayToBST(vector<int> &num);
//T *sortedListToBST(node *head);//-------------------------------------------------------------67
//T *sortedListToBST_(node *head,int n);
T *buildTree1(vector<int> &inorder, vector<int> &postorder);
T *buildTree2(vector<int> &preorder, vector<int> &inorder);
T *buildTree1(T ** pr, T ** in, int count);//---------------------------------------------------50
T *buildTree2(T ** in, T ** po, int count);//---------------------------------------------------51
T *maketree5(int a1[], int a2[], int a3[], int a4[], int a5[]);
T *maketree4(int a1[], int a2[], int a3[], int a4[]);
vector<T *>  itpostra(T *root);//������������--------------------------------------------------1
vector<T *>  itpretra(T *root);//����ǰ�����--------------------------------------------------2
vector<T *>  itmidtra(T *root);//�����������-------------------------------------------------29




void  print4(T *root);
void  print5(T *root);
void  postra(T *root);
void  pretra(T *root);
void  midtra(T *root);



void  print(vector<T *> v);
void  connect1(T *root);//--------------------------------------------------------------------60
void  connect2(T *root);//--------------------------------------------------------------------64
void  flatten(T *root);//������ת������-------------------------------------------------------21
int  sr2ln(T *root);//����·������֮��--------------------------------------------------------15

unsigned int mdbt(T * root);//��С���---------------------------------------------------------3
unsigned int mdbt2(T * root);//��С���-------------------------------------------------------19
unsigned int btmps(T *root);//·����----------------------------------------------------------13




bool ps(T *root, const int sum);//Path Sum --------------------------------------------------17

int Depth(T *root);

bool isSameTree(T *t1, T *t2);//�ж������Ƿ���ͬ----------------------------------------------27
bool isSymmetric(T *root);	//�ж��Ƿ�Գ�----------------------------------------------------30
bool isValidBST(T *root);//�ж��ǲ��Ƕ���������-----------------------------------------------28 

bool haschild(T *root);


vector<vector<int> > ps2(T *root, const int sum);//Path Sum2 --------------------------------18
vector<vector<int> > levelOrder1(T *root);//�������------------------------------------------19
vector<vector<int> > levelOrder2(T *root);//�������------------------------------------------20






#endif