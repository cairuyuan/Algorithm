#include "stdafx.h"
#include "code_7.h"

vector<string> summaryRanges(vector<int>& nums);
int countPrimes(int n);
void rotate(vector<int>& nums, int k);
vector<int> majorityElement(vector<int>& nums);
string fractionToDecimal(int numerator, int denominator);

int main(int argc, char * argv)
{
	cout<<fractionToDecimal(0-1, 0-2147483648)<<"\n";
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


vector<int> majorityElement(vector<int>& nums) {
	vector<int> res;
	int m = 0, n = 0, cm = 0, cn = 0;
	for (auto &a : nums) {
		if (a == m) ++cm;
		else if (a == n) ++cn;
		else if (cm == 0) m = a, cm = 1;
		else if (cn == 0) n = a, cn = 1;
		else --cm, --cn;
	}
	cm = cn = 0;
	for (auto &a : nums) {
		if (a == m) ++cm;
		else if (a == n) ++cn;
	}
	if (cm > nums.size() / 3) res.push_back(m);
	if (cn > nums.size() / 3) res.push_back(n);
	return res;
}

string fractionToDecimal(int n, int d){
	/*要考虑正负*/
	long long numerator = abs((long long)n),denominator = abs((long long)d);

	string res, fra;
	stringstream stream;
	stream << numerator / (long long)denominator;
	stream >> res;
	stream.clear();
	map<long long, int> m;
	long long  t, index = 1;
	numerator %= denominator;
	m[numerator] = index++;
	while (numerator != 0) {
		numerator *= 10;
		t = numerator / denominator;
		fra += (char)(t + '0');
		numerator %= denominator;
		if (m[numerator] == 0) {
			m[numerator] = index++;
		} else {//出现重复
			fra += ")";
			index = m[numerator];
			fra.insert(index-1,1,'(');
			break;
		}
	}
	if (fra.size() != 0) res += "." + fra;
	if (1.0 * n * d < 0) res.insert(0, 1, '-');

	return res;
}