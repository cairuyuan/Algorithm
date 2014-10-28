#ifndef __CODE_6_H__
#define __CODE_6_H__

#include "head.h"


struct Point 
{
	int x;
	int y;
	Point() : x(0), y(0) {}
	Point(int a, int b) : x(a), y(b) {}
};

int firstMissingPositive(int A[], int length);
int longestValidParentheses(char * str);
bool isValidSudoku(vector<vector<char> > &board);
vector<int> twoSum(vector<int> &numbers, int target);
string convert(string s, int nRows);

float invsqrts(float x);
double pows(double x, int n);
void rotate(vector<vector<int> > &matrix);
int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid);
bool isValid(char * s);
unsigned int  invertint(unsigned int i);


string countAndSay(int n);

void bub(int a[], int length, int tag = 0);

int maxProduct(int A[], int n);


vector<TreeNode *> generateTrees(int n);
vector<TreeNode *> generate(int start, int end);
int maxPoints(vector<Point> &points);
int numDistinct(const string &S, const string &T);
bool isInterleave(string s1, string s2, string s3);
int maximalRectangle(vector<vector<char> > &matrix);
#endif