#include<bits/stdc++.h>
using namespace std;
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

int getMinSumDiff(int arr[], int n, int s, int sum)
{
	if (s == 0 || n == 0)
		return abs(2 * sum, s);
	return min(getMinSumDiff(arr, n - 1, s, sum - arr[n - 1]), getMinSumDiff(arr, n - 1, s, sum));

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
	cout << "Required minimum difference is " << getMinSumDiff(arr, n, sum, sum);
	return 0;
}