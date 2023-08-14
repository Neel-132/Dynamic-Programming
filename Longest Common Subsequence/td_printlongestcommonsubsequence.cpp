#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
#define MAX 100

int t[MAX][MAX];
string s = "";

int max(int a, int b)
{
	return (a > b ? a : b);
}

void getLCS(string x, string y, int n, int m)
{
	for (int i = 0; i < n + 1; i++)
		for (int j = 0; j < m + 1; j++)
		{
			if (i == 0 || j == 0)
				t[i][j] = 0;
			if (x[i - 1] == y[j - 1])
				t[i][j] = 1 + t[i - 1][j - 1];
			else
				t[i][j] = max(t[i - 1][j], t[i][j - 1]);
		}
}

string printLCS(string x, string y)
{
	int i = x.length();
	int j = y.length();
	getLCS(x, y, i, j);
	while (i > 0 && j > 0)
	{
		if (x[i - 1] == y[j - 1])
		{
			s = s + x[i - 1];
			i--;
			j--;
		}
		else if (t[i - 1][j] > t[i][j - 1])
			i--;
		else
			j--;
	}
	return s;
}


int main()
{
	string x, y;
	cin >> x >> y;
	string res = printLCS(x, y);
	if (res.length() == 0)
		cout << "There exist no common subsequence";
	else
		cout << "Required length of longest common subsequence is " << res;
	return 0;
}