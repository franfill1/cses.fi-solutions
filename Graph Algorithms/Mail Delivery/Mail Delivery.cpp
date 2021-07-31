#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	
	vector < set < int > > g(n);
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b; a--; b--;
		g[a].insert(b);
		g[b].insert(a);
	}
	
	for (int x = 0; x < n; x++)
	{
		if (g[x].size() % 2)
		{
			cout << "IMPOSSIBLE\n";
			return 0;
		}
	}

	vector < bool > v(n, false);
	queue < int > q;
	q.push(0);
	int c = 1;

	while(!q.empty())
	{
		int x = q.front(); q.pop();
		for (int ne : g[x])
		{
			if (!v[ne])
			{
				v[ne] = true;
				c++;
				q.push(ne);
			}
		}
	}

	for (int i = 1; i < n; i++) if (g[i].size() == 0) c++;

	if (c < n)
	{
		cout << "IMPOSSIBLE\n";
		return 0;
	}	



	stack< int > ans;
	stack< int > s;
	s.push(0);
	while(!s.empty())
	{
		int x = s.top();
		if (g[x].size() == 0)
		{
			s.pop();
			ans.push(x);
		}
		else
		{
			int y = *g[x].begin();
			g[x].erase(y);
			g[y].erase(x);
			s.push(y);
		}
	}

	while(!ans.empty())
	{
		cout << ans.top()+1 << " ";
		ans.pop();
	}
			

}
