#ifndef __CODE_3_H__
#define __CODE_3_H__

#include "head.h"


using namespace std;


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

bool wordBreak(string s, unordered_set<string> & dic);
bool wordBreak2(string s, unordered_set<string> &dict);

int minPathSum(vector<vector<int> > &grid);


int romanToInt(string s);
string intToRoman(int num);


bool isInterleave(string s1, string s2, string s3);

int search(int A[], int n, int target);
bool search_2(int A[], int n, int target);
int candy(vector<int> &ratings);

#endif