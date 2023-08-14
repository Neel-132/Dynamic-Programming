#include<bits/stdc++.h>
using namespace std;
int getPartition(int arr[], int n, int sum)
{
	if (sum == 0)
		return 1;
	else if (n == 0)
		return 0;
	else if (sum >= arr[n - 1])
		return getPartition(arr, n - 1, sum - arr[n - 1]) || getPartition(arr, n - 1, sum);
	else
		return getPartition(arr, n - 1, sum);
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
		getPartition(arr, n, sum / 2) == 1 ? cout << "Yes such a partition exists!" : cout << "No, such a partition doesnt exist!";
	else
		cout << "No such partition doesn't exist!!";
	return 0;
}