/*
Task:              2179 Even Outdegree Edges
Sender:            franfill
Submission time:   2023-03-12 17:30:16
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

	vector < int > state(n);
	vector < bool > par(n);
	vector < pair < int , int > > ans;
	auto dfs = [&] (int x, int p, auto dfs) -> void
	{
		state[x] = 1;
		for (int y : g[x])
			if (y != p)
			{
				if (state[y] == 1)
				{
					ans.emplace_back(x, y);
					par[x] = !par[x];
				}
				else if (state[y] == 0)
				{
					dfs(y, x, dfs);
					if (par[y])
					{
						ans.emplace_back(y, x);
						par[y] = !par[y];
					}
					else
					{
						ans.emplace_back(x, y);	
						par[x] = !par[x];
					}
				}
			}
		state[x] = 2;
	};
	for (int i = 0; i < n; i++)
	{
		if (state[i] == 0)
		{
			dfs(i, 0, dfs);
			if (par[i])
			{
				cout << "IMPOSSIBLE\n";
				return 0;
			}
		}
	}
	for (auto [x, y] : ans)
	{
		cout << x+1 << " " << y+1 << "\n";
	}
}
