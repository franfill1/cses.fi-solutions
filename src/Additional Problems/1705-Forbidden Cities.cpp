/*
Task:              1705 Forbidden Cities
Sender:            franfill
Submission time:   2023-04-01 10:27:12
Language:          C++17
Result:            ACCEPTED
*/
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n, m, q;
	cin >> n >> m >> q;
	vector < vector < int > > g(n);
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		a--, b--;
		g[a].emplace_back(b);
		g[b].emplace_back(a);
	}

	vector < bool > res(q, true);
	vector < vector < pair < int , pair < int , int > > > > que(n);
	for (int i = 0; i < q; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		a--, b--, c--;
		que[c].emplace_back(i, make_pair(a, b));
	}

	vector < map < int , int > > app(n);
	vector < int > dis(n, -1), up(n);

	auto dfs = [&] (int x, int p, auto dfs) -> void
	{
		up[x] = dis[x];
		app[x][x] = x;
		map < int , int > rep;
		rep[x] = x;
		vector < int > fig;
		for (int y : g[x])
			if (y != p)
			{
				if (dis[y] == -1)
				{
					fig.emplace_back(y);
					dis[y] = dis[x]+1;
					dfs(y, x, dfs);
					if (up[y] >= dis[x])
						rep[app[y].begin()->second] = app[y].begin()->second;
					else
					 	rep[app[y].begin()->second] = x;
					
					if (app[y].size() > app[x].size())
						swap(app[y], app[x]);
					up[x] = min(up[x], up[y]);
				}
				up[x] = min(up[x], dis[y]);
			}
		set < int > to_upd;
		int par = app[x].begin()->second;
		for (auto y : fig)
			for (auto [k, v] : app[y])
			{
				to_upd.insert(k);
				app[x][k] = v;
			}
		for (auto [i, pa] : que[x])
		{
			auto [a, b] = pa;
			if (a == x || b == x)
				res[i] = false;
			int va=x, vb=x;
			if (app[x].count(a))
			{
				va = rep[app[x][a]];
			}
			if (app[x].count(b))
			{
				vb = rep[app[x][b]];
			}
			if (va != vb)
				res[i] = false;
		}
		for (auto k : to_upd)
			app[x][k] = par;
	};

	dis[0] = 0;
	dfs(0, -1, dfs);
	for (auto x : res)
		if (x)
			cout << "YES\n";
		else
		 	cout << "NO\n";
}
