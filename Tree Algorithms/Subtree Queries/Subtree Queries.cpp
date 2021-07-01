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

vector < vector < ll > > g;

vector < ll > idToi;
vector < ll > subsiz;

ll dfs(ll n, ll i, ll from)
{
	idToi[n] = i;
	subsiz[i] = 0;
	for (ll ne : g[n])
	{
		if (ne != from) subsiz[i] += dfs(ne, i + subsiz[i] + 1, n);
	}
	return subsiz[i] + 1;
}

int main()
{
	ll N, Q;
	cin >> N >> Q;
	
	tree.resize(N+1, 0);
	g.resize(N);
	idToi.resize(N);
	subsiz.resize(N+1);
	
	vector < ll > vall(N, 0);
	for (ll i = 0; i < N; i++)
	{
		cin >> vall[i];
	}
	
	for (ll i = 1; i < N; i++)
	{
		ll a, b;
		cin >> a >> b;
		a--; b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	
	dfs(0, 1, -1);
	for (ll i = 0; i < N; i++)
	{
		add(idToi[i], vall[i]);
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
			
			ll i = idToi[s];
			ll delta = x - vall[s];
			
			add(i, delta);
			vall[s] = x;
		}
		else
		{
			ll s;
			cin >> s;
			s--;
			cout <<  sum(idToi[s] + subsiz[idToi[s]]) - sum(idToi[s]-1) << "\n";
		}
	}
}

