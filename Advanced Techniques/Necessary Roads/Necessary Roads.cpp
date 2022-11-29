#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	vector < vector < int > > g(n);
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b; a--; b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	vector < pair < int , int > > ans;
	vector < int > t(n, 1<<30);
	vector < bool > vis(n);
	int timer = 0;
	auto dfs = [&] (int x, int p, auto dfs) -> int
	{
		int up = t[x] = timer;
		vis[x] = true;
		timer++;

		for (int y : g[x])
		{
			if (y != p) up = min(up, t[y]);
			if (!vis[y])
			{
				int v = dfs(y, x, dfs);
				up = min(up, v);
			}
		}
		if (x != 0 && up >= t[x]) ans.push_back({x, p});
		return up;
	};

	dfs(0, 0, dfs);

	cout << ans.size() << "\n";
	for (auto [x, y] : ans) cout << x+1 << " " << y+1 << "\n";
}

