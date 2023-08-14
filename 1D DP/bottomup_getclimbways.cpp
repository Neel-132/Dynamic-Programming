#include<bits/stdc++.h>
using namespace std;

int bu_fibo(int n)
{
	int prev1 = 1, prev2 = 0, res;
	if (n == 0)
		return prev2;
	if (n == 1)
		return prev1;
	for (int i = 2; i < n + 1; i++)
	{
		res = prev1 + prev2;
		prev2 = prev1;
		prev1 = res;
	}
	return res;
}

int getWays(int n)
{
	return bu_fibo(n + 1);
}

int main()
{
	int n;
	cin >> n;
	cout << "Required number of ways are " << getWays(n);
	return 0;
}