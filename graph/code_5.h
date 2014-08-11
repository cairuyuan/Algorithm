#ifndef __CODE_5_H__
#define __CODE_5_H__

#include "head.h"

using namespace std;

void OutputSubset(int set[], int length);
int maxSubArray(int A[], int n);
vector<vector<int> > generateMatrix(int n);
vector<int> spiralOrder(vector<vector<int> > &matrix);
int largestRectangleArea(vector<int> &hist);
void rotate(vector<vector<int> > &matrix);
bool canJump(int A[], int n);
int jump(int A[], int n);
int searchInsert2(int A[], int n, float target);
vector<int> searchRange(int A[], int n, int target);
unsigned int Com2(unsigned int n, unsigned int i);
int singleNumber2(int A[], int n);

string simplifyPath2(string path);



#endif