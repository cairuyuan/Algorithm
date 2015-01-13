
#ifndef __LINKListNode_
#define __LINKListNode_

#include "head.h"
using namespace std;

void  print(ListNode *head);//��ӡ

void  print(ListNode *list, unsigned int M);//��ӡM���������ظ����һ��
void recoverTree(ListNode *root);//***************************************************************
vector<ListNode *> generateTrees(int n);//*******************************************************


ListNode *find(ListNode *list, unsigned int nth);//�ҵ�nth���ڵ�
ListNode *ifcycle2(ListNode *list);//�����Ƿ��л����������--------------------------------------------9
ListNode *reorder(ListNode *list1, ListNode *list2); //����˳��,��ϸ:��������˵��--------------------------10
ListNode *get_inv_tail(ListNode *list);//������ӵ� m=n/2+2��Ԫ�ش�(��)�𿪣���������ķ��򣬷���
ListNode *inorder(ListNode *list);//��������
ListNode *reverseBetween(ListNode *head, int m, int n);//����m����n���ڵ�֮��(��)����----------------22

ListNode *reverse(ListNode * head);
ListNode *reverseKGroup(ListNode *head, int k);//Reverse ListNodes in k-Group --------------------------36


ListNode *swapPairs(ListNode *head);//Swap ListNodes in Pairs --------------------------------------------35
ListNode *makelist(const int *arr, const unsigned int length);//�����鹹������
ListNode *makelist(const vector<int> vi);//�����鹹������
ListNode *mergeKLists(vector<ListNode *> &lists);//---------------------------------------------------46
ListNode *rotateRight(ListNode *list, int k);//����ѭ������-------------------------------------------25
ListNode *mergeTwoLists(ListNode *l1, ListNode *l2);//��������������ϲ�----------------------------------26
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2);//�����������----------------------------------------31
ListNode *copyRandomList(ListNode *head);//-----------------------------------------------------------72
ListNode *sortlist2(ListNode *list); //���� ð��n*n

ListNode *partition(ListNode *head, int x);//�����ƺ����󣬶Ա�������������еķָ��㷨
ListNode *Qpart(ListNode * &list, ListNode *fron = NULL, ListNode *tail = NULL);//��������ָ�----------------------56
ListNode *sortList(ListNode *head);
ListNode *merge(ListNode *head1, ListNode *head2);

void  rdfsl1(ListNode *list); //ȥ���ظ���ֻ��һ��-------------------------------------------------6
void  rdfsl2(ListNode * &list);//ȥ���ظ�����������------------------------------------------------7
void  rnfel(ListNode * & list, unsigned int nth);//ȥ��������n���ڵ�------------------------------23


void  Qsort(ListNode * &list, ListNode *fron = NULL, ListNode *tail = NULL);//��������-��������------------------4
void  sortlist1(ListNode * & list); //���� ��������-----------------------------------------------16
unsigned int getsize(ListNode *list);//���ؽڵ���


int  makecycle(ListNode *list, unsigned int nth);//β��ָ��nth�����컷
int  ifcycle1(ListNode *list);//�����Ƿ��л�������1/0----------------------------------------------8
ListNode *sortList(ListNode *head);


ListNode *getIntersectionNode(ListNode *headA, ListNode *headB);
#endif