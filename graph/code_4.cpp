#include "stdafx.h"
#include "code_4.h"

int minDistance(const string &word1, const string &word2) 
{
	if (word1.length() < word2.length()) return minDistance(word2, word1);

	int *f = new int[word2.length() + 1];
	int upper_left = 0; // 额外用一个变量记录f[i-1][j-1]

	for (size_t i = 0; i <= word2.size(); ++i)
		f[i] = i;

	for (size_t i = 1; i <= word1.size(); ++i) 
	{
		upper_left = f[0];
		f[0] = i;
		for (size_t j = 1; j <= word2.size(); ++j) 
		{
			int upper = f[j];
			if (word1[i - 1] == word2[j - 1])
				f[j] = upper_left;
			else
				f[j] = 1 + min(upper_left, min(f[j], f[j - 1]));

			upper_left = upper;
		}
	}

	return f[word2.length()];
}

bool isaPalindrome(char * str)
{
	/*
	Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
	For example,
	"A man, a plan, a canal: Panama" is a palindrome.
	"race a car" is not a palindrome.

	Note:
	Have you consider that the string might be empty? This is a good question to ask during an interview.

	For the purpose of this problem, we define empty string as valid palindrome.
	*/

	//核心思想，利用栈,待优化
	if (str == 0 || *str == '\0')
	{
		return false;
	}

	char * s = str;
	char * p = str;
	while (*p)
	{
		cout << *p;
		p += 1;
	}

	p -= 1;
	while (true)
	{
		while (notchar(*p) && s<p)
		{
			p -= 1;
		}

		while (notchar(*s) && s<p)
		{
			s += 1;
		}


		if (s >= p)
		{
			return true;
		}

		if (!isequal(*s, *p))
		{
			return false;
		}

		p -= 1;
		s += 1;

	}

}

int rdfsa2(int * arr, int length)
{
	/*
	Remove Duplicates from Sorted Array II
	Follow up for "Remove Duplicates":
	What if duplicates are allowed at most twice?

	For example,
	Given sorted array A = [1,1,1,2,2,3],

	Your function should return length = 5, and A is now [1,1,2,2,3].
	*/

	if (!arr || length<3)
	{
		return length;
	}

	//sorted arr至少有三个元素
	// at most 2

	int *p = arr;
	int num = 1;
	for (int i = 1; i < length; i++)
	{
		if (arr[i] == *p && num == 1)
		{
			num = 2;
			*(++p) = arr[i];
		}

		if (arr[i] != *p)
		{
			num = 1;
			*(++p) = arr[i];

		}
	}

	return p - arr + 1;
}



vector<vector<int> > generate(int numRows)
{
	/*
	Given numRows, generate the first numRows of Pascal's triangle.

	For example, given numRows = 5,
	Return

	[
	[1],		1//
	[1,1],		2//0
	[1,2,1],		3//1
	[1,3,3,1],	4//2
	[1,4,6,4,1]	5//3
	]
	*/

	vector<vector<int> > vv;
	if (numRows <= 0)	return vv;

	vector<int> temp;

	temp.push_back(1);
	vv.push_back(temp);// for i=1

	for (int m, i = 2; i <= numRows; i += 1)
	{
		vector<int> vi;
		vi.push_back(1);
		for (int j = 2; j < i; j += 1)
		{
			m = temp.back();
			temp.pop_back();
			vi.push_back(m + temp.back());
		}
		vi.push_back(1);

		vv.push_back(vi);
		temp = vi;//效率损失比较大
	}

	return vv;
}



int divide(int dividend, int divisor)
{
	/*
	Divide two integers without using multiplication, division and mod operator.
	*/
	//最低端的用减法
	assert(divisor != 0);

	int tag;

	if (dividend >0 && divisor >0)
	{
		tag = 1;
	}
	else
		if (dividend >0 && divisor <0)
		{
		divisor = 0 - divisor;
		tag = -1;
		}
		else
			if (dividend <0 && divisor <0)
			{
		dividend = 0 - dividend;
		divisor = 0 - divisor;
		tag = 1;
			}
			else
				if (dividend <0 && divisor >0)
				{
		dividend = 0 - dividend;
		tag = -1;
				}


	int x = 0;
	while (dividend >= divisor)
	{
		x += 1;
		dividend -= divisor;
	}
	return x*tag;
}



char *multiply(char * num1, char *num2)
{

	/*
	确保
	1	除0-9字符外其他都不含
	2	0不出现在左端
	*/

	if (num1 == NULL || num2 == NULL)
	{
		return NULL;
	}

	int n1 = -1;
	int n2 = -1;
	while (num1[++n1]);
	while (num2[++n2]);

	if (n1 == 0 || n2 == 0)
	{
		return NULL;
	}

	char *sum = (char *)malloc(n1 + n2 + 1);
	char *p = NULL;
	for (int i = 0; i < n1 + n2; i++)
	{
		sum[i] = '0';
	}
	sum[n1 + n2] = '\0';
	/*
	num1  97
	*	num2  99
	-----------
	sum
	*/

	int c = 0;
	int s = 0;
	for (int i2 = n2 - 1; i2 >= 0; i2 -= 1)
	{
		c = 0;
		p = (sum + n1 + n2 - 1) - (n2 - 1 - i2);//=sum+n1+i2

		for (int i1 = n1 - 1; i1 >= 0; i1 -= 1)
		{
			//num2[i2] 和num1每个位 相乘
			s = (num2[i2] - '0')*(num1[i1] - '0') + c + (*p - '0');
			*p = s % 10 + '0';
			c = s / 10;
			p -= 1;
		}

		*p = c + '0';
	}


	return sum;
}



int minimumTotal(vector<vector<int> > &vv)
{
	/*
	Given a triangle, find the minimum path sum from top to bottom.
	Each step you may move to adjacent numbers on the row below.

	For example, given the following triangle
	[
	[2],
	[3,4],
	[6,5,7],
	[4,1,8,3]
	]
	The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

	Note:
	Bonus point if you are able to do this using only O(n) extra space,
	where n is the total number of rows in the triangle.
	*/

	if (vv.size() == 0)
	{
		return 0;
	}

	vector<int> pre_best(vv.size(), 0);
	pre_best[0] = vv[0][0];

	unsigned int layer;
	unsigned int LC;//layer count
	int  pi_1, tmp;

	for (layer = 1; layer < vv.size(); layer += 1)
	{
		/*
		当前处理layer层， 计算到layer层每个元素的最小代价
		*/
		LC = vv[layer].size();

		pi_1 = pre_best[0];
		pre_best[0] += vv[layer][0];

		for (unsigned int i = 1; i < LC - 1; i += 1)
		{
			//留出两头
			if (pi_1 > pre_best[i])
			{
				pi_1 = pre_best[i];
				pre_best[i] += vv[layer][i];
			}
			else
			{
				tmp = pi_1 + vv[layer][i];
				pi_1 = pre_best[i];
				pre_best[i] = tmp;
			}
		}
		pre_best[LC - 1] = pi_1 + vv[layer][LC - 1];
	}

	int ret = pre_best[0];

	for (unsigned int i = 1; i < pre_best.size(); i += 1)
	{
		if (ret > pre_best[i])
		{
			ret = pre_best[i];
		}
	}

	return ret;
}


int singleNumber1(int a[], int n)
{
	/*
	Given an array of integers, every element appears twice except for one.
	Find that single one.
	Note:
	Your algorithm should have a linear runtime complexity.
	Could you implement it without using extra memory?
	*/

	if (n == 0) return 0;
	int x = a[0];
	for (int i = 1; i < n; i++)
	{
		x ^= a[i];
	}

	return x;
}


int qpart(int *a, int length)
{
	if (a == NULL || length == 1)
	{
		return -1;
	}

	int i = 0;
	int j = length - 2;
	int *v = a + length - 1;
	int t;
	/*[2 2] 1
	[2 2] 3
	[2 1] 2
	[1 2] 2*/
	while (i<j)
	{
		if (a[i] <= *v)
		{
			i += 1;
			continue;
		}

		if (a[j]>*v)
		{
			j -= 1;
			continue;
		}
		t = a[j]; a[j] = a[i]; a[i] = t;

		i += 1;
		j -= 1;
	}

	if (a[i]>*v)
	{
		t = *v; *v = a[i]; a[i] = t;
	}

	return i;

}


void qsort(int *a, int length)
{
	if (length<2)
	{
		return;
	}
	int i = qpart(a, length);
	qsort(a, i + 1);
	qsort(a + i + 1, length - i - 1);
}


char *addBinary(char *s1, char *s2)
{
	/*
	Given two binary strings, return their sum (also a binary string).

	For example,
	a = "11"
	b = "1"
	Return "100".
	*/

	if (s1 == NULL || s2 == NULL)
	{
		return NULL;
	}

	int n1 = -1;
	int n2 = -1;
	while (s1[++n1]);
	while (s2[++n2]);

	int length = n1>n2 ? n1 : n2;
	char *p = (char *)malloc(2 + length);
	p[length + 1] = 0;

	/*
	s1    10
	+     s2    11
	--------------
	p    ___0
	*/

	int c = 0;
	int v, v1, v2;
	for (int i = 0; i < length; i += 1)
	{
		v1 = (i<n1 ? s1[n1 - 1 - i] - '0' : 0);
		v2 = (i<n2 ? s2[n2 - 1 - i] - '0' : 0);

		v = v1 + v2 + c;
		c = v / 2;
		p[length - i] = v % 2 + '0';
	}

	if (c == 1)
	{
		*p = c + '0';
		return p;
	}
	else
	{
		return p + 1;
	}
}


vector<int> plusOne(vector<int> &digits)
{
	/*
	Given a number represented as an array of digits, plus one to the number.
	*/
	vector<int> vi;
	/*
	[9 9]
	+	        [1]
	---------------

	v.insert(v.begin(),*);
	*/

	int c = 1;
	int n = digits.size();
	int v = 0;
	for (int i = 0; i < n; i += 1)
	{
		v = digits[n - 1 - i] + c;
		vi.insert(vi.begin(), v % 10);
		c = v / 10;
	}

	if (c == 1)
	{
		vi.insert(vi.begin(), c);
	}

	return vi;
}


char *simplifypath(char * path)
{
	/*
	Given an absolute path for a file (Unix-style), simplify it.

	For example,
	path = "/home/", => "/home"
	path = "/a/./b/../../c/", => "/c"
	click to show corner cases.

	Corner Cases:
	Did you consider the case where path = "/../"?
	In this case, you should return "/".
	Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
	In this case, you should ignore redundant slashes and return "/home/foo".

	. 当前目录
	..上级目录
	if(c-'A'>=0&&c-'Z'<=0)
	return false;

	if(c-'a'>=0&&c-'z'<=0)
	return false;
	*/

	if (path == NULL)
	{
		return NULL;
	}

	if (*path == '\0' || *path != '/')
	{
		return NULL;
	}

	vector<char *> sc;
	vector<int>    sl;
	char *s = path;

	int length;
	while (*s)
	{
		if (*s == '/')
		{
			s += 1;
			continue;
		}

		if (*s == '.' && *(s + 1) == '.')
		{
			if (sc.size()>0)
			{
				sc.pop_back();
				sl.pop_back();
			}
			s += 2;
			continue;
		}

		if (*s == '.')
		{
			s += 1;
			continue;
		}

		if (!notchar(*s))
		{
			length = 0;
			sc.push_back(s);
			while (!notchar(*(s++)))
			{
				length += 1;
			}
			sl.push_back(length);
			continue;
		}

		//other ascii
		return NULL;

	}


	cout << "\n";

	if (sc.size() == 0)
	{
		cout << '/';
		return NULL;
	}

	for (unsigned int i = 0; i < sc.size(); i++)
	{
		cout << '/';
		for (int j = 0; j < sl[i]; j++)
		{
			cout << sc[i][j];
		}
	}

	return NULL;
}



int magicindex(int A[], int length)
{
	/*
	A：递增，不重复
	如果 A[i]=i则是magic index
	如果重复怎么办？分别处理两侧，这使得性能下降到几乎O（n） T(n)= 2 * T(n/2) +c ---->顺序扫描更简单
	*/
	if (A == NULL)
	{
		return -1;
	}

	int i = 0;
	int j = length - 1;
	int m;
	/*
	int A[6]={ -1,2, 3 ,4,4,17};
	int A[6]={ 0 ,0, 1 ,2,5,17};
	*/
	while (i <= j)
	{
		m = (i + j) / 2;
		if (A[m] == m)
		{
			return m;
		}

		if (A[m] > m)
		{
			j = m - 1;
		}
		else//A[m] < m
		{
			i = m + 1;
		}
	}

	return -1;
}


void wangwochufa(int A[], int B[], const int length)
{
	if (A == NULL || B == NULL || length == 0)
	{
		return;
	}

	B[0] = 1;

	int i;
	for (i = 1; i < length; i += 1)
	{
		B[i] = B[i - 1];
		B[i] *= A[i - 1];
	}

	int tmp = 1;
	for (i = length - 1; i >= 0; i -= 1)
	{
		B[i] *= tmp;
		tmp *= A[i];
	}
}


void reverseWords(string &s)
{
	/*
	Given s = "the sky is blue",
	return "blue is sky the".
	*/



	int length = s.length();
	stack<string> ss;
	string tmp;
	int i = 0;

	while (i < length)
	{
		if (s[i] == ' ')
		{
			i += 1;
			continue;
		}



		while (i<length)
		{
			if (s[i] == ' ') //单词结束
			{
				ss.push(tmp);
				tmp.clear();
				break;
			}

			tmp.append(1, s[i]);
			i += 1;
		}

		i += 1;
	}

	if (tmp.length() != 0)
	{
		ss.push(tmp);
	}


	s.clear();
	while (!ss.empty())
	{
		s += ss.top();
		ss.pop();
		s += " ";
	}

	if (s.length())
	{
		s.erase(s.end() - 1, s.end());
	}

}


void reverseWords1(string &s)
{
	/*
	Given s = "the sky is blue",
	return "blue is sky the".
	*/



	int length = s.length();
	stack<string> ss;
	string tmp;
	int i = 0;

	while (i < length)
	{
		if (s[i] == ' ')
		{
			if (tmp.length() != 0)
			{
				ss.push(tmp);
				tmp.clear();
			}

			i += 1;
			continue;
		}

		tmp.append(1, s[i]);
		i += 1;
	}


	if (tmp.length() != 0)
	{
		ss.push(tmp);
	}


	s.clear();
	while (!ss.empty())
	{
		s += ss.top();
		ss.pop();
		s += " ";
	}

	if (s.length())
	{
		s.erase(s.end() - 1, s.end());
	}

}

void reverseWords2(string &s)
{
	/*
	Given s = "the sky is blue",
	return "blue is sky the".
	*/

	int length = 0;//trim_length
	string tmp;

	unsigned int i = ~0;
	while (++i <= s.length())
	{
		if (i == s.length() || s[i] == ' ')
		{
			if (tmp.length() != 0)
			{
				tmp += ' ';
				s.insert(0, tmp);
				length += tmp.length();
				i += tmp.length();
				tmp.clear();
			}
			continue;
		}

		tmp.append(1, s[i]);
	}

	if (s.length() != 0)
	{
		if (length != 0)
		{
			length -= 1;
		}
		s.erase(s.begin() + length, s.end());
	}



}


int Com(int n, int m)
{
	if (n > m)
	{
		std::cout << "n > m error\n";
		exit(-1);
	}

	if (n > m / 2)
	{
		return Com(m - n, m);
	}

	int *arr = (int *)malloc(n * sizeof(int));

	if (arr == NULL)
	{
		std::cout << "malloc error\n";
		exit(-1);
	}

	int i, ret = 1, length = n, d = n;

	for (i = 0; i < length; i += 1)
	{
		arr[i] = m--;
	}

	for (i = 0; i < length; i += 1)
	{
		for (int jj = 0; jj < length; jj += 1)
		{
			if (arr[jj] % d == 0)
			{
				arr[jj] /= d;
				break;
			}
		}

		d -= 1;
	}

	for (i = 0; i < length; i++)
	{
		ret *= arr[i];
	}
	return ret;
}



bool notchar(char c)
{
	if (c - 'A' >= 0 && c - 'Z' <= 0)
		return false;

	if (c - 'a' >= 0 && c - 'z' <= 0)
		return false;

	return true;
}


bool isequal(char c1, char c2)
{
	return (c1 == c2 ? true : false)
		|| (c1 - c2 == 'A' - 'a' ? true : false)
		|| (c2 - c1 == 'A' - 'a' ? true : false);
}

int C(int n, int m)
{
	//(m)
	//(n)
	assert(m >= 0 && n>0 && n >= m);
	m = (n - m)<m ? n - m : m;
	int u = 1;
	int d = 1;
	for (int j = 0; j < m; j++)
	{
		u *= n - j;
		d *= j + 1;
	}
	return u / d;
}

int climbStairs(int n)
{
	/*
	You are climbing a stair case. It takes n steps to reach to the top.

	Each time you can either climb 1 or 2 steps.
	In how many distinct ways can you climb to the top?
	*/
	if (n <= 0)
	{
		return -1;
	}
	int s = 0;
	int x;
	for (int i = 0; i <= n / 2; i += 1)
	{
		//2 :i
		//1 :j=n-i*2
		//m=i+j
		//C(i,m)=C(i,(i+n-i*2))=C(i,n-i);
		x = C(n - i, i);
		s += x;
	}

	return s;
}