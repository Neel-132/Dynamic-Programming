#include<bits/stdc++.h>
using namespace std;

int getcoinchangeWays(int value[], int n, int coin)
{
	if (n == 0)
		return 0;
	if (coin == 0)
		return 1;
	else if (value[n - 1] <= coin)
		return getcoinchangeWays(value, n, coin - value[n - 1]) + getcoinchangeWays(value, n - 1, coin);
	return getcoinchangeWays(value, n - 1, coin);
}

int main()
{
	int n, coin;
	cin >> n >> coin;
	int value[n];
	for (int i = 0; i < n; i++)
		cin >> value[i];
	cout << "Total number of ways for arranging a change of " << coin << " is " << getcoinchangeWays(value, n, coin);
	return 0;
}