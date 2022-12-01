/*
Task:              1695 Police Chase
Sender:            franfill
Submission time:   2021-07-30 22:35:27
Language:          C++11
Result:            ACCEPTED
/*
#include<bits/stdc++.h>
using namespace std;
typedef pair < int , int > state;

int n;
int adj[500][500];
int back[500];

int find_flow()
{
	vector < bool > vis(n, false);	
	queue < state > q;
	q.push({0, 1<<30});

	while(!q.empty())
	{
		int x = q.front().first; int flow = q.front().second; q.pop();
		for (int y = 0; y < n; y++) if (!vis[y] && adj[x][y])
		{
			int new_flow = min(flow, adj[x][y]);
			back[y] = x;
			vis[y] = true;
			if (y == n-1)
				return new_flow;
			q.push({y, new_flow});
		}
	}
	return 0;
}

int max_flow()
{
	int flow = 0;
	int new_flow;
	while(new_flow = find_flow())
	{
		flow += new_flow;
		int x = n-1;
		while(x != 0)
		{
			int y = back[x];
			assert(adj[y][x] >= new_flow);
			adj[y][x] -= new_flow;
			adj[x][y] += new_flow;
			x = y;
		}
	}
	return flow;
}

int main()
{
	int m;
	cin >> n >> m;
	vector < pair < int , int > > eds;
	
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b; a--; b--;
		adj[a][b]++;
		adj[b][a]++;
		eds.push_back({a, b});
	}

	int cut = max_flow();

	vector < bool > vis(n);
	vis[0] = true;
	queue < int > q;
	q.push(0);
	while(!q.empty())
	{
		int x = q.front(); q.pop();
		for (int y = 0; y < n; y++) if (adj[x][y] && !vis[y])
		{
			vis[y] = true;
			q.push(y);
		}
	}

	cout << cut << "\n";
	for (pair < int , int > ed : eds)
	{
		if (vis[ed.first] != vis[ed.second])
			cout << ed.first+1 << " " << ed.second+1 << "\n";
	}
}
