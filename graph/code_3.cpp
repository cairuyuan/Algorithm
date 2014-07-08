
#include "stdafx.h"
#include "head.h"
#include "Tree.h"
#include "LinkNode.h"
#include "code_2.h"


bool isValidSudoku(vector<vector<char> > &board);
int romanToInt(string s);

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}


int romanToInt(string s)
{
	int length = s.length();
	if (length <1) return 0;

	map<char, int> m;
	m['I'] = 1;
	m['V'] = 5;
	m['X'] = 10;
	m['L'] = 50;
	m['C'] = 100;
	m['D'] = 500;
	m['M'] = 1000;

	int i = length - 1;
	int sum = m[s[i--]];

	while (i >= 0)
	{
		if (m[s[i + 1]] > m[s[i]])
		{
			sum -= m[s[i--]];
		}
		else
		{
			sum += m[s[i--]];
		}
	}
	return sum;
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
