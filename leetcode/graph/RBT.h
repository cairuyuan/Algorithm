
#ifndef __RBT_
#define __RBT_


#include "head.h"
using namespace std;


inline RBT *gp(RBT *root);//
inline RBT *un(RBT *root);//
inline RBT *br(RBT *root);

void rotate_L(RBT *n);//第一个参数是补加的，整个树的根 ，第二个是插入的节点
void rotate_R(RBT *n);//

RBT * insert_rbt(RBT * root, int target);
void insert_case1(RBT *n);//第一个参数是补加的，整个树的根 ，第二个是插入的节点
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