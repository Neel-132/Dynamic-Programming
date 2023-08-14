#include<bits/stdc++.h>
#include<cstring>
using namespace std;
#define MAX_N 100
#define MAX_W 100

int t[MAX_N][MAX_W];

int getMemoPartitionSum(int arr[], int n, int sum)
{
	if (sum == 0)
		return 1;
	else if (n == 0)
		return 0;
	else if (t[n][sum] != -1)
		return t[n][sum];
	else if (sum >= arr[n - 1])
	{
		t[n][sum] = getMemoPartitionSum(arr, n - 1, sum - arr[n - 1]) || getMemoPartitionSum(arr, n - 1, sum);
		return t[n][sum];
	}
	else
	{
		t[n][sum] = getMemoPartitionSum(arr, n - 1, sum);
		return t[n][sum];
	}
}
int main()
{
	int n, sum = 0;
	cin >> n;
	memset(t, -1, sizeof(t));
	int arr[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		sum += arr[i];
	}

	if (sum % 2 == 0)
		getMemoPartitionSum(arr, n, sum / 2) == 1 ? cout << "Yes such a partition exists!" : cout << "No, such a partition doesnt exist!";
	else
		cout << "No such partition doesn't exist!!";
	return 0;
}


