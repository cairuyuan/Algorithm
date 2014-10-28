#include "stdafx.h"
#include "code_1.h"

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




vector<vector<int> > permute_2(vector<int> &num)
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
		vector<vector<int> > vvn_i = permute_2(pa[i]); //n个子集 每个含有n-1个元素 做全排
		for (unsigned int j = 0; j < (n - 1)*(n - 2); j++)//n-1个节点 (n-1)*(n-2)个排列
		{
			vvn_i[j].push_back(num[i]);
			vv.push_back(vvn_i[j]);
		}
	}


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