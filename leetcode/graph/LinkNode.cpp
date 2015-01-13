#include "stdafx.h"

#include "LinkNode.h"

ListNode *merge(ListNode *head1, ListNode *head2)
{
	/*
	head1��head2�Ѿ��źã��ϲ�
	*/

	ListNode *head = NULL;
	ListNode *p;

	if (head1 == NULL) return head2; 
	if (head2 == NULL) return head1; 
	/*�����������Ϊ��*/

	if (head1->val > head2->val)
	{
		head = p = head2;
		head2 = head2->next;
	}
	else
	{
		head = p = head1;
		head1 = head1->next;
	}//�������Сϵ��

	while (head1 && head2)
	{
		if (head1->val > head2->val)
		{
			p->next = head2;
			head2 = head2->next;
		}
		else
		{
			p->next = head1;
			head1 = head1->next;
		}
		p = p->next;
	}

	/*
	һ�������Ѿ�ΪNULL
	�����������һ���ƶ���
	p������������ǰһ���ڵ�
	*/
	p->next = head1 ? head1 : head2;
	return head;
}


ListNode * mergeSort(ListNode *head)
{
	if (!head || !head->next)	return head;

	ListNode *p = head, *q = head, *pre = NULL;
	while (q&&q->next != NULL)
	{
		q = q->next->next;
		pre = p;
		p = p->next;  
	}
	pre->next = NULL;

	ListNode *lhalf = mergeSort(head);
	ListNode *rhalf = mergeSort(p);  
	return merge(lhalf, rhalf); 
}

ListNode *sortList(ListNode *head)
{
	if (!head || !head->next)	return head;

	ListNode *p = head, *q = head, *pre = NULL;
	while (q&&q->next != NULL)
	{
		q = q->next->next;
		pre = p;
		p = p->next;
	}
	pre->next = NULL;

	ListNode *lhalf = sortList(head);
	ListNode *rhalf = sortList(p);
	return merge(lhalf, rhalf);
}



ListNode* makelist(const int *arr, const unsigned int length)
{

	if (arr == NULL || length == 0)
	{
		return NULL;
	}

	ListNode *head, *p;
	p = head = new ListNode(arr[0]);

	for (unsigned int i = 1; i < length; i += 1)
	{
		p->next=(new ListNode(arr[i]));
		p = p->next;
	}

	return head;
}


ListNode* makelist(const vector<int> vi)
{

	int length = vi.size();
	if (length == 0)
	{
		return NULL;
	}

	ListNode *head, *p;
	p = head = new ListNode(vi[0]);

	for (int i = 1; i < length; i += 1)
	{
		p->next=(new ListNode(vi[i]));
		p = p->next;
	}

	return head;
}


void print(ListNode *head)
{
	//�����е� const Ҫ��getval��Ҫ��const

	std::cout << "\n--------------------------------------------------\n";
	while (head)
	{
		std::cout.width(4);
		std::cout << left << head->val;
		head = head->next;
	}
}


void print(ListNode *list, unsigned int M)
{
	std::cout << "\n--------------------------------------------------\n";

	for (unsigned int i = 0; i<M; i += 1)
	{
		std::cout.width(4);
		std::cout << left << list->val;

		if (list->next)
		{
			list = list->next;
		}

	}
}


void sortlist1(ListNode * &list)
{
	//Sort a linked list using insertion sort.
	if (!list)
	{
		return;
	}

	ListNode *p;	//p��tail֮��Ҫ����Ԫ��
	ListNode *sp;
	ListNode *tail = list;

	while (p = tail->next)
	{
		/*
		tail���Ѿ����򲿷ֵ����һ��Ԫ��
		p��δ���򲿷ֵ�һ��Ԫ��
		*/

		if (p->val >= tail->val)
		{
			//p���ڵ�����󣬲嵽β��
			tail = p;
			continue;
		}

		if (p->val <= list->val)
		{
			//pС�ڵ�����С���鵽�ײ�
			tail->next=(p->next);
			p->next=(list);
			list = p;
			continue;
		}

		//�嵽�м䣬sp��֮��
		sp = list;
		while ((sp->next)->val<p->val)
		{
			//�ҵ�Ҫ����ĵ㣬֮ǰ�ĵ��¼Ϊsp
			sp = sp->next;
			//�����򲿷ֲ���Ԫ��
		}

		tail->next=(p->next);//tailָ�򡣡�������p

		p->next=(sp->next);
		sp->next=(p);

	}

}


ListNode* sortlist2(ListNode *list)
{
	//ð��

	if (!list || !list->next)
	{
		return list;
	}

	ListNode *Head = list;//store list-head for return

	ListNode *post;
	ListNode *curr;
	ListNode *prev;

	for (unsigned int i = 1; i<getsize(Head); i += 1)	//2 ele at least
	{
		//print(Head);

		post = Head;
		curr = post->next;
		prev = curr->next;

		if (curr->val<post->val)
		{
			curr->next=(post);
			post->next=(prev);

			//rename
			post = curr;
			curr = post->next;

			Head = post;
		}

		while (prev)//ð��һ��
		{
			if (prev->val<curr->val)
			{
				//exchange
				curr->next=(prev->next);
				prev->next=(curr);
				post->next=(prev);

				//re name
				curr = prev;
				prev = curr->next;
			}

			post = curr;
			curr = prev;
			prev = prev->next;
		}


	}
	return Head;
}


void  rdfsl1(ListNode *list)
{
	/*
	Given a sorted linked list,
	delete all duplicates such that each element appear only once.
	For example,
	Given 1->1->2, return 1->2.
	Given 1->1->2->3->3, return 1->2->3.
	*/

	ListNode *pre, *t;
	while (list && (pre = list->next))
	{
		while (pre && (list->val) == pre->val)
		{
			t = pre;
			pre = pre->next;
			delete t;
		}

		list->next=(pre);
		list = list->next;

	}

}

ListNode *deleteDuplicates(ListNode * head) 
{
	if (head == NULL || head->next == NULL)
	{
		return head;
	}


	ListNode * ret		= NULL;
	ListNode * tail		= NULL;
	ListNode * p		= head;
	ListNode * todel;
	ListNode * tmp		= head;


	while (p = p->next)
	{ 
		if (p->val != tmp->val)
		{
			if (ret == NULL)//ͷ��
			{
				ret = tail = tmp;
			}
			else
			{
				tail->next = tmp;
				tail = tmp;
			}
			tail->next = NULL;
			tmp = p;
			continue;
		}

		while (p && p->val == tmp->val)
		{
			todel = p;
			p = p->next;
			delete todel;
		}
		delete tmp;

		if (p == NULL)//ĩβ������������ͬ�����
		{
			return ret;
		}
		else//p����
		{
			tmp = p;//tmp/p������һ���½׶εĿ�ʼ��Ҳ���������һ����Ч��
		}
	} 

	if (ret == NULL)
	{
		ret = tmp;
	}
	else
	{
		tail->next = tmp;
	}
	tmp->next = NULL;
	 
	return ret;
}

void  rdfsl2(ListNode * & list)
{

	/*
	Given a sorted linked list,
	delete all ListNodes that have duplicate numbers,
	leaving only distinct numbers from the original list.

	For example,
	Given 1->2->3->3->4->4->5, return 1->2->5.
	Given 1->1->1->2->3, return 2->3.
	*/



	if (!list || !list->next)// 0 or 1 
	{
		return;
	}

	//����2��Ԫ��

	ListNode *temp = NULL;

	ListNode *p = list;

	ListNode *Head = NULL;
	ListNode *h = NULL;;

	//init
	temp = p;
	int count = 1;

	while (p = p->next)
	{
		if (p->val != temp->val)
		{
			if (count == 1)
			{
				if (!Head)	Head = temp;
				else		h->next=(temp);

				h = temp;
				h->next=(NULL);
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
			h->next=(temp);
			h = h->next;
			h->next=(NULL);
		}
	}


	list = Head;
	return;
}




unsigned int getsize(ListNode *list)
{
	unsigned int n = 0;

	while (list)
	{
		n += 1;
		list = list->next;
	}

	return n;
}


int   ifcycle1(ListNode *list)
{
	/*
	Given a linked list, determine if it has a cycle in it.

	Follow up:
	Can you solve it without using extra space?
	*/
	ListNode *p1 = list;
	ListNode *p2 = list;

	ListNode *t;
	while (p2)
	{
		p1 = p1->next;
		t = p2->next;
		if (!t)
		{
			break;
		}

		p2 = t->next;

		if (p1 == p2)
		{
			return 1;
		}
	}

	return 0;
}


ListNode* ifcycle2(ListNode *list)
{
	/*
	Given a linked list,
	return the ListNode where the cycle begins.
	If there is no cycle, return null.

	Follow up:
	Can you solve it without using extra space?
	*/

	return NULL;
}


ListNode *find(ListNode *list, unsigned int nth)
{

	/*�ҵ�list�еĵ�nth���ڵ�
	���������Χ����NULL
	*/
	while (list)
	{
		list = list->next;
		if (--nth == 1)
		{
			return list;
		}

	}

	return NULL;
}


int makecycle(ListNode *list, unsigned int nth)
{
	//�ѵ�nth���ڵ��β�����ӹ��ɻ���

	ListNode *t = find(list, nth);
	if (!t)
	{
		return 0;//nth too big
	}

	while (list->next)
	{
		list = list->next;
	}

	list->next=(t);
	return 1;

}


ListNode *Qpart(ListNode * &list, ListNode *fron, ListNode *tail)
{
	/*
	����ʱ��
	listָ����ף�Ҫ��������
	����ֵָ�������е�һ��Ԫ�أ�֮ǰ��Ԫ�ظ�С��֮���Ԫ�ظ�������
	*/

	if (list == tail) //list==fron  :0
	{
		return NULL;
	}

	if (list->next == tail) //list==fron->next  :
	{
		return NULL;
	}


	ListNode *mid = list;
	ListNode *p = list;
	ListNode *pp;

	while ((pp = p->next) != tail)
	{
		if (pp->val<mid->val)//ȡ��pp
		{
			p->next=(pp->next);
			pp->next=(list);
			list = pp;
		}
		else
		{
			p = pp;
		}
	}

	if (fron)
	{
		fron->next=(list);
	}

	if (tail)
	{
		p->next=(tail);
	}

	return mid;
}


void Qsort(ListNode * &list, ListNode *fron, ListNode *tail)
{
	ListNode *mid = Qpart(list, fron, tail);
	//print(list);

	ListNode *midn;
	if (mid)
	{
		midn = mid->next;

		Qsort(list, fron, mid);
		Qsort(midn, mid, tail);
	}

}


ListNode *reorder(ListNode *h1, ListNode *h2)
{

	/*
	Given a singly linked list L: L0��L1������Ln-1��Ln,
	reorder it to: L0��Ln��L1��Ln-1��L2��Ln-2����
	You must do this in-place without altering the ListNodes' values.
	For example,
	Given {1,2,3,4}, reorder it to {1,4,2,3}.
	*/


	if (!h1)
	{
		return NULL;
	}

	ListNode  *head = h1;
	ListNode *t;

	while (h2)
	{
		//����ÿһ��h2�����뵽h1֮��
		t = h1->next;
		h1->next=(h2);
		h1 = h1->next;

		h2 = h2->next;

		h1->next=(t);
		h1 = h1->next;
	}

	return head;
}


ListNode *get_inv_tail(ListNode *list)
{
	unsigned int n = getsize(list);

	if (n<3)
	{
		return NULL;
	}

	unsigned int m = n / 2 + 2;

	for (unsigned int i = 1; i<m - 1; i += 1)
	{
		list = list->next;
	}

	ListNode *t = list;
	list = list->next;
	t->next=(NULL);

	return inorder(list);
}


ListNode *inorder(ListNode *list)
{

	ListNode *head = NULL;;//head of reordered list
	ListNode *t;   //the  isolate ListNode

	while (list)
	{
		t = list;
		list = list->next;

		t->next=(head);
		head = t;
	}

	return head;
}


ListNode *reverseBetween(ListNode *head, int m, int n)
{
	/*
	Reverse a linked list from position m to n. Do it in-place and in one-pass.

	For example:
	Given 1->2->3->4->5->NULL, m = 2 and n = 4,

	return 1->4->3->2->5->NULL.

	Note:
	Given m, n satisfy the following condition:
	1 �� m �� n �� length of list.
	*/

	if (!head)
	{
		return NULL;
	}

	ListNode *p = head;
	for (int i = 1; i < m - 1; i += 1)
	{
		p = p->next;
		if (!p)	return head; //m���� 
	}

	ListNode *prev;//pre�Ƿ�תǰһ���ڵ�ָ��
	if (m == 1)
	{
		prev = NULL;
	}
	else
	{
		prev = p;
		p = prev->next;
	}

	ListNode *h = NULL;
	ListNode *t;
	for (int i = m; i <= n; i += 1)
	{
		if (p == NULL)	break;//pָ��Ҫ��ת���ֵ�һ���ڵ�
		t = p;
		p = p->next;
		t->next=(h);
		h = t;
	}

	ListNode *tail = (prev == NULL ? head : prev->next);
	tail->next=(p);		//����β��

	if (prev == NULL)			//����ͷ
	{
		head = h;
	}
	else
	{
		prev->next=(h);
	}

	return head;
}



void  rnfel(ListNode * & head, unsigned int nth)
{
	/*
	Given a linked list, remove the nth ListNode from the end of list and return its head.
	For example,
	Given linked list: 1->2->3->4->5, and n = 2.

	After removing the second ListNode from the end, the linked list becomes 1->2->3->5.
	Note:
	Given n will always be valid.
	Try to do this in one pass.
	*/

	ListNode *list = head;

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
		Σ�գ���������ֻ����1��Ԫ�أ�ɾ��һ��Ԫ�غ�delete��ԭָ�����Ұָ�룻
		�Ѵ���
		*/
		ListNode *p = list;
		list = list->next;
		delete p;

		if (n == 1)
		{
			head = NULL;
		}

		return;
	}

	for (unsigned int i = 0; i<(n - nth - 1); i += 1)
	{
		list = list->next;
	}

	ListNode *p = list->next;
	if (nth == 1)
	{
		list->next=(NULL);
	}
	else
	{
		list->next=(p->next);
	}
	delete p;
}



#define M 6
#define N 6

ListNode *rotateRight(ListNode *list, int k)
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
	ListNode *p = list;
	while (p->next)
	{
		n += 1;
		p = p->next;
	}


	int j = (n - k) % N;
	j = j>0 ? j : N + j;
	for (int i = 0; i < j; i += 1)
	{
		p->next=(list);
		list = list->next;
		p = p->next;
		p->next=(NULL);
	}


	return list;
}




ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
{

	if (l1 == NULL)	return l2;
	if (l2 == NULL)   return l1;

	ListNode *head;
	ListNode *tail;

	if (l1->val < l2->val)
	{
		head = tail = l1;
		l1 = l1->next;
	}
	else
	{
		head = tail = l2;
		l2 = l2->next;
	}

	while (l1&&l2)
	{
		if (l1->val<l2->val)
		{
			tail->next=(l1);
			l1 = l1->next;

		}
		else
		{
			tail->next=(l2);
			l2 = l2->next;
		}

		tail = tail->next;
	}

	l1 == NULL ? tail->next=(l2) : tail->next=(l1);

	return head;
}





ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{

	/*
	You are given two linked lists representing two non-negative numbers.
	The digits are stored in reverse order and each of their ListNodes contain a single digit.
	Add the two numbers and return it as a linked list.

	Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
	Output: 7 -> 0 -> 8
	*/

	int c = 0;
	int sum = 0;
	vector<int> vi;

	while (l1&&l2)
	{

		sum = l1->val + l2->val;
		vi.push_back(c + sum % 10);
		c = (sum >= 10 ? 1 : 0);

		l1 = l1->next;
		l2 = l2->next;
	}
	ListNode * p = (l1 == NULL ? l2 : l1);

	while (p)
	{
		vi.push_back(p->val + c);
		p = p->next;
		c = 0;
	}

	if (c != 0)
	{
		vi.push_back(c);
	}

	return makelist(vi);
}
ListNode *reverse(ListNode * head)
{
	/*
	��head ��ͷ��������
	�����µ�����ͷ��
	�ڵ��ú����У�ԭ����head��ʱ�������β��
	*/
	
	ListNode * p;
	ListNode * pp;

	if (head == NULL || head->next == NULL)
	{
		return head;
	}

	p = head->next;
	head->next = NULL;
	while (pp = p->next)
	{
		p->next = head;
		head = p;
		p = pp;
	}
	p->next = head;
	return p;
}

ListNode *reverseKGroup(ListNode *head, int k)
{
	/*
	���ȴ���ǰ��K���ڵ㣬�����������
	Ȼ�����Ҫע���¼����ε�
	ǰһ���ڵ㣬ͷ�ڵ㣬β�ڵ㣬��һ���ڵ�
	*/
	
	/*
	���ڲ���K�Ĳ��ֲ��ܷ�ת��������Ҫ����Ĵ��ۣ����ȼ���
	*/

	ListNode * previous = NULL, *start = head, *tail = NULL, *theNext = head;
	ListNode * p;
	ListNode * ret = head;
	int i;

	while (true)
	{
		previous = tail;
		start = theNext;//��ǰһ�ε�β������ȡ��ʼ��Ϣ

		p = start;
		i = 0;
		while (p && ++i < k)
		{
			p = p->next;
		}

		if (i < k)
		{
			if (previous != NULL)
			{
				previous->next = start;
			}
			break;
		}
		
		tail = start;
		theNext = p->next;

		p->next = NULL;
		if (previous != NULL)
		{
			previous->next = reverse(start);//����ǰһ��
		}
		else
		{
			ret = reverse(start);
		}
	}

	return ret;
	
}


ListNode *swapPairs(ListNode *head)
{
	if (!head || !head->next) // 0 / 1
	{
		return head;
	}

	ListNode *prev = head;
	ListNode *fron = head->next;
	ListNode *rest = head->next->next;

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




ListNode *mergeKLists(vector<ListNode *> &lists)
{
	/*
	Merge k sorted linked lists and return it as one sorted list.
	Analyze and describe its complexity.

	��ƽ������Ϊl
	��Ϊ kl��

	�ܽ����  �����Ժ���
	*/
	ListNode **min = NULL;
	ListNode *head = NULL;
	ListNode *tail = NULL;;

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
			if (lists[i] && (*min)->val > lists[i]->val)
			{
				min = &lists[i];
			}
		}

		head == NULL ? head = tail = *min : tail = tail->next = *min;

		(*min) = (*min)->next;

	}

	return head;
}



int lengthof(ListNode * head)
{
	int i = 0;
	while (head)
	{
		i += 1;
	}

	return i;
}

void recoverTree(ListNode *root)
{
}

ListNode *partition(ListNode *head, int x)
{
	/*
	Given a linked list and a value x,
	partition it such that all ListNodes less than x come before ListNodes greater than or equal to x.

	You should preserve the original relative order of the ListNodes in each of the two partitions.

	For example,�����д���
	Given  1->4->3->2->5->2 and x = 3,
	return 1->2->2->4->3->5.
	*/

	ListNode * scanp = head;
	ListNode * tmp, *tmp2;
	ListNode * pre = NULL;

	while (scanp && scanp->val < x)
	{
		pre = scanp;
		scanp = scanp->next;
	}

	//scanp ���ڵ���x

	while (scanp && scanp->next)
	{
		int xx = scanp->next->val;
		if (scanp->next->val < x)
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



vector<ListNode *> generateTrees(int n)
{
	vector<ListNode *> vn;

	return vn;
}



ListNode *copyRandomList(ListNode *head)
{
	if (head == NULL)
	{
		return NULL;
	}

	ListNode *p;
	ListNode *pp;
	ListNode *Head;

	p = head;
	while (p)
	{
		pp = p->next;
		p->next = new ListNode(p->val);//���� �����ձ�������ʹ��copy constructor
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

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
	int la = 0;
	int lb = 0;
	int gap = 0;
	ListNode * p = NULL;
	ListNode * L = NULL;
	ListNode * S = NULL;

	p = headA;
	while (p)
	{
		la += 1;
		p = p->next;
	}

	p = headB;
	while (p)
	{
		lb += 1;
		p = p->next;
	}

	if (la > lb)
	{
		gap = la - lb;
		L = headA;
		S = headB;
	}
	else
	{
		gap = lb - la;
		S = headA;
		L = headB;
	}

	while (gap)
	{
		L = L->next;
		gap -= 1;
	}

	while (L && S && L != S)
	{
		L = L->next;
		S = S->next;
	}

	if (L == NULL)
	{
		return NULL;
	}
	else
	{
		return L;
	}
}