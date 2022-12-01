/*
Task:              1682 Flight Routes Check
Sender:            franfill
Submission time:   2021-07-26 21:29:35
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
	vector < int > comp;
	int cnt = 0;
	
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
		comp[x] = c;
		for (int ne : r[x])
		{
			if (comp[ne] == -1)
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

		comp.resize(n, -1);
		for (int i = n-1; i >= 0; i--) 
		{
			int x = s[i];
			if (comp[x] == -1)
			{
				dfs2(s[i], cnt);
				cnt++;
			}
		}
	}

	pair < int , int > getExternalEdge()
	{
		for (int i = 0; i < m; i++)
		{
			int a = list[i].first, b = list[i].second;
			if (comp[list[i].first] != comp[list[i].second]) return list[i];
		}
		return {-1, -1};
	}

	pair < int , int > findImpossiblePath()
	{
		pair < int , int > edge = getExternalEdge();
		if (edge.first == -1)
		{
			v.assign(n, false);
			dfs1(0);
			for (int i = 0; i < n; i++)
			{
				if (!v[i]) return {0, i};
			}
		}
		return edge;
	}
};

int main()
{
	int n, m;
	cin >> n >> m;
	
	vector < vector < int > > g(n);

	for (int i = 0; i < m; i++)
	{
		int a, b; cin >> a >> b; a--; b--;
		g[a].push_back(b);
	}

	scc c(g);

	if (c.cnt == 1)
	{
		cout << "YES\n";
	}
	else
	{
		cout << "NO\n";
		pair < int , int > edge = c.findImpossiblePath();
		cout << edge.second+1 << " " << edge.first+1 << "\n";
	}
}
