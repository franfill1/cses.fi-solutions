/*
Task:              2138 Reachable Nodes
Sender:            franfill
Submission time:   2022-11-29 20:54:35
Language:          C++17
Result:            ACCEPTED
*/
#include<bits/stdc++.h>
#pragma GCC target("popcnt")
using namespace std;
bitset < 50000 > r[50000];
int ans[50000];
vector < int > g[50000];
int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		r[i].set(i);
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		a--, b--;
		g[a].emplace_back(b);
	}
	auto dfs = [&] (int x, auto dfs) -> void
	{
		for (auto y : g[x])
			if (ans[y] == 0)
				dfs(y, dfs);
		//sort(g[x].begin(), g[x].end(), [&] (int i, int j) {
				//return ans[i] > ans[j];
				//});
		for (auto y : g[x]) 
			if (!r[x].test(y))
				r[x] |= r[y];
		ans[x] = r[x].count();
	};
	for (int i = 0; i < n; i++)
		if (ans[i] == 0)
			dfs(i, dfs);
	for (int i = 0; i < n; i++)
		cout << ans[i] << " ";
	cout << "\n";
}
