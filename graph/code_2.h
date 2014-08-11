#ifndef __CODE_2_H__
#define __CODE_2_H__

#include "head.h"


struct Interval
{
public:
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

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

void sortColors(int A[], int n);
int canCompleteCircuit(vector<int> &gas, vector<int> &cost);
vector<vector<int> > combine(int n, int k);
int canCompleteCircuit(vector<int> &gas, vector<int> &cost);

#endif