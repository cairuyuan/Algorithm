// SortList.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "head.h"
#include "Tree.h"
#include "LinkNode.h"

using namespace std;

bool wordBreak(string s, unordered_set<string> &dic);
int decode(string s);
int lengthOfLastWord(const char *s);
bool isMatch(const char *s, const char *p);
string getPermutation(int n, int k);
ListNode *deleteDuplicates(ListNode * head);
vector<int> grayCode(int n);
TreeNode *sortedListToBST(ListNode *head);

int _tmain(int argc, _TCHAR* argv[])
{
	int a[5] = {2,1,3};
	ListNode *root = makelist(a,3);
	//print(root);
	//cout << "\n----------\n";
	TreeNode *Troot = sortedListToBST(root);
	print4(Troot);
	connect1(Troot);
	//zigzagLevelOrder(Troot);
	//root = deleteDuplicates(root);
	//print(root);
	

	return 0;   
}

TreeNode * packfun(ListNode * head, int count)//count 是个数
{

	/*
	退出条件
	*/

	if (count == 0)
	{
		return NULL;
	}

	ListNode * mid = head;
	for (int i = 0; i < count/2; i++)
	{
		mid = mid->next;
	}
	//此时mid在中间位置 count/2

	TreeNode *root = new TreeNode(mid->val);
	root->left = packfun(head,count/2);
	root->right = packfun(mid->next,count-count/2-1);

	return root;
}



TreeNode *sortedListToBST(ListNode *head)
{
	if (head ==NULL)
	{
		return NULL;
	}
	int n = 0;
	ListNode * p = head;
	while (p)
	{
		n += 1;
		p = p->next;
	}

	return packfun(head,n);
}



vector<int> grayCode(int n) 
{
	/*
	n位格雷码
	使用n个bit返回可以表示的格雷码序列
	格雷码两个数字之间只有一个bit不相同
	*/

	vector<int> ret(1,0);

	int num;
	for (int i = 1; i <= n; i++)
	{
		/*
		计算有i位的格雷码
		*/
		num = 1 << (i-1);//i-1位的格雷码共有num个码
		for (int j = 0; j < num; j++)
		{
			ret.push_back(ret[num - 1 - j] | num);
		}

	}
	return ret;
}

string getPermutation(int n, int k)
{
	/*
	1到n（n<10）个数字全排，的第k个
	*/
	int A[10];A[0] = 1;
	vector<char> C;
	for (size_t i = 1; i < 10; i++)
	{
		A[i] = i* A[i - 1];
		C.push_back( i + '0');
	}
	string s;
	int x;
	k -= 1;

	for (size_t i = 0; i < n; i++)
	{
		x = k / A[n - 1];
		s += C[x];
		C.erase(C.begin() + x);
		k %= A[n - 1];
		n -= 1;
	}

	return s;
}
bool isMatch(const char *s, const char *p)
{
	int i = 0;//s
	int j = 0;//p

	while (p[j])
	{
		switch (p[j])
		{
		case '?':
			if (s[i] == 0)
			{
				return false;
			}
			break;

		case '*':


			//*
			if (p[j+1] == 0)
			{
				return true;
			}
			else
			{
				return false;
			}
			break;

		default:
			if (p[j] != s[i])
			{
				return false;
			}
			break;
		}
		i += 1;
		j += 1;
	}

	return s[i] ? false : true;
}

bool wordBreak(string s, unordered_set<string> &dic)
{

	std::unordered_set<std::string>::const_iterator get;
	int sLength = s.size();
	int right = 0;
	string tmp;
	stack<int> index;
	int start;

	while (true)
	{
		
		tmp += s[right];
		//cout<< tmp.size()<<'\t'<< index.size() << '\n';
		get = dic.find(tmp);
		if (get != dic.end())
		{
			//匹配
			index.push(right);
			tmp.clear();

			if (right == sLength - 1)
			{
				return true;
			}
		}

		if (right == sLength - 1)
		{
			if (index.empty())
			{
				return false;
			}

			right = index.top();
			index.pop();
			start = index.empty() ? 0 : index.top() + 1;

			tmp = string(s, start, right - start + 1);//从index[top]+1下表开始(包含) 复制right - index[top]个

		}

		right += 1;
	}
}


int decode(string s)
{

	int s1 = 1;
	int s2 = 1;
	int result = 1;//只有一个非零数字
	
	int n = s.size();
	if (n == 0|| s[0] == '0')
	{
		return 0;
	}

	int i = 0;
	while (++i < n)
	{
		if (s[i] != '0')
		{
			if (   s[i - 1] == '1' && s[i] <= '9'
				|| s[i - 1] == '2' && s[i] <= '6'
				)
			{
				result = s2 + s1;
				s1 = s2;
				s2 = result;
			}
			else
			{
				s1 = result = s2;
				
			}
			
		}
		else
		{
			if (s[i-1] == '1' || s[i-1] == '2')
			{
				if (s2 > s1)
				{
					s2 -= s1;
				}
				
				result = s2;
				/*无需处理s1，下一步要么错误，要么不可向前结合，不会用到s1*/
			}
			else
			{
				return 0;
			}
		}

		
		
	}

	return result;
}

int lengthOfLastWord(const char *s)
{
	int length = 0;
	int state = 0;

	int i = 0;

	while (s[i] != 0)
	{
		switch (state)
		{
		case 0:
			s[i] == ' ' ? 0 : length = state = 1;
			break;

		case 1:
			s[i] == ' ' ? state = 0 : length += 1;
			break;

		default:
			break;
		}
		i += 1;
	}

	return length;
}
