// SortList.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "head.h"

using namespace std;

bool wordBreak(string s, unordered_set<string> &dic);
int decode(string s);
int lengthOfLastWord(const char *s);


int _tmain(int argc, _TCHAR* argv[])
{

	//string s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";
	string s = "aaab";
	unordered_set<string> dic;

	dic.insert("a");
	dic.insert("aa");

	//dic.insert("aaa");
	//dic.insert("aaaa");
	//dic.insert("aaaaa");
	//dic.insert("aaaaaa");
	//dic.insert("aaaaaaa");
	//dic.insert("aaaaaaaa");
	//dic.insert("aaaaaaaaa");
	//dic.insert("aaaaaaaaaa");
	
	bool x = wordBreak(s, dic);
	//decode("17");
	return 0;   
}


bool wordBreak(string s, unordered_set<string> &dic)
{

	int sLength = s.size();
	vector<int> index(sLength, 0);

	std::unordered_set<std::string>::const_iterator get;
	int right = 0;
	int top = 0;
	string tmp;
	bool done = false;

	while (true)
	{
		tmp += s[right];

		get = dic.find(tmp);
		if (get != dic.end())
		{

			index[++top] = right;
			tmp.clear();

			if (right == sLength - 1)
			{
				done = true;//return true;
				break;
			}
		}

		if (right == sLength - 1)
		{

			top = done ? --top : top;
			done = false;
			right = index[top];

			if (--top == -1)
			{
				break;//或break ;表示全局搜索结束
			}

			tmp = string(s, index[top]+1, right - index[top]);//从index[top]+1下表开始(包含) 复制right - index[top]个

		}

		right += 1;
	}

	return done;

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
