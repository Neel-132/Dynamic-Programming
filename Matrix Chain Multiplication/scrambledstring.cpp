#include<bits/stdc++.h>
#include<string>
using namespace std;

bool isScrambled(string x, string y)
{
	if (x.length() < 1 || y.length() < 1)
		return false;
	else if (x == y)
		return true;
	bool flag = false;
	int n = x.length();
	for (int i = 1; i < n - 1; i++)
	{
		bool swap = isScrambled(x.substr(0, i), y.substr(n - i, i)) && isScrambled(x.substr(i, n - i), y.substr(0, n - i));
		bool noswap = isScrambled(x.substr(0, i), y.substr(0, i)) && isScrambled(x.substr(i, n - i), y.substr(i, n - i));
		if (swap || noswap)
		{
			flag = true;
			break;
		}
	}
	return flag;
}

int main()
{
	string x, y;
	cin >> x >> y;
	if (x.length() != y.length())
		cout << "No, strings are unequal and hence are not scrambled";
	else if (x.length() == 0 || y.length() == 0)
		cout << "Both the strings are empty and hence not scrambled";
	else
		isScrambled(x, y) == true ? cout << "Yes, they are scrambled" : cout << "No, they're not scrambled";
	return 0;
}

