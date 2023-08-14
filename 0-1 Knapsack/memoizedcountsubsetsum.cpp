#include<bits/stdc++.h>
#include<cstring>
using namespace std;
#define MAX 100

int t[MAX][MAX];

int getMemCountSum(int arr[], int n, int sum)
{
	if (sum == 0)
		return 1;
	if (n == 0)
		return 0;
	if (t[n][sum] != -1)
		return t[n][sum];
	else if (arr[n - 1] <= sum)
	{
		t[n][sum] = getMemCountSum(arr, n - 1, sum - arr[n - 1]) + getMemCountSum(arr, n - 1, sum);
		return t[n][sum];
	}
	else
	{
		t[n][sum] = getMemCountSum(arr, n - 1, sum);
		return t[n][sum];
	}
}

int main()
{
	int n, sum;
	memset(t, -1, sizeof(t));
	cin >> n >> sum;
	int arr[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	cout << "Total number of subsets having a sum of " << sum << " is:- " << getMemCountSum(arr, n, sum);
	return 0;

}
