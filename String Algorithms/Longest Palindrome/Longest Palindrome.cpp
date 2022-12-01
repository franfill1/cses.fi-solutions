/*
Task:              1111 Longest Palindrome
Sender:            franfill
Submission time:   2022-05-28 18:45:54
Language:          C++17
Result:            ACCEPTED
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct rollingHash
{
	static const ll m = 1000000009, b = 257;
	int n;
	vector < ll > v;
	vector < ll > p;
	rollingHash(string s)
	{
		n = s.size();
		v.resize(n+1, 0);
		p.resize(n+1, 1);
		for (int i = 1; i <= n; i++)
		{
			v[i] = ((v[i-1] * b)%m + s[i-1])%m;
			p[i] = (p[i-1] * b) % m;
		}
	}

	ll get(int l, int r)
	{
		ll a = ((v[r] - (v[l]*p[r-l])%m)%m+m)%m;
		return a;
	}
};

string rev(string s)
{
	string ans = "";
	for (int i = s.size()-1; i >= 0; i--)
	{
		ans += s[i];
	}
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string s;
	cin >> s;
	string ns = "";
	for (int i = 0; i < s.size(); i++)
	{
		ns += s[i]; ns+= '#';
	}
	s = ns;

	rollingHash r(s);
	rollingHash rr(rev(s));

	int ans = 0;
	int ansc, ansm;

	for (int c = 0; c < s.size(); c++)
	{
		int a = 0, b = min(c+1, (int)s.size()-c)+1;
		while(a+1 != b)
		{
			int m = (a+b)/2;
			ll ha = r.get(c-m, c+1), hb = rr.get(s.size()-1 - (c+m), s.size()-1 - (c-1));
			if (ha == hb)
			{
				a = m;
			}
			else
			{
				b = m;
			}
		}
		if (a*2+1 > ans)
		{
			ans = a*2+1;
			ansc = c;
			ansm = a;
		}
	}
	for (int i = ansc-ansm; i < ansc+ansm+1; i++)
	{
		if (s[i] != '#')cout << s[i];
	}
}
