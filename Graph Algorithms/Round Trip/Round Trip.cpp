/*
Task:              1669 Round Trip
Sender:            franfill
Submission time:   2022-02-05 13:23:08
Language:          C++17
Result:            ACCEPTED
*/
#include <bits/stdc++.h>

using namespace std;

int N;
vector < vector < int > > g;
vector < bool > vis;
vector < int > ans;

int dfs(int n, int from)
{
	for (int ne : g[n])
	{
		if (ne != from)
		{
			if (!vis[ne])
			{
				vis[ne] = true;
				int temp = dfs(ne, n);
				if (ans.size() != 0)
				{
					if (temp != -2)
					{
						ans.push_back(n+1);
					}
					if (temp == n)
					{
						return -2;
					}
					else
					{
						return temp;
					}
				}
			}
			else
			{
				ans.push_back(ne+1);
				ans.push_back(n+1);
				return ne;
			}
		}
	}
	return -1;
}

int main()
{
	int M;
	cin >> N >> M;
	g.resize(N);
	vis.resize(N, false);
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		a--; b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	
	for (int i = 0; i < N; i++)
	{
		if (!vis[i]) 
		{
			vis[i] = true;
			dfs(i, -1);
		}
		if (ans.size() > 0) break;
	}
	if (ans.size() == 0)
	{
		cout << "IMPOSSIBLE";
	}
	else
	{
		cout << ans.size() << "\n";
		for (int i = 0; i < ans.size(); i++)
		{
			cout << ans[i] << " ";
		}
	}
}

