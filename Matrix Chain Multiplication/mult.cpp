#include<bits/stdc++.h>
using namespace std;
unordered_map <string, bool> mp;
bool getMult(string s, int i, int j, char ch)
{
	int n = s.length();
	if (i == j)
		return ch == s[i];
	string temp = to_string(i);
	temp.push_back(' ');
	temp.append(to_string(j));
	temp.push_back(' ');
	temp.push_back(ch);
	if (mp.find(temp) != mp.end())
		return mp[temp];

	bool flag = false;
	for (int k = i; k < j; k++)
	{
		bool left_a = getMult(s, i, k, 'a');
		bool left_b = getMult(s, i, k, 'b');
		bool left_c = getMult(s, i, k, 'c');
		bool right_c = getMult(s, k + 1, j, 'c');
		bool right_a = getMult(s, k + 1, j, 'a');
		bool right_b = getMult(s, k + 1, j, 'b');
		if (ch == 'a')
		{
			bool tempAns = left_a && right_c || left_b && right_c || left_c && right_a;
			if (tempAns == true)
			{
				flag = true;
				break;
			}
		}
		else if (ch == 'b')
		{
			bool tempAns = left_a && right_b || left_b && right_b;
			if (tempAns == true)
			{
				flag = true;
				break;
			}
		}
		else
		{
			bool tempAns = left_c && right_b || left_c && right_c || left_b && right_a;
			if (tempAns == true)
			{
				flag = true;
				break;
			}
		}
	}
	mp[temp] = flag;
	return flag;
}

int main()
{
	string s;
	cin >> s;
	cout << getMult(s, 0, s.length() - 1, 'a');
	return 0;
}