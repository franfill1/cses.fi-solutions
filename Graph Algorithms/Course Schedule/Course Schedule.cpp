#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	
	vector < vector < int > > g(n);
	vector < int > in(n, 0);

	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b; a--; b--;
		g[a].push_back(b);
		in[b]++;
	}

	queue < int > q;
	for (int i = 0; i < n; i++)
		if (!in[i]) q.push(i);

	vector < int > ans;

	while(!q.empty())
	{
		int p = q.front(); q.pop();
		ans.push_back(p);
		for (int ne : g[p])
		{
			in[ne]--;
			if (in[ne] == 0)
			{
				q.push(ne);
			}
		}
	}

	if (ans.size() != n)
	{
		cout << "IMPOSSIBLE\n";
	}
	else
	{
		for (int i : ans) cout << i+1 << " ";
	}
}
