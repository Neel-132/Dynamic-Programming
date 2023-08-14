#include<bits/stdc++.h>
using namespace std;
#define MAX 100
int t[MAX];
int min(int a, int b)
{
	return a > b ? b : a;
}
int abs(int a, int b)
{
	return a > b ? a - b : b - a;
}
int bu_getFrogJump(int height[], int n)
{
	for (int i = 0; i < n; i++)
	{
		if (i == 0)
			t[i] = 0;
		else if (i == 1)
			t[i] = t[i - 1] + abs(height[i], height[i - 1]);
		else
			t[i] = min(t[i - 1] + abs(height[i], height[i - 1]), t[i - 2] + abs(height[i], height[i - 2]));
	}
	return t[n - 1];
}
int main()
{
	int n;
	cin >> n;
	int height[n];
	for (int i = 0; i < n; i++)
		cin >> height[i];
	cout << "Required minimum energy is " << bu_getFrogJump(height, n);
}