#include <bits/stdc++.h>

#define maxc 1000000000

using namespace std;

typedef long long ll;

vector < ll > ans;
vector < vector < ll > > t;
vector < ll > c;
unordered_map < ll , ll > enc;


unordered_set < int > dfs(ll n, ll f)
{
	unordered_set < int > b;
	b.insert(enc[c[n]]);
	for (ll ne : t[n])
	{
		if (ne != f)
		{
			unordered_set < int > c = dfs(ne, n);
			merge(b.begin(), b.end(), c.begin(), c.end(), inserter(b, b.begin()));
		}
	}
	ans[n] = b.size();
	return b;
}

main()
{
	ll N;
	cin >> N;
	
	t.resize(N);
	c.resize(N);
	
	ll k = 0;
	for (ll i = 0; i<  N; i++)
	{
		cin >> c[i];
		if (!enc.count(c[i]))
		{
			enc[c[i]] = k;
			k++;
		}
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

