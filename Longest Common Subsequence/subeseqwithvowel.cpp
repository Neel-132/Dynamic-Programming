#include<bits/stdc++.h>
using namespace std;
int vowel = 0;
void getSubseq(string s, vector <pair<char, int>> &ds, int n)
{
	if (s.length() == 0)
	{
		for (auto it : ds)
		{
			cout << it.first << it.second << " ";
		}
		cout << endl;
		vowel = 0;
	}

	if (s[n - 1] == 'a' || s[n - 1] == 'e' || s[n - 1] == 'i' || s[n - 1] == 'o' || s[n - 1] == 'u')
		vowel ++;
	ds.push_back(make_pair(s[n - 1], vowel));
	getSubseq(s, ds, n - 1);
	vowel --;
	ds.pop_back();
	getSubseq(s, ds, n - 1);
}
int main()
{
	string s;
	cin >> s;
	vector <pair<char, int>> ds;
	getSubseq(s, ds, s.length());
	return 0;
}