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
	string s;
	cin >> s;
	Zalgo Z(s);	
	
	for (int i = 1; i < s.size(); i++)
	{
		if (Z[i]+i == s.size()) cout << i << " ";
	}
	cout << s.size();

}

