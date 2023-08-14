#include<bits/stdc++.h>
using namespace std;

int min(int a, int b)
{
	return (a > b ? b : a);
}

int getMinCoins(int value[], int n, int coin)
{
	if (n == 0)
		return INT_MAX;
	if (coin == 0)
		return 0;
	else if (n == 1)
	{
		if (coin % n == 0)
			return coin / n;
		return INT_MAX;
	}
	else if (value[n - 1] <= coin)
		return min(getMinCoins(value, n, coin - value[n - 1]) + 1, getMinCoins(value, n - 1, coin));
	return getMinCoins(value, n - 1, coin);
}
int main()
{
	int n, coin;
	cin >> n >> coin;
	int value[n];
	for (int i = 0; i < n; i++)
		cin >> value[i];
	cout << "Minimum number of coins required to achieve " << coin << " is " << getMinCoins(value, n, coin);
	return 0;
}