#include<bits/stdc++.h>
#include<cstring>
using namespace std;
#define MAX 100

int dp[MAX][MAX];

int getMemLongestCommonSubstring(string x, string y, int n, int m, int count)
{
	if (n == 0 || m == 0)
		return count;
	if (dp[n][m] != -1)
		return dp[n][m];
	else if (x[n - 1] == y[m - 1])
	{
		count = getMemLongestCommonSubstring(x, y, n - 1, m - 1, count + 1);
		dp[n][m] = count;
		return dp[n][m];
	}
	else
	{
		count = max(count, max(getMemLongestCommonSubstring(x, y, n, m - 1, 0), getMemLongestCommonSubstring(x, y, n - 1, m, 0)));
		dp[n][m] = count;
		return dp[n][m];
	}
}

int main()
{
	string x, y;
	memset(dp, -1, sizeof(dp));
	cin >> x >> y;
	cout << "Required length of longest common substring is " << getMemLongestCommonSubstring(x, y, x.length(), y.length(), 0);
	return 0;
}