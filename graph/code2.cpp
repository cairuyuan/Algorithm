#include "stdafx.h"
#include "head.h"

#include "code2.h"

using namespace std;


void  print(vector<vector<int> > vv)
{
	vector<int> cell;
	for (unsigned int i = 0; i < vv.size(); i++)
	{
		cout << '\n';
		for (unsigned int j = 0; j < vv[i].size(); j++)
		{
			cout.width(4);
			cout << left << vv[i][j];
		}
	}
}


void  print(vector<int> v)
{
	cout << '\n';
	for (unsigned int j = 0; j < v.size(); j++)
	{
		cout.width(4);
		cout << left << v[j];
	}
}



void  print(int v[], int length)
{
	if (v == NULL)
	{
		return;
	}
	cout << '\n';

	for (int j = 0; j < length; j++)
	{
		cout.width(4);
		cout << left << v[j];
	}
}





int  *randarr(int *arr, const unsigned int N, const int X)
{
	/*
	要包含ctime头文件
	*/

	if (!arr)
	{
		return NULL;
	}

	for (unsigned int i = 0; i<N; i += 1)
	{
		if (arr[i] != ~0)
		{
			srand((unsigned int)time(NULL) + i * 20);
			arr[i] = rand() % X;
		}
	}

	return arr;
}



int revint(int x)
{
	/*
	Reverse digits of an integer.

	Example1: x = 123, return 321
	Example2: x = -123, return -321

	click to show spoilers.Have you thought about this?
	Here are some good questions to ask before coding.
	Bonus points for you if you have already thought through this!
	If the integer's last digit is 0, what should the output be? ie, cases such as 10, 100.
	Did you notice that the reversed integer might overflow? Assume the input is a 32-bit integer,
	then the reverse of 1000000003 overflows. How should you handle such cases?
	Throw an exception? Good, but what if throwing an exception is not an option?
	You would then have to re-design the function (ie, add an extra parameter).
	*/


	/*
	存在问题，溢出！
	*/

	cout << "\n" << x;

	int t = 0;
	while (x)
	{
		t = t * 10 + x % 10;
		x /= 10;
	}
	cout << " --> " << t;
	return t;
}


unsigned int rdfsa(int * arr, unsigned int length)
{
	/*
	Given a sorted array, remove the duplicates in place such that each element appear only once and      return the new length.
	Do not allocate extra space for another array, you must do this in place with constant memory.
	For example,
	Given input array A = [1,1,2],
	Your function should return length = 2, and A is now [1,2].
	*/

	//arr is sorted
	if (!arr)
	{
		return 0;
	}

	if (length <= 1)
	{
		return length;
	}

	int *pp = &arr[1];

	unsigned int n = length;

	for (unsigned int i = 1; i <= length - 1; i += 1)
	{
		if (*arr == *pp)
		{
			n -= 1;
		}
		else
		{
			arr += 1;
			*arr = *pp;
		}

		pp += 1;
	}

	return n;
}



void  msa(int a[], unsigned int m, int b[], unsigned int n)
{
	/*
	Given two sorted integer arrays A and B, merge B into A as one sorted array.

	Note:
	You may assume that A has enough space to hold additional elements from B.
	The number of elements initialized in A and B are m and n respectively.
	*/
	return;
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

bool isValid(char * s)
{
	/*
	Given a string containing just the characters '(', ')', '{', '}', '[' and ']',
	determine if the input string is valid.
	The brackets must close in the correct order,
	"()" and "()[]{}" are all valid but "(]" and "([)]" are not.
	*/

#define mactch(c)  {if (sc.top()==c){sc.pop();break;} else return false;}

	stack<char> sc;
	sc.push('#');

	while (*s)
	{
		switch (*s)
		{
		case '(':
		case '[':
		case '{':
			sc.push(*s);
			break;

		case ')':
			mactch('(');
		case ']':
			mactch('[');
		case '}':
			mactch('{');

		default:
			break;
		}

		s += 1;
	}

	if (sc.top() == '#')
	{
		return true;
	}
	else
	{
		return false;
	}

	//#undef  mactch(c)
}


double pows(double x, int n)
{
	/*
	Implement pow(x, n).
	*/

	assert(!(x == 0 && n == 0));

	double s = 1.0;
	do
	{
		if (n & 0x01)
		{
			s *= x;
		}

		x = x*x;
	} while (n = n >> 1);

	return s;
}


float invsqrts(float x)
{
	/*
	Implement int sqrt(int x).
	Compute and return the square root of x.
	*/

	//C数学函数库中的sqrt具有理想的精度，但速度太慢

	float xhalf = 0.5f*x;
	int i = *(int*)&x;
	i = 0x5f3759df - (i >> 1);        // 计算第一个近似根
	x = *(float*)&i;
	x = x*(1.5f - xhalf*x*x);       // 牛顿迭代法

	return x;
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


vector<int> getRow(int rowIndex)
{
	/*
	Given an index k, return the kth row of the Pascal's triangle.

	For example, given k = 3,
	Return [1,3,3,1].



	Note:
	Could you optimize your algorithm to use only O(k) extra space?
	*/
	vector<int> veci;
	if (rowIndex == 0)
	{
		return veci;
	}

	int *v1 = new int[rowIndex];
	int *v2 = new int[rowIndex + 1];
	int *p;

	v2[0] = 1;

	for (int i = 2; i <= rowIndex + 1; i += 1)
	{

		v1[0] = 1;
		for (int j = 2; j < i; j += 1)
		{
			v1[j - 1] = v2[j - 2] + v2[j - 1];
		}
		v1[i - 1] = 1;

		p = v2;
		v2 = v1;
		v1 = p;
	}


	for (int i = 0; i < rowIndex + 1; i++)
	{
		veci.push_back(v2[i]);
	}

	delete v1, v2;

	return veci;
}


int removeElement(int a[], int n, int elem)
{
	/*
	Given an array and a value, remove all instances of that value in place and return the new length.
	The order of elements can be changed. It doesn't matter what you leave beyond the new length.
	*/

	if (a == NULL)
	{
		return -1;
	}

	if (n == 0)
	{
		return 0;
	}

	if (n == 1 && a[0] == elem)
	{
		return 0;
	}

	int num = 0;
	int i = 0, j = n - 1;
	int temp;

	while (i <= j)
	{
		if (a[i] != elem)
		{
			i += 1;
			continue;
		}

		if (a[j] == elem)
		{
			j -= 1;
			num += 1;
			continue;
		}

		temp = a[j];
		a[j] = a[i];
		a[i] = temp;

		i += 1;
		j -= 1;

		num += 1;
	}

	return n - num;
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


string multiply(string num1, string num2)
{
	/*
	Given two numbers represented as strings, return multiplication of the numbers as a string.
	Note: The numbers can be arbitrarily large and are non-negative.
	*/
	/*
	num1
	*	num2
	-----------
	sum
	*/

	//已通过下面的char版本实现
	const int length = num1.size() + num2.size();
	string sum(length, '\0');


	return sum;
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


vector<vector<int> > subsets(vector<int> &S)
{
	vector<vector<int> > vv;
	//[1,2,3,4,5,6]

	return vv;
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


int singleNumber3(int A[], int n)
{
	/*
	Given an array of integers, every element appears three times except for one.
	Find that

	single one.

	Note:
	Your algorithm should have a linear runtime complexity.
	Could you implement it without using extra memory?
	*/

	return 0;
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


vector<int> twoSum(vector<int> &numbers, int target)
{
	/*
	Given an array of integers,
	find two numbers such that they add up to a specific target number.
	The function twoSum should return indices of the two numbers such that they add up to the target,
	where index1 must be less than index2.
	Please note that your returned answers (both index1 and index2) are not zero-based.
	You may assume that each input would have exactly one solution.
	Input: numbers={2, 7, 11, 15}, target=9
	Output: index1=1, index2=2
	*/


	/*
	逐个搜索
	最快1次
	最慢 (n-1)+(n-2).....(2)  =(n-1-2+1)*(n-1+2)/2=(n-2)(n+1)/2
	*/

	/*
	1 排序 nlgn
	2 确定范围 n
	3 逐个二分查找

	nlgn + n +nlgn --> nlgn
	*/
	vector<int> vi(2, 0);
	//int len = numbers.size();
	//assert(len >=2);
	//vector<int> vi(2,0);

	//map<int,int> m;
	//vector<int ,int> mul(len,0);

	//for (int i = 0; i < len; i++)
	//{
	// mul[i]=(target-numbers[i])*numbers[i];

	// if (m[mul[i]] > 0)
	// {
	//	 if (numbers[i] + numbers[m[mul[i]]] == target)
	//	 {
	//		 vi[0]=m[mul[i]];
	//		 vi[1]=i+1;
	//		 break;
	//	 }
	// }
	// else
	// {
	//	 m[mul[i]] = i + 1;
	// }
	//}

	return vi;
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


vector<vector<int> > permute(vector<int> &num)
{
	/*
	Given a collection of numbers, return all possible permutations.

	For example,
	[1,2,3] have the following permutations:

	[1,2,3],
	[1,3,2],

	[2,1,3],
	[2,3,1],

	[3,1,2], and
	[3,2,1].
	*/



	vector<vector<int> > vv;
	vector<vector<int> > pa;
	vector<int> temp;
	unsigned int n = num.size();
	if (n == 1)
	{
		temp.push_back(num[0]);
		vv.push_back(temp);
		return vv;
	}


	for (unsigned int i = 0; i < n; i++)
	{
		temp.clear();
		for (unsigned int k = i + 1, j = 0; j < n; j++)
		{
			temp.push_back(num[k%n]);
			k += 1;
		}
		temp.pop_back();
		pa.push_back(temp);
	}

	print(pa);//pa[i] 缺少 num[i]

	for (unsigned int i = 0; i < n; i++)
	{
		vector<vector<int> > vvn_i = permute(pa[i]); //n个子集 每个含有n-1个元素 做全排
		for (unsigned int j = 0; j < (n - 1)*(n - 2); j++)//n-1个节点 (n-1)*(n-2)个排列
		{
			vvn_i[j].push_back(num[i]);
			vv.push_back(vvn_i[j]);
		}
	}


	return vv;
}


vector<vector<int> > permuteUnique(vector<int> &num)
{
	/*
	Given a collection of numbers that might contain duplicates, return all possible unique permutations.

	For example,
	[1,1,2] have the following unique permutations:
	[1,1,2], [1,2,1], and [2,1,1].
	*/

	vector<vector<int> > vv;

	return vv;
}


bool isPalindrome(int x)
{
	/*
	Determine whether an integer is a palindrome. Do this without extra space.

	click to show spoilers.

	Some hints:
	Could negative integers be palindromes? (ie, -1)

	If you are thinking of converting the integer to string,
	note the restriction of using extra space.

	You could also try reversing an integer.
	However, if you have solved the problem "Reverse Integer",
	you know that the reversed integer might overflow. How would you handle such case?

	There is a more generic way of solving this problem.
	*/

	//Do this without extra space
	x = (x >= 0 ? x : 0 - x);

	int xx = 0;
	int v = x;
	while (x)
	{
		xx = xx * 10 + x % 10;
		x /= 10;
	}

	return xx == v;
}


int search(int A[], int n, int target)
{
	/*
	Suppose a sorted array is rotated at some pivot unknown to you beforehand.
	(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 - 0 1 2).
	You are given a target value to search. If found in the array return its index,
	otherwise return -1.
	You may assume no duplicate exists in the array.
	Discuss
	*/
	/*
	a sorted array is rotated

	没有想同元素
	右边属于rotated部分均比A[0]小
	部分升序不变
	*/

	int i = 0;
	int j = n - 1;
	int m;

	while (i <= j)
	{
		m = (i + j) / 2;

		if (A[m] == target)
		{
			return m;
		}

		if (A[i] <= A[m])//m在上半区
		{
			if (A[m] > target && A[i] <= target)// i-m段
			{
				j = m - 1;
			}
			else//	A[m] <= target || A[i] >target
			{
				i = m + 1;
			}
		}
		else//m在下半区
		{
			if (A[m] < target && A[j] >= target)//m-j段
			{
				i = m + 1;
			}
			else// A[m] >= target || A[j] < target
			{
				j = m - 1;
			}
		}
	}
	return -1;
}


bool search2(int A[], int n, int target)
{
	/*
	Follow up for "Search in Rotated Sorted Array":
	What if duplicates are allowed?
	Would this affect the run-time complexity? How and why?
	Write a function to determine if a given target is in the array.
	*/
	return false;
}




inline bool isdigital(char c)
{
	return c >= '0' && c <= '9';
}


bool isNumber(const char *s)
{
	/*
	Validate if a given string is numeric.

	Some examples:
	"0" => true
	" 0.1 " => true
	"abc" => false
	"1 a" => false
	"2e10" => true
	Note: It is intended for the problem statement to be ambiguous.
	You should gather all requirements up front before implementing one.

	*/

#define dig (s[i] <= '9' && s[i] >= '0')

	int i = -1;
	int state = 0;
	bool predot = false;
	bool dot = false;
	while (s[i + 1] == ' '&& s[i + 1] != 0)//空格在开始
	{
		i += 1;
	}

	if (s[i + 1] == '-' || s[i + 1] == '+')
	{
		i += 1;
	}

	while (state < 8)
	{
		i += 1;

		if (s[i] == ' ')
		{
			while (s[i] == ' '&& s[i] != 0)
			{
				i += 1;
			}

			if (s[i] != 0)//空格必须在末尾
			{
				return false;
			}
		}

		if (s[i] == 0)
		{
			if (state == 1 || state == 3 || state == 5)
			{
				state = 8;
			}

			if (state == 2 && predot == true)
			{
				state = 8;
			}
			break;
		}



		switch (state)
		{
		case 0:
			//要求输入数字
			if (dig)
			{
				state = 1;
				predot = true;
			}
			else
				if (s[i] == '.')
				{
				dot = true;
				state = 2;
				}
				else
				{
					state = 9; //错误
				}

			break;

		case 1:
			//
			if (dig)
			{
				break;
			}

			if (s[i] == '.')
			{
				dot = true;
				state = 2;
			}
			else
				if (s[i] == 'E' || s[i] == 'e')
				{
				predot = false;
				state = 4;
				}
				else
				{
					state = 9;
				}
			break;

		case 2:
			//输入必须为数字
			if (dig)
			{
				state = 3;
			}
			else
				if (s[i] == 'E' || s[i] == 'e')
				{
				state = 4;
				}
				else
				{
					state = 9; //错误
				}
			break;

		case 3:
			if (dig)
			{
				break;
			}

			if (s[i] == 'E' || s[i] == 'e')
			{
				dot = false;
				predot = false;
				state = 4;
			}
			else
			{
				state = 9;
			}
			break;

		case 4:
			if (dot == true && predot == false)
			{
				return false;
			}

			if (dig)
			{
				predot = true;
				state = 5;
			}
			else
				if (s[i] == '-' || s[i] == '+')
				{
				state = 6;
				}
				else
				{
					state = 9; //错误
				}
			break;

		case 5:
			if (dig)
			{
				break;
			}
			else
			{
				state = 9;
			}
			break;

		case 6:
			if (dig)
			{
				state = 5;
				break;
			}
			else
			{
				state = 9;
			}
		default:
			break;
		}
	}

	if (state == 8)
	{
		return true;
	}
	else
	{
		return false;
	}

#undef dig
}


long Factorial(long n)
{
	long f = 1;
	while (n)
	{
		f *= n;
		n -= 1;
	}

	return f;
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



char *intToRoman(int num)
{
	/*
	Given an integer, convert it to a roman numeral.
	Input is guaranteed to be within the range from 1 to 3999.
	*/
	return NULL;
}


int romanToInt(char *)
{
	/*
	Given a roman numeral, convert it to an integer.
	Input is guaranteed to be within the range from 1 to 3999.
	*/
	/*
	相同的数字连写，所表示的数等于这些数字相加得到的数，如：Ⅲ = 3；
	小的数字在大的数字的右边，所表示的数等于这些数字相加得到的数， 如：Ⅷ = 8；Ⅻ = 12；
	小的数字，（限于Ⅰ、X 和C）在大的数字的左边，所表示的数等于大数减小数得到的数，如：Ⅳ= 4；Ⅸ= 9；

	基本数字Ⅰ、X 、C 中的任何一个，自身连用构成数目，或者放在大数的右边连用构成数目，都不能超过三个；
	放在大数的左边只能用一个。
	不能把基本数字V 、L 、D 中的任何一个作为小数放在大数的左边采用相减的方法构成数目；
	放在大数的右边采用相加的方式构成数目，只能使用一个。
	V 和X 左边的小数字只能用Ⅰ。
	L 和C 左边的小数字只能用X。
	D 和M 左边的小数字只能用C。
	*/


	return 0;
}


vector<string> generateParenthesis(int n)
{
	/*
	Given n pairs of parentheses,
	write a function to generate all combinations of well-formed parentheses.

	For example, given n = 3, a solution set is:

	"((()))", "(()())", "(())()", "()(())", "()()()"

	*/
	vector<string> vs;


	return vs;
}


int longestValidParentheses(char * str)
{
	/*
	Given a string containing just the characters '(' and ')',
	find the length of the longest valid (well-formed) parentheses substring.

	For "(()", the longest valid parentheses substring is "()", which has length = 2.

	Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.
	*/

	//		" ) ( ) ( ) ) "      "( ( ) ) ( ( ) "
	//        -         -                 -
	//cout<<longestValidParentheses(")()())") ;//"( ( ) ) ( ( ) "
	if (str == NULL || *str == '\0')
	{
		return 0;
	}

	char c = '#';
	char *s = str;
	stack<char *> sc;
	sc.push(&c);

	while (*s)
	{
		if (*sc.top() == '(' && *s == ')')
		{
			sc.pop();
		}
		else
		{
			sc.push(s);
		}
		s += 1;
	}
	// s在 '\0'
	int n = sc.size();
	if (n == 1)
	{
		return s - str;
	}

	//  ) ( ) ( ) ) \0
	//  -         -
	//()()
	// # ( ) ( 0
	// -     - s
	int length = s - sc.top();
	for (int i = 2; i < n; i++)
	{
		s = sc.top();
		sc.pop();
		if (s - sc.top() > length)
		{
			length = s - sc.top();
		}
	}

	if (sc.top() - (str - 1) > length)
	{
		length = sc.top() - (str - 1);
	}

	return length - 1;
}


int searchInsert(int A[], int n, int target)
{
	/*
	Given a sorted array and a target value, return the index if the target is found.
	If not, return the index where it would be if it were inserted in order.

	You may assume no duplicates in the array.

	Here are few examples.
	[1,3,5,6], 5 → 2
	[1,3,5,6], 2 → 1
	[1,3,5,6], 7 → 4
	[1,3,5,6], 0 → 0
	*/

	//先实现二分查找
	if (A == NULL)
	{
		return -1;
	}

	int i = 0;
	int j = n - 1;
	int m;

	/*		[1 3] 0
	[1 3] 2
	[1 3] 4
	[1 3] 1
	[1 3] 3
	*/
	while (i <= j)
	{
		m = (i + j) / 2;
		if (A[m] == target)
		{
			return m;
		}

		A[m] <target ? i = m + 1 : j = m - 1;

	}

	return i;
}


bool match_queen(int *qr, int matched_num, int n, int index)
{
	/*
	qr是记录 queen 位置的数组
	matched_num 表示前面已经放置好，并且不冲突的queen的数目，ie，前matched_num个已经放好
	index是下一个queen要放的位置
	测试index和前面matched_num个queen是否冲突
	ok  返回true
	err 返回false
	*/
	/*
	*/
	assert(qr);
	if (matched_num == 0)
	{
		return true;
	}

	int indexm = 0;
	int indexr = 0;
	int indexl = 0;
	for (int i = 0; i < matched_num; i++)
	{
		indexm = qr[i];
		indexr = qr[i] + matched_num - i;
		indexl = qr[i] - matched_num + i;

		if (indexm == index)
		{
			return false;
		}

		if (indexr < n && indexr == index)
		{
			return false;
		}

		if (indexl >= 0 && indexl == index)
		{
			return false;
		}
	}

	return true;
}


vector<vector<string> > solveNQueens(int n)
{
	/*
	The n-queens puzzle is the problem of placing n queens
	on an n×n chessboard such that no two queens attack each other.


	Given an integer n, return all distinct solutions to the n-queens puzzle.
	Each solution contains a distinct board configuration of the n-queens' placement,
	where 'Q' and '.' both indicate a queen and an empty space respectively.
	For example,
	There exist two distinct solutions to the 4-queens puzzle:

	[
	[".Q..",  // Solution 1
	"...Q",
	"Q...",
	"..Q."],

	["..Q.",  // Solution 2
	"Q...",
	"...Q",
	".Q.."]
	]

	*/

	assert(n >= 4);

	int count = 0;
	int *qr = new int[n];
	int matched_num = 0;
	int colum = 0;

	while (true)
	{
		for (; colum< n; colum += 1)//逐列测试，第matched_num+1个queeen的列位置
		{
			if (match_queen(qr, matched_num, n, colum))
			{
				qr[matched_num] = colum;
				matched_num += 1;
				colum = 0;
				break;
			}
		}

		if (colum == n)  //之前的colum列均不是合适位置
		{
			if (matched_num == 0)
			{
				goto end;
			}
			matched_num -= 1;
			colum = qr[matched_num] + 1;//qr内的值最高为n-1
			continue;
		}

		if (matched_num == n)
		{
			count += 1;
			print(qr, n);
			colum = qr[n - 1] + 1;

		}

	}


end:
	vector<vector <string> > vv;

	delete qr;

	cout << "\nthe " << n << " queens  solution num : " << count;
	return vv;
}


int totalNQueens(int n)
{
	/*
	Follow up for N-Queens problem.

	Now, instead outputting board configurations,
	return the total number of distinct solutions.
	*/

	/*
	六皇后问题的解的个数比五皇后问题的解的个数要少。
	现在还没有已知公式可以对 n 计算 n 皇后问题的解的个数。

	1	2	3	4	5	6	7	8	9	10	 11	    12	    13	    14
	1	0	0	2	10	4	40	92	352	724	 2,680  14,200	73,712	365,596

	*/
	return 0;
}


int prestr(char *p, int *pre, int length)
{
	if (!p)
		return -1;

	if (!pre)
		return -2;

	*pre = 0;
	if (length == 1)
		return -3;

	int current;
	int front;

	for (front = 0, current = 1; current<length; current += 1)
	{
		if (*(p + front) == *(p + current))
		{
			*(pre + current) = *(pre + current - 1) + 1;
			front += 1;
		}
		else
		{
			*(pre + current) = 0;
			front = 0;
		}
	}

	return 0;
}


int KMPmatch(char *p, char *s)
{

	if (!p || !s)
		return -1;
	int count = 0;
	unsigned int si = 0;				//string  index
	int ml = 0;				//matched length
	unsigned int pl = strlen(p);		//pattren length
	int *pre = new int[pl];	//contain prefix num


	prestr(p, pre, pl);

	while (si<strlen(s))
	{
		if (p[ml] != s[si])
		{
			if (ml == 0)
			{
				si += 1;
			}
			else
			{
				ml = pre[ml - 1];
			}
		}
		else
		{
			si += 1;
			ml += 1;
			if (ml == pl)
			{
				count += 1;
				ml = 0;
				std::cout << "match index: " << si - pl << std::endl;
			}
		}
	}
	delete pre;
	return count;
}



vector<string> restoreIpAddresses(string s)
{
	/*
	Given a string containing only digits,
	restore it by returning all possible valid IP address combinations.

	For example:
	Given "25525511135",

	return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)
	*/

	vector<string> vs;
	return vs;
}




double findMedianSortedArrays(int *A, int m, int *B, int n)
{
	/*
	There are two sorted arrays A and B of size m and n respectively.
	Find the median of the two sorted arrays.
	The overall run time complexity should be O(log (m+n)).
	*/
	/*
	[0  1  4  8  9]			m=5
	[2  3  5  6  10 11 12]		n=7

	0 1 3 5 7     m=4	中点(不含)以左舍弃  [m/2   m-1]
	0 2 4 6 8	  n=5   中点(不含)以右舍弃	[0     m/2]
	(m+n)/2 -1

	0 2 3 4 5 7 3.5

	mid=(a[m/2] + a[(m-1)/2])/2
	*/
	/*
	01357	357  35  3
	02468	024  24  4

	0135	35	3	3
	03468	034	34

	不含边界值 m/2+1
	123		3		NULL
	4567	45		4
	123		3
	456		4
	*/

	if (!A || !B)
	{
		return DBL_MIN;
	}


	if (m == 1 && n == 1)
	{
		return (0.0 + *A + *B) / 2;
	}
	if (m == 1 && n == 0)
	{
		return *A;
	}
	if (m == 0 && n == 1)
	{
		return *B;
	}

	double ma = DBL_MIN;
	double mb = DBL_MIN;

	if (m != 0)
	{
		ma = (0.0 + A[m / 2] + A[(m - 1) / 2]) / 2;
	}

	if (n != 0)
	{
		mb = (0.0 + B[n / 2] + B[(n - 1) / 2]) / 2;
	}

	//print(A,m);cout<<" ma="<<ma;
	//print(B,n);cout<<" mb="<<mb;

	if (ma == mb)
	{
		return ma;
	}

	int acount;
	int bcount;
	int *a;
	int *b;
	if (ma > mb)
	{
		acount = m / 2;//留A的前半部分 2  1
		bcount = n / 2;//留B的后半部分 1  0

		//中值较小的数组 要包含边界值：
		//是偶数个则包含中间两个，是奇数个则包含最中间的一个

		if ((m + n) % 4 != 3)
		{
			b = B + bcount;
			bcount = bcount + 1;
		}
		else
		{
			b = B + n - bcount;
		}
		a = A;

	}
	else
	{
		acount = m / 2;//留A的后半部分
		bcount = n / 2;//留B的前半部分

		if ((m + n) % 4 != 3)
		{
			a = A + acount;
			acount = acount + 1;
		}
		else
		{
			a = A + m - acount;
		}
		b = B;

	}

	return  findMedianSortedArrays(a, acount, b, bcount);
}


int nextpeak(int a[], int i, int n)
{
	/*
	寻找不超过 a[i]点的下一个尖峰
	1	第一个点
	2   下一个peak前已达到边界
	*/

	while (true)//下坡循环，
	{
		if (i + 1 == n)
		{
			return 0;
		}

		if (a[i] <a[i + 1])
		{
			break;
		}
		i += 1;
	}//退出，i在谷底最右端，i+1在上坡 

	while (true)
	{
		if (i + 1 == n)
		{
			break;//返回最后一个点
		}

		if (a[i] > a[i + 1])
		{
			break;
		}
		i += 1;
	}

	return i;

}


int trap(int A[], int n)
{
	/*
	Given n non-negative integers representing an elevation map where the width of each bar is 1,
	compute how much water it is able to trap after raining.

	For example,
	Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.


	The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1].
	In this case, 6 units of rain water (blue section) are being trapped.
	Thanks Marcos for contributing this image!
	*/


	int j;
	int m;
	int i = nextpeak(A, 0, n);
	int sum = 0;
	while (j = nextpeak(A, i, n))
	{
		if (A[i]>A[j])
		{
			m = A[j];
		}
		else
		{
			m = A[i];
		}

		for (int k = 1; k <= j - i + 1 - 2; k++)
		{
			if (m - (A + i)[k] >0)
			{
				sum += m - (A + i)[k];
			}
		}

		i = j;
	}

	return sum;
}


unsigned int  invertint(unsigned int i)
{
	/*
	二进制反转
	*/

	unsigned int y = 0;
	int n = sizeof(int) * 8;
	for (int j = 1; j <= n; j++)
	{
		y = y << 1;
		y += i&(0x01);
		i = i >> 1;
	}

	return i;
}


int *findkin2sortedarr(int *a, int la, int *b, int lb, int k)
{
	/*
	找到两个已排序数组中的第k个
	*/

	if (la + lb<k)
	{
		return NULL;
	}

	int n = k / 2;

	int ka = a[n - 1];//a 第n个
	int kb = b[k - n - 1];//b 第k-n个

	if (ka == kb)
	{
		return a + n;
	}

	/*
	k=3	      n=1	3-0=3	n=1
	a 189		1	189		1
	b 246	    4	24		2
	*/


	if (ka > kb)
	{
		return findkin2sortedarr(a, k - n, b + n, lb - n, k - n);
	}

	if (ka < kb)
	{
		return findkin2sortedarr(a + n, la - n, b, k - n, k - n);
	}

	return NULL;
}



int numTrees(int n)
{
	/*
	Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

	For example,
	Given n = 3, there are a total of 5 unique BST's.

	1         3     3      2      1
	\       /     /      / \      \
	3     2     1      1   3      2
	/     /       \                 \
	2     1         2                 3


	令h(0)=1,h(1)=1，catalan数满足
	递推式[1]：
	h(n)= h(0)*h(n-1)+h(1)*h(n-2) + ... + h(n-1)h(0) (n>=2)
	例如：h(2)=h(0)*h(1)+h(1)*h(0)=1*1+1*1=2
	h(3)=h(0)*h(2)+h(1)*h(1)+h(2)*h(0)=1*2+1*1+2*1=5

	递推式[2]：
	h(n)=h(n-1)*(4*n-2)/(n+1);
	递推关系的解为：
	h(n)=C(2n,n)/(n+1) (n=0,1,2,...)
	递推关系的另类解为：
	h(n)=c(2n,n)-c(2n,n+1)(n=0,1,2,...)
	*/

	return C(2 * n, n) / (n + 1);
}



void shellsort(int *data, size_t size)
{
	/*
	已知的最好步长串行是由Sedgewick提出的 (1, 5, 19, 41, 109,...)
	*/
	for (int gap = size / 2; gap > 0; gap /= 2)
		for (unsigned int i = gap; i < size; ++i)
		{

		int key = data[i];
		int j = 0;
		for (j = i - gap; j >= 0 && data[j] > key; j -= gap)
		{
			data[j + gap] = data[j];
		}
		data[j + gap] = key;
		}

}


template <typename T>
void printbinary(T t)
{
	char *s = new int[sizeof(T) + 1];
	int i = sizeof(T);

	s[i] = 0;

	do
	{
		i -= 1;
		s[i] = t & 0X01;
		t = t >> 1;
	} while (i>0);

	cout << "\n" << s;
}


int string2int(string s)
{
	int v = 0;
	for (unsigned int i = 0; i < s.size(); i++)
	{
		v = v * 10 + (s[i] - '0');
	}

	return v;
}


inline bool isop(char c)
{
	return c == '+' || c == '-' || c == '*' || c == '/';
}


int compute(int first, int second, char op)
{
	switch (op)
	{
	case '+':return first + second;
	case '-':return first - second;
	case '*':return first*second;
	case '/':return first / second;
	default:return op;
	}
}


int evalRPN(vector<string> &tokens)
{
	/*
	Evaluate the value of an arithmetic expression in Reverse Polish Notation.
	Valid operators are +, -, *, /. Each operand may be an integer or another expression.
	Some examples:
	["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
	["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
	*/


	//假定表达式是合理的
	int first, second;
	unsigned int next = 0;

	stack<int> si;

	while (next<tokens.size())
	{
		if (isop(tokens[next][0]))// op:+ - * /
		{
			second = si.top();
			si.pop();
			first = si.top();
			si.pop();

			si.push(compute(first, second, tokens[next][0]));
		}
		else//digital
		{
			si.push(string2int(tokens[next]));
		}

		next += 1;

	}

	if (si.size() != 1)
	{
		exit(-1);
	}

	return si.top();
}


char *getPermutation(int n, int k)
{
	/*
	The set [1,2,3,…,n] contains a total of n! unique permutations.

	By listing and labeling all of the permutations in order,
	We get the following sequence (ie, for n = 3):

	"123"
	"132"
	"213"
	"231"
	"312"
	"321"
	Given n and k, return the kth permutation sequence.

	Note: Given n will be between 1 and 9 inclusive.
	*/

	return NULL;
}


int firstMissingPositive(int A[], int length)
{
	/*
	Given an unsorted integer array, find the first missing positive integer.
	For example,
	Given [1,2,0] return 3,
	and [3,4,-1,1] return 2.

	Your algorithm should run in O(n) time and uses constant space.
	*/
	if (A == NULL)
	{
		return 0;
	}
	int t;
	int i;
	for (i = 0; i < length; i++)
	{
		if (A[i] <= length && A[i] >0 && A[i] != i + 1 && A[i] != (A[A[i] - 1]))
		{
			t = A[A[i] - 1]; A[A[i] - 1] = A[i]; A[i] = t;
			i -= 1;
		}
	}

	for (i = 0; i < length && A[i] == i + 1; i += 1)
	{
		;
	}

	return i + 1;
}


void OutputSubset(int set[], int length)
{
	char *flag = (char *)malloc(sizeof(char) * length);

	for (int k = 0; k < length; k++)
		flag[k] = '0';

	printf("{ }\n");

	int i = 0;
	while (true)
	{
		for (i = length - 1; i >= 0 && flag[i] == '1'; flag[i] = '0', --i)
			;
		if (i < 0)
			break;
		else
		{
			flag[i] = '1';
		}

		for (int j = 0; j < length; j++)
		{
			if (flag[j] == '1')
				printf("%d", set[j]);
		}

		printf("\n");
	}

	free(flag);
}


int maxSubArray(int A[], int n)
{
	/*
	Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

	For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
	the contiguous subarray [4,−1,2,1] has the largest sum = 6.

	More practice:
	If you have figured out the O(n) solution,
	try coding another solution using the divide and conquer approach, which is more subtle.
	*/

	if (A == NULL)
	{
		return 0;
	}

	int s = 0;
	int max = INT_MIN;

	for (int i = 0; i<n; i++)
	{
		if (s >= 0)
		{
			s += A[i];
		}
		else
		{
			s = A[i];
		}

		if (s>max)
		{
			max = s;
		}
	}

	return max;
}


vector<Interval> merge(vector<Interval> &intervals)
{
	/*
	Given a collection of intervals, merge all overlapping intervals.

	For example,
	Given [1,3],[2,6],[8,10],[15,18],
	return [1,6],[8,10],[15,18].
	*/

	/*
	要假设，区间的左端是递增的？
	否则，排序？
	*/

	for (unsigned int i = 0; i < intervals.size() - 1; i += 1)
	{
		if (intervals[i].end >= intervals[i + 1].start)//need merge
		{
			intervals[i].end = intervals[i + 1].end;
			intervals.erase(intervals.begin() + i + 1);
			i -= 1;
		}
	}

	return intervals;
}


vector<vector<int> > generateMatrix(int n)
{
	/*

	Given an integer n,
	generate a square matrix filled with elements from 1 to n2 in spiral order.

	For example,
	Given n = 3,

	You should return the following matrix:
	[
	[ 1, 2, 3 ],
	[ 8, 9, 4 ],
	[ 7, 6, 5 ]
	]
	*/
	vector<vector<int> > vv;
	vector<int> tmp;

	int i;
	for (i = 0; i < n; i++)
	{
		tmp.push_back(0);
	}
	for (i = 0; i < n; i++)
	{
		vv.push_back(tmp);
	}
	/*
	首先生成对应容量的矩阵/数组
	按照spiral访问顺序写入
	主要部分和 下面相同 读出改为写入
	*/

	int x = 0, xs = 0, xl = n - 1;
	int y = 0, ys = 0, yl = n - 1;

	i = 0;
	while (i < n*n)
	{
		y = ys;
		x = xs;
		for (; x <= xl; x += 1)
		{
			//vi.push_back(vv[y][x]);
			vv[y][x] = i;
			i += 1;
		}

		for (y += 1, x -= 1; y <= yl; y += 1)
		{
			//vi.push_back(matrix[y][x]);
			vv[y][x] = i;
			i += 1;
		}

		for (x -= 1, y -= 1; x >= xs; x -= 1)
		{
			//vi.push_back(matrix[y][x]);
			vv[y][x] = i;
			i += 1;
		}

		for (y -= 1, x += 1; y>ys; y -= 1)
		{
			//vi.push_back(matrix[y][x]);
			vv[y][x] = i;
			i += 1;
		}

		xs += 1;
		ys += 1;

		xl -= 1;
		yl -= 1;
	}


	return vv;
}


vector<int> spiralOrder(vector<vector<int> > &matrix)
{
	/*
	Given a matrix of m x n elements (m rows, n columns),
	return all elements of the matrix in spiral order.

	For example,
	Given the following matrix:

	[
	[ 1, 2, 3 ],
	[ 4, 5, 6 ],
	[ 7, 8, 9 ]
	]
	You should return [1,2,3,6,9,8,7,4,5].
	*/
	vector<int> vi;

	int x = 0, xs = 0, xl = matrix[0].size() - 1;
	int y = 0, ys = 0, yl = matrix.size() - 1;
	int n = (yl + 1)*(xl + 1);

	while (n>0)
	{
		y = ys;
		x = xs;
		for (; x <= xl; x += 1)
		{
			vi.push_back(matrix[y][x]);
			n -= 1;
		}

		for (y += 1, x -= 1; y <= yl; y += 1)
		{
			vi.push_back(matrix[y][x]);
			n -= 1;
		}

		for (x -= 1, y -= 1; x >= xs; x -= 1)
		{
			vi.push_back(matrix[y][x]);
			n -= 1;
		}

		for (y -= 1, x += 1; y>ys; y -= 1)
		{
			vi.push_back(matrix[y][x]);
			n -= 1;
		}

		xs += 1;
		ys += 1;

		xl -= 1;
		yl -= 1;
	}

	return vi;
}


int largestRectangleArea(vector<int> &hist)
{
	/*
	Given n non-negative integers representing the histogram's bar height
	where the width of each bar is 1, find the area of largest rectangle in the histogram.
	Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].
	The largest rectangle is shown in the shaded area, which has area = 10 unit.
	For example,
	[2,1,5,6,2,4] -->10
	[2,1,5,6,3,4] -->12
	*/
	int n = hist.size();
	stack<int> s;
	int max = 0;
	int tp;
	int area;

	int i = 0;
	while (i < n)
	{
		if (s.empty() || hist[s.top()] <= hist[i])
		{
			s.push(i);
			i += 1;
		}
		else
		{
			tp = s.top();
			s.pop();

			area = hist[tp] * (s.empty() ? i : i - s.top() - 1);
			max = max <area ? area : max;

		}
	}


	while (!s.empty())
	{
		tp = s.top();
		s.pop();
		area = hist[tp] * (s.empty() ? i : i - s.top() - 1);
		max = max <area ? area : max;
	}


	return max;
}


void setZeroes(vector<vector<int> > &matrix)
{
	/*
	Given a m x n matrix, if an element is 0,
	set its entire row and column to 0. Do it in place.

	click to show follow up.

	Follow up:
	Did you use extra space?
	A straight forward solution using O(mn) space is probably a bad idea.
	A simple improvement uses O(m + n) space,
	but still not the best solution.
	Could you devise a constant space solution?
	*/
	unsigned int x, y;
	for (y = 0; y < matrix.size(); y++)
	{
		for (x = 0; x < matrix[0].size(); x++)
		{
			if (matrix[y][x] == 0)
			{
				break;
			}
		}

		if (x == matrix[0].size())
		{
			continue;
		}

		//set this row  1-->0  0 -->~0
		for (x = 0; x < matrix[0].size(); x++)
		{
			matrix[y][x] = matrix[y][x] == 1 ? 0 : ~0;
		}

	}

	for (x = 0; x < matrix[0].size(); x++)
	{
		for (y = 0; y < matrix.size(); y++)
		{
			if (matrix[y][x] == ~0)
			{
				break;
			}
		}

		if (y == matrix.size())
		{
			continue;
		}

		//set this row  all 0
		for (y = 0; y < matrix.size(); y++)
		{
			matrix[y][x] = 0;
		}
	}

}


void rotate(vector<vector<int> > &matrix)
{
	/*
	You are given an n x n 2D matrix representing an image.

	Rotate the image by 90 degrees (clockwise).

	0 1 2 3    c 8 4 0
	4 5 6 7    d 9 5 1
	8 9 a b    e a 6 2
	c d e f    f b 7 3

	Follow up:
	Could you do this in-place?
	*/
	//n x n
	/*

	[i][j]

	[n-1-j][i]	  [j][n-1-i]

	[n-1-i][n-1-j]

	*/
	int tmp;
	const int n = matrix.size();
	for (int i = 0; i < n / 2; i++) //层
	{
		//第i层 单侧n-i*2个元素
		for (int j = i; j < n - 1 - i; j++)
		{
			tmp = matrix[i][j];

			matrix[i][j] = matrix[n - 1 - j][i];
			matrix[n - 1 - j][i] = matrix[n - 1 - i][n - 1 - j];
			matrix[n - 1 - i][n - 1 - j] = matrix[j][n - 1 - i];
			matrix[j][n - 1 - i] = tmp;
		}

	}
}


int maximalRectangle(vector<vector<char> > &matrix)
{
	/*
	Given a 2D binary matrix filled with 0's and 1's,
	find the largest rectangle containing all ones and return its area.
	*/

	return 0;
}



int candy(vector<int> &ratings)
{
	/*
	There are N children standing in a line. Each child is assigned a rating value.

	You are giving candies to these children subjected to the following requirements:

	Each child must have at least one candy.
	Children with a higher rating get more candies than their neighbors.
	What is the minimum candies you must give?
	*/
	return 0;
}


void solve(vector<vector<char>> &board)
{
	/*
	Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.
	A region is captured by flipping all 'O's into 'X's in that surrounded region .
	For example,
	X X X X
	X O O X
	X X O X
	X O X X
	After running your function, the board should be:
	X X X X
	X X X X
	X X X X
	X O X X
	*/


}


int longestConsecutive(vector<int> &num)
{
	/*
	Given an unsorted array of integers,
	find the length of the longest consecutive elements sequence.
	For example,
	Given [100, 12, 200, 13, 11, 14],
	The longest consecutive elements sequence is [11, 12, 13, 14].
	Return its length: 4.
	Your algorithm should run in O(n) complexity.
	*/
	/*
	将数组中所有元素放到HashSet中，
	然后对Set中的元素进行遍历，
	遍历每个元素时查看与它相邻的数字（递增与递减两个方向）是否存在Set中，
	如果存在则将连续序列的长度+1，
	同时将该相邻数字从Set中删除。
	遍历完整个Set即可得到最大长度。
	实现的时候通过使用Iterator来在遍历的时候实现删除，
	但是使用这种方法删除相邻元素仍然有困难（不知道怎样得到相邻元素的iterator）
	改用了HashMap来放置所有元素，
	通过0,1来表示该元素是否已经被访问过
	*/


	return 0;
}


bool isInterleave(string s1, string s2, string s3)
{
	/*
	Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.

	For example,
	Given:
	s1 = "aabcc",
	s2 = "dbbca",

	When s3 = "aadbbcbcac", return true.
	When s3 = "aadbbbaccc", return false.
	*/

	return false;
}


int numDecodings(string s)
{
	/*
	A message containing letters from A-Z is being encoded to numbers using the following mapping:

	'A' -> 1
	'B' -> 2
	...
	'Z' -> 26
	Given an encoded message containing digits, determine the total number of ways to decode it.

	For example,
	Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).

	The number of ways decoding "12" is 2.
	*/
	return 0;
}


bool searchMatrix(vector<vector<int> > &matrix, int target)
{
	/*
	Write an efficient algorithm that searches for a value in an m x n matrix.
	This matrix has the following properties:
	Integers in each row are sorted from left to right.
	The first integer of each row is greater than the last integer of the previous row.
	For example,

	Consider the following matrix:

	[
	[1,   3,  5,  7],
	[10, 11, 16, 20],
	[23, 30, 34, 50]
	]
	Given target = 3, return true.
	*/
	int i = 0;
	int j = matrix.size() - 1;
	int m;
	while (i <= j)
	{
		m = (i + j) / 2;
		if (matrix[m][0] == target)
		{
			i = m;
			break;
		}

		matrix[m][0] <target ? i = m + 1 : j = m - 1;

	}
	//i : i-1行找

	if (matrix[i][0] == target)
	{
		return true;
	}

	if (i == 0)
	{
		return false;
	}

	int n = i - 1;
	i = 0;
	j = matrix[n].size();
	while (i <= j)
	{
		m = (i + j) / 2;
		if (matrix[n][m] == target)
		{
			i = m;
			break;
		}

		matrix[n][m] <target ? i = m + 1 : j = m - 1;

	}

	if (matrix[n][i] == target)
	{
		return true;
	}
	else
	{
		return false;
	}
}


vector<string> fullJustify(vector<string> &words, int L)
{
	/*
	Given an array of words and a length L,
	format the text such that each line has exactly L characters and is fully (left and right) justified.

	You should pack your words in a greedy approach;
	that is, pack as many words as you can in each line. Pad extra spaces ' '
	when necessary so that each line has exactly L characters.

	Extra spaces between words should be distributed as evenly as possible.
	If the number of spaces on a line do not divide evenly between words,
	the empty slots on the left will be assigned more spaces than the slots on the right.

	For the last line of text,
	it should be left justified and no extra space is inserted between words.

	For example,
	words: ["This", "is", "an", "example", "of", "text", "justification."]
	L: 16.

	Return the formatted lines as:
	[
	"This    is    an",
	"example  of text",
	"justification.  "
	]
	Note: Each word is guaranteed not to exceed L in length.

	click to show corner cases.

	Corner Cases:
	A line other than the last line might contain only one word.
	What should you do in this case?
	In this case, that line should be left-justified.
	*/
	return words;
}



bool canJump(int A[], int n)
{
	/*
	Given an array of non-negative integers,
	you are initially positioned at the first index of the array.
	Each element in the array represents your maximum jump length at that position.
	Determine if you are able to reach the last index.
	For example:
	A = [2,3,1,1,4], return true.
	A = [3,2,1,0,4], return false.
	*/

	int i = 0;
	int max;
	while (i<n)
	{
		max = i + A[i];

		if (max >= n - 1)
		{
			break;
		}

		for (int j = i + 1; j <= i + A[i]; j++)
		{
			if (j + A[j] > max)
			{
				max = j + A[j];
			}
		}

		if (max == i + A[i])//某次无进展
		{
			return false;
		}

		i = max;
	}

	return true;
}


int jump(int A[], int n)
{
	/*
	Given an array of non-negative integers,
	you are initially positioned at the first index of the array.
	Each element in the array represents your maximum jump length at that position.
	Your goal is to reach the last index in the minimum number of jumps.
	For example:
	Given array A = [2,3,1,1,4]
	The minimum number of jumps to reach the last index is 2.
	(Jump 1 step from index 0 to 1, then 3 steps to the last index.)

	*/


	int i = 0;
	int max;
	int num = 1;
	while (i<n)
	{
		max = i + A[i];

		if (max >= n - 1)
		{
			break;
		}

		for (int j = i + 1; j <= i + A[i]; j++)
		{
			if (j + A[j] > max)
			{
				max = j + A[j];
			}
		}

		if (max == i + A[i])//某次无进展
		{
			return -1;
		}

		i = max;
		num += 1;
	}

	return num;
}



int searchInsert2(int A[], int n, float target)
{
	//变体
	if (A == NULL)
	{
		return -1;
	}

	int i = 0;
	int j = n - 1;
	int m;

	while (i <= j)
	{
		m = (i + j) / 2;
		if (A[m] == target)
		{
			return m;
		}

		A[m] <target ? i = m + 1 : j = m - 1;
	}

	return i;
}



vector<int> searchRange(int A[], int n, int target)
{

	/*
	Given a sorted array of integers,
	find the starting and ending position of a given target value.
	Your algorithm's runtime complexity must be in the order of O(log n).
	If the target is not found in the array, return [-1, -1].
	For example,
	Given [5, 7, 7, 8, 8, 10] and target value 8,
	return [3, 4].
	*/
	vector<int> vi;
	vi.push_back(-1);
	vi.push_back(-1);

	int i;

	i = searchInsert2(A, n, target - 0.5f);//起点
	if (i == n || A[i] != target)
	{
		return vi;
	}
	vi[0] = i;

	i = searchInsert2(A, n, target + 0.5f);
	vi[1] = i - 1;

	return vi;
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


unsigned int Com2(unsigned int n, unsigned int i)
{
	if (n < i)
	{
		return ~0;
	}

	if (i > n / 2)
	{
		return Com2(n, n - i);

	}

	/*增加错误检测*/

	unsigned int mul = 1;
	unsigned int den = n;
	unsigned int end = n - i + 1;
	unsigned int j = i;

	while (j >= 2 || n >= end)
	{
		if (j != 1 && den % j == 0)
		{
			den /= j;
			j -= 1;
		}
		else
		{
			mul *= den;
			den = --n;
		}
	}

	/*
	空间：常数
	时间：
	1	分子必然除完，i次除法
	2	分母必须连乘，i次乘法
	3	i最大为 n/2

	线性时间
	*/
	return mul;
}

int singleNumber2(int A[], int n)
{
	int one = 0;
	int two = 0;
	int car = 0;
	int thr = 0;

	for (int i = 0; i < n; i += 1)
	{
		car = one & A[i];
		one ^= A[i];
		two ^= car;

		thr = ~(one & two);

		one &= thr;
		two &= thr;
	}

	return one;
}


string simplifyPath2(string path)
{
	vector<string> cells;


	for (unsigned int i = 0; i < path.size(); i++)
	{
		string cell;

		switch (path[i])
		{
		case '/':
			break;

		case '.':

			if (i + 1 == path.size())
			{
				break;
			}

			if ((path[i + 1] >= '0' && path[i + 1] <= '9') || (path[i + 1] >= 'a' && path[i + 1] <= 'z') || (path[i + 1] >= 'A' && path[i + 1] <= 'Z') || path[i + 1] == '_' || path[i + 1] == '.')
			{
				do
				{
					cell += path[i];
					i += 1;

					if (i == path.size())
					{
						break;
					}
				} while ((path[i] >= '0' && path[i] <= '9') || (path[i] >= 'a' && path[i] <= 'z') || (path[i] >= 'A' && path[i] <= 'Z') || path[i] == '_' || path[i] == '.');

				i -= 1;
				cells.push_back(cell);
			}

			break;

		default:

			while ((path[i] >= '0' && path[i] <= '9') || (path[i] >= 'a' && path[i] <= 'z') || (path[i] >= 'A' && path[i] <= 'Z') || path[i] == '_' || path[i] == '.')
			{
				cell += path[i];
				i += 1;

				if (i == path.size())
				{
					break;
				}
			}
			i -= 1;
			cells.push_back(cell);
			break;
		}

	}

	//已经在 cells中
	stack<string> forret;
	for (size_t i = 0; i < cells.size(); i++)
	{
		if (cells[i][0] == '.' && cells[i][1] == '.'&&cells[i].size() == 2)
		{
			if (!forret.empty())
			{
				forret.pop();
			}
		}
		else
		{
			forret.push(cells[i]);
		}
	}

	string ret;

	if (forret.empty() == true)
	{
		ret = "/";
	}
	else
	{
		while (!forret.empty())
		{
			ret = '/' + forret.top() + ret;
			forret.pop();
		}
	}

	return ret;
}


int minPathSum(vector<vector<int> > &grid)
{
	/*

	测试 ，横条 竖条

	*/


	int h = grid.size();
	int w = grid[0].size();

	int n = h > w ? w : h;
	int m = h > w ? h : w;

	vector<int> b(n);

	b[0] = grid[0][0];

	int layer;
	int i;//层内索引
	int tmp, tmp2;

	for (layer = 1; layer < n; layer++)//逐层 
	{
		tmp = b[0];
		b[0] += grid[layer][0];
		for (i = 1; i < layer; i++) //当前层 逐个
		{
			tmp2 = b[i];
			if (tmp >= b[i])
			{
				b[i] = b[i] + grid[layer - i][i];
			}
			else
			{
				b[i] = tmp + grid[layer - i][i];
			}
			tmp = tmp2;
		}
		b[layer] = tmp + grid[layer - i][i];
	}

	if (n == h)
	{
		//矮长型
		for (layer = 0; layer < m - n; layer++)
		{
			for (i = 0; i <m - n - 1; i++)
			{
				b[i] = b[i] > b[i + 1] ? b[i + 1] : b[i];
				b[i] += grid[n - 1 - i][i + 1 + layer];
			}
		}

		for (layer = 0; layer < m - n - 1; layer++)
		{
			for (i = 0; i < m - n - 1 - layer; i++)
			{
				b[i] = b[i] > b[i + 1] ? b[i + 1] : b[i];
				b[i] += grid[n - 1 - i][n + 1 + i + layer];//0 0   --->  n+1 1
			}
		}
	}
	else
	{
		for (layer = 0; layer < m - n; layer++)
		{
			tmp = b[0];
			for (i = 1; i <m - n; i++)
			{
				b[i] = b[i] > tmp ? tmp : b[i];
				b[i] += grid[n + i + layer][i];
			}
		}

		for (layer = 0; layer < m - n - 1; layer++)
		{
			for (i = 0; i < m - n - 1 - layer; i++)
			{
				b[i] = b[i] > b[i + 1] ? b[i + 1] : b[i];
				b[i] += grid[m - 1 - i][i + 1 + layer];
			}

		}

	}

	return b[0];
}
