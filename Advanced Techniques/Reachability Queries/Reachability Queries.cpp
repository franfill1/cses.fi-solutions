/*
Task:              2143 Reachability Queries
Sender:            franfill
Submission time:   2022-11-29 21:37:26
Language:          C++17
Result:            ACCEPTED
/*
#include<bits/stdc++.h>
#pragma GCC target("popcnt")
using namespace std;

const int maxn = 50000;
bitset < maxn > r[maxn];
int ans[maxn], par[maxn], rap[maxn];
vector < int > g[maxn], gr[maxn], gc[maxn], comp[maxn];
bool vis[maxn];

int main()
{
	int n, m, q, a, b;
	cin >> n >> m >> q;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		a--, b--;
		g[a].emplace_back(b);
		gr[b].emplace_back(a);
	}
	int cnt = 0;
	{
		vector < int > ts;
		auto dfs1 = [&] (int x, auto dfs) -> void
		{
			vis[x] = true;
			for (auto y : g[x])
				if (!vis[y])
					dfs(y, dfs);
			ts.emplace_back(x);
		};
		for (int i = 0; i < n; i++)
			if (!vis[i])
				dfs1(i, dfs1);
		auto dfs2 = [&] (int x, int c, auto dfs) -> void
		{
			//cerr << x << " " << c << "!\n";
			comp[c].emplace_back(x);
			par[x] = c;
			rap[c] = x;
			vis[x] = true;
			for (auto y : gr[x])
				if (!vis[y])
					dfs(y, c, dfs);
		};
		fill(vis, vis+n, 0);
		for (int i = n-1; i >= 0; i--)
			if (!vis[ts[i]])
				dfs2(ts[i], cnt++, dfs2);
		for (int i = 0; i < n; i++)
			for (auto j : g[i])
				if (par[i] != par[j])
				{
					//cerr << par[i] << " -> " << par[j] << "\n";
					gc[par[i]].emplace_back(par[j]);
				}
	}

	for (int i = 0; i < cnt; i++)
		for (auto x : comp[i])
			r[i].set(x);
	auto dfs = [&] (int x, auto dfs) -> void
	{
		for (int y : gc[x])
			if (ans[y] == 0)
				dfs(y, dfs);
		for (int y : gc[x]) 
			if (!r[x].test(rap[y]))
				r[x] |= r[y];
		ans[x] = r[x].count();
	};
	for (int i = 0; i < cnt; i++)
		if (ans[i] == 0)
			dfs(i, dfs);
	//for (int i = 0; i < cnt; i++)
		//cerr << r[i] << "\n";
	while(q--)
	{
		cin >> a >> b;
		a--, b--;
		if (r[par[a]].test(b))
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}
