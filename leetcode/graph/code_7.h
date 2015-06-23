#ifndef __CODE_7_H__
#define __CODE_7_H__

#include "head.h"

vector<vector<string> > partition(string s);
vector<vector<string>> partition_p(string s);
int maxProduct(int A[], int n);
int lengthOfLongestSubstring2(string s);


int maximalRectangle(vector<vector<char> > &matrix);
int RecArea(vector<int>& heights);
vector<vector<string>> partition(string s);


void push(int x);
void pop();
int top();
int getMin();


string convertToTitle(int n);
int compareVersion(string version1, string version2);
int findPeakElement(const vector<int> &num);

int calculateMinimumHP(vector<vector<int> > &dungeon);
string largestNumber(vector<int> &num);

int prim();
ListNode* removeElements(ListNode* head, int val);

#endif