#include<bits/stdc++.h>
#include<string.h>
using namespace std;

bool isPalindrome(string p, int i, int j)
{
	string r = p.substr(i, j - i + 1);
	string org = r;
	reverse(org.begin(), org.end());
	if (r == org)
		return true;
	return false;
}

int getMinPart(string p, int i, int j)
{
	int m = p.length() - 1;
	if (i == j)
		return 0;
	if (isPalindrome(p, i, j))
		return 0;
	for (int k = i; k < j; k++)
	{
		int ans = getMinPart(p, i, k) + getMinPart(p, k + 1, j) + 1;
		if (ans < m)
			m = ans;
	}
	return m;
}

int main()
{
	string s;
	cin >> s;
	cout << "Required minimum partitions are " << getMinPart(s, 0, s.length() - 1);
	return 0;
}