#include<bits/stdc++.h>
#include<cstring>
using namespace std;
#define MAX 100

int t[MAX][MAX];

int abs(int a, int b)
{
	if (a > b)
		return a - b;
	return b - a;
}

int min(int a, int b)
{
	if (a > b)
		return b;
	return a;
}

int getMemSumDiff(int arr[], int n, int sum, int s)
{
	if (n == 0 || s == 0)
		return abs(2 * sum, s);
	else if (t[n][sum] != -1)
		return t[n][sum];
	else
		t[n][sum] = min(getMemSumDiff(arr, n - 1, sum - arr[n - 1], s) , getMemSumDiff(arr, n - 1, sum , s));
	return t[n][sum];
}

int main()
{
	int n, sum = 0;
	cin >> n;
	memset(t, -1, sizeof(t));
	int arr[n];
	for (int i = 0; i < n ; i++)
	{
		cin >> arr[i];
		sum += arr[i];
	}
	cout << "Required minimum difference is " << getMemSumDiff(arr, n, sum, sum);
	return 0;
}

