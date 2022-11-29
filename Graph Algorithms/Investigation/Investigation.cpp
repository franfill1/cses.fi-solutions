#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair < int , ll > edge;
typedef pair < ll , int > state;
const ll inf = 1ll<<60;

const ll M = 1000000007;

int main()
{
	int n, m;
	cin >> n >> m;

	vector < vector < edge > > g(n);
	for (int i = 0; i < m; i++)
	{
		int a, b; ll c;
		cin >> a >> b >> c; a--; b--;
		g[a].push_back({b, c});
	}

	vector < ll > D(n, inf);
	D[0] = 0;

	priority_queue < state , vector < state > , greater < state > > pq;
	pq.push({0, 0});

	while(!pq.empty())
	{
		int p = pq.top().second; ll d = pq.top().first; pq.pop();
		if (d > D[p]) continue;

		for (edge ed : g[p])
		{
			int ne = ed.first;
			ll c = ed.second;
			ll nd = d + c;
			if (nd < D[ne])
			{
				D[ne] = nd;
				pq.push({nd, ne});
			}
		}
	}

	for (int i = 0; i < n; i++) pq.push({D[i], i});

	vector < ll > cnt(n, 0);
	cnt[0] = 1;

	vector < ll > mi(n, inf);
	mi[0] = 0;

	vector < int > ma(n, 0);

	for (int i = 0; i < n; i++)
	{
		int p = pq.top().second;
		pq.pop();

		for (edge ed : g[p])
		{
			int ne = ed.first; ll c = ed.second;
			if (D[ne] == D[p] + c)
			{
				cnt[ne] += cnt[p];
				cnt[ne] %= M;
				mi[ne] = min(mi[ne], mi[p] + 1);
				ma[ne] = max(ma[ne], ma[p] + 1);
			}
		}
	}

	cout << D[n-1] << " " << cnt[n-1] << " " << mi[n-1] << " " << ma[n-1] << "\n";
}

