#ifndef __CODE_1_H__
#define __CODE_1_H__

#include "head.h"

void   shellsort(int *data, size_t size);//
double findMedianSortedArrays(int *A, int m, int *B, int n);//--------------------------------63

void  print(vector<vector<int> > vv);
void  print(vector<int> v);
void  print(int a[], int length);//打印
void  msa(int a[], unsigned int m, int b[], unsigned int n);//两个已排序数组合并------------------5
void  setZeroes(vector<vector<int> > &matrix);//----------------------------------------------78

int  *randarr(int *arr, const unsigned int N, const int X = 100);//随机数填充arr

int  revint(int x);//十进制数反转-------------------------------------------------------------11

int  rdfsa2(int * arr, int length);//去掉已排序数组中重复元素----------------------------------43
int  totalNQueens(int n);//------------------------------------------------------------------54

int  Factorial(int n);

int  removeElement(int A[], int n, int elem);//删除数组中，等于elem的所有元素-----------------34

int  prestr(char *, int *, int); //***
unsigned int rdfsa(int * arr, unsigned int length);//去掉已排序数组中重复元素-----------------12

bool isNumber(const char *s);//---------------------------------------------------------------------69

vector<int> getRow(int rowIndex);//产生帕斯卡三角形的第rowindex行-----------------------------33
vector<int> twoSum(vector<int> &numbers, int target);//Two Sum -------------------------------41

vector<vector<string> > solveNQueens(int n);//------------------------------------------------53

const unsigned int N = 3;
const unsigned int M = 6;

#endif