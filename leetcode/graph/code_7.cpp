#include "stdafx.h"
#include "code_7.h"
#include "LinkNode.h"
#include "head.h"


#define MaxInt 0x3f3f3f3f
#define N 110

int maps[N][N], low[N], visited[N];
int nn;

class tmp{
	virtual int x();
};

void comb(int , int , int *);
vector<string> findWords(vector<vector<char>>& board, vector<string>& words);
int findKth(int *a, int m, int *b, int n, int k);
int findKth(int *a, int m, int k);
void myqsort(int a[], int length );
int bsearch(int a[], int length, int target);

int mostContainer(int a[],int length);
int calculate(string s);
int findKth2(int *a, int l, int r);
int calculate2(string s);

int computeArea(int A, int B, int C, int D, int E, int F, int G, int H);
int calculate4(string s);

int maximalSquare(vector<vector<char>>& matrix);

int departition(vector<int> &a, int start, int end);
void mydesort(vector<int> &a, int start, int end);
int findKL(vector<int>& nums, int k);



int findKLsub(vector<int>& a, int start, int end, int k){
	if (start > end || start < 0 || end < 0) return -1;

	if (start == end && start == k) return a[k];

	int p = departition(a, start, end);
	if (p < k) {
		return findKLsub(a,p,end,k);
	} else{
		return findKLsub(a, start, p - 1, k);
	}
}

int findKL(vector<int>& a, int k){
	int L = 0, R = a.size() - 1;
	while (L < R) {
		int i = L, j = R, p = a[i];
		while (i < j) {
			while (i < j && a[j] < p) --j;
			a[i] = a[j];
			while (i < j && a[i] >= p) ++i;
			a[j] = a[i];
		}
		a[i] = p;

		if (i == k - 1) return a[k - 1];
		else if (i > k - 1) R = i - 1;
		else L = i + 1;
	}
	return a[k - 1];
}


int departition(vector<int> &a, int start, int end){
	int i = start, j = end, p = a[start];
	while (i < j){
		while (i < j && a[i] >= p) i += 1;
		while (i < j && a[j]  < p) j -= 1;
		if (i < j) swap(a[i], a[j]);
		else if (a[i] > p) swap(a[start],a[i]);
	}
	return i;
}

void mydesort(vector<int> &a, int start, int end){
	if (start >= end || start < 0 || end < 0) return;
	int p = departition(a, start, end);
	mydesort(a, start, p - 1);
	mydesort(a, p, end);
}

int maximalSquare(vector<vector<char>>& matrix){
	size_t Y = matrix.size();
	if (Y == 0) return 0;
	size_t X = matrix[0].size();
	vector<int> size(X, 0);
	int p, ret = 0;
	for (size_t j = 0; j < X; j++) {
		size[j] = matrix[0][j] == '0' ? 0 : 1;
		ret = max(ret, size[j]);
	}
	for (size_t i = 1; i < Y; i++) {
		p = matrix[i][0] == '0' ? 0 : 1;
		ret = max(ret, p);
		for (size_t j = 1; j < X; j++) {
			int tmp = 0;
			if (matrix[i][j] != '0') {
				tmp = 1 + min(min(size[j], size[j - 1]), p);
			}
			size[j - 1] = p;
			p = tmp;
			ret = max(ret, p);
		}
		size[X - 1] = p;
	}
	return ret*ret;
}
int calculate4(string s){
	stack<int> ss;
	stack<char> op;
	int i = 0, t;

	while (i < s.length()) {
		switch (s[i]){
		case ' ':i++; break;
		case '+':
		case '-':
			if (!op.empty()){
				t = ss.top(); ss.pop();
				if (op.top() == '+') t = ss.top() + t; 
				else t = ss.top() - t;  
				ss.pop();
				ss.push(t);
				op.pop();
			}
			op.push(s[i]);
			i += 1;
			break;
		case '*':
			i++; op.push('*'); break;
		case '/':
			i++; op.push('/'); break;
		default:
			t = 0;
			while (s[i] >= '0' && s[i] <= '9' && i < s.length()) {
				t = t * 10 + s[i] - '0';
				i += 1;
			}
			if (!op.empty() && (op.top() == '/' || op.top() == '*')) {
				if (op.top() == '/') t = ss.top() / t; 
				else                 t = ss.top() * t; 
				ss.pop(); op.pop();
			}
			ss.push(t);
		}

	}
	if (!op.empty()) {
		t = ss.top(); ss.pop();
		if (op.top() == '+')       t = ss.top() + t;
		else if (op.top() == '-')  t = ss.top() - t;
		ss.push(t);
	}
	return ss.top();
}

int calculate2(string s){
	stack<int> ss;
	stack<char> op;
	int i = 0, t;
	while (i < s.length()) {
		switch (s[i]) {
		case ' ':break;
		case '+':op.push('+'); break;
		case '-':op.push('-'); break;
		case '(':op.push('('); break;
		default:
			t = 0;
			if (s[i] == ')'){
				t = ss.top(); ss.pop(); op.pop();
			} else {
				while (s[i] >= '0' && s[i] <= '9' && i < s.length()) {
					t = t * 10 + s[i] - '0';
					i += 1;
				}
				i -= 1;
			}
			while (!op.empty() && op.top() != '(') {
				t = ss.top() + (op.top() == '+' ? 1 : -1) * t;
				ss.pop(); op.pop();
			}
			ss.push(t);
			break;
		}
		i += 1;
	}
	return  ss.top();
}
int computeArea(int A, int B, int C, int D, int E, int F, int G, int H){
	int x = max(A, E), y = max(B, F);
	int X = min(C, G), Y = min(D,H);
	return (C - A) * (D - B) + (G - E)*(H - F) - max(0.0, (X*1.0 - x))*max(0.0, (Y*1.0 - y));
}
int findKth2(int *a, int i, int j){
	if (a == NULL || j <= i) return -1;

	int l = i, r = j;
	int piv = a[r];
	while (r > l){
		while (r > l && a[r] >= piv) r -= 1;
		while (r > l && a[l] <  piv) l += 1;

		if (l < r)            swap(a[l], a[r]); 
		else if (a[l] > piv)  swap(a[l], a[j]); 
	}
	return l;// [0, l], [l+1 , m-1]
}

static int sindex = 0;
int fetchNextToken(string &s, int isLookUp){
	int ret = -5;
	int presindex = sindex;
	while (sindex < s.length()) {
		switch (s[sindex]) {
		case ' ':break;
		case '+':ret = -1; break;
		case '-':ret = -2; return -2;
		case '*':ret = -3; return -3;
		case '/':ret = -4; return -4;
		default:
			ret = 0;
			while (s[sindex] >= '0' && s[sindex] <= '9' && sindex < s.length()) {
				ret = ret * 10 + s[sindex] - '0';
				sindex += 1;
			}
			sindex -= 1;
		}
		sindex += 1;
	}
	if (isLookUp)  sindex = presindex; 

	return ret;
}

int calculate(string s) {
	
	stack<int> ss;
	stack<char> op;
	int token = 0;
	int ret;
	while ((token = fetchNextToken(s, 0)) != -5) {
		if (token >=0 ) {//数字
			;
		}
	}
	return 0;
}





int mostContainer(int a[], int length){
	if (!a || length <= 0)
		return 0;

	int i = 1, j = length - 2;
	int ret  = min(a[0], a[length - 1])*length;
	while (i < j)
	{
		while (a[i] < a[i - 1] && i < j) i += 1;
		while (a[j] < a[j + 1] && i < j) j -= 1;
		const int area = min(a[i], a[j]) *(j - 1);

		if (area > ret) ret = area; 
	}

	return ret;
}
int bsearch(int a[], int length, int target){
	int i = 0, j = length - 1, m;
	while (i < j) {
		m = (i + j) / 2;
		if (a[m] == target) return m;
		a[m] <target ? i = m + 1 : j = m - 1;
	}
	return i;
}
int findKth(int *a, int m, int *b, int n, int k){

	if (m > n)  return findKth(b,n,a,m,k);
	if (m == 0) return b[k - 1];
	if (k == 1) return min(a[0],b[0]);

	int pa = min(m , k/2);
	int pb = k - pa;

	if (a[pa - 1] < b[pb - 1])
		return findKth(a + pa, m - pa, b, pb, k - pa);
	else if (a[pa - 1] > b[pb - 1])
		return findKth(a, pa, b + pb, n - pb, k - pb);
	else
		return a[pa -1];
}

int findKth(int *a, int m, int k = 0){

	if (a == NULL) return 0;
	//if (m < k) return 0;

	int extmp;
	int piv = a[m - 1];
	int r = m - 1, l = 0;
	while (r > l){
		while (r > l && a[r] >= piv) r -= 1;
		while (r > l && a[l] <  piv) l += 1;
		if (l < r) {		//尚未遇到的情况，调整
			swap(a[l], a[r]);
		}
		else if (a[l] > piv) {//lr遇到或超过，做最后一次调整,1 7 2 4 8 6
			swap(a[l], a[m - 1]);
		}
	}
	return l;// [0, l], [l+1 , m-1]
}

void myqsort(int a[], int length){
	if (a == NULL || length < 2) return;
	int Lcount = findKth(a, length)+1;
	myqsort(a, Lcount);
	myqsort(a + Lcount, length - Lcount);
}


ListNode* removeElements(ListNode* head, int val){

	ListNode *m = NULL, *p = NULL, *tmp = NULL;

	while(head != NULL && head->val == val){
		tmp = head;
		head = head->next;
		tmp->next = NULL;
		delete tmp;
	}

	if (head == NULL) return NULL;

	p = head;
	m = p->next;

	while (m) {
		if (m->val == val){
			tmp = m;
			m = p->next = m->next;
			tmp->next = NULL;
			delete tmp;
		}
		else{
			p = m;
			m = m->next;
		}
	}
	return head;
}

void comb(int m, int k, int *a)
{
	int i, j;
	for (i = m; i >= k; i--)
	{
		a[k-1] = i;
		if (k > 1)
		{
			comb(i - 1, k - 1,a);
		}
		else
		{
			for (j = 0; j < 3; j += 1)
				printf("%4d", a[j]);
			printf("\n");
		}
	}
}

int prim()
{
	int pos, min, result = 0;
	memset(visited, 0, sizeof(visited));
	pos = 0;
	visited[pos] = 1;			
	for (int i = 0; i < nn; i++)			//初始化low数组
	{				
		if (i != pos)  low[i] = maps[pos][i];//初始点到各点的距离/权值
	}

	for (int i = 0; i < nn; i++) 
	{
		min = MaxInt;							
		for (int j = 0; j < nn; j++)	//i是当前点，搜索与i最近的点pos，距离min
		{
			if (visited[j] == 0 && min > low[j])
			{
				min = low[j];
				pos = j;	 
			}									
		}
		result += min;						
		visited[pos] = 1;	

		for (int j = 0; j < nn; j++)
		{
			if (visited[j] == 0 && low[j] > maps[pos][j])//更新： 当前点到j的距离 大于 pos到j的距离
				low[j] = maps[pos][j];
		}
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
	if (num[0] > num[1]) {
		return 0;
	}
	if (num[n-1] > num[n-2]) {
		return n - 1;
	}

	for (size_t i = 1; i < n-1; i++) {
		if (num[i-1] < num[i] && num[i] > num[i+1]) {
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

class Solution {
public:
	struct TriNode {
		TriNode *ch[26];
		bool isWord;
		TriNode() : isWord(false) {
			for (auto &a : ch) a = NULL;
		}
	} *root;

	void insert(string word) {
		TriNode *p = root;
		for (auto &a : word) {
			int i = a - 'a';
			if (p->ch[i] == NULL) p->ch[i] = new TriNode();
			p = p->ch[i];
		}
		p->isWord = true;
	}

	bool isPrefix(string word) {
		TriNode *p = root;
		for (auto &a : word) {
			int i = a - 'a';
			if (p->ch[i] == NULL) return false;
			p = p->ch[i];
		}
		return true;
	}

	bool isWord(string word) {
		TriNode *p = root;
		for (auto &a : word) {
			int i = a - 'a';
			if (p->ch[i] == NULL) return false;
			p = p->ch[i];
		}
		return p->isWord;
	}

	Solution() {
		root = new TriNode();
	}

	bool isValid(vector<vector<char>> &board, vector<vector<bool>> &visit, int x, int y) {
		int m = board.size(), n = board[0].size();
		if (x < 0 || x >= m || y < 0 || y >= n || visit[x][y]) return false;
		return true;
	}

	bool dfs(vector<vector<char>> &board, vector<vector<bool>> &visit, set<string> &st, string &s, int x, int y) {
		int dx[4] = { 1, 0, -1, 0 };
		int dy[4] = { 0, 1, 0, -1 };
		visit[x][y] = true;
		int xx, yy;
		for (int i = 0; i < 4; ++i) {
			xx = x + dx[i]; yy = y + dy[i];
			if (isValid(board, visit, xx, yy)) {
				s.push_back(board[xx][yy]);
				if (isWord(s)) st.insert(s);
				if (isPrefix(s)) dfs(board, visit, st, s, xx, yy);
				s.pop_back();
			}
		}
		visit[x][y] = false;
	}

	vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
		vector<string> res;
		if (board.empty() || board[0].empty() || words.empty()) return res;
		for (auto &word : words) insert(word);
		int m = board.size(), n = board[0].size();
		vector<vector<bool>> visit(m, vector<bool>(n, false));
		string s;
		set<string> st;
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				s.push_back(board[i][j]);
				if (isWord(s)) st.insert(s);
				if (isPrefix(s)) dfs(board, visit, st, s, i, j);
				s.pop_back();
			}
		}
		for (auto &word : st) res.push_back(word);
		return res;
	}
};
