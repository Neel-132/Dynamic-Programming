#include<bits/stdc++.h>
using namespace std;
#define MAX 100

int dp[MAX][MAX];

int max(int a, int b)
{
	return (a > b ? a : b);
}

int getLongestRepeatingSubseq(string x, int n)
{
	for (int i = 0; i < n + 1; i++)
		for (int j = 0; j < n + 1; j++)
		{
			if (i == 0 || j == 0)
				dp[i][j] = 0;
			else if (x[i - 1] == y[j - 1] && i != j)
				dp[i][j]  = 1 + dp[i - 1][j - 1];
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	return dp[n][m];
}

int main()
{
	string x;
	cin >> x;
	cout << "Required length of longest common subsequence is " << getLongestRepeatingSubseq(x, x.length());
	return 0;
}