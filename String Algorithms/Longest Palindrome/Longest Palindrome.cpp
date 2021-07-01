#include <bits/stdc++.h>
#pragma gcc optimize("Ofast")

using namespace std;

typedef long long ll;

#define B 1000000009
#define A 257

struct rollingHash
{
	int N;
	vector < ll > pre;
	vector < ll > p;
	
	rollingHash(string s) : N(s.size())
	{
		pre.resize(N+1);
		p.resize(N+1);
		pre[0] = 0;
		p[0] = 1;
		for (int i = 1; i <= N; i++)
		{
			pre[i] = ((pre[i-1]*A)%B + s[i-1])%B;
			p[i] = (p[i-1]*A)%B;
		}
	};
	
	ll get (int a, int b)
	{
		return ((pre[b] - (pre[a]*p[b-a])%B)%B + B)%B;
	};
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

