#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair < int , ll > edge;
typedef pair < ll , int > state;

int main()
{
	int n, m, k;
	cin >> n >> m >> k;

	vector < vector < edge > > g(n);
	for (int i = 0; i < m; i++)
	{
		int a, b;
		ll c;
		cin >> a >> b >> c; a--; b--;
		g[a].push_back({b, c});
	}

	vector < ll > cnt (n, 0);
	cnt[0]++;

	priority_queue < state , vector < state > , greater < state > > pq;
	pq.push({0, 0});

	vector < ll > ans;

	while(!pq.empty())
	{
		int p = pq.top().second; ll d = pq.top().first; pq.pop();

		if (cnt[p] == k+1) continue;
		cnt[p]++;

		if (p == n-1 && ans.size() < k) ans.push_back(d);

		for (edge ed : g[p])
		{
			int ne = ed.first; ll c = ed.second;
			ll nd = d + c;
			if (cnt[ne] < k) pq.push({nd, ne});
		}
	}

	for (ll d : ans) cout << d << " ";
}
