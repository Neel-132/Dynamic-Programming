#include<bits/stdc++.h>
#include<string>
using namespace std;
#define MAX 100
unordered_map <string, int> mp;
bool isScrambledMem(string x, string y)
{
	if (x.length() < 1 || y.length() < 1)
		return false;
	else if (x == y)
		return true;
	string key = x;
	key.push_back(' ');
	key.append(y);
	if (mp.find(key) != mp.end())
		return mp[key];
	bool flag = false;
	int n = x.length();
	for (int i = 1; i < n - 1; i++)
	{
		bool swap = isScrambledMem(x.substr(0, i), y.substr(n - i, i)) && isScrambledMem(x.substr(i, n - i), y.substr(0, n - i));
		bool noswap = isScrambledMem(x.substr(0, i), y.substr(0, i)) && isScrambledMem(x.substr(i, n - i), y.substr(i, n - i));
		if (swap || noswap)
		{
			flag = true;
			break;
		}
	}
	mp[key] = flag;
	return flag;
}

int main()
{
	string x, y;
	cin >> x >> y;
	mp.clear();
	if (x.length() != y.length())
		cout << "No, strings are unequal and hence are not scrambled";
	else if (x.length() == 0 || y.length() == 0)
		cout << "Both the strings are empty and hence not scrambled";
	else
		isScrambledMem(x, y) == true ? cout << "Yes, they are scrambled" : cout << "No, they're not scrambled";
	return 0;
}

