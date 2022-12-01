/*
Task:              1668 Building Teams
Sender:            franfill
Submission time:   2021-07-20 20:57:14
Language:          C++11
Result:            ACCEPTED
/*
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
		cin >> a >> b; a--; b--;
		g[a].push_back(b); g[b].push_back(a);
	}

	vector < int > c (n, 0);

	for (int i = 0; i < n; i++)
	{
		if (c[i] == 0)
		{
			c[i] = 1;	
			queue < int > q;
			q.push(i);

			while(!q.empty())
			{
				int n = q.front(); q.pop();
				for (int ne : g[n])
				{
					if (c[ne] == 0)
					{
						c[ne] = 3 - c[n];
						q.push(ne);
					}
					else if (c[ne] == c[n])
					{
						cout << "IMPOSSIBLE";
						return 0;
					}
				}
			}
		}
	}

	for (int i : c) cout << i << " ";
}
