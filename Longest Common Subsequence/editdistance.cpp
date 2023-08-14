#include<bits/stdc++.h>
using namespace std;

int min(int a, int b, int c)
{
	if (a <= b && a <= c)
		return a;
	if (b < a && b <= c)
		return b;
	if (c < a && c < b)
		return c;
}

int getEditDistance(string x, string y, int i, int j)
{
	if (i == 0)
		return j;
	if (j == 0)
		return i;
	if (x[i - 1] == y[j - 1])
		return getEditDistance(x, y, i - 1, j - 1);
	int insert = getEditDistance(x, y, i, j - 1) + 1;
	int del = getEditDistance(x, y, i - 1, j) + 1;
	int replace = getEditDistance(x, y, i - 1, j - 1) + 1;
	return min(insert, del, replace);
}

int main()
{
	string x, y;
	cin >> x >> y;
	cout << "Required minimum operations is " << getEditDistance(x, y, x.length(), y.length());
	return 0;
}