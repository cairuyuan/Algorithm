// SortList.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "head.h"
#include "Tree.h"
#include "LinkNode.h"
#include "code2.h"


using namespace std;
struct Interval
{
public:
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

bool wordBreak(string s, unordered_set<string> &dic);
int decode(string s);
int lengthOfLastWord(const char *s);
bool isMatch(const char *s, const char *p);
string getPermutation(int n, int k);
ListNode *deleteDuplicates(ListNode * head);
vector<int> grayCode(int n);
TreeNode *sortedListToBST(ListNode *head);
void solve(vector<vector<char>> &board);


int searchInsert_(int A[], int n, int target);
bool searchMatrix(vector<vector<int> > &matrix, int target);
string longestCommonPrefix(vector<string> &strs);

vector<Interval> insert(vector<Interval> &intervals, Interval newInterval);
vector<Interval> merge(vector<Interval> &intervals);//----------------------------------------74
int longestConsecutive(vector<int> &num);

int longestValidParentheses(string s);
int trap(int A[], int n);
vector<string> letterCombinations(string digits);
double findMedianSortedArrays(int A[], int m, int B[], int n);
int maxProfit(vector<int> &prices);
int maxProfit2(vector<int> &prices);
int maxProfit3(vector<int> &prices);


int _tmain(int argc, _TCHAR* argv[])
{
	//int A[] = {5, 4, 1 ,2};

	//int x = trap(A,5);
	/*vector<string> x =  letterCombinations("23");*/

	//int a[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	//ListNode * root = makelist(a,9);
	//print(root);

	//root = reverseKGroup(root ,2);
	//print(root);
	vector<int> prices;
	prices.push_back(1);
	prices.push_back(2);
	int x = maxProfit2(prices);
	return 0;   
}
int maxProfit2(vector<int> &prices)
{
 

	return 0;
}

int maxProfit(vector<int> &prices) 
{
	/*
	应该先买后卖
	*/
	if (prices.size() == 0)
	{
		return 0;
	}

	int maxPrice = prices[prices.size() - 1];
	int ans = 0;
	for (int i = prices.size() - 1; i >= 0; i--)
	{
		maxPrice = max(maxPrice, prices[i]);//最大的股价
		ans = max(ans, maxPrice - prices[i]);//最大利润
	}

	return ans;
}
int maxProfit3(vector<int> &prices)
{
	if (prices.size() == 0)  return 0;

	int start = prices[0];
	int profit = 0;
	for (int i = 1; i < prices.size(); i++)
	{
		if (prices[i] >= prices[i - 1])  continue;

		profit += prices[i - 1] - start;
		start = prices[i];
	}

	profit += prices[prices.size() - 1] - start;

	return profit;
}

vector<string> letterCombinations(string digits)
{
	vector<string> ret;
	if (digits.size() == 0)
	{
		ret.push_back("");
		return ret;
	}
						
	vector<string> board;/*-2为下标*/
	board.push_back("abc");
	board.push_back("def");
	board.push_back("ghi");
	board.push_back("jkl");
	board.push_back("mno");
	board.push_back("pqrs");
	board.push_back("tuv");
	board.push_back("wxyz");

	unsigned int count = 1;
	size_t i;
	char  c;
	for (i = 0; i < digits.size(); i += 1)
	{
		c = digits[i] - '2';
		if (0 <= c && c <= 7)
		{
			count *= board[c].size();
		}
		else
		{
			return ret;
		}
	}/*计算个数*/
	
	string tmp;
	int index;
	unsigned int ii;
	for (i = 0; i < count; i += 1)
	{
		tmp.clear();
		ii = i;
		for (size_t j = 0; j < digits.size(); j += 1)
		{
			c = digits[j] -'2';
			index = ii % board[c].size();
			tmp += board[c][index];
			ii  /= board[c].size();
		}
		ret.push_back(tmp);
	}

	return ret;
}


double findKth(int A[], int m, int B[], int n, int k)
{
	if (m > n)
	{
		return findKth(B,n,A,m,k);
	}

	if (m == 0)
	{
		return B[k-1];
	}

	if (k == 1)
	{
		return A[0] > B[0] ? B[0] : A[0];
	}

	int xa = k / 2 > m ? m : k / 2;
	int xb = k - xa;

	/*
	比较两个数组第k/2个元素，
	*/
	if (A[xa - 1] == B[xb - 1])
	{
		return A[xa - 1];
	}

	/*去掉最小的xa或xb个数据*/
	if (A[xa -1] < B[xb -1])/*A中的前xa个都小，可以排除*/
	{
		return findKth(A + xa, m - xa, B, n, k - xa);
	}
	else/*B中的前xb个可以排除*/
	{
		return findKth(A, m, B + xb, n - xb, k - xb);
	}

	
}

double findMedianSortedArrays(int A[], int m, int B[], int n)
{
	if ((m + n) & 0x1)
	{
		return findKth(A, m, B, n, (m + n) / 2 + 1);
	}
	else
	{
		return ( findKth(A, m, B, n, (m + n) / 2) 
			   + findKth(A, m, B, n, (m + n) / 2 + 1)
			   ) / 2;
	}

}



int trap(int A[], int n)
{
	if (A == NULL || n <3)
	{
		return 0;
	}

	int direction = 0;//0;上升	,1:下降
	int previous_highest_peak = 0;//前一个最高峰
	int i = 0;//index
	int water = 0;
	int level;

	while (++i < n)
	{
		if (A[i] < A[i - 1] && direction == 0 && A[i-1] >= A[previous_highest_peak])
		{
			level = A[previous_highest_peak] > A[i - 1] ? A[i - 1] : A[previous_highest_peak];
			for (int j = previous_highest_peak + 1; j < i - 1; j += 1)
			{
				if (level - A[j] > 0)
				{
					water += level - A[j];
				}
			}
			previous_highest_peak = i - 1;
			direction = 1;
		}
		else
			if (A[i] > A[i - 1] && direction == 1)//在下降过程遇到上坡，波谷
			{
				direction = 0;
			}
	}

	if (A[n - 1] >= A[previous_highest_peak])
	{
		level = A[previous_highest_peak] > A[n - 1] ? A[n - 1] : A[previous_highest_peak];
		for (int j = previous_highest_peak + 1; j < n - 1; j += 1)
		{
			if (level - A[j] > 0)
			{
				water += level - A[j];
			}
		}
		return water;
	}
	//i = n
	n = previous_highest_peak;//n为数组中最高峰的下表，左侧边界
	direction = 0;
	previous_highest_peak = --i;//第一个高峰位初始点
	while (--i >= n)
	{
		if (direction == 0 && A[i] < A[i + 1] && A[i + 1] >= A[previous_highest_peak])//上升过程中遇到下破，波峰，并且要是更高的波峰
		{
			level = A[previous_highest_peak] > A[i + 1] ? A[i + 1] : A[previous_highest_peak];
			for (int j = i + 1 + 1; j < previous_highest_peak; j += 1)
			{
				if (level - A[j] > 0)
				{
					water += level - A[j];
				}
			}

			previous_highest_peak = i + 1;
			direction = 1;
		}
		else
			if (direction == 1 && A[i] > A[i + 1])//在下降过程遇到上坡，波谷
			{
				direction = 0;
			}
	}
	
	if (A[n] >= A[previous_highest_peak])
	{
		level = A[previous_highest_peak] > A[n] ? A[n] : A[previous_highest_peak];
		for (int j = n+1; j < previous_highest_peak; j += 1)
		{
			if (level - A[j] > 0)
			{
				water += level - A[j];
			}
		}
		return water;
	}

	return water;
}

int longestValidParentheses(string s)
{
	unsigned int length = s.size();
	if (length <2 )
	{
		return 0;
	}

	
	stack<int > index;
	index.push(0);

	for (size_t i = 1; i < length; i += 1)
	{
		if (!index.empty() && s[index.top()] == '(' && s[i] == ')')
		{
			index.pop();
		}
		else
		{
			index.push(i);
		}
	}
	/*下面计算间距*/

	int lastIndex = length;
	int maxLength = 0;

	while (!index.empty())
	{
		if (lastIndex - index.top() -1 > maxLength)
		{
			maxLength = lastIndex - index.top() - 1;
		}

		lastIndex = index.top();
 		index.pop();
	}

	if (lastIndex != 0 && lastIndex > maxLength)
	{
		maxLength = lastIndex;
	}

	return maxLength;
}

int longestConsecutive(vector<int> &num)
{
	set<int> si;
	int length;

	length = num.size();
	if (length == 0)
	{
		return 0;
	}

	for (int i = 0; i < length; i++)
	{
		si.insert(num[i]);
	}

	set<int> ::iterator iter = si.begin();
	length = 1;
	
	int maxLength = 1;
	int pre = *iter;
	while (++iter != si.end())
	{
		if (*iter == pre+1)
		{
			length += 1;
		}
		else
		{
			if (length > maxLength)
			{
				maxLength = length;
			}

			length = 1;
		}
		pre = *iter;
	}

	return maxLength > length ? maxLength:length;
}


string longestCommonPrefix(vector<string> &strs)
{
	string prefix;

	int i,j = 0;
	int n = strs.size();
	char c;

	if (n == 0) return prefix;

	while (true)
	{
		/*
		一层循环处理竖向一个字符
		i: 字符串
		j：公共前缀
		*/

		if (j == strs[0].size())	return prefix;

		c = strs[0][j];
		i = 0;

		while (++i < n)//串的数量
		{
			if (j == strs[i].size() || strs[i][j] != c)//公共字符已到达某一个串的结尾，有一处不相同
			{
				return prefix;
			}
		}
		j += 1;
		prefix += c;
	}
}



void pro2spread(vector<vector<char>> &board, int i0, int j0)
{
	/*
	从（i,j）点开始，向邻域蔓延
	凡是4邻域联通的，相同值的点，值都改为 ~0
	*/
	/*
	二维数组中ij点的4邻域坐标为
	i-1,j
	i,j-1   i,j		i,j+1
	i+1,j
	注意检查边界
	*/
	if (board[i0][j0] != '0')
	{
		return;
	}

	stack<int> I;
	stack<int> J;
	int i;
	int j;
	int boundaryI = board.size();
	int boundaryJ = board[0].size();

	I.push(i0);
	J.push(j0);//存储的元素是board[x][y]

	while (!I.empty())
	{
		i = I.top(); I.pop();
		j = J.top(); J.pop();

		board[i][j] = ~0;

		if (i - 1 >= 0 && board[i - 1][j] == '0')//上
		{
			I.push(i - 1);
			J.push(j);
		}

		if (j + 1 < boundaryJ && board[i][j + 1] == '0')//右
		{
			I.push(i);
			J.push(j + 1);
		}

		if (i + 1 < boundaryI && board[i + 1][j] == '0')//下
		{
			I.push(i + 1);
			J.push(j);
		}

		if (j - 1 >= 0 && board[i][j - 1] == '0')//左
		{
			I.push(i);
			J.push(j - 1);
		}
	}

}

void solve(vector<vector<char>> &board) 
{
	int boundaryI = board.size();
	if (boundaryI == 0)	return; 
	int boundaryJ = board[0].size();

	int i,j;
	for (j = 0; j < boundaryJ; j += 1)
	{
		pro2spread(board, 0, j);
		pro2spread(board, boundaryI-1, j);
	}

	for (i = 1; i < boundaryI - 1; i += 1)
	{
		pro2spread(board,i,0);
		pro2spread(board, i, boundaryJ - 1);
	}

	/*
	现在，中间的hole值均为 '0'
	和边界相连的0均为~0
	‘x’位置数量保持不变
	*/

	for (i = 0; i < boundaryI; i += 1)
	{
		for (j = 0; j < boundaryJ; j += 1)
		{
			if (board[i][j] == '0')
			{
				board[i][j] = 'x';
			}

			if (board[i][j] == ~0)
			{
				board[i][j] = '0';
			}
			/*上面的处理是逐行逐格的，不会有重复*/
		}
	}
}



TreeNode * packfun(ListNode * head, int count)//count 是个数
{

	/*
	退出条件
	*/

	if (count == 0)
	{
		return NULL;
	}

	ListNode * mid = head;
	for (int i = 0; i < count/2; i++)
	{
		mid = mid->next;
	}
	//此时mid在中间位置 count/2

	TreeNode *root = new TreeNode(mid->val);
	root->left = packfun(head,count/2);
	root->right = packfun(mid->next,count-count/2-1);

	return root;
}



TreeNode *sortedListToBST(ListNode *head)
{
	if (head ==NULL)
	{
		return NULL;
	}
	int n = 0;
	ListNode * p = head;
	while (p)
	{
		n += 1;
		p = p->next;
	}

	return packfun(head,n);
}



vector<int> grayCode(int n) 
{
	/*
	n位格雷码
	使用n个bit返回可以表示的格雷码序列
	格雷码两个数字之间只有一个bit不相同
	*/

	vector<int> ret(1,0);

	int num;
	for (int i = 1; i <= n; i++)
	{
		/*
		计算有i位的格雷码
		*/
		num = 1 << (i-1);//i-1位的格雷码共有num个码
		for (int j = 0; j < num; j++)
		{
			ret.push_back(ret[num - 1 - j] | num);
		}

	}
	return ret;
}

string getPermutation(int n, int k)
{
	/*
	1到n（n<10）个数字全排，的第k个
	*/
	int A[10];A[0] = 1;
	vector<char> C;
	for (int i = 1; i < 10; i++)
	{
		A[i] = i* A[i - 1];
		C.push_back( i + '0');
	}
	string s;
	int x;
	k -= 1;

	for (int i = 0; i < n; i++)
	{
		x = k / A[n - 1];
		s += C[x];
		C.erase(C.begin() + x);
		k %= A[n - 1];
		n -= 1;
	}

	return s;
}
bool isMatch(const char *s, const char *p)
{
	int i = 0;//s
	int j = 0;//p

	while (p[j])
	{
		switch (p[j])
		{
		case '?':
			if (s[i] == 0)
			{
				return false;
			}
			break;

		case '*':


			//*
			if (p[j+1] == 0)
			{
				return true;
			}
			else
			{
				return false;
			}
			break;

		default:
			if (p[j] != s[i])
			{
				return false;
			}
			break;
		}
		i += 1;
		j += 1;
	}

	return s[i] ? false : true;
}

bool wordBreak(string s, unordered_set<string> &dic)
{

	std::unordered_set<std::string>::const_iterator get;
	int sLength = s.size();
	int right = 0;
	string tmp;
	stack<int> index;
	int start;

	while (true)
	{
		
		tmp += s[right];
		//cout<< tmp.size()<<'\t'<< index.size() << '\n';
		get = dic.find(tmp);
		if (get != dic.end())
		{
			//匹配
			index.push(right);
			tmp.clear();

			if (right == sLength - 1)
			{
				return true;
			}
		}

		if (right == sLength - 1)
		{
			if (index.empty())
			{
				return false;
			}

			right = index.top();
			index.pop();
			start = index.empty() ? 0 : index.top() + 1;

			tmp = string(s, start, right - start + 1);//从index[top]+1下表开始(包含) 复制right - index[top]个

		}

		right += 1;
	}
}


int decode(string s)
{

	int s1 = 1;
	int s2 = 1;
	int result = 1;//只有一个非零数字
	
	int n = s.size();
	if (n == 0|| s[0] == '0')
	{
		return 0;
	}

	int i = 0;
	while (++i < n)
	{
		if (s[i] != '0')
		{
			if (   s[i - 1] == '1' && s[i] <= '9'
				|| s[i - 1] == '2' && s[i] <= '6'
				)
			{
				result = s2 + s1;
				s1 = s2;
				s2 = result;
			}
			else
			{
				s1 = result = s2;
				
			}
			
		}
		else
		{
			if (s[i-1] == '1' || s[i-1] == '2')
			{
				if (s2 > s1)
				{
					s2 -= s1;
				}
				
				result = s2;
				/*无需处理s1，下一步要么错误，要么不可向前结合，不会用到s1*/
			}
			else
			{
				return 0;
			}
		}

		
		
	}

	return result;
}

int lengthOfLastWord(const char *s)
{
	int length = 0;
	int state = 0;

	int i = 0;

	while (s[i] != 0)
	{
		switch (state)
		{
		case 0:
			s[i] == ' ' ? 0 : length = state = 1;
			break;

		case 1:
			s[i] == ' ' ? state = 0 : length += 1;
			break;

		default:
			break;
		}
		i += 1;
	}

	return length;
}

int searchInsert_(int A[], int n, int target)
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

bool searchMatrix(vector<vector<int> > &matrix, int target)
{
	if (matrix.size() == 0)	return false; 

	int i,ii,j,m;

	i = 0;
	j = matrix.size() - 1;
	while (i <= j)
	{
		m = (i + j) / 2;
		if (matrix[m][0] == target) return true;//理想情况
		matrix[m][0] <target ? i = m + 1 : j = m - 1;
	}

	/*
	target应该插入i位置
	target大于matrix[i-1][0]
		  小于matrix[i][0]
	target应该在	前一行	i-1

	临界条件：
	i == 0，应该是不存在

	*/
	if (i == 0) return false;

	/*下面搜索第i-1行*/

	ii = 0;
	j = matrix[i-1].size() - 1;
	while (ii <= j)
	{
		m = (ii + j) / 2;
		if (matrix[i-1][m] == target) return true;//理想情况
		matrix[i-1][m] <target ? ii = m + 1 : j = m - 1;
	}
	return false;
}