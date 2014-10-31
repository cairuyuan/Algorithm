#include "stdafx.h"
#include "code_5.h"


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


	vector<int> vi;

	int down = matrix.size() - 1;
	if (down == -1)
	{
		return vi;
	}
	int right = matrix[0].size() - 1;//down若不为0，则right 至少为1;
	int left = 0;
	int up = 0;
	int i, j;
	/*
	up
	left			right
	down
	以上四个为下标的边界
	*/

	while (left < right && up < down)
	{
		/*
		每个循环绕一圈
		*/
		i = up;//一圈中，顶层
		j = left;
		for (; j < right; j += 1)//最后一个不读，作为另一条边的开始
		{
			vi.push_back(matrix[i][j]);
			cout << matrix[i][j] << " ";
		}

		i = up;
		j = right;
		for (; i < down; i += 1)
		{
			vi.push_back(matrix[i][j]);
			cout << matrix[i][j] << " ";
		}
		i = down;
		j = right;
		for (; j > left; j -= 1)
		{
			vi.push_back(matrix[i][j]);
			cout << matrix[i][j] << " ";
		}

		i = down;
		j = left;
		for (; i > up; i -= 1)
		{
			vi.push_back(matrix[i][j]);
			cout << matrix[i][j] << " ";
		}

		left += 1;
		right -= 1;
		up += 1;
		down -= 1;
	}


	if (down == up) //只有1层
	{
		for (i = down, j = left; j <= right; j += 1)
		{
			vi.push_back(matrix[i][j]);
			cout << matrix[i][j] << " ";
		}
		return vi;
	}

	if (right == left)//竖条
	{
		for (j = right, i = up; i <= down; i += 1)
		{
			vi.push_back(matrix[i][j]);
			cout << matrix[i][j] << " ";
		}
		return vi;
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
	/*
	A已经排好序
	如果找到target，则返回的是其下标
	如果没有找到，返回的是应该插入的下标，此下标后的元素相应后移
	*/
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
		if (A[m] == target) return m;
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



vector<vector<int>> threeSum(vector<int>& num)
{
	//a + b + c = 0; 
	vector<vector<int>> result;
	if (num.size() < 3) return result;

	sort(num.begin(), num.end());

	const int target = 0;
	auto last = num.end();
	for (auto a = num.begin(); a < prev(last, 2); a = upper_bound(a, prev(last, 2), *a)) 
	{
		for (auto b = next(a); b < prev(last); b = upper_bound(b, prev(last), *b)) //使用upper_bound逃过重复部分
		{
			const int c = target - *a - *b;
			if (binary_search(next(b), last, c))
			{
				result.push_back(vector < int > { *a, *b, c });
			}
		}
	}
	
	return result;
}


int threeSumClosest(vector<int>& num, int target) 
{
	int result = 0;
	int min_gap = INT_MAX;
	int sum, gap;

	sort(num.begin(), num.end());

	for (auto a = num.begin(); a != prev(num.end(), 2); a = upper_bound(a, prev(num.end(), 2), *a))
	{
		auto b = next(a);
		auto c = prev(num.end());
		while (b < c) 
		{
			sum = *a + *b + *c;
			gap = abs(sum - target);
			if (gap < min_gap) 
			{
				result = sum;
				min_gap = gap;
			}
			//sum < target ? ++b : --c;
			if (sum < target)
			{
				b = upper_bound(b, c, *b);
			}
			else
			{
				c = prev(lower_bound(b, c, *c));
			}
		}
	}
	return result;
}

int num_size;
vector<int> A;
list<int> index;

void  getPermutation2(vector<vector<int> > &ret,vector<int> &num, int n,int k)//n的阶乘的第k个
{
	list<int> C(index);

	vector<int>  s;
	int x;
	int m = n;
	for (int i = 0; i < m; i += 1)
	{
		x = k / A[n - 1];
		auto it = next(C.begin(),x);
		s.push_back(num[*it]);//s.push_back(num[C[x]])
		C.erase(it);//C.erase(C.begin() + x);

		k %= A[n - 1];
		n -= 1;
	}

	ret.push_back(s);
}


vector<vector<int> > permute(vector<int> &num) 
{
	vector<vector<int> > ret;
	num_size = num.size();
	
	if (num_size == 0)
	{
		return ret;
	}
	A.push_back(1);
	index.push_back(0);

	int i;
	for (i = 1; i <= num_size; i++)
	{
		index.push_back(i);
		A.push_back(i* A[i - 1]);
	}
	for (i = 0; i < A[num_size]; i += 1)
	{
		getPermutation2(ret, num, num_size, i);
	}

	return ret;
}


void setZeroes(vector<vector<int> > &matrix) 
{
	const size_t m = matrix.size();
	const size_t n = matrix[0].size();

	bool row_has_zero = false; // 第一行是否存在0
	bool col_has_zero = false; // 第一列是否存在0

	for (size_t i = 0; i < n; i++)//第一行
	{
		if (matrix[0][i] == 0)
		{
			row_has_zero = true;
			break;
		}
	}
	for (size_t i = 0; i < m; i++)//第一列
	{
		if (matrix[i][0] == 0)
		{
			col_has_zero = true;
			break;
		}
	}


	for (size_t i = 1; i < m; i++)
	{
		for (size_t j = 1; j < n; j++)//扫描1,1以后的点，用第一行/列记录
		{
			if (matrix[i][j] == 0)
			{
				matrix[0][j] = 0;
				matrix[i][0] = 0;
			}
		}
	}


	for (size_t i = 1; i < m; i++)//内部置零
	{
		for (size_t j = 1; j < n; j++)
		{
			if (matrix[i][0] == 0 || matrix[0][j] == 0)
			{
				matrix[i][j] = 0;
			}
		}
	}


	if (row_has_zero)
	{
		for (size_t i = 0; i < n; i++)
		{
			matrix[0][i] = 0;
		}
	}

	if (col_has_zero)
	{
		for (size_t i = 0; i < m; i++)
		{
			matrix[i][0] = 0;
		}
	}

}


template<typename BidiIt>
bool next_permutation_(BidiIt first, BidiIt last)
{

	const auto rfirst = reverse_iterator<BidiIt>(last);
	const auto rlast = reverse_iterator<BidiIt>(first);

	auto pivot = next(rfirst);

	while (pivot != rlast && !(*pivot < *prev(pivot)))
	{
		++pivot;
	}

	if (pivot == rlast) 
	{
		reverse(rfirst, rlast);
		return false;
	}

	auto change = find_if(rfirst, pivot, bind1st(less<int>(), *pivot));
	swap(*change, *pivot);
	reverse(rfirst, pivot);
	return true;
}


void nextPermutation2(vector<int> &num)
{
	int num_size = num.size();
	if (num_size <= 1) return;

	int i = num_size - 1;
	int j = num_size - 1;
	int ii = 0;

	while (i >= 1 && num[i - 1] >= num[i]) i -= 1;

	if (i)
	{
		ii = i--;
		while (num[i] >= num[j]) j -= 1;
		swap(num[i], num[j]);
	}

	for (int k = 0; k<(num_size - ii) / 2; k++)
	{
		swap(num[ii + k], num[num_size - 1 - k]);
	}
}



bool nextPermutation(vector<int> &num)
{
	/*
	函数实现原理如下：
	在当前序列中，从尾端往前寻找两个相邻元素，前一个记为*i，后一个记为*ii，并且满足*i < *ii。
	然后再从尾端寻找另一个元素*j，满足*i < *j，将第i个元素与第j个元素对调，
	并将第ii个元素之后（包括ii）的所有元素颠倒排序，即求出下一个序列了。
	*/
	int num_size = num.size();

	int i = num_size - 1;
	int j = num_size - 1;
	int ii = 0;

	if (num_size <= 1) return false;

	while (i >= 1 && num[i - 1] >= num[i]) i -= 1;

	if (!i)
	{
		return false;
	}

	ii = i--;
	while (num[i] >= num[j]) j -= 1;
	swap(num[i], num[j]);

	for (int k = 0; k < (num_size - ii) / 2; k++)
	{
		swap(num[ii + k], num[num_size - 1 - k]);
	}

	return true;
}


vector<vector<int> > permuteUnique(vector<int> &num)
{
	vector<vector<int> > ret;
	sort(num.begin(),num.end());
	do
	{
		ret.push_back(num);
	} while (nextPermutation(num));

	return ret;
}