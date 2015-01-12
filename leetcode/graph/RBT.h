
#ifndef __RBT_
#define __RBT_


#include "head.h"
using namespace std;


inline RBT *gp(RBT *root);//
inline RBT *un(RBT *root);//
inline RBT *br(RBT *root);

void rotate_L(RBT *n);//��һ�������ǲ��ӵģ��������ĸ� ���ڶ����ǲ���Ľڵ�
void rotate_R(RBT *n);//

RBT * insert_rbt(RBT * root, int target);
void insert_case1(RBT *n);//��һ�������ǲ��ӵģ��������ĸ� ���ڶ����ǲ���Ľڵ�
void insert_case2(RBT *n);
void insert_case3(RBT *n);
void insert_case4(RBT *n);
void insert_case5(RBT *n);

RBT * delete_rbt(RBT * root, int target);
RBT * delete_fix(RBT * root, RBT * N);

void  postra(RBT *root);
void  pretra(RBT *root);
void  midtra(RBT *root);
void  print4(RBT *root);
void  print4_(RBT *root);

int  Depth(RBT *root);
bool isBalanced(RBT *root);//

#endif