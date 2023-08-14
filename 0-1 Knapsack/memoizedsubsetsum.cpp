#include<bits/stdc++.h>
#include<cstring>
using namespace std;
#define MAX_N 100
#define MAX_S 100

int t[MAX_N][MAX_S];

int memgetSum(int arr[], int n, int sum)
{
	if (sum == 0)
		return 1;
	if (n == 0)
		return 0;
	if (t[n][sum] != -1)
		return t[n][sum];
	if (arr[n - 1] <= sum)
		t[n][sum] = memgetSum(arr, n - 1, sum - arr[n - 1]) || memgetSum(arr, n - 1, sum);
	return t[n][sum];
	t[n][sum] = memgetSum(arr, n - 1, sum);
	return t[n][sum];
}

int main()
{
	int n, sum;
	memset(t, -1, sizeof(t));
	cin >> n >> sum;
	int arr[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	memgetSum(arr, n, sum) == 1 ? cout << "Yes, there exists such subset!" : cout << "No, there exist no such subset!";
	return 0;
}

