#ifndef __HEAD_
#define __HEAD_


#include <iostream>
#include <assert.h>
#include <ctime>
#include <stack>
#include <queue>
#include <map>
#include <unordered_set> 
#include <unordered_map> 
#include <set>
#include <list>
#include <iterator> 
#include <sstream>

using namespace std;

class TreeNode
{
public:
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode *next;

public:
	TreeNode(void) :val(0), left(NULL), right(NULL), next(NULL){};
	TreeNode(int x) :val(x), left(NULL), right(NULL), next(NULL){};
	TreeNode(int x, TreeNode *l, TreeNode *r) :val(x), left(l), right(r), next(NULL){};
	~TreeNode(void){ std::cout << "\ndelete :" << this->val << endl;; };
};

class ListNode
{
public:
	int  val;
	ListNode *next;
	ListNode *random;

public:
	ListNode(int x) :val(x), next(NULL), random(NULL){}
	ListNode(){}
	ListNode *getnext()const{ return next; }
	void  setnext(ListNode *pnext){ next = pnext; }
	int   getval()const{ return val; }
	void  setval(int x){ val = x; }
};




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



class UndirectedGraphNode
{
public:
	int label;
	vector<UndirectedGraphNode *> neighbors;
	UndirectedGraphNode(int x) : label(x) {};

};;


struct Interval
{
public:
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};



#endif