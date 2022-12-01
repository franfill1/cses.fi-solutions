/*
Task:              1753 String Matching
Sender:            franfill
Submission time:   2021-05-29 18:51:22
Language:          C++11
Result:            ACCEPTED
/*
#include <bits/stdc++.h>

using namespace std;

struct Zalgo
{
	vector < int > Z;	
	
	Zalgo(string s)
	{
		Z.resize(s.size());
		Z[0] = s.size();
		int r = 0, l, m;
		for (int i = 1; i < Z.size(); i++)
		{
			if (Z[i-l] < r - i + 1) Z[i] = Z[i-l];
			else
			{
				r = max(r, i-1); l = i;
				while(s[r+1] == s[r-l+1]) r++; 
				Z[i] = r-i+1;
			}
		}
	}
	
	int operator [](int i)
	{
		return Z[i];
	};
	
	int size()
	{
		return Z.size();
	}
};

int main()
{
	string s, p;
	cin >> s >> p;
	string t = p + '$' + s;
	Zalgo Z(t);
	int ans = 0;
	for (int i = p.size()+1; i < Z.size(); i++)
	{
		ans += Z[i] == p.size();
	}
	cout << ans << "\n";
}

