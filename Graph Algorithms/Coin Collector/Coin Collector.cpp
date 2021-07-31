#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct scc
{
	int n, m;
	vector < vector < int > > g;
	vector < vector < int > > r;

	vector < int > par;
	vector < vector < int > > comp;
	vector < set < int > > cg;
	vector < int > ts;
	int cnt = 0;

	vector < bool > v;
	vector < int > s;
	
	void dfs1(int x)
	{
		v[x] = true;
		for (int ne : g[x])
		{
			if (!v[ne]) dfs1(ne);
		}
		s.push_back(x);
	}

	void dfs2(int x, int c)
	{
		par[x] = c;
		comp[c].push_back(x);
		for (int ne : r[x])
		{
			if (par[ne] == -1) dfs2(ne, c);
		}
	}

	void toposort(int c)
	{
		v[c] = true;
		for (int nc : cg[c])
		{
			if (!v[nc]) toposort(nc);
		}
		ts.push_back(c);
	}

	scc(vector < vector < int > > ig) : g(ig) , n (ig.size())
	{
		r.resize(n);
		for (int a = 0; a < n; a++)
		{
			for (int b : g[a])
			{
				r[b].push_back(a);
			}
		}

		v.assign(n, false);
		for (int x = 0; x < n; x++) if (!v[x]) dfs1(x);

		par.resize(n, -1);
		for (int i = n-1; i >= 0; i--) if (par[s[i]] == -1)
		{
			comp.emplace_back(0);
			dfs2(s[i], cnt++);
		}

		cg.resize(cnt);
		for (int a = 0; a < n; a++)
		{
			for (int b : g[a])
			{
				if (par[a] != par[b])
				{
					cg[par[a]].insert(par[b]);
				}
			}
		}
					
		v.assign(cnt, false);
		for (int c = 0; c < cnt; c++) if (!v[c])
		{
			toposort(c);
		}
	}
};

int main()
{
	int n, m;
	cin >> n >> m;

	vector < ll > v(n);
	for (int i = 0; i < n; i++) cin >> v[i];

	vector < vector < int > > g(n);
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b; a--; b--;
		g[a].push_back(b);
	}

	scc s(g);

	vector < ll > cv(s.cnt, 0);
	for (int x = 0; x < n; x++)
	{
		cv[s.par[x]] += v[x];
	}

	ll ans = 0;
	vector < ll > ma(s.cnt);
	for (int c : s.ts)
	{
		ma[c] = cv[c];
		for (int nc : s.cg[c])
		{
			ma[c] = max(ma[c], cv[c] + ma[nc]);
		}
		ans = max(ans, ma[c]);
	}

	cout << ans << "\n";
}
