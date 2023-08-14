#include<bits/stdc++.h>
using namespace std;

int max(int a, int b)
{
	return (a > b ? a : b);
}

int getLongestCommonSubstring(string x, string y, int n, int m, int count)
{
	if (n == 0 || m == 0)
		return count;
	if (x[n - 1] == y[m - 1])
		count = getLongestCommonSubstring(x, y, n - 1, m - 1, count + 1);
	else
		count = max(count, max(getLongestCommonSubstring(x, y, n - 1, m, 0), getLongestCommonSubstring(x, y, n , m - 1, 0)));
	return count;
}

int main()
{
	string x, y;
	cin >> x >> y;
	cout << "Length of the longest common substring is " << getLongestCommonSubstring(x, y, x.length(), y.length(), 0);
	return 0;
}