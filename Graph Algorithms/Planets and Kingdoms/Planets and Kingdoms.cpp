/*
Task:              1683 Planets and Kingdoms
Sender:            franfill
Submission time:   2022-04-28 12:20:36
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
	vector < vector < int > > r(n);
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b; a--; b--;
		g[a].push_back(b);
		r[b].push_back(a);
	}

	vector < int > ts;
	vector < bool > vis(n, 0);
	function < void(int) > dfs = [&] (int x) -> void {
		vis[x] = true;
		for (int y : g[x]) if (!vis[y]) dfs(y);
		ts.push_back(x);
	};
	for (int x = 0; x < n; x++) if (!vis[x]) dfs(x);
	int count = 0;
	vector < int > kingdom(n, -1);
	function < void(int) > bfs = [&] (int s) -> void {
		queue < int > q;	
		int k = ++count;
		kingdom[s] = k;
		q.push(s);
		while(q.size())
		{
			int x = q.front();
			q.pop();
			for (int y : r[x]) if (kingdom[y] == -1)
			{
				kingdom[y] = k;
				q.push(y);
			}
		}
	};

	for (int i = n-1; i >= 0; i--) if (kingdom[ts[i]] == -1) bfs(ts[i]);
	cout << count << "\n";
	for (int k : kingdom) cout << k << " ";
	cout << "\n";
}
