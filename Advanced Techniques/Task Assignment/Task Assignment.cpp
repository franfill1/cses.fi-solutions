#include<bits/stdc++.h>
using namespace std;

using ll=long long;

const int MAXN = 402;

struct edge
{
	int to;
	int r;
	int ori;
	ll cap=0, cost;
	explicit edge(int to_, int r_, ll cap_, ll cost_) :
		to(to_), r(r_), cap(cap_), cost(cost_), ori(cap_)
	{
	}
};

vector < edge > g[MAXN];
ll pre[MAXN], dis[MAXN], flo[MAXN];
bool inq[MAXN];
int N;

ll extend_flow()
{
	fill(pre, pre+N, -1);
	fill(dis, dis+N, 1ll<<60);
	fill(flo, flo+N, 0);
	fill(inq, inq+N, false);

	queue < int > q;
	dis[0] = 0;
	flo[0] = 1ll<<60;
	inq[0] = true;
	q.emplace(0);
	while(!q.empty())
	{
		int x = q.front();
		q.pop();
		inq[x] = false;
		for (edge &ed : g[x]) 
		{
			if (ed.cap > 0)
			{
				int y = ed.to;
				ll d = dis[x] + ed.cost;
				if (dis[y] > d)
				{
					dis[y] = d;
					flo[y] = min(flo[x], ed.cap);
					pre[y] = ed.r;
					if (!inq[y])
					{
						q.emplace(y);
						inq[y] = true;
					}
				}
			}
		}
	}
	return flo[N-1];
}

pair < ll , ll > mincost(ll K)
{
	ll flow = 0, new_flow;
	ll cost = 0;
	while((new_flow = min(K-flow, extend_flow())))
	{
		flow += new_flow;
		int x = N-1;
		while(x != 0)
		{
			int i = pre[x];
			int y = g[x][i].to;
			int j = g[x][i].r;
			swap(x, y);
			swap(i, j);
			cost += g[x][i].cost*new_flow;
			g[x][i].cap -= new_flow;
			g[y][j].cap += new_flow;
		}
	}
	return make_pair(flow, cost);
}

int main()
{
	int n;
	cin >> n;
	N = 2*n+2;
	for (int i = 1; i <= n; i++)
	{
		g[0].emplace_back(i, g[i].size(), 1, 0);
		g[i].emplace_back(0, g[0].size()-1, 0, 0);
		g[n+i].emplace_back(2*n+1, g[2*n+1].size(), 1, 0);
		g[2*n+1].emplace_back(n+i, g[n+i].size()-1, 0, 0);
		for (int j = 1; j <= n; j++)
		{
			int x;
			cin >> x;
			g[i].emplace_back(n+j, g[n+j].size(), 1, x);
			g[n+j].emplace_back(i, g[i].size()-1, 0, -x);
		}
	}
	cout << mincost(n).second << "\n";
	for (int i = 1; i <= n; i++)
	{
		for (auto &ed : g[i]) if (ed.to != 0 && ed.cap != ed.ori)
		{
			cout << i << " " << ed.to - n << "\n";
		}
	}
}

