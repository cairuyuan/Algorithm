#include "stdafx.h"
#include "code_6.h"


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


bool isValidSudoku(vector<vector<char> > &board)
{

	/*
	Sudoku规则：
	在一个9 * 9的区域内，
	每行1 - 9出现且只出现一次，
	每列1 - 9出现且只出现一次，
	在9个子3 * 3的区域内1 - 9出现且只出现一次。

	这题允许填空('.')，所以不必要每个数字都出现。

	*/

	int count[9];
	int j;
	int i;
	char c;
	int bi, bj;/*box 的左上角坐标*/


	/*验证行有效*/
	for (i = 0; i < 9; i += 1)
	{
		for (j = 0; j < 9; j += 1)
		{
			count[j] = 0;
		}
		for (j = 0; j < 9; j += 1)
		{
			c = board[i][j];
			if (c == '.')
			{
				continue;
			}

			c -= '1';
			if (count[c] == 1)
			{
				return false;
			}
			else
			{
				count[c] = 1;
			}
		}

	}


	/*验证列有效*/
	for (j = 0; j < 9; j += 1)
	{
		for (i = 0; i < 9; i += 1)
		{
			count[i] = 0;
		}
		for (i = 0; i < 9; i += 1)
		{
			c = board[i][j];
			if (c == '.')
			{
				continue;
			}

			c -= '1';
			if (count[c] == 1)
			{
				return false;
			}
			else
			{
				count[c] = 1;
			}

		}

	}



	for (bi = 0; bi < 9; bi += 3)
	{
		for (bj = 0; bj < 9; bj += 3)/*board[bi][bj]是左上角*/
		{
			/*验证一个盒子*/
			for (i = 0; i < 9; i += 1)
			{
				count[i] = 0;
			}
			for (i = 0; i < 3; i += 1)
			{
				for (j = 0; j < 3; j += 1)
				{
					c = board[bi + i][bj + j];
					if (c == '.')
					{
						continue;
					}

					c -= '1';
					if (count[c] == 1)
					{
						return false;
					}
					else
					{
						count[c] = 1;
					}
				}
			}

			/*一个循环，为一个3*3*/

		}

	}

	return true;
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

string convert(string s, int nRows)
{
	if (nRows <= 1 || s.size() <= 1) return s;

	string result;

	for (int i = 0; i < nRows; i++)
	{
		for (unsigned int j = 0, index = i; index < s.size(); j++, index = (2 * nRows - 2) * j + i)
		{
			result.append(1, s[index]); // 垂直元素
			if (i == 0 || i == nRows - 1) continue; // 斜对角元素

			if (index + (nRows - i - 1) * 2 < s.size())
			{
				result.append(1, s[index + (nRows - i - 1) * 2]);
			}
		}
	}

	return result;
}

vector<int> twoSum(vector<int> &numbers, int target)
{
	unordered_map<int, int> mapping;
	vector<int> result;
	int gap;
	unsigned int j;
	for (unsigned int i = 0; i < numbers.size(); i++)
	{
		mapping[numbers[i]] = i;
	}

	for (unsigned int i = 0; i < numbers.size(); i++)
	{
		gap = target - numbers[i];
		if (mapping.find(gap) != mapping.end())
		{
			j = mapping[gap];

			if (i == j)
			{
				continue;
			}

			result.push_back(i + 1);
			result.push_back(j + 1);
			break;

		}
	}
	return result;
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


int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid)
{
	const int m = obstacleGrid.size();
	const int n = obstacleGrid[0].size();

	if (obstacleGrid[0][0] || obstacleGrid[m - 1][n - 1]) return 0;

	vector<int> f(n, 0);
	f[0] = obstacleGrid[0][0] ? 0 : 1;
	for (int i = 0; i < m; i += 1)//行
	{
		for (int j = 1; j < n; j += 1)//列
		{
			f[j] = obstacleGrid[i][j] ? 0 : f[j - 1] + f[j];
		}
	}

	return f[n - 1];
}


string getNext(const string &s)
{
	/*
	扫描s，将结果写入tmp，交换到s
	*/

	string tmp;

	int s_length = s.size();
	int i;

	char num = s[0];
	int count = 1;
	for (i = 1; i < s_length; i += 1)
	{
		if (s[i] == num)
		{
			count += 1;
		}
		else
		{
			/*扫描到和之前不一样*/
			tmp += count + '0';
			tmp += num;
			num = s[i];
			count = 1;
		}
	}

	if (count)
	{
		tmp += count + '0';
		tmp += num;
	}

	return tmp;
}


string countAndSay(int n)
{
	if (n <= 0) return string();

	string say = "1";

	for (int i = 1; i < n; ++i)
	{
		say = getNext(say);
	}

	return say;
}

void bub(int a[], int length, int tag)
{

	/*
	*/

	for (int i = 0; i < length; i += 1)
	{
		for (int j = 0; j < length - 1 - i; j += 1)
		{
			if (a[j] > a[j + 1])
			{
				swap(a[j], a[j + 1]);
			}
		}
	}

	
}


int maxProduct(int A[], int n)
{
	int max_product = 0;
	int tmp_product = 1;
	int i = 0;

	while (i < n)
	{
		if (A[i] <= 0)
		{
			if (max_product < tmp_product && tmp_product!=1)
			{
				max_product = tmp_product;
			}
			tmp_product = 1;
		}
		else
		{
			tmp_product *= A[i];
		}

		i += 1;
	}

	if (max_product < tmp_product && tmp_product != 1)
	{
		max_product = tmp_product;
	}

	return max_product;
}


vector<TreeNode *> generateTrees2(int n) 
{
	if (n == 0) return generateT(1, 0);
	return generateT(1, n);
}

vector<TreeNode *> generateT(int start, int end) 
{
	vector<TreeNode*> subTree;
	if (start > end) 
	{
		subTree.push_back(nullptr);
		return subTree;
	}

	for (int k = start; k <= end; k++) 
	{
		vector<TreeNode*> leftSubs = generateT(start, k - 1);
		vector<TreeNode*> rightSubs = generateT(k + 1, end);
		for (auto left_sub_tree : leftSubs) 
		{
			for (auto right_sub_tree : rightSubs) 
			{
				TreeNode *node = new TreeNode(k);
				node->left = left_sub_tree;
				node->right = right_sub_tree;
				subTree.push_back(node);
			}
		}
	}
	return subTree;
}

vector<vector<int> > subsetsWithDup(vector<int> &S)
{
	sort(S.begin(), S.end()); // 必须排序
	set<vector<int> > result;// 用set 去重，不能用unordered_set，因为输出要求有序
	const size_t n = S.size();
	vector<int> v;

	for (size_t i = 0; i < (1U << n); ++i) 
	{
		for (size_t j = 0; j < n; ++j)
		{
			if (i & 1 << j) v.push_back(S[j]);
		}
		result.insert(v);
		v.clear();
	}
	vector<vector<int> > real_result;
	copy(result.begin(), result.end(), back_inserter(real_result));
	return real_result;
}

vector<vector<int> > subsets(vector<int> &S) 
{
	sort(S.begin(), S.end()); // 输出要求有序
	vector<vector<int> > result;
	const size_t n = S.size();
	vector<int> v;

	for (size_t i = 0; i < ((size_t)1 << n); i++) 
	{
		for (size_t j = 0; j < n; j++) 
		{
			if (i & 1 << j) v.push_back(S[j]);
		}
		result.push_back(v);
		v.clear();
	}
	return result;
}

int maxPoints(vector<Point> &points) 
{
	if (points.size() == 0) return 0;
	unordered_map<double, int> count;
	int size = points.size();
	int ans = 0;
	for (int i = 0; i < size; i++)
	{
		int x = points[i].x;
		int y = points[i].y;
		int du = 0;
		count.clear();
		count[(double)INT_MIN] = 0;

		for (int j = 0; j < size; j++)
		{
			if (i == j) continue;

			int x1 = points[j].x;
			int y1 = points[j].y;
			if (x == x1 && y == y1)
			{
				du += 1;
			}
			else
			{
				if (x == x1)
				{
					count[(double)INT_MAX] ++;
				}
				else
				{
					double k = (double)(y1 - y) / (double)(x1 - x);
					count[k]++;
				}
			}
		}

		for (auto it = count.begin(); it != count.end(); it++)
		{
			if (it->second + du> ans)
			{
				ans = it->second + du;
			}
		}

	}
	return ans + 1;
}


bool isInterleave(string s1, string s2, string s3) 
{
	if (s1.length() + s2.length() != s3.length())
		return false;

	if (s1.length() < s2.length())
		return isInterleave(s2, s1, s3);

	vector<bool> f(s2.length() + 1, true);
	for (size_t i = 1; i <= s2.length(); ++i)
		f[i] = s2[i - 1] == s3[i - 1] && f[i - 1];

	for (size_t i = 1; i <= s1.length(); ++i) 
	{
		f[0] = s1[i - 1] == s3[i - 1] && f[0];
		for (size_t j = 1; j <= s2.length(); ++j)
			f[j] = (s1[i - 1] == s3[i + j - 1] && f[j]) || (s2[j - 1] == s3[i + j - 1] && f[j - 1]);
	}
	return f[s2.length()];
}


void dfs_IP(string s, size_t start, size_t step, string ip, vector<string> &result) 
{
	if (start == s.size() && step == 4) 
	{ // 找到一个合法解
		ip.resize(ip.size() - 1);
		result.push_back(ip);
		return;
	}
	if (s.size() - start > (4 - step) * 3)
		return; // 剪枝

	if (s.size() - start < (4 - step))
		return; // 剪枝

	int num = 0;
	for (size_t i = start; i < start + 3; i++) 
	{
		num = num * 10 + (s[i] - '0');
		if (num <= 255) 
		{ // 当前结点合法，则继续往下递归
			ip += s[i];
			dfs_IP(s, i + 1, step + 1, ip + '.', result);
		}

		if (num == 0) break; // 不允许前缀0，但允许单个0
	}
}
vector<string> restoreIpAddresses(string s) 
{
	vector<string> result;
	string ip; // 存放中间结果
	dfs_IP(s, 0, 0, ip, result);
	return result;
}

/*
int minDistance(const string &word1, const string &word2) 
{
	const size_t n = word1.size();
	const size_t m = word2.size();
	int f[n + 1][m + 1];

	for (size_t i = 0; i <= n; i++)
		f[i][0] = i;

	for (size_t j = 0; j <= m; j++)
		f[0][j] = j;

	for (size_t i = 1; i <= n; i++)
	{
		for (size_t j = 1; j <= m; j++)
		{
			if (word1[i - 1] == word2[j - 1])
				f[i][j] = f[i - 1][j - 1];
			else 
			{
				int mn = min(f[i - 1][j], f[i][j - 1]);
				f[i][j] = 1 + min(f[i - 1][j - 1], mn);
			}
		}
	}
	return f[n][m];
}*/


int maximalRectangle(vector<vector<char> > &matrix) 
{
	if (matrix.empty()) return 0;

	const int m = matrix.size();
	const int n = matrix[0].size();
	vector<int> H(n, 0);
	vector<int> L(n, 0);
	vector<int> R(n, n);

	int ret = 0;
	for (int i = 0; i < m; ++i) 
	{
		int left = 0, right = n;
		// calculate L(i, j) from left to right
		for (int j = 0; j < n; ++j) 
		{
			if (matrix[i][j] == '1')
			{
				++H[j];
				L[j] = max(L[j], left);
			}
			else 
			{
				left = j + 1;
				H[j] = 0;
				L[j] = 0;
				R[j] = n;
			}
		}

		// calculate R(i, j) from right to left
		for (int j = n - 1; j >= 0; --j) 
		{
			if (matrix[i][j] == '1') 
			{
				R[j] = min(R[j], right);
				ret = max(ret, H[j] * (R[j] - L[j]));
			}
			else 
			{
				right = j;
			}
		}
	}

	return ret;
}

vector<vector<int> > rets;
vector<vector<int> > fourSum(vector<int> &num, int target) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	sort(num.begin(), num.end());
	rets.clear();

	for (size_t i = 0; i < num.size(); i++)
	{
		if (i > 0 && num[i] == num[i - 1]) continue;

		for (size_t j = i + 1; j < num.size(); j++)
		{
			if (j > i + 1 && num[j] == num[j - 1]) continue;

			size_t k = j + 1;
			size_t t = num.size() - 1;

			while (k < t)
			{
				if (k > j + 1 && num[k] == num[k - 1])
				{
					k++;
					continue;
				}

				if (t < num.size() - 1 && num[t] == num[t + 1])
				{
					t--;
					continue;
				}

				int sum = num[i] + num[j] + num[k] + num[t];
				if (sum == target)
				{
					vector<int> a;
					a.push_back(num[i]);
					a.push_back(num[j]);
					a.push_back(num[k]);
					a.push_back(num[t]);
					rets.push_back(a);
					k++;
				}
				else if (sum < target) k++;
				else t--;
			}
		}
	}
	return rets;
}

int findMin(vector<int> &num)
{
	size_t i = 0;
	size_t j = num.size()-1;
	size_t mid;

	while (i < j && num[i] >= num[j])
	{
		mid = (i + j) / 2;
		if (num[i] < num[mid])
		{
			i = mid + 1;
		}
		else
		if (num[i] == num[mid])
		{
			i = mid;
			if (i+1 == j)
			{
				return num[i]>num[j] ? num[j] : num[i];
			}
		}
		else
		{
			j = mid - 1;
		}
	}

	if (j < num.size() - 1 && num[i] > num[j+1])
	{
		i = j + 1;
	}

	if (i < num.size() - 1 && num[i]> num[i + 1])
	{
		i += 1;
	}

	return num[i] > num[0] ?num[0]:num[i];
}