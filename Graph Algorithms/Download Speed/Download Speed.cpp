/*
Task:              1694 Download Speed
Sender:            franfill
Submission time:   2021-07-30 22:13:43
Language:          C++11
Result:            ACCEPTED
/*
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair < int , ll > state;

struct edge
{
	int b;
	ll c;
	int r;
};

vector < vector < edge > > g;
vector < int > back;
int n;

ll find_flow()
{
	vector < bool > vis(n);
	queue < state > q;
	q.push({0, 1ll<<60});

	while(!q.empty())
	{
		int x = q.front().first; ll flow = q.front().second;
		q.pop();

		for (int i = 0; i < g[x].size(); i++)
		{
			edge ed = g[x][i];
			ll new_flow = min(flow, ed.c);
			int y = ed.b;
			
			if (new_flow > 0 && !vis[y])
			{
				back[y] = ed.r;
				vis[y] = true;
				if (y == n-1)
				{
					return new_flow;
				}
				q.push({y, new_flow});
			}
		}
	}
	return 0;
}

ll max_flow()
{
	back.resize(n);
	ll flow = 0, new_flow = 0;
	while(new_flow = find_flow())
	{
		flow += new_flow;
		int x = n-1;
		while(x != 0)
		{
			int y = g[x][back[x]].b;
			int front = g[x][back[x]].r;
			
			assert(g[y][front].c >= new_flow);
			g[y][front].c -= new_flow;
			g[x][back[x]].c += new_flow;
			x = y;
		}
	}

	return flow;
}

int main()
{
	int m;
	cin >> n >> m;
	g.resize(n);
	for (int i = 0; i < m; i++)
	{
		int a, b; ll c;
		cin >> a >> b >> c; a--; b--;
		g[a].push_back({b, c, g[b].size()});
		g[b].push_back({a, 0, g[a].size()-1});
	}
	
	cout << max_flow();
}
