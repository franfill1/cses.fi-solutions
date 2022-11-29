#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair < ll , ll > pll;

int main()
{
	int n, m;
	cin >> n >> m;
	
	vector < vector < pll > > g(n);
	for (int i = 0; i < m; i++)
	{
		int a, b;
		ll c;
		cin >> a >> b >> c; a--; b--; 
		g[a].push_back({b, c});
	}

	vector < ll > D(n, 1ll<<60);
	D[0] = 0;

	priority_queue < pll, vector < pll > , greater < pll > > pq;
	pq.push({0, 0});

	while(!pq.empty())
	{
		int c = pq.top().second; ll d = pq.top().first;
		pq.pop();

		if (D[c] < d) continue;

		for (pll nep : g[c])
		{
			int ne = nep.first; ll w = nep.second;
			ll nd = d + w;
			if (nd < D[ne])
			{
				D[ne] = nd;
				pq.push({nd, ne});
			}
		}
	}

	for (ll d : D) cout << d << " ";
}

