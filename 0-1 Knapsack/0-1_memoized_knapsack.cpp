#include<bits/stdc++.h>
#include<cstring>
using namespace std;
#define MAX_wt 100
#define MAX_n 100

int t[MAX_n][MAX_wt];

int knapsack(int wt[], int val[], int w, int n)
{
	if (n == 0 || w == 0)
		return 0;
	if (t[n - 1][w - 1] != -1)
		return t[n - 1][w - 1];
	else if (w >= wt[n - 1])
	{
		t[n - 1][w - 1] = max(val[n - 1] + knapsack(wt, val, w - wt[n - 1], n - 1), knapsack(wt, val, w, n - 1));
		return t[n - 1][w - 1];
	}
	else
	{
		t[n - 1][w - 1] = knapsack(wt, val, w, n - 1);
		return t[n - 1][w - 1];
	}
}

int main()
{
	int n, w;
	cin >> n >> w;
	int wt[n], val[n];
	for (int i = 0; i < n; i++)
		cin >> wt[i];
	for (int i = 0; i < n; i++)
		cin >> val[i];
	memset(t, - 1, sizeof(t));
	cout << "The required maximum profit is:- " << knapsack(wt, val, w, n);

	return 0;
}