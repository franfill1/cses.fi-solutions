/*
Task:              1707 Graph Girth
Sender:            franfill
Submission time:   2022-12-09 20:40:08
Language:          C++17
Result:            ACCEPTED
*/
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
		cin >> a >> b;
		a--, b--;
		if (a == b)
		{
			cout << 1 << "\n";
			return 0;
		}
		g[a].emplace_back(b);
		g[b].emplace_back(a);
	}
	int ans = n+1;
	vector < int > d(n, -1);
	auto dfs = [&] (int x, int p, auto dfs) -> void
	{
		for (auto y : g[x])
			if (y != p)
			{
				if (d[y] != -1)
				{
					ans = min(ans, abs(d[x] - d[y]) + 1);
				}
				else
				{
					d[y] = d[x]+1;
					dfs(y, x, dfs);
				}
			}
	};
	for (int i = 0; i < n; i++)
	{
		d.assign(n, -1);
		d[i] = 0;
		dfs(i, i, dfs);
	}
	if (ans == n+1)
		cout << -1;
	else
		cout << ans << "\n";
}
