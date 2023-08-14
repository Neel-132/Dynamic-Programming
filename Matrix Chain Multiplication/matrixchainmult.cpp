#include<bits/stdc++.h>
using namespace std;


int getCost(int arr[], int i, int j)
{
	int m = INT_MAX;
	if (i >= j)
		return 0;
	for (int k = i; k < j; k++)
	{
		int ans = getCost(arr, i, k) + getCost(arr, k + 1, j) + arr[i - 1] * arr[k] * arr[j];
		if (m > ans)
			m = ans;
	}
	return m;
}

int main()
{
	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	cout << "Required minimum cost is " << getCost(arr, 1, n - 1);
	return 0;
}