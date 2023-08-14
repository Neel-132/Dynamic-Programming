#include<bits/stdc++.h>
#include<cstring>
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
int getMemFrogJump(int height[], int n)
{
	if (n == 1)
		return height[n - 1];
	if (n == 0)
		return 0;
	if (t[n] != -1)
		return t[n];
	if (n > 2)
		return t[n] = min(abs(height[n - 1], height[n - 2]) + getMemFrogJump(height, n - 1), abs(height[n - 1], height[n - 3]) + getMemFrogJump(height, n - 2));
	return t[n] = min(abs(height[n - 1], height[n - 2]) + getMemFrogJump(height, n - 1), height[n - 2] + getMemFrogJump(height, n - 2));
}

int main()
{
	int n;
	cin >> n;
	memset(t, -1, sizeof(t));
	int height[n];
	for (int i = 0; i < n; i++)
		cin >> height[i];
	cout << "Required minimum energy is " << getMemFrogJump(height, n);
}