/*
Task:              2078 Eulerian Subgraphs
Sender:            franfill
Submission time:   2022-10-17 18:01:00
Language:          C++17
Result:            ACCEPTED
*/
#include<bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;

int main()
{
	int n, m;
	cin >> n >> m;
	
	vector < long long > p(m, 1);
	for (int i = 1; i < m; i++)
		p[i] = (p[i-1] * 2) % mod;

	vector < vector < int > > g(n);
	for (int i = 0; i < m; i++)
	{
		int a, b; cin >> a >> b;
		a--; b--;
		g[a].emplace_back(b);
		g[b].emplace_back(a);
	}

	vector < bool > vis(n, false);
	long long ans = 1;
	for (int i = 0; i < n; i++)
		if (!vis[i])
		{
			int nn = 0, mm = 0;
			vis[i] = true;
			queue < int > q;
			q.emplace(i);
			while(!q.empty())
			{
				int x = q.front();
				q.pop();
				nn++;
				mm += g[x].size();
				for (auto y : g[x])
					if (!vis[y])
					{
						vis[y] = true;
						q.emplace(y);
					}
			}
			mm /= 2;
			int k = mm - nn + 1;
			ans *= p[k];
			ans %= mod;
		}

	cout << ans << "\n";
}
