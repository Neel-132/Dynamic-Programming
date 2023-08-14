#include<bits/stdc++.h>
using namespace std;

int max(int a, int b)
{
	return (a > b ? a : b);
}

int getMaxVal(int length[], int price[], int n, int L)
{
	if (n == 0 || L == 0)
		return 0;
	else if (length[n - 1] <= L)
		return max(getMaxVal(length, price, n , L - length[n - 1]) + price[n - 1], getMaxVal(length, price, n - 1, L));
	return getMaxVal(length, price, n - 1, L);
}

int main()
{
	int n, i = 0;
	cin >> n;
	int length[n], price[n];
	while (i < n)
	{
		length[i] = i + 1;
		i++;
	}
	for (int i = 0; i < n; i++)
		cin >> price[i];
	cout << "Required maximum profit is " << getMaxVal(length, price, n, n);
	return 0;
}