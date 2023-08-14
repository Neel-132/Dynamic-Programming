#include<bits/stdc++.h>
#include<cstring>
using namespace std;

#define MAX 100

int t[MAX][MAX];

int max(int a, int b)
{
	return (a > b ? a : b);
}

int memgetProfit(int length[], int price[], int n, int L)
{
	if (n == 0 || L == 0)
		return 0;
	if (t[n][L] != -1)
		return t[n][L];
	if (length[n - 1] <= L)
	{
		t[n][L] = max(memgetProfit(length, price, n, L - length[n - 1]) + price[n - 1], memgetProfit(length, price, n - 1, L));
		return t[n][L];
	}
	t[n][L] = memgetProfit(length, price, n - 1, L);
	return t[n][L];
}

int main()
{
	int n, i = 0;
	cin >> n;
	memset(t, -1, sizeof(t));
	int length[n], price[n];
	while (i < n)
	{
		length[i] = i + 1;
		i++;
	}
	for (int i = 0; i < n; i++)
		cin >> price[i];
	cout << "Required maximum profit is " << memgetProfit(length, price, n, n);
	return 0;
}