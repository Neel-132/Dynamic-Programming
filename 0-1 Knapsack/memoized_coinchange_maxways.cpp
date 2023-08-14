#include<bits/stdc++.h>
#include<cstring>
using namespace std;
#define MAX 100

int t[MAX][MAX];

int getMemMaxways(int value[], int n, int coin)
{
	if (n == 0)
		return 0;
	if (coin == 0)
		return 1;
	if (t[n][coin] != -1)
		return t[n][coin];
	else if (value[n - 1] <= coin)
	{
		t[n][coin] = getMemMaxways(value, n, coin - value[n - 1]) + getMemMaxways(value, n - 1, coin);
		return t[n][coin];
	}
	t[n][coin] = getMemMaxways(value, n - 1, coin);
	return t[n][coin];
}

int main()
{
	int n, coin;
	memset(t, -1, sizeof(t));
	cin >> n >> coin;
	int value[n];
	for (int i = 0; i < n; i++)
		cin >> value[i];
	cout << "Total number of ways for arranging a change of " << coin << " is " << getMemMaxways(value, n, coin);
	return 0;
}