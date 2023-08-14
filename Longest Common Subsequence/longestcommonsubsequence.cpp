#include<bits/stdc++.h>
using namespace std;

int max(int a, int b)
{
	return (a > b ? a : b);
}

int getLongestCommonSubsequence(string x, string y, int n, int m)
{
	if (n == 0 || m == 0)
		return 0;
	else if (x[n - 1] == y[m - 1])
		return getLongestCommonSubsequence(x, y, n - 1, m - 1) + 1;
	return max(getLongestCommonSubsequence(x, y, n, m - 1), getLongestCommonSubsequence(x, y, n - 1, m));
}

int main()
{
	string x, y;
	cin >> x >> y;
	cout << "Required length of longest common subsequence is " << getLongestCommonSubsequence(x, y, x.length(), y.length());
	return 0;
}

