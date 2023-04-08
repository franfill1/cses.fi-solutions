/*
Task:              1139 Distinct Colors
Sender:            franfill
Submission time:   2021-06-03 22:18:32
Language:          C++11
Result:            ACCEPTED
*/
#include <bits/stdc++.h>

#define maxc 1000000000

using namespace std;

typedef long long ll;

vector < ll > ans;
vector < vector < ll > > t;
vector < ll > c;

set < int > dfs(ll n, ll f)
{
	set < int > b;
	b.insert(c[n]);
	for (ll ne : t[n])
	{
		if (ne != f)
		{
			set < int > c = dfs(ne, n);
			if(c.size() > b.size()) swap(b, c);
			for (int x : c) b.insert(x);
		}
	}
	ans[n] = b.size();
	return b;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	ll N;
	cin >> N;
	
	t.resize(N);
	c.resize(N);
	
	for (ll i = 0; i < N; i++)
	{
		cin >> c[i];
	}
	
	for (ll i = 0; i < N-1; i++)
	{
		ll a, b;
		cin >> a >> b;
		a--; b--;
		t[a].push_back(b);
		t[b].push_back(a);
	}
	
	ans.resize(N);
	dfs(0, -1);
	for (int v : ans)
	{
		cout << v << " ";
	}
}

