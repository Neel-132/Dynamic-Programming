#include<bits/stdc++.h>
using namespace std;
#define MAX_N 100
#define MAX_S 200

int t[MAX_N][MAX_S];

int get_optimized_partitionSum(int arr[], int n, int sum)
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
	int n, sum = 0;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		sum += arr[i];
	}

	if (sum % 2 == 0)
		get_optimized_partitionSum(arr, n, sum / 2) == 1 ? cout << "Yes such a partition exists!" : cout << "No, such a partition doesnt exist!";
	else
		cout << "No such partition doesn't exist!!";
	return 0;
}