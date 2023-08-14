#include<bits/stdc++.h>
using namespace std;

unordered_map <string, int> mp;

int getResult(string p, int i, int j, bool isTrue)
{
	if (i == j)
	{
		if (isTrue == true)
		{
			if (p[i] == 'T')
				return 1;
			return 0;
		}
		else
		{
			if (p[i] == 'F')
				return 1;
			return 0;
		}
		string temp = to_string(i);
		temp.push_back(' ');
		temp.append(to_string(j));
		temp.push_back(' ');
		temp.append(to_string(isTrue));
		if (mp.find(temp) != mp.end())
			return mp[temp];
		int ans = 0;
		for (int k = i + 1; k < j; k = k + 2)
		{
			int ltrue, rtrue, lfalse, rfalse;
			string s1, s2, s3, s4;
			s1 = to_string(i);
			s1.push_back(' ');
			s1.append(to_string(k - 1));
			s1.push_back(' ');
			s1.append("true");
			if (mp.find(s1) != mp.end())
				int ltrue = mp[s1];
			else
			{
				int ltrue = getResult(p, i, k - 1, true);
				mp[s1] = ltrue;
			}
			s2 = to_string(i);
			s2.push_back(' ');
			s2.append(to_string(k - 1));
			s2.push_back(' ');
			s2.append("false");

			if (mp.find(s2) != mp.end())
				int lfalse = mp[s2];
			else
			{
				int lfalse = getResult(p, i, k - 1, false);
				mp[s1] = lfalse;
			}
			s3 = to_string(k + 1);
			s3.push_back(' ');
			s3.append(to_string(j));
			s3.push_back(' ');
			s3.append("true");

			if (mp.find(s3) != mp.end())
				int rtrue = mp[s3];
			else
			{
				int rtrue = getResult(p, k + 1, j, true);
				mp[s3] = rtrue;
			}
			s4 = to_string(k + 1);
			s4.push_back(' ');
			s4.append(to_string(j));
			s4.push_back(' ');
			s4.append("false");
			if (mp.find(s4) != mp.end())
				int rfalse = mp[s4];
			else
			{
				int rfalse = getResult(p, k + 1, j, false);
				mp[s4] = rfalse;
			}
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
					ans += ltrue * rfalse + rtrue * lfalse + ltrue * rtrue;
				else
					ans += lfalse * rfalse;
			}
			else
			{
				if (isTrue == true)
					ans += ltrue * rfalse + lfalse * rtrue;
				else
					ans += lfalse * lfalse + rtrue * rtrue;
			}
		}
		mp[temp] = ans;
		return ans;
	}

	int main()
	{
		string p;
		cin >> p;
		mp.clear();
		cout << "Required number of ways are" << getResult(p, 0, p.length() - 1, true);
		return 0;
	}