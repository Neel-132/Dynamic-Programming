#include<bits/stdc++.h>
using namespace std;

int getCountsum(int arr[], int n, int sum)
{
	if (sum == 0)
	{
		return 1;
	}

	if (n == 0)
		return 0;

	else if (sum >= arr[n - 1])
		return getCountsum(arr, n - 1, sum - arr[n - 1]) + getCountsum(arr, n - 1, sum);
	else
		return getCountsum(arr, n - 1, sum);
}

int main()
{
	int n, sum;
	cin >> n >> sum;
	int arr[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	cout << "Total number of subsets having a sum of " << sum << " is:- " << getCountsum(arr, n, sum);
	return 0;

}