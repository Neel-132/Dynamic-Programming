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

int memgetEditDistance(string x, string y, int i, int j)
{
	if (i == 0)
		return j;
	if (j == 0)
		return i;
	if (dp[i][j] != -1)
		return dp[i][j];
	if (x[i - 1] == y[j - 1])
		return dp[i][j] = memgetEditDistance(x, y, i - 1, j - 1);
	int insert = memgetEditDistance(x, y, i, j - 1) + 1;
	int del = memgetEditDistance(x, y, i - 1, j) + 1;
	int replace = memgetEditDistance(x, y, i - 1, j - 1) + 1;
	return dp[i][j] = min(insert, del, replace);
}

int main()
{
	string x, y;
	memset(dp, -1, sizeof(dp));
	cin >> x >> y;
	cout << "Required minimum operations is " << memgetEditDistance(x, y, x.length(), y.length());
	return 0;
}