#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	
	vector < set < int > > g(n);
	vector < int > deg(n, 0);
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b; a--; b--;
		g[a].insert(b);
		deg[b]++;
	}

	if (deg[0]+1 != g[0].size() || deg[n-1] != g[n-1].size()+1)
	{
		cout << "IMPOSSIBLE\n";
		return 0;
	}

	for (int i = 1; i < n-1; i++)
	{
		if (deg[i] != g[i].size())
		{
			cout << "IMPOSSIBLE\n";
			return 0;
		}
	}

	stack < int > ans;
	stack < int > s;
	s.push(0);
	while(!s.empty())
	{
		int x = s.top();
		if (g[x].empty())
		{
			ans.push(x);
			s.pop();
		}
		else
		{
			int y = *g[x].begin();
			g[x].erase(y);
			s.push(y);
		}
	}

	if (ans.size() != m+1)
	{
		cout << "IMPOSSIBLE\n";
		return 0;
	}

	while(!ans.empty())
	{
		cout << ans.top()+1 << " ";
		ans.pop();
	}
}

