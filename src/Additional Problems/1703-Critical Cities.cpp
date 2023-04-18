/*
Task:              1703 Critical Cities
Sender:            franfill
Submission time:   2023-04-18 18:04:23
Language:          C++17
Result:            ACCEPTED
*/
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	vector < vector < int > > g(n);
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		a--, b--;
		g[a].emplace_back(b);
	}

	vector < int > pa(n, -1);
	queue < int > q;
	pa[0] = 0;
	q.emplace(0);
	while(!q.empty())
	{
		int x = q.front();
		q.pop();
		for (auto y : g[x])
			if (pa[y] == -1)
			{
				pa[y] = x;
				q.emplace(y);
			}
	}

	vector < int > path, id(n, -1);
	int x = n-1;
	id[x] = path.size();
	path.emplace_back(x);
	while(x != 0)
	{
		x = pa[x];
		id[x] = path.size();
		path.emplace_back(x);
	}

	vector < int > up(path.size(), -1);
	vector < bool > vis(n, 0);
	stack < pair < int , int > > s;
	up.back() = path.size()-1;
	for (int i = path.size()-1; i >= 0; i--)
	{
		q.emplace(path[i]);
		while(!q.empty())
		{
			int x = q.front();
			q.pop();
			for (auto y : g[x])
				if (!vis[y])
				{
					vis[y] = true;
					if (id[y] == -1)
						q.emplace(y);
					else
					 	up[id[y]] = i;
				}
		}
		int val = up[i];
		while(s.size() && s.top().first < up[i])
		{
			val = s.top().second;
			s.pop();
		}
		s.emplace(i, val);
	}

	int ans = 0, ris = 0;
	vector < bool > crit(n);
	for (int i = 0; i < path.size(); i++)
	{
		if (ris <= i)
			crit[path[i]] = true, ans++;
		ris = max(ris, up[i]);
	}

	cout << ans << "\n";
	for (int i = 0; i < n; i++)
		if (crit[i])
			cout << i+1 << " ";
	cout << "\n";
}
