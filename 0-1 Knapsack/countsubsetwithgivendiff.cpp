#include<bits/stdc++.h>
using namespace std;
#define MAX 100

int t[MAX][MAX];

int getCountofSubset(int arr[], int n, int sum)
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

int getCountDiff(int arr[], int n, int diff)
{
	int sum = 0;
	for (int i = 0; i < n; i++)
		sum += arr[i];
	if ((sum + diff) % 2 == 0)
		return getCountofSubset(arr, n, (diff + sum) / 2);
	return 0;
}

int main()
{
	int n, diff;
	cin >> n >> diff;
	int arr[n];
	for (int i = 0; i < n ; i++)
		cin >> arr[i];
	cout << "Required number of subsets with difference " << diff << " is " << getCountDiff(arr, n, diff);
	return 0;

}