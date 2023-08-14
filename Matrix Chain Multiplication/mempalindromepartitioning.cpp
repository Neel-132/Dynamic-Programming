#include<bits/stdc++.h>
#include<string.h>
#include<cstring>
#define MAX 100

int t[MAX][MAX];

bool isPalindrome(string s, int i, int j)
{
	string org = s.substr(i, j - i + 1);
	string r = org;
	reverse(r.begin(), r.end());
	if (org == r)
		return true;
	return false;
}

int getMemParti(string s, int i, int j)
{
	int m = s.length() - 1;
	if (i >= j)
		return 0;
	if (isPalindrome(s, i, j))
		return 0;
	if (t[i][j] != -1)
		return t[i][j];
	for (int k = i; k < j; k++)
	{
		int ans = getMemParti(s, i, k) + getMemParti(s, k + 1, j) + 1;
		if (ans < m)
			m = ans;
	}
	t[i][j] = m;
	return t[i][j];
}

int main()
{
	string s;
	cin >> s;
	memset(t, -1, sizeof(t));
	cout << "Required minimum partitions are " << getMemParti(s, 0, s.length() - 1);
	return 0;
}