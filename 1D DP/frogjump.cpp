#include<bits/stdc++.h>
using namespace std;

int min(int a, int b)
{
	return a > b ? b : a;
}
int abs(int a, int b)
{
	return a > b ? a - b : b - a;
}

int getFrogJump(int height[], int n)
{
	if (n == 1)
	{
		return height[n - 1];
	}
	if (n == 0)
	{
		return 0;
	}
	if (n > 2)
		return min(abs(height[n - 1], height[n - 2]) + getFrogJump(height, n - 1), abs(height[n - 1], height[n - 3]) + getFrogJump(height, n - 2));
	return min(abs(height[n - 1], height[n - 2]) + getFrogJump(height, n - 1), height[n - 2] + getFrogJump(height, n - 2));
}

int main()
{
	int n;
	cin >> n;
	int height[n];
	for (int i = 0; i < n; i++)
		cin >> height[i];
	cout << "Required minimum energy is " << getFrogJump(height, n);
}