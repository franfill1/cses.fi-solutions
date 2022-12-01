/*
Task:              2101 New Roads Queries
Sender:            franfill
Submission time:   2021-12-04 12:02:39
Language:          C++17
Result:            ACCEPTED
/*
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair < ll , ll > pll;

struct DSU
{
	ll n;
	vector < ll > par, siz;
	DSU(ll _n) : n(_n)
	{
		par.resize(n);
		siz.resize(n, 1);
		for (ll i = 0; i < n; i++)
		{
			par[i] = i;
		}
	}

	ll find(ll x)
	{
		if (x == par[x]) return x;
		else return par[x] = find(par[x]);
	}

	bool merge(ll a, ll b)
	{
		if (find(a) == find(b)) return false;
		a = find(a);
		b = find(b);
		if (siz[a] < siz[b]) swap(a, b);
		siz[a] += siz[b];
		par[b] = a;
		return true;
	}
};

struct lca
{
	ll N, P;
	vector < vector < pll > > anc;
	vector < ll > d;

	lca(vector < pll > &t, vector < ll > &_d) : N(t.size()) , d(_d)
	{
		P = 1;
		while((1<<P) <= N) P++;
		P++;

		anc.resize(P, vector < pll > (N));
		anc[0] = t;

		for (ll p = 1; p < P; p++)
		{
			for (ll x = 0; x < N; x++)
			{
				ll m = anc[p-1][x].first;
				ll y = anc[p-1][m].first;
				ll w = max(anc[p-1][x].second, anc[p-1][m].second);
				anc[p][x] = {y, w};
			}
		}
	}

	ll get_anc(ll x, ll k, ll &w)
	{
		for (ll p = P-1; p >= 0; p--)
		{
			if (k >= (1<<p))
			{
				w = max(w, anc[p][x].second);
				x = anc[p][x].first;
				k -= 1<<p;
			}
		}
		return x;
	}

	ll get_w_bet(ll a, ll b)
	{
		ll wa = 0;
		ll wb = 0;
		if (d[a] > d[b]) a = get_anc(a, d[a] - d[b], wa);
		else if (d[b] > d[a]) b = get_anc(b, d[b] - d[a], wb);
		assert(d[a] == d[b]);
		if (a == b) return max(wa, wb);

		for (ll p = P-1; p >= 0; p--)
		{
			ll na = anc[p][a].first;
			ll nb = anc[p][b].first;
			if (na != nb)
			{
				wa = max(wa, anc[p][a].second);
				wb = max(wb, anc[p][b].second);
				a = na; b = nb;
			}
		}
		assert(d[a] == d[b]);
		wa = max(wa, anc[0][a].second);
		wb = max(wb, anc[0][b].second);
		assert(anc[0][a].first == anc[0][b].first);
		return max(wa, wb);
	}
};

int main()
{
	ll n, m, Q;
	cin >> n >> m >> Q;
	vector < vector < pll > > g(n);
	vector < pll > t(n);
	DSU d(n);
	for (ll i = 1; i <= m; i++)
	{
		ll a, b;
		cin >> a >> b;
		a--; b--;
		if (d.merge(a, b))
		{
			g[a].push_back({b, i});
			g[b].push_back({a, i});
		}
	}
	
	vector < bool > vis(n, false);	
	vector < ll > D(n, 0);
	queue < ll > q;
	for (int i = 0; i < n; i++) if (!vis[i])
	{
		vis[i] = true;
		q.push(i);
		t[i] = {i, 0};
		while(!q.empty())
		{
			ll x = q.front();
			q.pop();
			for (auto [y, p] : g[x]) if (!vis[y])
			{
				vis[y] = true;
				D[y] = D[x] + 1;
				t[y] = {x, p};
				q.push(y);
			}
		}
	}

	lca l(t, D);

	while(Q--)
	{
		ll a, b;
		cin >> a >> b;
		a--; b--;
		if (d.find(a) != d.find(b)) cout << -1 << "\n";
		else
		{
			cout << l.get_w_bet(a, b) << "\n";
		}
	}
}

