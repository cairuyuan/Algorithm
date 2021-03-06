#ifndef __CODE_4_H__
#define __CODE_4_H__


#include "head.h"


int minDistance(const string &word1, const string &word2);

bool isaPalindrome(char * str);
bool notchar(char c);

int Com(int n, int m);

void reverseWords2(string &s);
void reverseWords1(string &s);
void reverseWords(string &s);

void wangwochufa(int A[], int B[], const int length);

int magicindex(int A[], int length);
char *simplifypath(char * path);

vector<int> plusOne(vector<int> &digits);
char *addBinary(char *s1, char *s2);
void qsort(int *a, int length);

int qpart(int *a, int length);
int singleNumber1(int a[], int n);
int minimumTotal(vector<vector<int> > &vv);
int climbStairs(int n);


char *multiply(char * num1, char *num2);

int divide(int dividend, int divisor);
vector<vector<int> > generate(int numRows);
int rdfsa2(int * arr, int length);

bool isequal(char c1, char c2);

int C(int n, int m);

#endif