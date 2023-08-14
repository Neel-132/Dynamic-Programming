#include<bits/stdc++.h>
using namespace std;
#define MAX 100

int t[MAX][MAX];

int max(int a, int b)
{
	return (a > b ? a : b);
}

int cutRod(int length[], int price[], int n, int L)
{
	for (int i = 0; i < n + 1; i++)
		for (int j = 0; j < L + 1; j++)
		{
			if (i == 0 || j == 0)
				t[i][j] = 0;
			else if (length[i - 1] <= j)
				t[i][j] = max(t[i][j - length[i - 1]] + price[i - 1], t[i - 1][j]);
			else
				t[i][j] = t[i - 1][j];
		}
	return t[n][L];
}

int main()
{
	int n;
	cin >> n;
	int length[n];
	for (int i = 0; i < n; i++)
		length[i] = i + 1;
	int price[n];
	for (int i = 0; i < n; i++)
		cin >> price[i];
	cout << "Required maximum profit is " << cutRod(length, price, n, n);
	return 0;
}