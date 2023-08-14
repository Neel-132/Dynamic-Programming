#include<bits/stdc++.h>
using namespace std;
#define MAX 100

int t[MAX][MAX];

int max(int a, int b)
{
	if (a > b)
		return a;
	return b;
}

int get_TD_max_profit(int val[], int wt[], int n, int W)
{
	for (int i = 0; i < n + 1; i++)
		for (int j = 0; j < W + 1; j++)
		{
			if (i == 0 || j == 0)
				t[i][j] = 0;
			else if (wt[i - 1] <= j)
				t[i][j] = max(val[i - 1] + t[i][j - wt[i - 1]], t[i - 1][j]);
			else
				t[i][j] = t[i - 1][j];
		}
	return t[n][W];
}

int main()
{
	int n, W;
	cin >> n >> W;
	int val[n], wt[n];
	for (int i = 0; i < n; i++)
		cin >> val[i];
	for (int i = 0; i < n; i++)
		cin >> wt[i];
	cout << "Required maximum profit is:- " << get_TD_max_profit(val, wt, n, W);
	return 0;
}