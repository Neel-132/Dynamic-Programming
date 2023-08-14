#include<bits/stdc++.h>
using namespace std;
#define MAX 100

int t[MAX][MAX];

int getCountSubset(int arr[], int n, int sum)
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

int getTarget(int arr[], int n, int target)
{
	int sum = 0;
	for (int i = 0; i < n; i++)
		sum += arr[i];
	if ((sum + target) % 2 == 0)
		return getCountSubset(arr, n, (sum + target) / 2);
	return 0;
}

int main()
{
	int n, target;
	cin >> n >> target;
	int arr[n];
	for (int i = 0; i < n ; i++)
		cin >> arr[i];
	cout << "Required number of ways with target " << target << " is " << getTarget(arr, n, target);
	return 0;
}

