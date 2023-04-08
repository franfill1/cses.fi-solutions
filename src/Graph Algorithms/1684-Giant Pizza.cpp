/*
Task:              1684 Giant Pizza
Sender:            franfill
Submission time:   2021-07-26 22:23:38
Language:          C++11
Result:            ACCEPTED
*/
#include<bits/stdc++.h>
using namespace std;

struct scc
{
	int n, m;
	vector < vector < int > > g;
	vector < vector < int > > r;
	vector < pair < int , int > > list;

	vector < vector < int > > comp;
	vector < int > par;
	vector < vector < int > > cg;
	vector < int > ts;
	
	vector < bool > v;
	vector < int > s;

	void dfs1(int x)
	{
		v[x] = true;
		for (int ne : g[x])
		{
			if (!v[ne])
			{
				dfs1(ne);
			}
		}
		s.push_back(x);
	}

	void dfs2(int x, int c)
	{
		par[x] = c;
		comp[c].push_back(x);
		for (int ne : r[x])
		{
			if (par[ne] == -1)
			{
				dfs2(ne, c);
			}
		}
	}

	scc(vector < vector < int > > &ig) : g(ig) , n(ig.size())
	{
		m = 0;
		r.resize(n);
		for (int i = 0; i < n; i++)
		{
			for (int v : g[i])
			{
				m++;
				r[v].push_back(i);
				list.push_back({i, v});
			}
		}

		v.assign(n, false);
		for (int x = 0; x < n; x++) if (!v[x]) dfs1(x);

		par.resize(n, -1);
		for (int i = n-1; i >= 0; i--) if (par[s[i]] == -1) 
		{
			comp.emplace_back(0);
			dfs2(s[i], comp.size()-1);
		}
		
		cg.resize(comp.size());
		for (int i = 0; i < m; i++)
		{
			int a = list[i].first, b = list[i].second;
			if (par[a] != par[b])
			{
				cg[par[a]].push_back(par[b]);
			}
		}

		v.assign(comp.size(), false);
		for (int i = 0; i < comp.size(); i++)
		{
			if (!v[i]) toposort(i);
		}
	}

	void toposort(int c)
	{
		v[c] = true;
		for (int nc : cg[c])
		{
			if (!v[nc]) toposort(nc);
		}
		ts.push_back(c);
	}
};

int main()
{
	int n, m;
	cin >> m >> n;	

	vector < vector < int > > g(n*2);
	for (int i = 0; i < m; i++)
	{
		char c1, c2; int a, b;
		cin >> c1 >> a >> c2 >> b;
		a--; b--;
		if (c1 == '-') a += n;
		if (c2 == '+') b += n;

		g[a].push_back(b);

		if (c1 == '-') a -= n;
		else a += n;
		if (c2 == '+') b -= n;
		else b += n;

		g[b].push_back(a);
	}

	scc s(g);

	for (int i = 0; i < n; i++)
	{
		if (s.par[i] == s.par[i+n])
		{
			cout << "IMPOSSIBLE\n";
			return 0;
		}
	}

	vector < int > val(n, -1);

	for (int c : s.ts)
	{
		for (int x : s.comp[c])
		{
			if (val[x%n] == -1)
			{
				if (x >= n) val[x%n] = 1;
				else val[x%n] = 0;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		cout << (val[i] ? '+' : '-') << " ";
	}
}
