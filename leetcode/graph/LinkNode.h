
#ifndef __LINKListNode_
#define __LINKListNode_

#include "head.h"
using namespace std;

void  print(ListNode *head);//打印

void  print(ListNode *list, unsigned int M);//打印M个，不够重复最后一个
void recoverTree(ListNode *root);//***************************************************************
vector<ListNode *> generateTrees(int n);//*******************************************************


ListNode *find(ListNode *list, unsigned int nth);//找到nth个节点
ListNode *ifcycle2(ListNode *list);//测试是否有环，返回起点--------------------------------------------9
ListNode *reorder(ListNode *list1, ListNode *list2); //调整顺序,详细:函数体中说明--------------------------10
ListNode *get_inv_tail(ListNode *list);//将链表从第 m=n/2+2个元素处(含)拆开，并将后面的反向，返回
ListNode *inorder(ListNode *list);//将链表反向
ListNode *reverseBetween(ListNode *head, int m, int n);//将第m到第n个节点之间(含)反序----------------22

ListNode *reverse(ListNode * head);
ListNode *reverseKGroup(ListNode *head, int k);//Reverse ListNodes in k-Group --------------------------36


ListNode *swapPairs(ListNode *head);//Swap ListNodes in Pairs --------------------------------------------35
ListNode *makelist(const int *arr, const unsigned int length);//以数组构造链表
ListNode *makelist(const vector<int> vi);//以数组构造链表
ListNode *mergeKLists(vector<ListNode *> &lists);//---------------------------------------------------46
ListNode *rotateRight(ListNode *list, int k);//链表循环右移-------------------------------------------25
ListNode *mergeTwoLists(ListNode *l1, ListNode *l2);//两个已排序链表合并----------------------------------26
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2);//两个链表相加----------------------------------------31
ListNode *copyRandomList(ListNode *head);//-----------------------------------------------------------72
ListNode *sortlist2(ListNode *list); //排序 冒泡n*n

ListNode *partition(ListNode *head, int x);//举例似乎有误，对比链表快速排序中的分隔算法
ListNode *Qpart(ListNode * &list, ListNode *fron = NULL, ListNode *tail = NULL);//快速排序分割----------------------56
ListNode *sortList(ListNode *head);
ListNode *merge(ListNode *head1, ListNode *head2);

void  rdfsl1(ListNode *list); //去掉重复，只留一个-------------------------------------------------6
void  rdfsl2(ListNode * &list);//去掉重复，不留本身------------------------------------------------7
void  rnfel(ListNode * & list, unsigned int nth);//去掉倒数第n个节点------------------------------23


void  Qsort(ListNode * &list, ListNode *fron = NULL, ListNode *tail = NULL);//快速排序-单向链表------------------4
void  sortlist1(ListNode * & list); //排序 插入排序-----------------------------------------------16
unsigned int getsize(ListNode *list);//返回节点数


int  makecycle(ListNode *list, unsigned int nth);//尾部指向nth，构造环
int  ifcycle1(ListNode *list);//测试是否有环，返回1/0----------------------------------------------8
ListNode *sortList(ListNode *head);


ListNode *getIntersectionNode(ListNode *headA, ListNode *headB);
#endif