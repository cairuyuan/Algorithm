#ifndef __TREE_1_
#define __TREE_1_

#include "head.h"


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
vector<vector<int> > zigzagLevelOrder(TreeNode *root);

#endif