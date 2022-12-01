/*
Task:              2077 Necessary Cities
Sender:            franfill
Submission time:   2022-04-28 13:05:27
Language:          C++17
Result:            ACCEPTED
/*
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

	vector < int > ans;
	vector < int > t(n, 1<<30);
	vector < bool > vis(n);
	int timer = 0;
	auto dfs = [&] (int x, auto dfs) -> int
	{
		int up = t[x] = timer;
		vis[x] = true;
		timer++;

		int rootcnt = 0;
		bool art = false;
		for (int y : g[x])
		{
			up = min(up, t[y]);
			if (!vis[y])
			{
				int v = dfs(y, dfs);
				if (v == t[x])
				{
					art = true;
				}
				up = min(up, v);
				rootcnt++;
			}
		}
		if (x != 0 && art) ans.push_back(x);
		else if (x == 0 && rootcnt > 1) ans.push_back(x);
		return up;
	};

	dfs(0, dfs);

	cout << ans.size() << "\n";
	for (int x : ans) cout << x + 1 << " ";
	cout << "\n";
}
