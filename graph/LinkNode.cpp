#include "stdafx.h"

#include "LinkNode.h"

#include "head.h"

using namespace std;



node* makelist(const int *arr, const unsigned int length)
{

	if (arr == NULL || length == 0)
	{
		return NULL;
	}

	node *head, *p;
	p = head = new node(arr[0]);

	for (unsigned int i = 1; i < length; i += 1)
	{
		p->setnext(new node(arr[i]));
		p = p->getnext();
	}

	return head;
}


node* makelist(const vector<int> vi)
{

	int length = vi.size();
	if (length == 0)
	{
		return NULL;
	}

	node *head, *p;
	p = head = new node(vi[0]);

	for (int i = 1; i < length; i += 1)
	{
		p->setnext(new node(vi[i]));
		p = p->getnext();
	}

	return head;
}


void print(node *head)
{
	//参数中的 const 要求getvar需要加const

	std::cout << "\n--------------------------------------------------\n";
	while (head)
	{
		std::cout.width(4);
		std::cout << left << head->getvar();
		head = head->getnext();
	}
}


void print(node *list, unsigned int M)
{
	std::cout << "\n--------------------------------------------------\n";

	for (unsigned int i = 0; i<M; i += 1)
	{
		std::cout.width(4);
		std::cout << left << list->getvar();

		if (list->getnext())
		{
			list = list->getnext();
		}

	}
}


void sortlist1(node * &list)
{
	//Sort a linked list using insertion sort.
	if (!list)
	{
		return;
	}

	node *p;	//p是tail之后，要插入元素
	node *sp;
	node *tail = list;

	while (p = tail->getnext())
	{
		/*
		tail是已经排序部分的最后一个元素
		p是未排序部分第一个元素
		*/

		if (p->getvar() >= tail->getvar())
		{
			//p大于等于最大，插到尾部
			tail = p;
			continue;
		}

		if (p->getvar() <= list->getvar())
		{
			//p小于等于最小，查到首部
			tail->setnext(p->getnext());
			p->setnext(list);
			list = p;
			continue;
		}

		//插到中间，sp点之后
		sp = list;
		while ((sp->getnext())->getvar()<p->getvar())
		{
			//找到要插入的点，之前的点记录为sp
			sp = sp->getnext();
			//在排序部分查找元素
		}

		tail->setnext(p->getnext());//tail指向。。。更换p

		p->setnext(sp->getnext());
		sp->setnext(p);

	}

}


node* sortlist2(node *list)
{
	//冒泡

	if (!list || !list->getnext())
	{
		return list;
	}

	node *Head = list;//store list-head for return

	node *post;
	node *curr;
	node *prev;

	for (unsigned int i = 1; i<getsize(Head); i += 1)	//2 ele at least
	{
		//print(Head);

		post = Head;
		curr = post->getnext();
		prev = curr->getnext();

		if (curr->getvar()<post->getvar())
		{
			curr->setnext(post);
			post->setnext(prev);

			//rename
			post = curr;
			curr = post->getnext();

			Head = post;
		}

		while (prev)//冒泡一轮
		{
			if (prev->getvar()<curr->getvar())
			{
				//exchange
				curr->setnext(prev->getnext());
				prev->setnext(curr);
				post->setnext(prev);

				//re name
				curr = prev;
				prev = curr->getnext();
			}

			post = curr;
			curr = prev;
			prev = prev->getnext();
		}


	}
	return Head;
}


void  rdfsl1(node *list)
{
	/*
	Given a sorted linked list,
	delete all duplicates such that each element appear only once.
	For example,
	Given 1->1->2, return 1->2.
	Given 1->1->2->3->3, return 1->2->3.
	*/

	node *pre, *t;
	while (list && (pre = list->getnext()))
	{
		while (pre && (list->getvar()) == pre->getvar())
		{
			t = pre;
			pre = pre->getnext();
			delete t;
		}

		list->setnext(pre);
		list = list->getnext();

	}

}


void  rdfsl2(node * & list)
{

	/*
	Given a sorted linked list,
	delete all nodes that have duplicate numbers,
	leaving only distinct numbers from the original list.

	For example,
	Given 1->2->3->3->4->4->5, return 1->2->5.
	Given 1->1->1->2->3, return 2->3.
	*/



	if (!list || !list->getnext())// 0 or 1 
	{
		return;
	}

	//至少2个元素

	node *temp = NULL;

	node *p = list;

	node *Head = NULL;
	node *h = NULL;;

	//init
	temp = p;
	int count = 1;

	while (p = p->getnext())
	{
		if (p->getvar() != temp->getvar())
		{
			if (count == 1)
			{
				if (!Head)	Head = temp;
				else		h->setnext(temp);

				h = temp;
				h->setnext(NULL);
			}

			count = 1;
		}
		else
			count += 1;

		temp = p;
	}

	if (count == 1)
	{
		if (!Head)//Head,h:NULL
		{
			Head = temp;
		}
		else
		{
			h->setnext(temp);
			h = h->getnext();
			h->setnext(NULL);
		}
	}


	list = Head;
	return;
}


unsigned int getsize(node *list)
{
	unsigned int n = 0;

	while (list)
	{
		n += 1;
		list = list->getnext();
	}

	return n;
}


int   ifcycle1(node *list)
{
	/*
	Given a linked list, determine if it has a cycle in it.

	Follow up:
	Can you solve it without using extra space?
	*/
	node *p1 = list;
	node *p2 = list;

	node *t;
	while (p2)
	{
		p1 = p1->getnext();
		t = p2->getnext();
		if (!t)
		{
			break;
		}

		p2 = t->getnext();

		if (p1 == p2)
		{
			return 1;
		}
	}

	return 0;
}


node* ifcycle2(node *list)
{
	/*
	Given a linked list,
	return the node where the cycle begins.
	If there is no cycle, return null.

	Follow up:
	Can you solve it without using extra space?
	*/

	return NULL;
}


node *find(node *list, unsigned int nth)
{

	/*找到list中的第nth个节点
	如果超出范围返回NULL
	*/
	while (list)
	{
		list = list->getnext();
		if (--nth == 1)
		{
			return list;
		}

	}

	return NULL;
}


int makecycle(node *list, unsigned int nth)
{
	//把第nth个节点和尾部连接构成环；

	node *t = find(list, nth);
	if (!t)
	{
		return 0;//nth too big
	}

	while (list->getnext())
	{
		list = list->getnext();
	}

	list->setnext(t);
	return 1;

}


node *Qpart(node * &list, node *fron, node *tail)
{
	/*
	返回时：
	list指向队首，要重新设置
	返回值指向链表中的一个元素，之前的元素更小，之后的元素更大或等于
	*/

	if (list == tail) //list==fron  :0
	{
		return NULL;
	}

	if (list->getnext() == tail) //list==fron->getnext()  :
	{
		return NULL;
	}


	node *mid = list;
	node *p = list;
	node *pp;

	while ((pp = p->getnext()) != tail)
	{
		if (pp->getvar()<mid->getvar())//取出pp
		{
			p->setnext(pp->getnext());
			pp->setnext(list);
			list = pp;
		}
		else
		{
			p = pp;
		}
	}

	if (fron)
	{
		fron->setnext(list);
	}

	if (tail)
	{
		p->setnext(tail);
	}

	return mid;
}


void Qsort(node * &list, node *fron, node *tail)
{
	node *mid = Qpart(list, fron, tail);
	//print(list);

	node *midn;
	if (mid)
	{
		midn = mid->getnext();

		Qsort(list, fron, mid);
		Qsort(midn, mid, tail);
	}

}


node *reorder(node *h1, node *h2)
{

	/*
	Given a singly linked list L: L0→L1→…→Ln-1→Ln,
	reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…
	You must do this in-place without altering the nodes' values.
	For example,
	Given {1,2,3,4}, reorder it to {1,4,2,3}.
	*/


	if (!h1)
	{
		return NULL;
	}

	node  *head = h1;
	node *t;

	while (h2)
	{
		//对于每一个h2，插入到h1之后
		t = h1->getnext();
		h1->setnext(h2);
		h1 = h1->getnext();

		h2 = h2->getnext();

		h1->setnext(t);
		h1 = h1->getnext();
	}

	return head;
}


node *get_inv_tail(node *list)
{
	unsigned int n = getsize(list);

	if (n<3)
	{
		return NULL;
	}

	unsigned int m = n / 2 + 2;

	for (unsigned int i = 1; i<m - 1; i += 1)
	{
		list = list->getnext();
	}

	node *t = list;
	list = list->getnext();
	t->setnext(NULL);

	return inorder(list);
}


node *inorder(node *list)
{

	node *head = NULL;;//head of reordered list
	node *t;   //the  isolate node

	while (list)
	{
		t = list;
		list = list->getnext();

		t->setnext(head);
		head = t;
	}

	return head;
}


node *reverseBetween(node *head, int m, int n)
{
	/*
	Reverse a linked list from position m to n. Do it in-place and in one-pass.

	For example:
	Given 1->2->3->4->5->NULL, m = 2 and n = 4,

	return 1->4->3->2->5->NULL.

	Note:
	Given m, n satisfy the following condition:
	1 ≤ m ≤ n ≤ length of list.
	*/

	if (!head)
	{
		return NULL;
	}

	node *p = head;
	for (int i = 1; i < m - 1; i += 1)
	{
		p = p->getnext();
		if (!p)	return head; //m过大 
	}

	node *prev;//pre是反转前一个节点指针
	if (m == 1)
	{
		prev = NULL;
	}
	else
	{
		prev = p;
		p = prev->getnext();
	}

	node *h = NULL;
	node *t;
	for (int i = m; i <= n; i += 1)
	{
		if (p == NULL)	break;//p指向要反转部分第一个节点
		t = p;
		p = p->getnext();
		t->setnext(h);
		h = t;
	}

	node *tail = (prev == NULL ? head : prev->getnext());
	tail->setnext(p);		//处理尾部

	if (prev == NULL)			//处理开头
	{
		head = h;
	}
	else
	{
		prev->setnext(h);
	}

	return head;
}



void  rnfel(node * & head, unsigned int nth)
{
	/*
	Given a linked list, remove the nth node from the end of list and return its head.
	For example,
	Given linked list: 1->2->3->4->5, and n = 2.

	After removing the second node from the end, the linked list becomes 1->2->3->5.
	Note:
	Given n will always be valid.
	Try to do this in one pass.
	*/

	node *list = head;

	if (!list)
	{
		return;
	}

	//at least 1

	unsigned int n = getsize(list);

	if (nth>n)
	{
		return;//too big
	}

	if (nth == n)
	{
		/*
		危险，当链表中只含有1个元素，删掉一个元素后，delete，原指针会变成野指针；
		已处理
		*/
		node *p = list;
		list = list->getnext();
		delete p;

		if (n == 1)
		{
			head = NULL;
		}

		return;
	}

	for (unsigned int i = 0; i<(n - nth - 1); i += 1)
	{
		list = list->getnext();
	}

	node *p = list->getnext();
	if (nth == 1)
	{
		list->setnext(NULL);
	}
	else
	{
		list->setnext(p->getnext());
	}
	delete p;
}



#define M 6
#define N 6

node *rotateRight(node *list, int k)
{
	/*
	Given a list, rotate the list to the right by k places,
	where k is non-negative.

	For example:
	Given 1->2->3->4->5->NULL and k = 2,
	return 4->5->1->2->3->NULL.
	*/
	if (list == NULL)
	{
		return NULL;
	}
	if (k <= 0)
	{
		return list;
	}


	int n = 1;
	node *p = list;
	while (p->getnext())
	{
		n += 1;
		p = p->getnext();
	}


	int j = (n - k) % N;
	j = j>0 ? j : N + j;
	for (int i = 0; i < j; i += 1)
	{
		p->setnext(list);
		list = list->getnext();
		p = p->getnext();
		p->setnext(NULL);
	}


	return list;
}




node *mergeTwoLists(node *l1, node *l2)
{

	if (l1 == NULL)	return l2;
	if (l2 == NULL)   return l1;

	node *head;
	node *tail;

	if (l1->getvar() < l2->getvar())
	{
		head = tail = l1;
		l1 = l1->getnext();
	}
	else
	{
		head = tail = l2;
		l2 = l2->getnext();
	}

	while (l1&&l2)
	{
		if (l1->getvar()<l2->getvar())
		{
			tail->setnext(l1);
			l1 = l1->getnext();

		}
		else
		{
			tail->setnext(l2);
			l2 = l2->getnext();
		}

		tail = tail->getnext();
	}

	l1 == NULL ? tail->setnext(l2) : tail->setnext(l1);

	return head;
}





node *addTwoNumbers(node *l1, node *l2)
{

	/*
	You are given two linked lists representing two non-negative numbers.
	The digits are stored in reverse order and each of their nodes contain a single digit.
	Add the two numbers and return it as a linked list.

	Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
	Output: 7 -> 0 -> 8
	*/

	int c = 0;
	int sum = 0;
	vector<int> vi;

	while (l1&&l2)
	{

		sum = l1->getvar() + l2->getvar();
		vi.push_back(c + sum % 10);
		c = (sum >= 10 ? 1 : 0);

		l1 = l1->getnext();
		l2 = l2->getnext();
	}
	node * p = (l1 == NULL ? l2 : l1);

	while (p)
	{
		vi.push_back(p->getvar() + c);
		p = p->getnext();
		c = 0;
	}

	if (c != 0)
	{
		vi.push_back(c);
	}

	return makelist(vi);
}





node *reverseKGroup(node *head, int k)
{
	/*
	Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

	If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

	You may not alter the values in the nodes, only nodes itself may be changed.

	Only constant memory is allowed.

	For example,
	Given this linked list: 1->2->3->4->5

	For k = 2, you should return: 2->1->4->3->5

	For k = 3, you should return: 3->2->1->4->5
	*/

	node *p = head;//即将处理的点
	node *tail;//k-group中已反序部分的尾部
	node *rest;//未反序部分的头
	node *thehead = NULL;//k-group已反序部分的头
	node *list = NULL;//总体的头
	node *prev = NULL;//k-group的前一个点

	if (k <= 1)
	{
		return head;
	}

	while (p)
	{
		tail = p;//一个K-group中的第一个元素（未反序）
		thehead = prev;
		for (int i = 0; i < k; i += 1)
		{
			if (p == NULL)
			{
				break;
			}
			rest = p->next;
			p->next = thehead;
			thehead = p;
			p = rest;
		}
		//prev ->[tail <- ..... <-thehead] p(=rest)
		if (list == NULL)
		{
			list = thehead;//剩下部分 以p为首
			head->next = p;

			prev = tail;//=head
			continue;
		}
		//prev ->[<-tail <- ..... <-thehead] p(=rest)  
		prev->next = thehead;
		tail->next = p;

		prev = tail;
	}

	return list;
}


node *swapPairs(node *head)
{
	/*
	Given a linked list, swap every two adjacent nodes and return its head.

	For example,
	Given 1->2->3->4, you should return the list as 2->1->4->3.

	Your algorithm should use only constant space.
	You may not modify the values in the list, only nodes itself can be changed.
	*/
	if (!head || !head->next) // 0 / 1
	{
		return head;
	}

	node *prev = head;
	node *fron = head->next;
	node *rest = head->next->next;

	//[prev front] rest
	head->next = fron->next;
	fron->next = prev;
	head = fron;

	while ((fron = rest) && fron->next)
	{
		rest = (fron->next)->next;//prev [front-> back]-> ~rest

		prev->next = fron->next;
		prev->next->next = fron;
		fron->next = rest;        //prev [back fron] ~rest

		prev = fron;
	}

	return head;
}




node *mergeKLists(vector<node *> &lists)
{
	/*
	Merge k sorted linked lists and return it as one sorted list.
	Analyze and describe its complexity.

	若平均长度为l
	则为 kl次

	总结点数  的线性函数
	*/
	node **min = NULL;
	node *head = NULL;
	node *tail = NULL;;

	unsigned int k = lists.size();;
	unsigned int i;
	while (true)
	{
		i = 0;
		for (; i < k; i++)
		{
			if (*(min = &lists[i]) != NULL)
			{
				break;
			}
		}

		if (i == k)
		{
			return head;
		}

		for (i += 1; i < k; i++)
		{
			if (lists[i] && (*min)->var > lists[i]->var)
			{
				min = &lists[i];
			}
		}

		head == NULL ? head = tail = *min : tail = tail->next = *min;

		(*min) = (*min)->next;

	}

	return head;
}



int lengthof(node * head)
{
	int i = 0;
	while (head)
	{
		i += 1;
	}

	return i;
}

/*
T *sortedListToBST_(node *head, int n)
{
	if (head == NULL || n <= 0)
	{
		return NULL;
	}

	if (n == 1)
	{
		return new T(head->var);
	}

	T *root;
	node *parent = head;
	for (int i = 0; i < n / 2; i += 1)
	{
		parent = parent->next;
	}

	root = new T(parent->var);

	root->L = sortedListToBST_(head, n / 2);
	root->R = sortedListToBST_(parent->next, n - n / 2 - 1);

	return root;
}


T *sortedListToBST(node *head)
{
	/*
	Given a singly linked list where elements are sorted in ascending order,
	convert it to a         height-balanced         BST.

	The worst-case time of build_binary_tree is O(n^{2})—if you feed it a sorted list of values,
	it chains them into a linked list with no left subtrees.
	For example, build_binary_tree([1, 2, 3, 4, 5]) yields the tree (1 (2 (3 (4 (5))))).

	树排序的问题使得CPU Cache性能较差，特别是当节点是动态内存分配时。
	堆排序的CPU Cache性能较好。
	

	return sortedListToBST_(head, lengthof(head));
}

*/



vector<vector<int> > zigzagLevelOrder(node *root)
{
	/*
	Given a binary tree, return the zigzag level order traversal of its nodes' values.
	(ie, from left to right, then right to left for the next level and alternate between).

	For example:
	Given binary tree {3,9,20,#,#,15,7},
	3
	/ \
	9  20
	/  \
	15   7
	return its zigzag level order traversal as:
	[
	[3],
	[20,9],
	[15,7]
	]
	confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.


	OJ's Binary Tree Serialization:
	The serialization of a binary tree follows a level order traversal,
	where '#' signifies a path terminator where no node exists below.

	Here's an example:
	1
	/ \
	2   3
	/
	4
	\
	5
	The above binary tree is serialized as "{1,2,3,#,#,4,#,#,5}".
	*/

	vector<vector<int> > vv;
	//在level order 的实现中加一个bool标记，
	//当添加一层时，根据标记决定，
	//	在vector<T *>尾部按RL添加-----从右向左读
	//  在vector<T *>头部按RL添加-----从左向右读

	return vv;
}


void recoverTree(node *root)
{
	/*
	Two elements of a binary search tree (BST) are swapped by mistake.

	Recover the tree without changing its structure.

	Note:
	A solution using O(n) space is pretty straight forward.
	Could you devise a constant space solution?
	confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.
	*/

}

node *partition(node *head, int x)
{
	/*
	Given a linked list and a value x,
	partition it such that all nodes less than x come before nodes greater than or equal to x.

	You should preserve the original relative order of the nodes in each of the two partitions.

	For example,好像有错误
	Given  1->4->3->2->5->2 and x = 3,
	return 1->2->2->4->3->5.
	*/

	node * scanp = head;
	node * tmp, *tmp2;
	node * pre = NULL;

	while (scanp && scanp->var < x)
	{
		pre = scanp;
		scanp = scanp->next;
	}

	//scanp 大于等于x

	while (scanp && scanp->next)
	{
		int xx = scanp->next->var;
		if (scanp->next->var < x)
		{
			tmp = scanp->next;
			scanp->next = tmp->next;

			if (pre == NULL)
			{
				pre = tmp;
				pre->next = head;
				head = pre;
			}
			else
			{
				tmp2 = pre->next;
				pre->next = tmp;
				pre = tmp;
				pre->next = tmp2;
			}
		}
		else
		{
			scanp = scanp->next;
		}

		print(head);
	}

	print(head);
	return head;

}



vector<node *> generateTrees(int n)
{
	/*
	Given n, generate all structurally unique BST's (binary search trees) that store values 1...n.

	For example,
	Given n = 3, your program should return all 5 unique BST's shown below.

	1         3     3      2      1
	\       /     /      / \      \
	3     2     1      1   3      2
	/     /       \                 \
	2     1         2                 3
	confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.
	*/

	vector<node *> vn;

	return vn;
}



node *copyRandomList(node *head)
{
	if (head == NULL)
	{
		return NULL;
	}

	node *p;
	node *pp;
	node *Head;

	p = head;
	while (p)
	{
		pp = p->next;
		p->next = new node(p->var);//复制 ，更普遍的情况，使用copy constructor
		p->next->next = pp;
		p = pp;
	}

	p = head;
	while (p)
	{
		pp = p->next;
		pp->random = p->random == NULL ? NULL : p->random->next;
		p = pp->next;
	}

	Head = head->next;
	pp = Head;
	p = Head->next;
	head->next = p;
	while (p)
	{
		pp->next = p->next;
		pp = pp->next;
		p->next = pp->next;
		p = p->next;
	}

	return Head;
}

