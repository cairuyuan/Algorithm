#include "stdafx.h"
#include "code_7.h"

vector<string> summaryRanges(vector<int>& nums);
int countPrimes(int n);
void rotate(vector<int>& nums, int k);

int main(int argc, char * argv)
{
	rotate(vector<int>{1}, 1);
	return 0;
}

vector<string> summaryRanges(vector<int>& a){
	/*[0,1,2,4,5,7], return ["0->2","4->5","7"].
	   i     j
	*/
	vector<string> ret;
	string s;
	stringstream stream;
	int i = 0, j;
	for (j = 1; j <= a.size(); j++) {
		if (j == a.size() || (long long)a[j] - a[j - 1] > 1) {
			stream.clear();
			stream << a[i];
			if (i != j - 1) stream << "->" << a[j - 1]; 
			stream >> s;
			ret.push_back(s);
			i = j;
		}
	}
	return ret;
}

int countPrimes(int n) {
	bool* a = new bool[n];
	for (int i = 2; i*i<n; i++) {
		if (!a[i]) {
			for (int j = i; i*j<n; j++)  a[i*j] = true;
		}
	}

	int c = 0;
	for (int i = 2; i<n; i++)  if (a[i] == false) ++c;
	return c;
}

void rotate(vector<int>& nums, int k){
	for (int i = 0; i < k; i++) {
		int tmp = nums[nums.size() - 1];
		for (int j = nums.size() - 2; j >= 0; j -= 1) {
			nums[j + 1] = nums[j];
		}
		nums[0] = tmp;
	}
}

void Reversee(int nums[], int left, int right){
	int tmp;
	for (int i = left, j = right; i < j; ++i, --j){
		tmp = nums[j]; nums[j] = nums[i]; nums[i] = tmp;
	}
}

void rotate(int nums[], int n, int k) {
	if (n <= 1) return; 
	k = k % n;
	if (k <= 0) return; 
	Reversee(nums, 0, n - k - 1);
	Reversee(nums, n - k, n - 1);
	Reversee(nums, 0, n - 1);
}
