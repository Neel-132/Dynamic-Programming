#include<bits/stdc++.h>
#include<cstring>
using namespace std;
#define MAX 1000

int dp[MAX][MAX];

int max(int a, int b)
{
	return (a > b ? a : b);
}

int memgetLongestCommonSubsequence(string x, string y, int n, int m)
{
	if (n == 0 || m == 0)
		return 0;
	if (dp[n][m] != -1)
		return dp[n][m];
	else if (x[n - 1] == y[m - 1])
	{
		dp[n][m] = memgetLongestCommonSubsequence(x, y, n - 1, m - 1) + 1;
		return dp[n][m];
	}
	dp[n][m] = max(memgetLongestCommonSubsequence(x, y, n, m - 1), memgetLongestCommonSubsequence(x, y, n - 1, m));
	return dp[n][m];
}

int main()
{
	string x, y;
	memset(dp, -1, sizeof(dp));
	cin >> x >> y;
	cout << "Required Longest Common Subsequence is " << memgetLongestCommonSubsequence(x, y, x.length(), y.length());
	return 0;
}

