
#include "stdafx.h"
#include "code_3.h"



int candy(vector<int> &ratings) 
{
	const int n = ratings.size();
	int result = n;
	vector<int> increment(n, 0);
	
	for (int i = 1, inc = 1; i < n; i++)
	{
		if (ratings[i - 1] < ratings[i])
		{
			increment[i] = inc;//max(inc, increment[i])
			inc += 1;
		}
		else
		{
			inc = 1;
		}
	}

	for (int i = n - 2, inc = 1; i >= 0; i--)
	{
		if (ratings[i] > ratings[i + 1])
		{
			increment[i] = max(inc, increment[i]);
			inc += 1;
		}
		else
		{
			inc = 1;
		}
	}

	for (int i = 0; i < n; i++)
	{
		result += increment[i];
	}

	return result;
}



bool search_2(int A[], int n, int target)
{
	int first = 0, last = n, mid;

	while (first != last) 
	{
		mid = (first + last) / 2;

		if (A[mid] == target) return true;

		if (A[first] < A[mid]) 
		{
			if (A[first] <= target && target < A[mid])
			{
				last = mid;
			}
			else
			{
				first = mid + 1;
			}
		}
		else if (A[first] > A[mid])
		{
			if (A[mid] <= target && target <= A[last - 1])
			{
				first = mid + 1;
			}
			else
			{
				last = mid;
			}
		}
		else
		{
			first++;
		}
	}

	return false;
}

int search(int A[], int n, int target)
{
	/*
	Suppose a sorted array is rotated at some pivot unknown to you beforehand.
	(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 - 0 1 2).
	You are given a target value to search. If found in the array return its index,
	otherwise return -1.
	You may assume no duplicate exists in the array.
	Discuss
	*/
	/*
	a sorted array is rotated

	û����ͬԪ��
	�ұ�����rotated���־���A[0]С
	�������򲻱�
	*/

	int i = 0;
	int j = n - 1;
	int m;

	while (i <= j)
	{
		m = (i + j) / 2;

		if (A[m] == target)
		{
			return m;
		}

		if (A[i] <= A[m])//m���ϰ���
		{
			if (A[m] > target && A[i] <= target)// i-m��
			{
				j = m - 1;
			}
			else//	A[m] <= target || A[i] >target
			{
				i = m + 1;
			}
		}
		else//m���°���
		{
			if (A[m] < target && A[j] >= target)//m-j��
			{
				i = m + 1;
			}
			else// A[m] >= target || A[j] < target
			{
				j = m - 1;
			}
		}
	}
	return -1;
}

bool isInterleave(string s1, string s2, string s3) 
{
	return false;

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
		quo = num / radix[i];//����
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
	index�Ӹ����ͣ�
	���iС��i+1 , �����ȥi��
	����		   �������i��
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
	vector<int> f(W, INT_MAX);//��¼��ǰ���У��ߵ�ĳһ�������С����

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


void gen_path(const string &s, const vector<vector<bool> > &prev, int cur, vector<string> &path, vector<string> &result)
{
	if (cur == 0)
	{
		string tmp;
		for (auto iter = path.crbegin(); iter != path.crend(); ++iter)
		{
			tmp += *iter + " ";
		}

		tmp.erase(tmp.end() - 1);
		result.push_back(tmp);
	}
	for (size_t i = 0; i < s.size(); ++i)
	{
		if (prev[cur][i])
		{
			path.push_back(s.substr(i, cur - i));
			gen_path(s, prev, i, path, result);
			path.pop_back();
		}
	}
}


vector<string> wordBreak3(string s, unordered_set<string> &dict) 
{
	vector<bool> f(s.length() + 1, false);
	vector<vector<bool> > prev(s.length() + 1, vector<bool>(s.length()));

	f[0] = true;
	for (size_t i = 1; i <= s.length(); ++i) 
	{
		for (int j = i - 1; j >= 0; --j)
		{
			if (f[j] && dict.find(s.substr(j, i - j)) != dict.end()) 
			{
				f[i] = true;
				prev[i][j] = true;
			}
		}
	}
	vector<string> result;
	vector<string> path;
	gen_path(s, prev, s.length(), path, result);
	return result;
}



bool wordBreak2(string s, unordered_set<string> &dict) 
{
	vector<bool> f(s.size() + 1, false);
	f[0] = true; // ���ַ���
	for (unsigned int i = 1; i <= s.size(); ++i) 
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


bool wordBreak(string s, unordered_set<string> &dict)
{

	vector<bool> f(s.size() + 1, false);
	f[0] = true; // ���ַ���

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




int numDistinct(const string &S, const string &T)
{
	vector<int> f(T.size() + 1);
	f[0] = 1;
	for (size_t i = 0; i < S.size(); ++i) 
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
	��board������word
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
	int m = 0;//�Ѿ�ƥ��ĳ���

	indexH.push(i); indexW.push(j);
	while (!indexH.empty())
	{
		i = indexH.top(); j = indexW.top();
		

		if (i == -1)//j Ҳ��-1
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
	if (index == word.size())		return true; // �������� 
	if (x < 0 || y < 0 || x >= board.size() || y >= board[0].size()) return false; // Խ�磬��ֹ���� 
	if (visited[x][y])				return false; // �Ѿ����ʹ�����֦
	if (board[x][y] != word[index]) return false; // ����ȣ���֦

	visited[x][y] = true;
	bool ret = 
		dfs_3(board, word, index + 1, x - 1, y, visited) || // ��
		dfs_3(board, word, index + 1, x + 1, y, visited) || // ��
		dfs_3(board, word, index + 1, x, y - 1, visited) || // ��
		dfs_3(board, word, index + 1, x, y + 1, visited); // ��

	visited[x][y] = false;
		return ret;
}


char *strStr(char *haystack, char *needle) 
{
	/*
	�������ַ���A, B, �ж�B�Ƿ������A�У�������֣����ص�һ�γ��ֵ�λ��ָ�룬���򣬷���NULL
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

vector<string> anagrams(vector<string> &strs) 
{
	unordered_map<string, vector<string> > group;
	for (const auto &s : strs)
	{
		string key = s;
		sort(key.begin(), key.end());
		group[key].push_back(s);//keyΪ�����valueΪans��ɵ�vector
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

vector<vector<int> > result; // ���ս��
vector<int> intermediate; // �м���
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
		dfs(nums, gap - nums[i], i); //��i��ʼ��ȷ����������ظ���������ͬһ����Բ�ͬ��˳�����
		intermediate.pop_back();
	}
}
void dfs2(vector<int> &nums, int gap, int start) 
{
	if (gap == 0) 
	{ // �ҵ�һ���Ϸ���
		result.push_back(intermediate);
		return;
	}
	int previous = -1;
	for (size_t i = start; i < nums.size(); i++) 
	{
		if (previous == nums[i]) //��һ������������Ϊԭ����������ͬ���֣���ͬ���ֻ������ظ�������֣�֮ǰ�ѽ���������ʹ��pre�������ظ��Ǻ��ʵ�
			continue;
		if (gap < nums[i])		 
			return;  // ��֦

		previous = nums[i];//��¼��һ��ѡ�����

		intermediate.push_back(nums[i]);
		dfs2(nums, gap - nums[i], i + 1);//�����ظ�ʹ�õ�ǰ��
		intermediate.pop_back(); // �ָ�����
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
	int l = 0;			//һ���еĵ�����
	int llength = 0;	//һ���д����ʵĳ���
	int sWidth = 0;	//���ʼ�ո񳤶�
	int pre = 0;		//ǰ�棬��ո��������

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

	//�������һ�У����һ�п��󣬵��ʼ�һ���ո�ĩβ�����Կո����
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
		for (i = 1; i <= m; i += 1)/*��S�е�Ԫ�ط���vi�У��±���a[1],a[m]��*/
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
			if (Trans.find(nbr) != Trans.end()) //nbr���Ѿ�����ͼ�У�����ʱ���ƣ�������ڹ�ϵ
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

	queue<string> next, current; // ��ǰ�㣬��һ��
	unordered_set<string> visited; // ����
	unordered_map<string, string > father;
	int level = 0; // ���
	bool found = false;

	current.push(start);
	while (!current.empty() && !found) 
	{
		++level;
		while (!current.empty() && !found) //����һ��
		{
			const string str(current.front()); 
			current.pop();
			for (size_t i = 0; i < str.size(); ++i) 
			{
				string new_word(str);
				for (char c = 'a'; c <= 'z'; c++) 
				{
					if (c == new_word[i]) continue;
					swap(c, new_word[i]);//ȷ��ֻ����һ��һ����ĸ

					if (new_word == end) 
					{
						found = true; //�ҵ���
						father[new_word] = str;
						break;
					}

					if (dict.count(new_word) > 0 && !visited.count(new_word))//��dict�в���δvisited
					{
						next.push(new_word);
						visited.insert(new_word);
						father[new_word] = str;
					}
					swap(c, new_word[i]); // �ָ��õ���
				}
			}
		}

		swap(next, current); //!!! ������������
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
	unordered_set<string> visited; // ����
	unordered_map<string, vector<string> > father; // ��
	unordered_set<string> current, next; // ��ǰ�㣬��һ�㣬�ü�����Ϊ��ȥ��
	bool found = false;
	current.insert(start);
	while (!current.empty() && !found)
	{
		// �Ƚ�����ȫ����Ϊ�ѷ��ʣ���ֹͬ��֮�以��ָ��
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
					if (new_word == end) found = true; //�ҵ���
					if (visited.count(new_word) == 0 && (dict.count(new_word) > 0 || new_word == end))
					{
						next.insert(new_word);
						father[new_word].push_back(word);
						// visited.insert(new_word) �ƶ�����������
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



string preProcess(string s) 
{
	int n = s.length();
	if (n == 0) return "^$";

	string ret = "^";
	for (int i = 0; i < n; i++) 
		ret += "#" + s.substr(i, 1);

	return ret += "#$";
}
string longestPalindrome(string s) 
{ 
	string T = preProcess(s); 
	const int n = T.length(); 
	
	int C = 0;//������ĸ��ǵ�ǰ��i��������Ӵ������ĵ�
	int R = 0;//C�İ뾶��ֻ��������Ϊ0��3��Ԫ��Ϊ1
	int *P = new int[n]; 
	for (int i = 1; i < n - 1; i++) 
	{ 
		int i_mirror = 2 * C - i;  
		P[i] = (R > i) ? min(R - i, P[i_mirror]) : 0; 
		 
		while (T[i + 1 + P[i]] == T[i - 1 - P[i]])
		{
			P[i] += 1;
		}

		if (i + P[i] > R) 
		{ 
			C = i; 
			R = i + P[i]; 
		} 
	}  
	 
	int max = 0;
	for (int i = 1; i < n - 1; i++)  
	{ 
		if (P[i] > P[max]) 
		{ 
			max = i;
		} 
	}

	return s.substr((max - 1 - P[max]) / 2, P[max]);
} 
vector<int> findSubstring(string s, vector<string> &dict)
{
	/*
	You are given a string, S, and a list of words, L, that are all of the same length.
	Find all starting indices of substring(s) in S that is a concatenation of each word in L exactly once and without any intervening characters.
	For example, given:
	S: "barfoothefoobarman"
	L: ["foo", "bar"]
	You should return the indices: [0,9].
	(order does not matter).
	*/

	size_t wordLength = dict.front().length();
	size_t catLength = wordLength * dict.size();
	vector<int> result;

	if (s.length() < catLength)
	{
		return result;
	}

	unordered_map<string, int> wordCount;
	for (auto const& word : dict)
	{
		++wordCount[word];
	}

	for (auto i = begin(s); i <= prev(end(s), catLength); ++i)
	{
		unordered_map<string, int> unused(wordCount);

		for (auto j = i; j != next(i, catLength); j += wordLength)
		{
			auto pos = unused.find(string(j, next(j, wordLength)));

			if (pos == unused.end() || pos->second == 0)
			{
				break;
			}

			if (--pos->second == 0)
			{
				unused.erase(pos);
			}
		}

		if (unused.size() == 0)
		{
			result.push_back(distance(begin(s), i));
		}

	}
	return result;
}