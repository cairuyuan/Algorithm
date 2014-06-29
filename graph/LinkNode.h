
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


void  print(node *head);//��ӡ

void  print(node *list, unsigned int M);//��ӡM���������ظ����һ��
void recoverTree(node *root);//***************************************************************
vector<node *> generateTrees(int n);//*******************************************************


node *find(node *list, unsigned int nth);//�ҵ�nth���ڵ�
node *ifcycle2(node *list);//�����Ƿ��л����������--------------------------------------------9
node *reorder(node *list1, node *list2); //����˳��,��ϸ:��������˵��--------------------------10
node *get_inv_tail(node *list);//������ӵ� m=n/2+2��Ԫ�ش�(��)�𿪣���������ķ��򣬷���
node *inorder(node *list);//��������
node *reverseBetween(node *head, int m, int n);//����m����n���ڵ�֮��(��)����----------------22
node *reverseKGroup(node *head, int k);//Reverse Nodes in k-Group --------------------------36
node *swapPairs(node *head);//Swap Nodes in Pairs --------------------------------------------35
node *makelist(const int *arr, const unsigned int length);//�����鹹������
node *makelist(const vector<int> vi);//�����鹹������
node *mergeKLists(vector<node *> &lists);//---------------------------------------------------46
node *rotateRight(node *list, int k);//����ѭ������-------------------------------------------25
node *mergeTwoLists(node *l1, node *l2);//��������������ϲ�----------------------------------26
node *addTwoNumbers(node *l1, node *l2);//�����������----------------------------------------31
node *copyRandomList(node *head);//-----------------------------------------------------------72
node *sortlist2(node *list); //���� ð��n*n
node *partition(node *head, int x);//�����ƺ����󣬶Ա�������������еķָ��㷨
node *Qpart(node * &list, node *fron = NULL, node *tail = NULL);//��������ָ�----------------------56



void  rdfsl1(node *list); //ȥ���ظ���ֻ��һ��-------------------------------------------------6
void  rdfsl2(node * &list);//ȥ���ظ�����������------------------------------------------------7
void  rnfel(node * & list, unsigned int nth);//ȥ��������n���ڵ�------------------------------23


void  Qsort(node * &list, node *fron = NULL, node *tail = NULL);//��������-��������------------------4
void  sortlist1(node * & list); //���� ��������-----------------------------------------------16
unsigned int getsize(node *list);//���ؽڵ���



int  makecycle(node *list, unsigned int nth);//β��ָ��nth�����컷
int  ifcycle1(node *list);//�����Ƿ��л�������1/0----------------------------------------------8
vector<vector<int> > zigzagLevelOrder(node *root);//------------------------------------------59





#endif