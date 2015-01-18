#include "stdafx.h"
#include "code_7.h"
#define MaxInt 0x3f3f3f3f
#define N 110

int maps[N][N], low[N], visited[N];
int n;

int main(int argc, char * argv)
{
	int i, v, j, ans;
	while (scanf("%d", &n) != EOF)
	{
		memset(maps, MaxInt, sizeof(maps));
		for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
		{
			scanf("%d", &v);
			maps[i][j] = maps[i][j] = v;
		}
		ans = prim();
		printf("%d\n", ans);
	}
	return 0;
}

int prim()
{
	int i, j, pos, min, result = 0;
	memset(visited, 0, sizeof(visited));	//从某点开始，分别标记和记录该点
	visited[1] = 1; pos = 1;				//第一次给low数组赋值
	for (i = 1; i <= n; i++)
	if (i != pos) low[i] = maps[pos][i];	//再运行n-1次
	for (i = 1; i<n; i++)					//找出最小权值并记录位置
	{
		min = MaxInt;
		for (j = 1; j <= n; j++)
		if (visited[j] == 0 && min>low[j])
		{
			min = low[j]; pos = j;
		}									//最小权值累加
		result += min;						//标记该点
		visited[pos] = 1;					//更新权值
		for (j = 1; j <= n; j++)
		if (visited[j] == 0 && low[j] > maps[pos][j])
			low[j] = maps[pos][j];
	}
	return result;
}


bool cmp(const string s1, const string s2) {
	return (s1 + s2) > (s2 + s1);
}

string largestNumber(vector<int> &num){
		vector<string> s_num(num.size());
		stringstream stream;
		for (int i = 0; i < num.size(); ++i) {
			stream << num[i];
			stream >> s_num[i];
			stream.clear();
		}
		sort(s_num.begin(), s_num.end(), cmp);
		string tmp_res;
		for (int i = 0; i < s_num.size(); ++i) {
			tmp_res += s_num[i];
		}

		string res;
		bool flag = false;
		for (int i = 0; i < tmp_res.size(); ++i) {
			if (tmp_res[i] != '0') {
				res.push_back(tmp_res[i]);
				flag = true;
			}
			else if (flag) {
				res.push_back(tmp_res[i]);
			}
		}
		if (!flag) res.push_back('0');
		return res;
	}

int calculateMinimumHP(vector<vector<int> > &dungeon)
{ 
	int m = dungeon.size();
	int n = dungeon[0].size();

	//int dp[m][n];
	int dp[1][1];
	dp[m - 1][n - 1] = max(0 - dungeon[m - 1][n - 1], 0);
	for (int i = m - 2; i >= 0; i--){
		dp[i][n - 1] = max(dp[i + 1][n - 1] - dungeon[i][n - 1], 0);
	}
	for (int i = n - 2; i >= 0; i--){
		dp[m - 1][i] = max(dp[m - 1][i + 1] - dungeon[m - 1][i], 0);
	}
	for (int i = m - 2; i >= 0; i--){
		for (int j = n - 2; j >= 0; j--){
			dp[i][j] = max(min(dp[i][j + 1], dp[i + 1][j]) - dungeon[i][j], 0);
		}
	}
	return dp[0][0] + 1;
}
int findPeakElement(const vector<int> &num)
{
	// greater than its neighbors.
	// num[-1] = num[n] = -∞.
	size_t n = num.size();
	if (num[0] > num[1])
	{
		return 0;
	}
	if (num[n-1] > num[n-2])
	{
		return n - 1;
	}

	for (size_t i = 1; i < n-1; i++)
	{
		if (num[i-1] < num[i] && num[i] > num[i+1])
		{
			return i;
		}
	}

	return 0;
	/*
	A peak element is an element that is greater than its neighbors.

Given an input array where num[i] ≠ num[i+1], find a peak element and return its index.

The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.

You may imagine that num[-1] = num[n] = -∞.

For example, in array [1, 2, 3, 1], 3 is a peak element and your function should return the index number 2.
	*/
}
void getints(const string & version, queue<int> & v)
{
	int i = 0, j = 0;
	while (j < version.length())
	{
		if (version[j] == '.')
		{
			v.push(atoi(version.substr(i, j - i).c_str()));
			i = j + 1;
		}
		j += 1;
	}
	v.push(atoi(version.substr(i, j - i).c_str()));
}
int isAllZero(queue<int> & v)
{
	while (!v.empty())
	{
		if (v.front() != 0)
		{
			return 0;
		}
		v.pop();
	}
	return 1;
}
int compareVersion(string version1, string version2)
{
	queue<int> v1,v2;
	getints(version1, v1);
	getints(version2, v2);
	while (!v1.empty() && !v2.empty())
	{
		if (v1.front() == v2.front())
		{
			v1.pop();
			v2.pop();
			continue;
		}
		return v1.front() > v2.front() ? 1 : -1;
	}

	if (v1.empty() && v2.empty())
	{
		return 0;
	}
	
	if (!v1.empty())
	{
		return isAllZero(v1) ? 0 : 1;
	}
	else
	{
		return isAllZero(v2) ? 0 : -1;
	}


	/*Compare two version numbers version1 and version1.
If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.

You may assume that the version strings are non-empty and contain only digits and the . character.
The . character does not represent a decimal point and is used to separate number sequences.
For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.

Here is an example of version numbers ordering:

0.1 < 1.1 < 1.2 < 13.37*/
}
string convertToTitle(int n)
{
	string ret;
	char c;
	while (n > 0)
	{
		c = 'A' - 1;
		if (n % 26 == 0)
		{
			c = 'Z';
		}
		else
		{
			c += n % 26;
		}
		
		ret = c + ret;
		n /= 26;
		if (n == 1 && c == 'Z')
		{
			break;
		}

	}
	return ret;
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

int RecArea(vector<int>& heights)
{
	int len = heights.size();
	int maxArea = 0;
	vector<int> hIndex;
	int i = 0;
	while (i < len)
	{
		if (hIndex.size() == 0 || heights[i] >= heights[hIndex[hIndex.size() - 1]])//hindex是栈，记录索引
		{
			hIndex.push_back(i++);
		}
		else
		{
			int idex = hIndex[hIndex.size() - 1];
			hIndex.pop_back();
			int w = hIndex.size() == 0 ? i : i - hIndex[hIndex.size() - 1] - 1;
			//栈里面的都是递增的矩形（索引），w是i后面的矩形（含）一直到当前栈顶（不含）的矩形s，也就是已经出栈的矩形s，个数/宽度
			int cur_area = heights[idex] * w;//前面出栈的的矩形是最矮的，作为高度
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

	int minWidth = INT_MAX, min_start = 0; // 窗口大小，起点
	int wnd_start = 0;
	int appeared = 0; //特定情况下增长，完整包含了一个T
	//尾指针不断往后扫
	for (size_t wnd_end = 0; wnd_end < S.size(); wnd_end++) 
	{
		if (expected_count[S[wnd_end]] > 0)
		{ // this char is a part of T
			appeared_count[S[wnd_end]] += 1;
			if (appeared_count[S[wnd_end]] <= expected_count[S[wnd_end]])//等号，出现的字母刚刚计数，还没有反映到appeared中
				appeared += 1;
		}

		if (appeared == T.size())
		{ // 完整包含了一个T   // 收缩头指针
			while (appeared_count[S[wnd_start]] > expected_count[S[wnd_start]] || expected_count[S[wnd_start]] == 0)
			{
				appeared_count[S[wnd_start]] -= 1;//如果是字母超数，最多减到相等，如果T中没有，则会出现负数
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
			output.pop_back(); // 撤销上一个push_back 的砍
		}
	}
}
vector<vector<string>> partition_p(string s) 
{
	vector<vector<string>> result;
	vector<string> output; // 一个partition 方案
	DFS_p(s, 0, output, result);
	return result;
}
// 搜索必须以s[start] 开头的partition 方案
stack<int> data;
stack<int> mi;
void push(int x) {
	data.push(x);
	if (mi.empty() || x <= mi.top())
	{
		mi.push(x);
	}
}

void pop() {
	if (data.top() == mi.top())
	{
		mi.pop();
	}
	data.pop();
}

int top() {
	return data.top();
}

int getMin() {
	return mi.top();
}

