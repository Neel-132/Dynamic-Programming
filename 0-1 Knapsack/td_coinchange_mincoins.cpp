#include<bits/stdc++.h>
using namespace std;
#define MAX 100

int t[MAX][MAX];

int min(int a, int b)
{
	return (a > b ? b : a);
}

int getCoinsMin(int value[], int n, int coin)
{
	for (int i = 0; i < n + 1; i++)
		for (int j = 0; j < coin + 1; j++)
		{
			if (i == 0)
				t[i][j] = INT_MAX - 1;
			else if (j == 0)
				t[i][j] = 0;
			else if (i == 1)
			{
				if (j % i == 0)
					t[i][j] = j / i;
				else
					t[i][j] = INT_MAX - 1;
			}
			else if (value[i - 1] <= j)
				t[i][j] = min(t[i][j - value[i - 1]] + 1, t[i - 1][j]);
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
	cout << "Minimum number of coins required to achieve " << coin << " is " << getCoinsMin(value, n, coin);
	return 0;
}