#include "stdafx.h"
#include "code_5.h"




int main(int argc, char * argv)
{

	return 0;
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
