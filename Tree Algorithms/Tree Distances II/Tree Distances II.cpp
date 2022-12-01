/*
Task:              1133 Tree Distances II
Sender:            franfill
Submission time:   2021-02-08 16:18:19
Language:          C++11
Result:            ACCEPTED
/*
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector < vector  < ll > > t;
vector < ll > a;
vector < ll > s;
vector < ll > ans;

void dfs(ll n, ll from)
{
	a[n] = 0;
	s[n] = 1;
	for (ll ne : t[n])
	{
		if (ne != from)
		{
			dfs(ne, n);
			a[n] += a[ne] + s[ne];
			s[n] += s[ne];
		}
	}
}

void recalc(ll n, ll from)
{
	if (from == -1)
	{
		ans[n] = a[n];
	}
	else
	{
		ans[n] = ans[from] + s[0] - 2*s[n];
	}
	for (ll ne : t[n])
	{
		if (ne != from)
		{
			recalc(ne, n);
		}
	}
}

int main()
{
	ll N;
	cin >> N;
	t.resize(N);
	a.resize(N);
	s.resize(N);
	ans.resize(N);
	for (ll i = 0; i < N-1; i++)
	{
		ll a, b;
		cin >> a >> b;
		a--; b--;
		t[a].push_back(b);
		t[b].push_back(a);
	}
	dfs(0, -1);
	recalc(0, -1);
	
	for (ll i = 0; i < N; i++)
	{
		cout << ans[i] << " ";
	}
}

