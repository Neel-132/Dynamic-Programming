#include<bits/stdc++.h>
using namespace std;

int getResult(string p, int i, int j, bool isTrue)
{
	int ltrue, rtrue, lfalse, rfalse;
	if (i == j)
	{
		if (isTrue == true)
		{
			if (p[i] == 'T')
				return 1;
			return 0;
		}
		if (isTrue == false)
		{
			if (p[i] == 'F')
				return 1;
			return 0;
		}
	}
	int ans = 0;
	for (int k = i + 1; k < j; k = k + 2)
	{
		ltrue = getResult(p, i, k - 1, true);
		lfalse = getResult(p, i, k - 1, false);
		rtrue = getResult(p, k + 1, j, true);
		rfalse = getResult(p, k + 1, j, false);
		if (p[k] == '&')
		{
			if (isTrue == true)
				ans += ltrue * rtrue;
			else
				ans += ltrue * rfalse + lfalse * rtrue + lfalse * rfalse;
		}
		else if (p[k] == '|')
		{
			if (isTrue == true)
				ans += ltrue * rtrue + ltrue * rfalse + lfalse * rtrue;
			else
				ans += lfalse * rfalse;
		}
		else
		{
			if (isTrue == true)
				ans += ltrue * rfalse + lfalse * rtrue;
			else
				ans += ltrue * rtrue + lfalse * rfalse;
		}
	}
	return ans;
}

int main()
{
	string p;
	cin >> p;
	cout << "Required number of ways are: " << getResult(p, 0, p.length() - 1, true);
}
