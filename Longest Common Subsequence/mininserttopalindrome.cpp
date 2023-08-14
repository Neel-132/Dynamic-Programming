#include<bits/stdc++.h>
using namespace std;
#define MAX 100

int t[MAX][MAX];

int max(int a, int b)
{
	return (a > b ? a : b);
}

int getLCS(string x, string y, int n)
{
	for (int i = 0; i < n + 1; i++)
		for (int j = 0; j < n + 1; j++)
		{
			if (i == 0 || j == 0)
				t[i][j] = 0;
			else if (x[i - 1] == y[j - 1])
				t[i][j] = 1 + t[i - 1][j - 1];
			else
				t[i][j] = max(t[i - 1][j], t[i][j - 1]);

		}

	return t[n][n];
}

int getInsert(string x)
{
	string y = x;
	reverse(y.begin(), y.end());
	return x.length() - getLCS(x, y, x.length());
}

int main()
{
	string x;
	cin >> x;
	cout << "Required number of insertions to make a string palindrome is " << getInsert(x);
	return 0;
}