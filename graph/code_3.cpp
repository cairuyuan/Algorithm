
#include "stdafx.h"
#include "head.h"
#include "Tree.h"
#include "LinkNode.h"
#include "code_2.h"

 struct UndirectedGraphNode 
 {
	int label;
	vector<UndirectedGraphNode *> neighbors;
	UndirectedGraphNode(int x) : label(x) {};
	
};
 vector<vector<int> > ret;


bool isValidSudoku(vector<vector<char> > &board);

UndirectedGraphNode *cloneGraph(const UndirectedGraphNode *node);
vector<int> twoSum(vector<int> &numbers, int target);
string convert(string s, int nRows);
void comb(int m, int n, vector<int> &S);
vector<string> fullJustify(vector<string> &words, int L);

vector<vector<int> > combinationSum(vector<int> &nums, int target);
vector<string> anagrams(vector<string> &strs);

bool exist(vector<vector<char> > &board, string word);
char *strStr(char *haystack, char *needle);

string getNext(const string &s);
int numDistinct(const string &S, const string &T);
int numDistinct2(const string &S, const string &T);

bool wordBreak(string s,unordered_set<string> & dic);
bool wordBreak2(string s, unordered_set<string> &dict);

int minPathSum(vector<vector<int> > &grid);


int romanToInt(string s);
string intToRoman(int num);


bool isInterleave(string s1, string s2, string s3);


int _tmain(int argc, _TCHAR* argv[])
{
	//vector<int> S = { 3,2 };
	//sort(S.begin(), S.end());

	//vector<int> x =  twoSum(numbers, 0);
	//comb(2, 2, S); 

	//vector<string> words = { "This", "is", "an", "example", "of", "text", "justification." };
	//fullJustify(words, 16);
	/*vector<int> nums = {1,1,6};
	
	vector<vector<int> >  ret = combinationSum(nums, 8);*/

	//int x = KMPmatch("qwe","uyrtqwe");

	//vector<vector<char> > board(3);
	//board[0].push_back('A');
	//board[0].push_back('B');
	//board[0].push_back('C');
	//board[0].push_back('E');

	//board[1].push_back('S');
	//board[1].push_back('F');
	//board[1].push_back('C');
	//board[1].push_back('S');

	//board[2].push_back('A');
	//board[2].push_back('D');
	//board[2].push_back('E');
	//board[2].push_back('E');

	//board[0].push_back('a');
	//board[0].push_back('b');
	//board[1].push_back('c');
	//board[1].push_back('d');
	//bool ret = exist(board , "ABCCED");
	//getNext("1211");

	int x = numDistinct("rabbbit", "rabit");

	return 0;
}


bool isInterleave(string s1, string s2, string s3) 
{

}

string intToRoman(int num) 
{
	const int     radix[] = { 1000, 900, 500,  400, 100,   90,  50,   40,  10,    9,   5,    4,  1  };
	const string symbol[] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
	int quo;
	string roman;
	size_t i = 0;

	while ( num > 0) 
	{
		quo = num / radix[i];//个数
		num = num % radix[i];
		
		while (quo-- > 0)
		{
			roman += symbol[i];
		}

		++i;
	}

	return roman;
}


int romanToInt(string s)
{
	/*
	index从高往低，
	如果i小于i+1 , 结果减去i项
	否则		   结果加上i项
	*/
	int i = s.length() -1;
	if (i < 0)
	{
		return 0;
	}

	map<char, int> m;
	m['I'] = 1;
	m['V'] = 5;
	m['X'] = 10;
	m['L'] = 50;
	m['C'] = 100;
	m['D'] = 500;
	m['M'] = 1000;
	int sum = m[s[i]];

	i -= 1;
	while (i >= 0)
	{
		if (m[s[i]] < m[s[i + 1]])
		{
			sum -= m[s[i]];
		}
		else
		{
			sum += m[s[i]];
		}

		i -= 1;
	}
	return sum;
}



int minPathSum(vector<vector<int> > &grid)
{
	const unsigned int H = grid.size();
	const unsigned int W = grid[0].size();
	vector<int> f(W, INT_MAX);//记录当前行中，走到某一个格的最小消耗

	f[0] = 0;
	for (size_t i = 0; i < H; i += 1)
	{
		f[0] += grid[i][0];
		for (size_t j = 1; j < W; j += 1)
		{
			f[j] = min(f[j - 1], f[j]) + grid[i][j];
		}
	}
	return f[W - 1];
}


int max_sum;
int maxPathSum(TreeNode *root) 
{
	max_sum = INT_MIN;
	dfs(root);
	return max_sum;
}
int dfs(const TreeNode *root)
{
	if (root == nullptr) return 0;

	int l = dfs(root->left);
	int r = dfs(root->right);
	int sum = root->val;

	if (l > 0) sum += l;
	if (r > 0) sum += r;

	max_sum = max(max_sum, sum);
	return max(r, l) > 0 ? max(r, l) + root->val : root->val;
}


bool wordBreak2(string s, unordered_set<string> &dict) 
{
	vector<bool> f(s.size() + 1, false);
	f[0] = true; // 空字符串
	for (int i = 1; i <= s.size(); ++i) 
	{
		for (int j = i - 1; j >= 0; --j)
		{
			if (f[j] && dict.find(s.substr(j, i - j)) != dict.end()) 
			{
				f[i] = true;
				break;
			}
		}
	}
	return f[s.size()];
}


string S;
int length;
bool dfs_break(int i, unordered_set<string>  &dic)
{
	string tmp;
	while (i<length)
	{
		tmp += S[i++];
		if (dic.count(tmp) && dfs_break(i, dic))
		{
			return true;
		}
	}
	return dic.count(tmp) == 1;
}

bool wordBreak(string s, unordered_set<string> &dict)
{
	S = s;
	length = s.size();
	return dfs_break(0, dict);
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

int numDistinct(const string &S, const string &T)
{
	vector<int> f(T.size() + 1);
	f[0] = 1;
	for (int i = 0; i < S.size(); ++i) 
	{
		for (int j = T.size() - 1; j >= 0; --j) 
		{
			f[j + 1] += S[i] == T[j] ? f[j] : 0;
		}
	}
	return f[T.size()];
}

int numDistinct2(const string &S, const string &T)
{
	const  int S_size = S.size();
	const  int T_size = T.size();
	int tmp = 0;

	vector<int> f(T_size + 1);
	f[0] = 1;

	for (int i = 1; i < S_size; i += 1)
	{
		for (int j = 1; j <= T_size; j += 1)
		{
			if (S[i] == T[j])
			{
				tmp += f[j];
				swap(tmp,f[j]);
			}
		}
	}
	return f[T.size()];
}


bool find(int i, int j, vector<vector<char> > &board, string word, vector<vector<bool> > &pushed);
int H ;
int W ;
int word_size;

bool exist(vector<vector<char> > &board, string word)
{
	/*
	从board中搜索word
	*/
	H = board.size();
	W = board[0].size();
	word_size = word.size();
	vector<vector<bool> > pushed(H, vector<bool>(W, false));

	for (int i = 0; i < H; i += 1)
	{
		for (int j = 0; j < W; j += 1)
		{
			if (find(i, j, board, word, pushed))
			{
				return true;
			}
		}
	}

	return false;

	return false;
}
bool find(int i, int j, vector<vector<char> > &board, string word, vector<vector<bool> > &pushed)
{
	stack<int> indexH;
	stack<int> indexW;
	int m = 0;//已经匹配的长度

	indexH.push(i); indexW.push(j);
	while (!indexH.empty())
	{
		i = indexH.top(); j = indexW.top();
		

		if (i == -1)//j 也是-1
		{
			m -= 1;
			indexH.pop(); indexW.pop();
			
			pushed[indexH.top()][indexW.top()] = false;
			indexH.pop(); indexW.pop();
			continue;
		}

		if (board[i][j] == word[m])
		{
			m += 1;
			if (m == word_size)
			{
				return true;
			}
			pushed[i][j] = true;
			indexH.push(-1); indexW.push(-1);

			if (i - 1 >= 0 && pushed[i - 1][j] == false)
			{
				indexH.push(i - 1); indexW.push(j);
			}
			if (i + 1 < H && pushed[i + 1][j] == false)
			{
				indexH.push(i + 1); indexW.push(j);
			}
			if (j - 1 >= 0 && pushed[i][j - 1] == false)
			{
				indexH.push(i); indexW.push(j - 1);
			}
			if (j + 1 < W && pushed[i][j + 1] == false)
			{
				indexH.push(i); indexW.push(j + 1);
			}

		}
		else
		{
			indexH.pop(); indexW.pop();
		}
	}

	return false;

}


static bool dfs_3(const vector<vector<char> > &board, const string &word, int index, int x, int y, vector<vector<bool> > &visited)
{
	if (index == word.size())		return true; // 收敛条件 
	if (x < 0 || y < 0 || x >= board.size() || y >= board[0].size()) return false; // 越界，终止条件 
	if (visited[x][y])				return false; // 已经访问过，剪枝
	if (board[x][y] != word[index]) return false; // 不相等，剪枝

	visited[x][y] = true;
	bool ret = 
		dfs_3(board, word, index + 1, x - 1, y, visited) || // 上
		dfs_3(board, word, index + 1, x + 1, y, visited) || // 下
		dfs_3(board, word, index + 1, x, y - 1, visited) || // 左
		dfs_3(board, word, index + 1, x, y + 1, visited); // 右

	visited[x][y] = false;
		return ret;
}


char *strStr(char *haystack, char *needle) 
{
	/*
	给两个字符串A, B, 判断B是否出现在A中，如果出现，返回第一次出现的位置指针，否则，返回NULL
	*/

	return NULL;
}


int prestr(char *p, int *pre, int length)
{
	if (!p)
		return -1;

	if (!pre)
		return -2;

	*pre = 0;
	if (length == 1)
		return -3;

	int current;
	int front;

	for (front = 0, current = 1; current<length; current += 1)
	{
		if (*(p + front) == *(p + current))
		{
			*(pre + current) = *(pre + current - 1) + 1;
			front += 1;
		}
		else
		{
			*(pre + current) = 0;
			front = 0;
		}
	}

	return 0;
}


int KMPmatch(char *p, char *s)
{

	if (!p || !s) return -1;
	unsigned int si = 0;				//string  index
	unsigned int ml = 0;				//matched length
	unsigned int pl = strlen(p);		//pattren length
	unsigned int sl = strlen(s);		//pattren length
	int *pre = new int[pl];	//contain prefix num


	prestr(p, pre, pl);

	while (si < sl)
	{
		if (p[ml] != s[si])
		{
			if (ml == 0)
			{
				si += 1;
			}
			else
			{
				ml = pre[ml - 1];
			}
		}
		else
		{
			si += 1;
			ml += 1;
			if (ml == pl)
			{
				return  si - pl;
				/*count += 1;
				ml = 0;
				std::cout << "match index: " << si - pl << std::endl;*/
			}
		}
	}
	delete pre;
	return 0;
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
			f[j] = obstacleGrid[i][j] ? 0  : f[j - 1] + f[j];
		}
	}

	return f[n - 1];
}


vector<string> anagrams(vector<string> &strs) 
{
	unordered_map<string, vector<string> > group;
	for (const auto &s : strs)
	{
		string key = s;
		sort(key.begin(), key.end());
		group[key].push_back(s);//key为排序后，value为ans组成的vector
	}

	vector<string> result;
	for (auto it = group.cbegin(); it != group.cend(); it++) 
	{
		if (it->second.size() > 1)
		{
			result.insert(result.end(), it->second.begin(), it->second.end());
		}
	}

	return result;
}

vector<vector<int> > result; // 最终结果
vector<int> intermediate; // 中间结果
void dfs(vector<int>& nums, int gap, int start) 
{
	if (gap == 0) 
	{ 
		result.push_back(intermediate);
		return;
	}
	for (size_t i = start; i < nums.size(); i++)
	{ 
		if (gap < nums[i]) return; 
		intermediate.push_back(nums[i]);
		dfs(nums, gap - nums[i], i); //从i开始，确保至多可以重复自身，避免同一结果以不同的顺序出现
		intermediate.pop_back();
	}
}
void dfs2(vector<int> &nums, int gap, int start) 
{
	if (gap == 0) 
	{ // 找到一个合法解
		result.push_back(intermediate);
		return;
	}
	int previous = -1;
	for (size_t i = start; i < nums.size(); i++) 
	{
		if (previous == nums[i]) //从一层内搜索，因为原集合允许相同数字，相同数字会引起重复结果出现，之前已将集合排序，使用pre来避免重复是合适的
			continue;
		if (gap < nums[i])		 
			return;  // 剪枝

		previous = nums[i];//记录这一层选择的数

		intermediate.push_back(nums[i]);
		dfs2(nums, gap - nums[i], i + 1);//不再重复使用当前点
		intermediate.pop_back(); // 恢复环境
	}
}
vector<vector<int> > combinationSum(vector<int> &nums, int target) 
{
	sort(nums.begin(), nums.end());
	dfs2(nums, target, 0);
	return result;
}
 
vector<string> fullJustify(vector<string> &words, int L)  
{ 
	int i = 0, j, size = words.size();
	int l = 0;			//一行中的单词数
	int llength = 0;	//一行中纯单词的长度
	int sWidth = 0;	//单词间空格长度
	int pre = 0;		//前面，多空格区间个数

	vector<string> ret; 
	string cell;

	while ((i += l) < size)
	{ 
		l = 1;
		llength = words[i + l - 1].size();
		while (i + l < size)
		{
			if ((int)(llength + words[i + l].size()) + l > L) break; 

			llength += words[i + l].size();
			l += 1;
		}
		cell.clear();
		if (i+l == size) break; 

		if (l == 1)
		{
			cell += words[i + l - 1] + string(L - words[i + l - 1].size(), ' ');
			ret.push_back(cell);
			continue;
		}
		
		sWidth = (L - llength) / (l - 1);
		pre = (L - llength) % (l - 1);
		for (j = 0; j < l-1; j += 1)
		{
			cell += words[i + j] + string((j < pre ? sWidth + 1 : sWidth), ' ');
		}
		cell += words[i + l - 1];
		ret.push_back(cell);
	} 

	//处理最后一行，最后一行靠左，单词间一个空格，末尾部分以空格填充
	for (j = 0; j < l - 1; j += 1)
	{
		cell += words[i + j] + string(1, ' ');
	}
	cell += words[i + l - 1];
	cell += string((L - cell.size()),' ');
	ret.push_back(cell);

	return ret;
}

void comb(int m, int n, vector<int> &S)
{
	
	int *a = new int[m + 1], i, j;
	a[0] = 1;
	for (i = 1; i <= m; i++)
	{
		a[i] = i;
	}

	vector<int> vi(m);
	while (a[0] == 1)
	{
		vector<int> vi(m);
		for (i = 1; i <= m; i += 1)/*把S中的元素放入vi中，下标在a[1],a[m]中*/
		{
			vi[m - i] = S[a[i] - 1];//vi.push_back(S[a[i] -1]);
		}
		ret.push_back(vi);

		j = m;
		while (a[j] == n - m + j && j > 0)
		{
			j -= 1;
		}

		a[j] += 1;

		for (i = j + 1; i <= m; i++)
		{
			a[i] = a[i - 1] + 1;
		}
	}
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



UndirectedGraphNode *cloneGraph(const UndirectedGraphNode *node)
{
	if (node == nullptr) return nullptr;

	unordered_map<const UndirectedGraphNode *, UndirectedGraphNode *> Trans;
	queue<const UndirectedGraphNode *> q;

	q.push(node);
	Trans[node] = new UndirectedGraphNode(node->label);
	while (!q.empty()) 
	{
		const UndirectedGraphNode *cur = q.front();
		q.pop();
		for (auto nbr : cur->neighbors) 
		{
			if (Trans.find(nbr) != Trans.end()) //nbr点已经存在图中，遍历时复制，添加相邻关系
			{
				Trans[cur]->neighbors.push_back(Trans[nbr]);
			}
			else 
			{
				UndirectedGraphNode *new_node = new UndirectedGraphNode(nbr->label);
				Trans[nbr] = new_node;
				Trans[cur]->neighbors.push_back(new_node);

				q.push(nbr);
			}
		}
	}
	return Trans[node];
}


int ladderLength(string start, string end, const unordered_set<string> &dict)
{
	if (start.size() != end.size()) return 0;

	if (start.empty() || end.empty()) return 0;

	queue<string> next, current; // 当前层，下一层
	unordered_set<string> visited; // 判重
	unordered_map<string, string > father;
	int level = 0; // 层次
	bool found = false;

	current.push(start);
	while (!current.empty() && !found) 
	{
		++level;
		while (!current.empty() && !found) //处理一层
		{
			const string str(current.front()); 
			current.pop();
			for (size_t i = 0; i < str.size(); ++i) 
			{
				string new_word(str);
				for (char c = 'a'; c <= 'z'; c++) 
				{
					if (c == new_word[i]) continue;
					swap(c, new_word[i]);//确保只更换一个一个字母

					if (new_word == end) 
					{
						found = true; //找到了
						father[new_word] = str;
						break;
					}

					if (dict.count(new_word) > 0 && !visited.count(new_word))//在dict中并且未visited
					{
						next.push(new_word);
						visited.insert(new_word);
						father[new_word] = str;
					}
					swap(c, new_word[i]); // 恢复该单词
				}
			}
		}

		swap(next, current); //!!! 交换两个队列
	}

	if (found) return level + 1;
	else return 0;
}


void buildPath(unordered_map<string, vector<string> > &father, vector<string> &path, const string &start, const string &word, vector<vector<string> > &result) 
{
		path.push_back(word);
		if (word == start)
		{
			result.push_back(path);
			reverse(result.back().begin(), result.back().end());
		}
		else 
		{
			for (auto f : father[word]) 
			{
				buildPath(father, path, start, f, result);
			}
		}
		path.pop_back();
}


vector<vector<string> > findLadders(string start, string end, const unordered_set<string> &dict)
{
	unordered_set<string> visited; // 判重
	unordered_map<string, vector<string> > father; // 树
	unordered_set<string> current, next; // 当前层，下一层，用集合是为了去重
	bool found = false;
	current.insert(start);
	while (!current.empty() && !found)
	{
		// 先将本层全部置为已访问，防止同层之间互相指向
		for (auto word : current)
			visited.insert(word);
		for (auto word : current)
		{
			for (size_t i = 0; i < word.size(); ++i)
			{
				string new_word = word;
				for (char c = 'a'; c <= 'z'; ++c)
				{
					if (c == new_word[i]) continue;
					swap(c, new_word[i]);
					if (new_word == end) found = true; //找到了
					if (visited.count(new_word) == 0 && (dict.count(new_word) > 0 || new_word == end))
					{
						next.insert(new_word);
						father[new_word].push_back(word);
						// visited.insert(new_word) 移动到最上面了
					}
					swap(c, new_word[i]); // restore
				}
			}
		}
		current.clear();
		swap(current, next);
	}
	vector<vector<string> > result;
	if (found)
	{
		vector<string> path;
		buildPath(father, path, start, end, result);
	}
	return result;
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

