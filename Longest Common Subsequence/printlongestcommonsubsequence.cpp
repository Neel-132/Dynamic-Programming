#include<bits/stdc++.h>
#include <algorithm>
#include<string>
using namespace std;

string printLongestCommonSubsequence(string x, string y, int n, int m, string s)
{
	if (n == 0 || m == 0)
	{
		return s;
	}
	else if (x[n - 1] == y[m - 1])
	{
		s = printLongestCommonSubsequence(x, y, n - 1, m - 1, s) + x[n - 1];
		return s;
	}
	return max(printLongestCommonSubsequence(x, y, n, m - 1, s), printLongestCommonSubsequence(x, y, n - 1, m, s));
}

int main()
{
	string x, y;
	cin >> x >> y;
	string res = printLongestCommonSubsequence(x, y, x.length(), y.length(), {});
	if (res.length() == 0)
		cout << "There exist no common subsequence";
	else
		cout << "Required length of longest common subsequence is " << res;
	return 0;
}

