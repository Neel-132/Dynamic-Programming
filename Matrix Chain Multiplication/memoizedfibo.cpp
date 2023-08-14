#include<bits/stdc++.h>
#include<cstring>
using namespace std;
int fibo(int n, vector <int> &f)
{
	if (n == 0 || n == 1)
		return n;
	if (f[n] != -1)
		return f[n];
	return f[n] = fibo(n - 1, f) + fibo(n - 2, f);
}

int main()
{
	int n;
	cin >> n;
	vector <int> f(n, -1);
	cout << n << "th fibonacci number is " << fibo(n, f);
	return 0;
}