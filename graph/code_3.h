#ifndef __CODE_3_H__
#define __CODE_3_H__

#include "head.h"
;
UndirectedGraphNode *cloneGraph(const UndirectedGraphNode *node);
void comb(int m, int n, vector<int> &S);
vector<string> fullJustify(vector<string> &words, int L);

vector<vector<int> > combinationSum(vector<int> &nums, int target);
vector<string> anagrams(vector<string> &strs);

bool exist(vector<vector<char> > &board, string word);
char *strStr(char *haystack, char *needle);

string getNext(const string &s);
int numDistinct(const string &S, const string &T);
int numDistinct2(const string &S, const string &T);

bool wordBreak(string s, unordered_set<string> & dic);
bool wordBreak2(string s, unordered_set<string> &dict);
vector<string> wordBreak3(string s, unordered_set<string> &dict);

int minPathSum(vector<vector<int> > &grid);


int romanToInt(string s);
string intToRoman(int num);

int search(int A[], int n, int target);
bool search_2(int A[], int n, int target);
int candy(vector<int> &ratings);
vector<int> findSubstring(string S, vector<string> &L);

#endif