#include<bits/stdc++.h>
using namespace std;

int max(int a, int b)
{
	if (a > b)
		return a;
	else
		return b;
}
int knapsack(int wt[], int val[], int w, int n)
{
	if (n == 0 || w == 0)
		return 0;
	if (wt[n - 1] <= w)
		return max(val[n - 1] + knapsack(wt, val, w - wt[n - 1], n - 1), knapsack(wt, val, w, n - 1));
	else
		return knapsack(wt, val, w, n - 1);
}

int main()
{

	int n, w;
	cin  >> n >> w;
	int wt[n], val[n];
	for (int i = 0; i < n; i++)
		cin >> wt[i];
	for (int i = 0; i < n; i++)
		cin >> val[i];
	cout << "The maximum profit is:- " << knapsack(wt, val, w, n);
	return 0;

}