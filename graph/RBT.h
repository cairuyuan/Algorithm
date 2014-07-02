
#ifndef __RBT_
#define __RBT_


#include <iostream>
#include <assert.h>
#include <ctime>
#include <stack>
#include <queue>
#include <map>

#define black 0
#define red   1


class RBT
{
public:
	int val;
	RBT *left;
	RBT *right;
	RBT *P;
	bool color;
public:
	RBT(void) :val(0), left(NULL), right(NULL), P(NULL), color(black){};
	RBT(int x, bool c) :val(x), left(NULL), right(NULL), P(NULL), color(c){};
	RBT(int x, RBT *l, RBT *r, bool c) :val(x), left(l), right(r), P(NULL), color(c){};
	RBT(int x, RBT *l, RBT *r, RBT *p, bool c) :val(x), left(l), right(r), P(p), color(c){};
	~RBT(void){};
};
RBT *nil = new RBT(~0, black);



inline RBT *gp(RBT *root);//
inline RBT *un(RBT *root);//

RBT * rotate_L(RBT *ROOT, RBT *n);//第一个参数是补加的，整个树的根 ，第二个是插入的节点
RBT * rotate_R(RBT *ROOT, RBT *n);//

RBT * insert_rbt(RBT * root, int target);

RBT * insert_case1(RBT *ROOT, RBT *n);//第一个参数是补加的，整个树的根 ，第二个是插入的节点
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