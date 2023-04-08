/*
Task:              2177 Strongly Connected Edges
Sender:            franfill
Submission time:   2022-12-02 15:21:40
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
		g[a].emplace_back(b);
		g[b].emplace_back(a);
	}

	vector < pair < int , int > > ans;
	vector < int > d(n, n), up(n);
	bool ok = true;
	int cnt = 0;
	auto dfs = [&] (int x, int di, int p, auto dfs) -> void
	{
		cnt++;
		d[x] = up[x] = di;
		for (int y : g[x])
			if (y != p)
			{
				if (d[y] < d[x])
				{
					up[x] = min(up[x], d[y]);
					ans.emplace_back(x, y);
				}
				else if (d[y] == n)
				{
					dfs(y, d[x]+1, x, dfs);
					up[x] = min(up[x], up[y]);
					ans.emplace_back(x, y);
					if (up[y] > d[x])
						ok = false;
				}
			}
	};

	dfs(0, 0, 0, dfs);
	
	if (ok && cnt == n)
		for (auto [x, y] : ans)
			cout << x+1 << " " << y+1 << "\n";
	else
		cout << "IMPOSSIBLE\n";
}
