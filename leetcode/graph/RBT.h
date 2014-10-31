
#ifndef __RBT_
#define __RBT_


#include "head.h"
using namespace std;


inline RBT *gp(RBT *root);//
inline RBT *un(RBT *root);//

RBT * rotate_L(RBT *ROOT, RBT *n);//��һ�������ǲ��ӵģ��������ĸ� ���ڶ����ǲ���Ľڵ�
RBT * rotate_R(RBT *ROOT, RBT *n);//

RBT * insert_rbt(RBT * root, int target);

RBT * insert_case1(RBT *ROOT, RBT *n);//��һ�������ǲ��ӵģ��������ĸ� ���ڶ����ǲ���Ľڵ�
RBT * insert_case2(RBT *ROOT, RBT *n);
RBT * insert_case3(RBT *ROOT, RBT *n);
RBT * insert_case4(RBT *ROOT, RBT *n);
RBT * insert_case5(RBT *ROOT, RBT *n);

RBT * delete_case1(RBT *ROOT, RBT *n);
RBT * delete_case2(RBT *ROOT, RBT *n);
RBT * delete_case3(RBT *ROOT, RBT *n);
RBT * delete_case4(RBT *ROOT, RBT *n);
RBT * delete_case5(RBT *ROOT, RBT *n);
RBT * delete_case6(RBT *ROOT, RBT *n);

RBT * deletetarget(RBT *ROOT, int target);
RBT * deletetarget2(RBT *ROOT, int target);
RBT * deletefixup(RBT *ROOT, RBT *X);
RBT * deletefixup2(RBT *ROOT, RBT *XP, RBT * X);

RBT * replace(RBT *root);


void  postra(RBT *root);
void  pretra(RBT *root);
void  midtra(RBT *root);
void  print4(RBT *root);
void  print4_(RBT *root);

int  Depth(RBT *root);
bool isBalanced(RBT *root);//


#endif