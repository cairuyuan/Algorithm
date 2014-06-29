#ifndef __CODE2_
#define __CODE2_

#include "head.h"
using namespace std;



struct Interval
{
public:
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};


int minPathSum(vector<vector<int> > &grid);//
vector<string> restoreIpAddresses(string s);//************************************************
vector<string> generateParenthesis(int n);//**************************************************
char *intToRoman(int num);//******************************************************************
int   romanToInt(char *); //******************************************************************
vector<vector<int> > permuteUnique(vector<int> &num);//***************************************
vector<vector<int> > permute(vector<int> &num);//*********************************************
char *getPermutation(int n, int k);//********************************************************
int numTrees(int n);//***********************************************************************
int maximalRectangle(vector<vector<char> > &matrix);//****************************************
vector<vector<int> > subsets(vector<int> &S);//***********************************************
int candy(vector<int> &ratings);//************************************************************
void solve(vector<vector<char>> &board);//****************************************************
int longestConsecutive(vector<int> &num);//**************************************************
int numDecodings(string s);//*****************************************************************
bool isInterleave(string s1, string s2, string s3);//*****************************************
vector<string> fullJustify(vector<string> &words, int L);//***********************************
double pows(double x, int n);//---------------------------------------------------------------48
float  invsqrts(float x);//-------------------------------------------------------------------49
int    largestRectangleArea(vector<int> &height);//-------------------------------------------77
void   OutputSubset(int set[], int length);//-----------------------------------------********70
void   shellsort(int *data, size_t size);//
double findMedianSortedArrays(int *A, int m, int *B, int n);//--------------------------------63
int  search(int A[], int n, int target);//---------------------------------------------------52
bool search2(int A[], int n, int target);//------------------------------------------------***85
int maxSubArray(int A[], int n);//------------------------------------------------------------75
int  magicindex(int A[], int length);
void wangwochufa(int A[], int B[], const int length);
int jump(int A[], int n);//-------------------------------------------------------------------82
bool canJump(int A[], int n);//---------------------------------------------------------------81
bool searchMatrix(vector<vector<int> > &matrix, int target);//--------------------------------83
vector<int> searchRange(int A[], int n, int target);//----------------------------------------84
void  print(vector<vector<int> > vv);
void  print(vector<int> v);
void  print(int a[], int length);//打印
void  msa(int a[], unsigned int m, int b[], unsigned int n);//两个已排序数组合并------------------5
void  setZeroes(vector<vector<int> > &matrix);//----------------------------------------------78
void  rotate(vector<vector<int> > &matrix);//-------------------------------------------------79
void  qsort(int *a, int length);//数组快速排序
int  trap(int A[], int n); //-----------------------------------------------------------------62
int  *randarr(int *arr, const unsigned int N, const int X = 100);//随机数填充arr
int  firstMissingPositive(int A[], int n);//--------------------------------------------------71
int  revint(int x);//十进制数反转-------------------------------------------------------------11
int  divide(int dividend, int divisor);//Divide Two Integers----------------------------------38 
int  rdfsa2(int * arr, int length);//去掉已排序数组中重复元素----------------------------------43
int  totalNQueens(int n);//------------------------------------------------------------------54
int  minimumTotal(vector<vector<int> > &triangle);//Triangle ---------------------------------37
int  singleNumber1(int A[], int n);//appears twice except for one.----------------------------39
int  singleNumber2(int A[], int n);//appears three times except for one.**********************40
int  climbStairs(int n);//-------------------------------------------------------------------47
int  Factorial(int n);
int  C(int n, int m);
int  removeElement(int A[], int n, int elem);//删除数组中，等于elem的所有元素-----------------34
int  evalRPN(vector<string> &tokens);//-------------------------------------------------------68
int  longestValidParentheses(char * s);//----------------------------------------------------57
int  searchInsert(int A[], int n, int target);//----------------------------------------------58
int  prestr(char *, int *, int); //***
int  KMPmatch(char *, char *);//***
unsigned int  invertint(unsigned int);//------------------------------------------------------61
unsigned int rdfsa(int * arr, unsigned int length);//去掉已排序数组中重复元素-----------------12
bool isaPalindrome(char *s);//回文------------------------------------------------------------14
bool notchar(char c);
bool isequal(char c1, char c2);
bool isPalindrome(int x);//-------------------------------------------------------------------45
bool isValid(char * s);//括号对是否匹配-------------------------------------------------------24
bool isNumber(const char *s);//---------------------------------------------------------------------69
vector<vector<int> > generateMatrix(int n);//-------------------------------------------------76
vector<vector<int> > generate(int numRows);//产生帕斯卡三角形---------------------------------32
vector<int> getRow(int rowIndex);//产生帕斯卡三角形的第rowindex行-----------------------------33
vector<int> twoSum(vector<int> &numbers, int target);//Two Sum -------------------------------41
vector<int> plusOne(vector<int> &digits);//--------------------------------------------------44
vector<int> spiralOrder(vector<vector<int> > &matrix);//--------------------------------------73
vector<vector<string> > solveNQueens(int n);//------------------------------------------------53
vector<Interval> merge(vector<Interval> &intervals);//----------------------------------------74
char *addBinary(char *s1, char *s2);//二进制字符相加-------------------------------------------43
char *simplifypath(char * path);//------------------------------------------------------------55
string simplifyPath2(string path);//------------------------------------------------------------55
char *multiply(char * num1, char *num2);//-----------------------------------------------------42
string multiply(string num1, string num2);//Multiply Strings
int Com(int n, int m);
unsigned int Com2(unsigned int n, unsigned int m);
const unsigned int N = 3;
const unsigned int M = 6;

#endif