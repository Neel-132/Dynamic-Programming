#include<bits/stdc++.h>
using namespace std;
#define MAX 100

int dp[MAX][MAX];

int min(int a, int b, int c)
{
	if (a <= b && a <= c)
		return a;
	if (b < a && b <= c)
		return b;
	if (c < a && c < b)
		return c;
}
int bu_getEditDistance(string x, string y)
{
	int n = x.length();
	int m = y.length();
	for (int i = 0; i < n + 1; i++)
		for (int j = 0; j < m + 1; j++)
		{
			if (i == 0)
				dp[i][j] = j;
			else if (j == 0)
				dp[i][j] = i;
			else if (x[i - 1] == y[i - 1])
				dp[i][j] = dp[i - 1][j - 1];
			else
				dp[i][j] = min(1 + dp[i - 1][j], 1 + dp[i][j - 1], 1 + dp[i - 1][j - 1]);
		}
	return dp[n][m];
}
int main()
{
	string x, y;
	cin >> x >> y;
	cout << "Required minimum operations is " << bu_getEditDistance(x, y);
	return 0;
}