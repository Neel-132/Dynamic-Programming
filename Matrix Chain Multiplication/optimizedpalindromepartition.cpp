#include<bits/stdc++.h>
#include<cstring>
using namespace std;
#define MAX 100

int t[MAX][MAX];

bool isPalindrome(string p, int i, int j)
{
	while (i < j)
	{
		if (p[i] != p[j])
			return false;
		i++;
		j--;
	}
	return true;
}

int getoptPart(string p, int i, int j)
{
	int leftpart, rightpart;
	if (i >= j)
		return 0;
	if (isPalindrome(p, i, j))
		return 0;
	if (t[i][j] != -1)
		return t[i][j];
	int m = p.length() - 1;
	for (int k = i; k < j; k++)
	{
		if (t[i][k] != -1)
			leftpart = t[i][k];
		else
		{
			leftpart = getoptPart(p, i, k);
			t[i][k] = leftpart;
		}
		if (t[k + 1][j] != -1)
			rightpart = t[k + 1][j];
		else
		{
			rightpart = getoptPart(p, k + 1, j);
			t[k + 1][j] = rightpart;
		}
		int ans = leftpart + rightpart + 1;
		if ( m > ans)
			m = ans;
	}
	t[i][j] = m;
	return t[i][j];
}

int main()
{
	string p;
	memset(t, -1, sizeof(t));
	cin >> p;
	cout << "Required minimum partitions are: " << getoptPart(p, 0, p.length() - 1);
	return 0;
}