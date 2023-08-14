#include<bits/stdc++.h>
using namespace std;

int fibo(int n)
{
	if (n == 0 || n == 1)
		return n;


	return fibo(n - 2) + fibo(n - 1);
}

int getClimbWays(int n)
{
	return fibo(n + 1);
}
int main()
{
	int n;
	cin >> n;
	cout << "Required number of ways are: " << getClimbWays(n);
}