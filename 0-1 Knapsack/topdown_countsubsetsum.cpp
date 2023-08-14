#include<bits/stdc++.h>
using namespace std;
#define MAX 100

int t[MAX][MAX];

int top_down_getcountSum(int arr[], int n, int sum)
{
	for (int i = 0; i < n + 1; i++)
		for (int j = 0; j < sum + 1; j++)
		{
			if (i == 0)
				t[i][j] = 0;
			if (j == 0)
				t[i][j] = 1;
			else if (arr[i - 1] <= j)
				t[i][j] = t[i - 1][j - arr[i - 1]] + t[i - 1][j];
			else
				t[i][j] = t[i - 1][j];
		}
	return t[n][sum];
}
int main()
{
	int n, sum;
	cin >> n >> sum;
	int arr[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	cout << "Total number of subsets having a sum of " << sum << " is:- " << top_down_getcountSum(arr, n, sum);
	return 0;
}