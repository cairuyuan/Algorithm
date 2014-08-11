#ifndef __TREE_1_
#define __TREE_1_

#include "head.h"


TreeNode *maketree5(int a1[], int a2[], int a3[], int a4[], int a5[]);
TreeNode *maketree4(int a1[], int a2[], int a3[], int a4[]);
vector<TreeNode *>  itpostra(TreeNode *root);//������������--------------------------------------------------1
vector<TreeNode *>  itpretra(TreeNode *root);//����ǰ�����--------------------------------------------------2
vector<TreeNode *>  itmidtra(TreeNode *root);//�����������-------------------------------------------------29

void  print4(TreeNode *root);
void  print5(TreeNode *root);
void  postra(TreeNode *root);
void  pretra(TreeNode *root);
void  midtra(TreeNode *root);

int  sr2ln(TreeNode *root);//����·������֮��--------------------------------------------------------15

unsigned int mdbt(TreeNode * root);//��С���---------------------------------------------------------3
unsigned int mdbt2(TreeNode * root);//��С���-------------------------------------------------------19
unsigned int btmps(TreeNode *root);//·����----------------------------------------------------------13

bool ps(TreeNode *root, const int sum);//Path Sum --------------------------------------------------17

int Depth(TreeNode *root);

bool isSameTree(TreeNode *t1, TreeNode *t2);//�ж������Ƿ���ͬ----------------------------------------------27
bool isSymmetric(TreeNode *root);	//�ж��Ƿ�Գ�----------------------------------------------------30
bool isValidBST(TreeNode *root);//�ж��ǲ��Ƕ���������-----------------------------------------------28 
bool haschild(TreeNode *root);

vector<vector<int> > ps2(TreeNode *root, const int sum);//Path Sum2 --------------------------------18
vector<vector<int> > zigzagLevelOrder(TreeNode *root);

#endif