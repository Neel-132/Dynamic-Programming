#include<bits/stdc++.h>
using namespace std;
#define MAX_N 100
#define MAX_W 100

int t[MAX_N][MAX_W];
int max(int a, int b)
{
	return a > b ? a : b;
}

int top_down_knapsack(int val[], int wt[], int W, int n)
{
	for (int i = 0; i < n + 1; i++)
		for (int j = 0; j < W + 1; j++)
		{
			if (i == 0 || j == 0)
				t[i][j] = 0;
			else
				t[i][j] = -1;
		}
	for (int i = 1; i < n + 1; i++)
		for (int j = 1; j < W + 1; j++)
		{
			if (j >= wt[i - 1])
				t[i][j] = max(t[i - 1][j - wt[i - 1]] + val[i - 1], t[i - 1][j]);
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
		cin >> wt[i];
	for (int i = 0; i < n; i++)
		cin >> val[i];
	cout << "Required maximum profit is:- " << top_down_knapsack(val, wt, W, n) << endl;
	cout << endl;
	return 0;

}