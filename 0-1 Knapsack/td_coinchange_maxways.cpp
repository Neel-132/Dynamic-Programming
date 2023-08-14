#include<bits/stdc++.h>
using namespace std;
#define MAX 100

int t[MAX][MAX];

int getCoinWays(int value[], int n, int coin)
{
	for (int i = 0; i < n + 1; i++)
		for (int j = 0; j < coin + 1; j++)
		{
			if (i == 0)
				t[i][j] = 0;
			else if (j == 0)
				t[i][j] = 1;
			else if (value[i - 1] <= j)
				t[i][j] = t[i][j - value[i - 1]] + t[i - 1][j];
			else
				t[i][j] = t[i - 1][j];
		}
	return t[n][coin];
}

int main()
{
	int n, coin;
	cin >> n >> coin;
	int value[n];
	for (int i = 0; i < n; i++)
		cin >> value[i];
	cout << "Total number of ways for arranging a change of " << coin << " is " << getCoinWays(value, n, coin);
	return 0;
}
