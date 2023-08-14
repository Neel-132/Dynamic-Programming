#include<bits/stdc++.h>
using namespace std;

int max(int a, int b)
{
	return a > b ? a : b;
}

int eggDrop(int floor, int egg)
{
	if (floor == 0 || floor == 1)
		return floor;
	if (egg == 1)
		return floor;
	int m = INT_MAX;
	for (int k = 1; k <= floor; k++)
	{
		int attempts = 1 + max(eggDrop(k - 1, egg - 1), eggDrop(floor - k, egg));
		if (attempts < m)
			m = attempts;
	}
	return m;
}

int main()
{
	int floor, egg;
	cin >> floor >> egg;
	cout << "Required minimum attempts:- " << eggDrop(floor, egg);
	return 0;
}