#include<bits/stdc++.h>
using namespace std;

int max(int a, int b)
{
	if (a > b)
		return a;
	return b;
}

int getMaxProf(int val[], int wt[], int n, int W)
{
	if (n == 0 || W == 0)
		return 0;
	else if (wt[n - 1] <= W)
		return max(getMaxProf(val, wt, n, W - wt[n - 1]) + val[n - 1], getMaxProf(val, wt, n - 1, W));
	else
		return getMaxProf(val, wt, n - 1, W);
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
	cout << "Required maximum profit is:- " << getMaxProf(val, wt, n, W);
	return 0;
}