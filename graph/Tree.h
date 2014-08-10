#ifndef __TREE_
#define __TREE_

#include <iostream>
#include <assert.h>
#include <ctime>
#include <stack>
#include <queue>
#include <map>

using namespace std;

class TreeNode
{
public:
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode *next;

public:
	TreeNode(void) :val(0), left(NULL), right(NULL), next(NULL){};
	TreeNode(int x) :val(x), left(NULL), right(NULL), next(NULL){};
	TreeNode(int x, TreeNode *l, TreeNode *r) :val(x), left(l), right(r), next(NULL){};
	~TreeNode(void){ std::cout << "\ndelete :" << this->val << endl;; };
};


TreeNode *  searchinbst(TreeNode *root, int target);
void insert_bst(TreeNode *root, int target);
TreeNode *  delete_bst(TreeNode *root, int target);
bool isBalanced(TreeNode *root);//-------------------------------------------------------------------65
vector<TreeNode *>  morritra(TreeNode *root);//-------------------------------------------------------------80



TreeNode *sortedArrayToBST(int *arr, unsigned int n);//---------------------------------------------66
TreeNode *sortedArrayToBST(vector<int> &num);
//T *sortedListToBST(ListNode *head);//-------------------------------------------------------------67
//T *sortedListToBST_(ListNode *head,int n);
TreeNode *buildTree1(vector<int> &inorder, vector<int> &postorder);
TreeNode *buildTree2(vector<int> &preorder, vector<int> &inorder);
TreeNode *buildTree1(TreeNode ** pr, TreeNode ** in, int count);//---------------------------------------------------50
TreeNode *buildTree2(TreeNode ** in, TreeNode ** po, int count);//---------------------------------------------------51

TreeNode *maketree5(int a1[], int a2[], int a3[], int a4[], int a5[]);
TreeNode *maketree4(int a1[], int a2[], int a3[], int a4[]);
vector<TreeNode *>  itpostra(TreeNode *root);//迭代后续遍历--------------------------------------------------1
vector<TreeNode *>  itpretra(TreeNode *root);//迭代前序遍历--------------------------------------------------2
vector<TreeNode *>  itmidtra(TreeNode *root);//迭代中序遍历-------------------------------------------------29




void  print4(TreeNode *root);
void  print5(TreeNode *root);
void  postra(TreeNode *root);
void  pretra(TreeNode *root);
void  midtra(TreeNode *root);



void  print(vector<TreeNode *> v);
void  connect1(TreeNode *root);//--------------------------------------------------------------------60
void  connect2(TreeNode *root);//--------------------------------------------------------------------64
void  flatten(TreeNode *root);//二叉树转成链表-------------------------------------------------------21
int  sr2ln(TreeNode *root);//所有路径数字之和--------------------------------------------------------15

unsigned int mdbt(TreeNode * root);//最小深度---------------------------------------------------------3
unsigned int mdbt2(TreeNode * root);//最小深度-------------------------------------------------------19
unsigned int btmps(TreeNode *root);//路径数----------------------------------------------------------13




bool ps(TreeNode *root, const int sum);//Path Sum --------------------------------------------------17

int Depth(TreeNode *root);

bool isSameTree(TreeNode *t1, TreeNode *t2);//判断两树是否相同----------------------------------------------27
bool isSymmetric(TreeNode *root);	//判断是否对称----------------------------------------------------30
bool isValidBST(TreeNode *root);//判断是不是二叉搜索树-----------------------------------------------28 

bool haschild(TreeNode *root);


vector<vector<int> > ps2(TreeNode *root, const int sum);//Path Sum2 --------------------------------18
vector<vector<int> > levelOrder1(TreeNode *root);//按层访问------------------------------------------19
vector<vector<int> > levelOrder2(TreeNode *root);//按层访问------------------------------------------20
vector<vector<int> > zigzagLevelOrder(TreeNode *root);



void recoverTree(TreeNode* root);
int   maxPathSum(TreeNode* root);


#endif