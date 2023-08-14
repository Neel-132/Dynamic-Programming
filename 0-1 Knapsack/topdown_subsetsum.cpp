#include<bits/stdc++.h>
using namespace std;
#define MAX_N 100
#define MAX_S 100
int t[MAX_N][MAX_S];

int optimized_getSum(int arr[], int n, int sum)
{
	for (int i = 0; i < n + 1; i++)
		for (int j = 0; j < sum + 1; j++)
		{
			if (j == 0)
				t[i][j] = 1;
			else if (i == 0)
				t[i][j] = 0;
			else if (arr[i] <= j)
				t[i][j] = t[i - 1][j - arr[i]] || t[i - 1][j];
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
	optimized_getSum(arr, n, sum) == 1 ? cout << "Yes, there exists a subset with the required sum" : cout << "No there exist no such subset";
	return 0;
}