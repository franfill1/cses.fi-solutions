/*
Task:              2130 Distinct Routes II
Sender:            franfill
Submission time:   2022-11-29 22:18:56
Language:          C++17
Result:            ACCEPTED
*/
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int MAXN = 500;
struct edge
{
	int to;
	int r;
	ll cap=0, cost, ori;
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
	int M, K;
	cin >> N >> M >> K;
	for (int i = 0; i < M; i++)
	{
		int a, b; 
		ll r = 1, c = 1;
		cin >> a >> b;
		a--; b--;
		g[a].emplace_back(b, g[b].size(), r, c);
		g[b].emplace_back(a, g[a].size()-1, 0, -c);
	}
	auto [flow, cost] = mincost(K);
	if (flow < K)
	{
		cout << -1 << "\n";
		return 0;
	}
	else
	{
		cout << cost << "\n";
		for (int i = 0; i < K; i++)
		{
			int x = 0;
			vector < int > p(1, 0);
			while(x != N-1)
			{
				for (auto &ed : g[x])
					if (ed.cap != ed.ori && ed.ori == 1)
					{
						x = ed.to;
						ed.cap = ed.ori;
						p.emplace_back(x);
						break;
					}
			}
			cout << p.size() << "\n";
			for (auto x : p)
				cout << x+1 << " ";
			cout << "\n";
		}
	}
}
