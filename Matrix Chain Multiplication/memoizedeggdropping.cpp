#include<bits/stdc++.h>
#include<cstring>
using namespace std;
#define MAX 100
int dp[MAX][MAX];
int max(int a, int b)
{
	return a > b ? a : b;
}

int eggDropMem(int floor, int egg)
{
	if (floor == 0 || floor == 1)
		return floor;
	if (egg == 1)
		return floor;
	if (dp[floor][egg] != -1)
		return dp[floor][egg];
	int m = INT_MAX, drop, nodrop;
	for (int k = 1; k <= floor; k++)
	{
		if (dp[k - 1][egg - 1] != -1)
			drop = dp[k - 1][egg - 1];
		else
		{
			drop = eggDropMem(k - 1, egg - 1);
			//dp[k - 1][egg - 1] = drop;
		}
		if (dp[floor  - k][egg] != -1)
			nodrop = dp[floor - k][egg];
		else
		{
			nodrop = eggDropMem(floor - k, egg);
			//dp[floor - k][egg] = drop;
		}
		int attempts = 1 + max(drop, nodrop);
		if (attempts < m)
			m = attempts;
	}
	return dp[floor][egg] = m;
}

int main()
{
	int floor, egg;
	memset(dp, -1, sizeof(dp));
	cin >> floor >> egg;
	cout << "Required minimum attempts:- " << eggDropMem(floor, egg);
	return 0;
}