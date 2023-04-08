/*
Task:              1694 Download Speed
Sender:            franfill
Submission time:   2023-03-30 11:34:02
Language:          C++17
Result:            ACCEPTED
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct edge
{
	ll to, cap, r;
	edge(ll to_, ll cap_, ll r_) : to(to_) , cap(cap_), r(r_)
	{
	}
};

vector < vector < edge > > g;
vector < int > from;

ll find_path(int s, int f)
{
	queue < int > q;
	vector < ll > fl(g.size(), 0);
	fl[0] = 1<<30;
	q.emplace(0);
	while(!q.empty())
	{
		int x = q.front();
		q.pop();
		for (auto ed : g[x])
			if (ed.cap && fl[ed.to] == 0)
			{
				fl[ed.to] = min(fl[x], ed.cap);
				from[ed.to] = ed.r;
				if (ed.to == f)
					return fl[ed.to];
				q.push(ed.to);
			}
	}
	return 0;
}

ll maxflow(int s, int f)
{
	from.resize(g.size());
	ll res = 0;
	ll new_flow;
	while(new_flow = find_path(s, f))
	{
		res += new_flow;
		int x = f;
		while(x != s)
		{
			auto &ed_r = g[x][from[x]];
			int y = ed_r.to;
			auto &ed = g[y][ed_r.r];
			ed_r.cap += new_flow;
			ed.cap -= new_flow;
			x = y;
		}
	}
	return res;
}

main()
{
	int n, m;
	cin >> n >> m;
	g.resize(n);
	for (int i = 0; i < m; i++)
	{
		ll a, b, c;
		cin >> a >> b >> c;
		a--, b--;
		g[a].emplace_back(b, c, g[b].size());
		g[b].emplace_back(a, 0, g[a].size()-1);
	}
	cout << maxflow(0, n-1) << "\n";
}

