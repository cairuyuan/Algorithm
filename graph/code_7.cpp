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
�����ַ�������
*/
int lengthOfLongestSubstring(string s) 
{
	const int ASCII_MAX = 26;
	int last[ASCII_MAX];						 // ��¼�ַ��ϴγ��ֹ���λ��
	fill(last, last + ASCII_MAX, -1);			 // 0 Ҳ����Чλ�ã���˳�ʼ��Ϊ-1
	int len = 0, max_len = 0;

	for (size_t i = 0; i < s.size(); i++, len++) 
	{
		if (last[s[i] - 'a'] >= 0) 
		{
			max_len = max(len, max_len);
			len = 0;
			i = last[s[i] - 'a'] + 1;
			fill(last, last + ASCII_MAX, -1);	 // ���¿�ʼ
		}
		last[s[i] - 'a'] = i;
	}
	return max(len, max_len);					 // ���������һ�Σ�����"abcd"
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


int RecArea(vector<int>& heights)
{
	int len = heights.size();
	int maxArea = 0;
	vector<int> hIndex;
	int i = 0;
	while (i < len)
	{
		if (hIndex.size() == 0 || heights[i] >= heights[hIndex[hIndex.size() - 1]])//hindex��ջ����¼����
		{
			hIndex.push_back(i++);
		}
		else
		{
			int idex = hIndex[hIndex.size() - 1];
			hIndex.pop_back();
			int w = hIndex.size() == 0 ? i : i - hIndex[hIndex.size() - 1] - 1;
			//ջ����Ķ��ǵ����ľ��Σ���������w��i����ľ��Σ�����һֱ����ǰջ�����������ľ���s��Ҳ�����Ѿ���ջ�ľ���s������/���
			int cur_area = heights[idex] * w;//ǰ���ջ�ĵľ�������ģ���Ϊ�߶�
			maxArea = max(maxArea, cur_area);
		}
	}
	return  maxArea;
}
/*
int maximalRectangle(vector<vector<char> > &matrix)
{
	int rows = matrix.size();
	if (rows == 0) return 0;
	int cols = matrix[0].size();
	int maxArea = 0;
	vector<int> pre_row(cols + 1, 0);

	for (int row = 0; row < rows; ++row)
	{
		vector<int> cur_row(cols + 1, 0);
		for (int col = 0; col < cols; ++col)
		{
			if (matrix[row][col] == '1')
				cur_row[col] = pre_row[col] + 1;
			else
				cur_row[col] = 0;
		}
		int cur_area = RecArea(cur_row);
		maxArea = max(maxArea, cur_area);
		pre_row = cur_row;
	}
	return maxArea;
}
*/


string minWindow(string S, string T)
{
	if (S.empty()) return "";
	if (S.size() < T.size()) return "";

	const int ASCII_MAX = 256;
	int appeared_count[ASCII_MAX];
	int expected_count[ASCII_MAX];
	fill(appeared_count, appeared_count + ASCII_MAX, 0);
	fill(expected_count, expected_count + ASCII_MAX, 0);

	for (size_t i = 0; i < T.size(); i++) expected_count[T[i]] += 1;

	int minWidth = INT_MAX, min_start = 0; // ���ڴ�С�����
	int wnd_start = 0;
	int appeared = 0; //�ض����������������������һ��T
	//βָ�벻������ɨ
	for (size_t wnd_end = 0; wnd_end < S.size(); wnd_end++) 
	{
		if (expected_count[S[wnd_end]] > 0)
		{ // this char is a part of T
			appeared_count[S[wnd_end]] += 1;
			if (appeared_count[S[wnd_end]] <= expected_count[S[wnd_end]])//�Ⱥţ����ֵ���ĸ�ոռ�������û�з�ӳ��appeared��
				appeared += 1;
		}

		if (appeared == T.size())
		{ // ����������һ��T   // ����ͷָ��
			while (appeared_count[S[wnd_start]] > expected_count[S[wnd_start]] || expected_count[S[wnd_start]] == 0)
			{
				appeared_count[S[wnd_start]] -= 1;//�������ĸ��������������ȣ����T��û�У������ָ���
				wnd_start += 1;
			}
			if (minWidth > (wnd_end - wnd_start + 1)) 
			{
				minWidth = wnd_end - wnd_start + 1;
				min_start = wnd_start;
			}
		}
	}

	if (minWidth == INT_MAX) return "";
	else return S.substr(min_start, minWidth);
}



void DFS_p(string &s, int start, vector<string>& output, vector<vector<string>> &result) 
{
	if (start == s.size())
	{
		result.push_back(output);
		return;
	}
	for (int i = start; i < s.size(); i++) 
	{
		if (isPalindrome(s, start, i)) 
		{ 
			output.push_back(s.substr(start, i - start + 1));
			DFS_p(s, i + 1, output, result); 
			output.pop_back(); // ������һ��push_back �Ŀ�
		}
	}
}
bool isPalindrome(string &s, int start, int end) 
{
	while (start < end) 
	{
		if (s[start] != s[end]) return false;
		start += 1;;
		end -= 1;
	}
	return true;
}

vector<vector<string>> partition(string s) 
{
	vector<vector<string>> result;
	vector<string> output; // һ��partition ����
	DFS_p(s, 0, output, result);
	return result;
}
// ����������s[start] ��ͷ��partition ����