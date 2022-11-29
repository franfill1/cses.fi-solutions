#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;
	vector < vector < int > > g(N);
	
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		a--; b--;
		
		g[a].push_back(b);
		g[b].push_back(a);
	}
	
	vector < int > ans;
	vector < int > vis(N, false);
	
	for (int i = 0; i < N; i++)
	{
		if (!vis[i])
		{
			ans.push_back(i);
			vis[i] = true;
			queue < int > q;
			q.push(i);
			while(!q.empty())
			{
				int n = q.front();
				q.pop();
				for (int ne : g[n])
				{
					if (!vis[ne])
					{
						vis[ne] = true;
						q.push(ne);
					}
				}
			}
		}
	}
	
	cout << ans.size() - 1 << "\n";
	for (int i = 1; i < ans.size(); i++)
	{
		cout << 1 << " " << ans[i]+1 << "\n";
	}
}


