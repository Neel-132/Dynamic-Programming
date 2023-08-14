#include<bits/stdc++.h>
#include<cstring>
using namespace std;
#define MAX 100

int t[MAX][MAX];

int getMemMaxProf(int val[], int wt[], int n, int W)
{
	if (n == 0 || W == 0)
		return 0;
	if (t[n][W] != -1)
		return t[n][W];
	else if (wt[n - 1] <= W)
	{
		t[n][W] = max(val[n - 1] + getMemMaxProf(val, wt, n, W - wt[n - 1]), getMemMaxProf(val, wt, n - 1, W));
		return t[n][W];
	}
	else
	{
		t[n][W] = getMemMaxProf(val, wt, n - 1, W);
		return t[n][W];
	}
}

int main()
{
	int n, W;
	cin >> n >> W;
	memset(t, -1, sizeof(t));
	int val[n], wt[n];
	for (int i = 0; i < n; i++)
		cin >> val[i];
	for (int i = 0; i < n; i++)
		cin >> wt[i];
	cout << "Required maximum profit is:- " << getMemMaxProf(val, wt, n, W);
	return 0;
}