
#ifndef __LINKNODE_
#define __LINKNODE_

#include <iostream>
#include <assert.h>
#include <ctime>
#include <stack>
#include <queue>
#include <map>

using namespace std;


class node
{
public:
	int  var;
	node *next;
	node *random;

public:
	node(int x) :var(x), next(NULL), random(NULL){}
	node(){}
	//~node(){cout<<"dead ";};

public:
	node *getnext()const{ return next; }
	void  setnext(node *pnext){ next = pnext; }

	int   getvar()const{ return var; }
	void  setvar(int x){ var = x; }
};


void  print(node *head);//打印

void  print(node *list, unsigned int M);//打印M个，不够重复最后一个
void recoverTree(node *root);//***************************************************************
vector<node *> generateTrees(int n);//*******************************************************


node *find(node *list, unsigned int nth);//找到nth个节点
node *ifcycle2(node *list);//测试是否有环，返回起点--------------------------------------------9
node *reorder(node *list1, node *list2); //调整顺序,详细:函数体中说明--------------------------10
node *get_inv_tail(node *list);//将链表从第 m=n/2+2个元素处(含)拆开，并将后面的反向，返回
node *inorder(node *list);//将链表反向
node *reverseBetween(node *head, int m, int n);//将第m到第n个节点之间(含)反序----------------22
node *reverseKGroup(node *head, int k);//Reverse Nodes in k-Group --------------------------36
node *swapPairs(node *head);//Swap Nodes in Pairs --------------------------------------------35
node *makelist(const int *arr, const unsigned int length);//以数组构造链表
node *makelist(const vector<int> vi);//以数组构造链表
node *mergeKLists(vector<node *> &lists);//---------------------------------------------------46
node *rotateRight(node *list, int k);//链表循环右移-------------------------------------------25
node *mergeTwoLists(node *l1, node *l2);//两个已排序链表合并----------------------------------26
node *addTwoNumbers(node *l1, node *l2);//两个链表相加----------------------------------------31
node *copyRandomList(node *head);//-----------------------------------------------------------72
node *sortlist2(node *list); //排序 冒泡n*n
node *partition(node *head, int x);//举例似乎有误，对比链表快速排序中的分隔算法
node *Qpart(node * &list, node *fron = NULL, node *tail = NULL);//快速排序分割----------------------56



void  rdfsl1(node *list); //去掉重复，只留一个-------------------------------------------------6
void  rdfsl2(node * &list);//去掉重复，不留本身------------------------------------------------7
void  rnfel(node * & list, unsigned int nth);//去掉倒数第n个节点------------------------------23


void  Qsort(node * &list, node *fron = NULL, node *tail = NULL);//快速排序-单向链表------------------4
void  sortlist1(node * & list); //排序 插入排序-----------------------------------------------16
unsigned int getsize(node *list);//返回节点数



int  makecycle(node *list, unsigned int nth);//尾部指向nth，构造环
int  ifcycle1(node *list);//测试是否有环，返回1/0----------------------------------------------8
vector<vector<int> > zigzagLevelOrder(node *root);//------------------------------------------59





#endif