#include<bits/stdc++.h>
using namespace std;

int getSum(int arr[], int n, int sum)
{
	if (sum == 0)
	{
		return 1;
	}
	if (n == 0)
		return 0;
	else if (arr[n - 1] <= sum)
		return (getSum(arr, n - 1, sum - arr[n - 1]) || getSum(arr, n - 1, sum));
	else
		return getSum(arr, n - 1, sum);
}

int main()
{
	int n, sum;
	cin >> n >> sum;
	int arr[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	getSum(arr, n, sum) == 1 ? cout << "Yes, there exists a subset with the required sum" : cout << "No there exist no such subset";
	return 0;
}