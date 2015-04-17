// ACMCoder.cpp : 定义控制台应用程序的入口点。
//


#include "stdafx.h"

#include <map>
#include <iostream>
using namespace std;

char * add(char *sS, char *sL, char *ret);
int maxSubArray(int A[], int n, int *start, int *end);

int _tmain(int argc, _TCHAR* argv[])
{

	int A, B, n;
	while (true) {
		cin >> A >> B >> n;
		int fn_1 = 1, fn_2 = 1, fout = 0;
		if (A == 0 && B == 0 && n == 0) break;
		for (int i = 0; i < n - 2; i++) {
			fout = (A * fn_1 + B * fn_2) % 7;
			fn_2 = fn_1;
			fn_1 = fout;
		}
		cout << fout << '\n';
	}

	//int n;
	//cin >> n;
	//while (n != 0) {
	//	char color[16];
	//	map<string, int> box;
	//	int mNum = 0;
	//	string mColo;
	//	for (int i = 0; i < n; i++) {
	//		cin >> color;
	//		string c = string(color);
	//		box[c] += 1;
	//		if (mNum < box[c]) {
	//			mNum = box[c];
	//			mColo = c;
	//		}
	//	}
	//	cout << mColo.c_str() << '\n';
	//	cin >> n;
	//}

	//int max = maxSubArray(A,n,&start,&end);


	//int cn = 0;
	//cin >> cn;
	//for (int i = 0; i < cn; i++)
	//{
	//	int n = 0;
	//	cin >> n;
	//	int *A = new int[n];
	//	for (int j = 0; j < n; j++)
	//	{
	//		cin >> A[j];
	//	}

	//	int start;
	//	int end;
	//	int max = maxSubArray(A, n, &start, &end);
	//	
	//	cout << "Case " << i+1 << ":\n";
	//	cout << max << " " << start + 1 << " " << end + 1 << "\n";

	//	if (i != cn-1)
	//	{
	//		cout << "\n";
	//	}
	//}
	//int a, b;
	//while (cin >> a >> b)
	//	cout << a + b << endl;
	//return 0;

	//int num;
	//int res;
	//while (cin >> num)
	//{
	//	res = (num + 1)*(num) / 2;
	//	cout << res<< '\n' << endl;
	//}
	//int n, sum;
	//while (cin >> n)
	//{
	//	sum = (n*(n+1))>>1;
	//	cout << sum << endl << endl;
	//}
	//return 0;
	//int n, sum;
	//while (cin >> n)
	//{
	//	sum = n & 1 ? ((n + 1) / 2) * n : (n / 2) * (n + 1);

	//	cout << sum << endl << endl;
	//}

	//int n = 1;
	//char x1[1000];
	//char x2[1000];
	//char x3[1001];

	//cin >> n;
	//for (int j = 0; j < n; j++)
	//{
	//	cin >> x1 >> x2;
	//	cout << "Case " << j + 1 << ":" << endl;;
	//	cout << x1 << " + " << x2 << " = " << add(x1, x2, x3) << "\n";
	//	if (j != n-1)
	//	{
	//		cout<< endl;
	//	}
	//}

	return 0;
}

char * add(char *sS, char *sL, char *ret)
{
	int Ls = strlen(sS);
	int Ll = strlen(sL);
	if (Ls > Ll) return add(sL, sS, ret);

	ret[0] = '\0';
	int i;
	for (i = 1; i <= Ll - Ls; i++)
	{
		ret[i] = '0';
	}
	strcpy(ret + i, sS);
	int c = 0;
	for (i = Ll - 1; i >= 0; i--)
	{
		int s = c + ret[i + 1] - '0' + sL[i] - '0';
		c = s / 10;
		ret[i + 1] = s % 10 + '0';
	}

	if (c == 0)
	{
		return ret + 1;
	}
	else
	{
		ret[0] = '1';
		return ret;
	}

}

int maxSubArray(int A[], int n, int *start, int *end)
{
	int sec_sum = -1;
	int max = INT_MIN;
	int s = 0;
	for (int i = 0; i < n; i++)
	{
		if (sec_sum < 0)
		{
			sec_sum = A[i];
			s = i;
		}
		else
		{
			sec_sum += A[i];
		}

		if (sec_sum > max)
		{
			max = sec_sum;
			*start = s;
			*end = i;
		}
	}
	return max;
}