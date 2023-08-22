/*
Task:              1699 Flight Route Requests
Sender:            franfill
Submission time:   2023-06-15 10:17:45 +0300
Language:          C++17
Result:            ACCEPTED
*/
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	vector < vector < int > > g1(n), g2(n);
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		a--, b--;
		g1[a].emplace_back(b);
		g2[a].emplace_back(b);
		g2[b].emplace_back(a);
	}

	vector < int > sta(n, 0);

	bool found;
	auto dfs = [&] (int x, auto dfs) -> void
	{
		sta[x] = 2;
		for (auto y : g1[x])
		{
			assert(sta[y] != 0);
			if (sta[y] == 1)
				dfs(y, dfs);
			else if (sta[y] == 2)
				found = true;
		}
		sta[x] = 3;
	};

	int ans = n;
	for (int i = 0; i < n; i++)
		if (sta[i] == 0)
		{
			vector < int > v;
			queue < int > q;
			q.emplace(i);
			sta[i] = 1;
			while(!q.empty())
			{
				int x = q.front();
				v.push_back(x);
				q.pop();
				for (auto y : g2[x])
					if (sta[y] == 0)
					{
						sta[y] = 1;
						q.emplace(y);
					}
			}
			
			found = false;
			for (auto &x : v)
				if (sta[x] == 1)
					dfs(x, dfs);
			if (!found)
				ans--;
		}
	cout << ans << "\n";
}
