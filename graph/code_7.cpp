#include "stdafx.h"
#include "code_7.h"

int main(int argc, char * argv)
{

	int x = lengthOfLongestSubstring2("abcabc");
	return 0;
}


bool isPalindrome(string &s, int start, int end)
{
	while (start < end)
	{
		if (s[start++] != s[end--])
			return false;
	}
	return true;
}
void DFS(string &s, size_t prev, size_t start, vector<string>& output, vector<vector<string>> &result) 
{
	if (start == s.size()) 
	{ 
		if (isPalindrome(s, prev, start - 1))
		{ 
			output.push_back(s.substr(prev, start - prev));
			result.push_back(output);
			output.pop_back();
		}
		return;
	}
	DFS(s, prev, start + 1, output, result);
	if (isPalindrome(s, prev, start - 1)) 
	{
		output.push_back(s.substr(prev, start - prev));
		DFS(s, start, start + 1, output, result);
		output.pop_back();
	}
}

vector<vector<string>> partition(string s)
{
	vector<vector<string>> result;
	vector<string> output;
	DFS(s, 0, 1, output, result);
	return result;
}



int maxProduct(int A[], int n)
{
	int ma = A[0];
	int mi = A[0];
	int a = ma;
	for (int i = 1; i < n; i += 1)
	{
		int tmpmax = ma * A[i];
		int tmpmin = mi * A[i];
		ma = max(max(tmpmax, tmpmin), A[i]);
		mi = min(min(tmpmax, tmpmin), A[i]);
		a = max(a,ma);
	}

	return a;
}

/*
abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!"#$%&'()*+,-./:;<=>?@[\]^_`{|}~
所有字符都包含
*/
int lengthOfLongestSubstring(string s) 
{
	const int ASCII_MAX = 26;
	int last[ASCII_MAX];						 // 记录字符上次出现过的位置
	fill(last, last + ASCII_MAX, -1);			 // 0 也是有效位置，因此初始化为-1
	int len = 0, max_len = 0;

	for (size_t i = 0; i < s.size(); i++, len++) 
	{
		if (last[s[i] - 'a'] >= 0) 
		{
			max_len = max(len, max_len);
			len = 0;
			i = last[s[i] - 'a'] + 1;
			fill(last, last + ASCII_MAX, -1);	 // 重新开始
		}
		last[s[i] - 'a'] = i;
	}
	return max(len, max_len);					 // 别忘了最后一次，例如"abcd"
}

int lengthOfLongestSubstring2(string s) 
{
	int i, j, len = s.length(), maxx = 0;
	bool sign[95];
	memset(sign, 0, sizeof(sign));

	for (i = 0, j = 0; j < len; ++j)
	{
		while (sign[s[j] - ' '] == 1)
		{
			sign[s[i] - ' '] = 0;
			++i;
		}
		sign[s[j] - ' '] = 1;
		maxx = max(maxx, j - i + 1);
	}
	return maxx;
}


bool isValid(const vector<vector<char> > &board, int x, int y) {
	int i, j;
	for (i = 0; i < 9; i++) // 检查y 列
		if (i != x && board[i][y] == board[x][y]) return false;

	for (j = 0; j < 9; j++) // 检查x 行
		if (j != y && board[x][j] == board[x][y]) return false;

	for (i = 3 * (x / 3); i < 3 * (x / 3 + 1); i++)
		for (j = 3 * (y / 3); j < 3 * (y / 3 + 1); j++)
			if (i != x && j != y && board[i][j] == board[x][y]) return false;
	return true;
}

bool solveSudoku(vector<vector<char> > &board) 
{
	for (int i = 0; i < 9; ++i)
	for (int j = 0; j < 9; ++j) 
	{
		if (board[i][j] == '.')
		{
			for (int k = 0; k < 9; ++k)
			{
				board[i][j] = '1' + k;
				if (isValid(board, i, j) && solveSudoku(board)) return true;

				board[i][j] = '.';
			}
			return false;
		}
	}
	return true;
}

