#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair < int , ll > pill;
 
int main()
{
	int N, M;
	cin >> N >> M;
	vector < vector < pill > > g(N);
	for (int i = 0; i < M; i++)
	{
		int a, b, w;
		cin >> a >> b >> w; a--; b--;
		g[a].push_back({b, w});
	}
	
	vector < ll > D(N, LONG_MIN/2);
	D[0] = 0;
 
	bool cha=true, lcha=false;
	queue < int > q;
	vector < bool > vis(N, false);
	int r = 0;
	while(cha && r <= 2*N)
	{
		r++;
		cha = false;
		for (int n = 0; n < N; n++)
		{
			if (D[n] == LONG_MIN/2) continue;
			for (pill p : g[n])
			{
				int ne = p.first; ll w = p.second;
				if (D[n] + w > D[ne])
				{
					D[ne] = D[n] + w;
					cha = true;
					if (r > N+1)
					{
						q.push(ne);
						vis[ne] = true;
					}
 				}
			}
		}
	}
	while(!q.empty())
	{
		int n = q.front(); q.pop();
		for (pill p : g[n])
		{
			int ne = p.first;
			if (!vis[ne])
			{ 
				vis[ne] = true;
				q.push(ne);
			}
		}
	}
	if (vis[N-1]) cout << -1 << "\n";
	else cout << D[N-1] << "\n";
}
