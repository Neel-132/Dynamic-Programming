#include<bits/stdc++.h>
#include<cstring>
using namespace std;
#define MAX 100

int t[MAX][MAX];

int min(int a, int b)
{
	return (a > b ? b : a);
}

int getMemMinCoins(int value[], int n, int coin)
{
	if (n == 0)
		return INT_MAX - 1;
	if (coin == 0)
		return 0;
	if (n == 1)
	{
		if (coin % n == 0)
			return coin / n;
		return INT_MAX - 1;
	}
	if (t[n][coin] != -1)
		return t[n][coin];
	else if (value[n - 1] <= coin)
	{
		t[n][coin] = min(getMemMinCoins(value, n, coin - value[n - 1]) + 1, getMemMinCoins(value, n - 1, coin));
		return t[n][coin];
	}
	else
	{
		t[n][coin] = getMemMinCoins(value, n - 1, coin);
		return t[n][coin];
	}
}

int main()
{
	int n, coin;
	memset(t, -1, sizeof(t));
	cin >> n >> coin;
	int value[n];
	for (int i = 0; i < n; i++)
		cin >> value[i];
	cout << "Minimum number of coins required to achieve " << coin << " is " << getMemMinCoins(value, n, coin);
	return 0;
}