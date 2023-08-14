#include <bits/stdc++.h>
using namespace std;
#define MAX 1000

int f[MAX];

int bu_fibo(int n)
{
	int last = 1, slast = 0, res;
	if (n == 0)
		res = slast;
	else if (n == 1)
		res = last;
	for (int i = 2; i < n + 1; i++)
	{
		res = last + slast;
		slast = last;
		last = res;
	}
	return res;
}

int main()
{
	int n;
	cin >> n;
	cout << n << "th fibonacci number is " << bu_fibo(n);
	return 0;
}