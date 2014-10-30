#include "stdafx.h"
#include "code_7.h"

int main(int argc, char * argv)
{


	return 0;
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