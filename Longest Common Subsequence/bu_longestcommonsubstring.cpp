#include<bits/stdc++.h>
using namespace std;
#define MAX 100

int dp[MAX][MAX];
int res = 0;

int get_td_LongestCommonSubstring(string x, string y, int n, int m)
{
	for (int i = 0; i < n + 1; i++)
		for (int j = 0; j < m + 1; j++)
		{
			if (i == 0 || j == 0)
				dp[i][j] = 0;
			else if (x[i - 1] == y[j - 1])
			{
				dp[i][j] = 1 + dp[i - 1][j - 1];
				res = max(res, dp[i][j]);
			}
			else
				dp[i][j] = 0;
		}
	return res;
}

int main()
{
	string x, y;
	cin >> x >> y;
	cout << "Required length of longest common substring is " << get_td_LongestCommonSubstring(x, y, x.length(), y.length());
	return 0;
}