/*
Task:              1138 Path Queries
Sender:            franfill
Submission time:   2021-03-22 10:02:29
Language:          C++11
Result:            ACCEPTED
/*
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector < ll > tree;

ll sum(ll k)
{
	ll ans = 0;
	while(k)
	{
		ans += tree[k];
		k -= k&-k;
	}
	return ans;
}

void add(ll k, ll x)
{
	while(k < tree.size())
	{
		tree[k] += x;
		k += k&-k;
	}
}

vector < vector < ll > > t;
vector < ll > idToi;
vector < ll > subsiz;

ll dfs(ll n, ll i, ll f)
{
	idToi[n] = i;
	subsiz[i] = 0;
	for (ll ne : t[n])
	{
		if (ne != f) subsiz[i] += dfs(ne, i + subsiz[i] + 1, n);
	}
	return subsiz[i] + 1;
}

main()
{
	ll N, Q;
	cin >> N >> Q;
	tree.resize(N+1);
	t.resize(N);
	idToi.resize(N);
	subsiz.resize(N+1);
	
	vector < ll > v(N);
	for (ll i = 0; i < N; i++)
	{
		cin >> v[i];
	}
	
	for (ll i = 0; i < N-1; i++)
	{
		ll a, b;
		cin >> a >> b;
		a--;b--;
		t[a].push_back(b);
		t[b].push_back(a);
	}
	
	dfs(0, 1, -1);
	
	for (ll n = 0; n < N; n++)
	{
		ll i = idToi[n];
		add(i, v[n]);
		add(i + subsiz[i]+1, -v[n]);
	}
	
	while(Q--)
	{
		ll boh;
		cin >> boh;
		if (boh == 1)
		{
			ll s, x;
			cin >> s >> x;
			s--;
			ll delta = x - v[s];
			
			ll i = idToi[s];
			add(i, delta);
			add(i + subsiz[i]+1, -delta);	
			v[s] = x;
		}
		else
		{
			ll s;
			cin >> s;
			s--;
			cout << sum(idToi[s]) << "\n";
		}
	}
}

