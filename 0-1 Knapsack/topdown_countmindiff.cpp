#include<bits/stdc++.h>
using namespace std;
#define MAX 100

bool t[MAX][MAX];

int min(int a, int b)
{
	if (a > b)
		return b;
	return a;
}

bool getsubsetSum(int arr[], int n, int sum)
{
	for (int i = 0; i < n + 1; i++)
		for (int j = 0; j < sum + 1; j++)
		{
			if (j == 0)
				t[i][j] = true;
			else if (i == 0)
				t[i][j] = false;
			else if (arr[i - 1] <= j)
				t[i][j] = t[i - 1][j - arr[i - 1]] || t[i - 1][j];
			else
				t[i][j] = t[i - 1][j];
		}
	return t[n][sum];
}

int getMinSumDiff(int arr[], int n, int s)
{
	int minimal = MAX;
	for (int i = 0; i <= s / 2; i++)
		if (t[n][i] == true)
		{
			if (minimal > (s - 2 * i));
			minimal = s - 2 * i;
		}
	return minimal;
}

int main()
{
	int n, sum = 0;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n ; i++)
	{
		cin >> arr[i];
		sum += arr[i];
	}
	bool get = getsubsetSum(arr, n, sum);
	cout << "Required minimum difference is " << getMinSumDiff(arr, n, sum);
	return 0;
}
