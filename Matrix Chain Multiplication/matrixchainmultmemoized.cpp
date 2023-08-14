#include<bits/stdc++.h>
#include<cstring>
using namespace std;
#define MAX 100

int t[MAX][MAX];

int getMemCost(int arr[], int i, int j)
{
	int m = INT_MAX;
	if (i >= j)
		return 0;
	if (t[i][j] != -1)
		return t[i][j];
	for (int k = i; k < j; k++)
	{
		int ans = getMemCost(arr, i, k) + getMemCost(arr, k + 1, j) + arr[i - 1] * arr[k] * arr[j];
		if (ans < m)
			m = ans;
	}
	t[i][j] = m;
	return t[i][j];
}

int main()
{
	int n;
	memset(t, -1, sizeof(t));
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	cout << "Required minimum cost is " << getMemCost(arr, 1, n - 1);
	return 0;
}