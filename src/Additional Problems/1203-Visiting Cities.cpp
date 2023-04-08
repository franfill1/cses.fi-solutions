/*
Task:              1203 Visiting Cities
Sender:            franfill
Submission time:   2023-04-06 13:20:18
Language:          C++17
Result:            ACCEPTED
*/
#include<bits/stdc++.h>
#define int ll
using namespace std;
using ll=long long;
constexpr int CNT = 2;
constexpr ll MODS[CNT] = {1000000007,
													879190421, 
													};

signed main()
{
	int n, m;
	cin >> n >> m;
	vector < vector < pair < int , ll > > > g(n), r(n);
	for (int i = 0; i < m; i++)
	{
		int a, b;
		ll w;
		cin >> a >> b >> w;
		a--, b--;
		g[a].emplace_back(b, w);
		r[b].emplace_back(a, w);
	}
	priority_queue < pair < ll , int > , vector < pair < ll , int > > , greater < pair < ll , int > > > pq;
	vector < ll > D(n, 1ll<<60);
	vector < array < int, CNT > > W(n);
	auto dijkstra = [&] (int s)
	{
		D[s] = 0;
		for (int i = 0; i < CNT; i++)
			W[s][i] = 1;
		pq.emplace(0, s);
		while(!pq.empty())
		{
			auto [d, x] = pq.top();
			pq.pop();
			if (d != D[x])
				continue;
			for (auto [y, w] : g[x])
				if (D[y] > d + w)
				{
					for (int i = 0; i < CNT; i++)
						W[y][i] = W[x][i];
					D[y] = d + w;
					pq.emplace(D[y], y);
				}
				else if (D[y] == d + w)
					for (int i = 0; i < CNT; i++)
						W[y][i] = (W[y][i] + W[x][i]) % MODS[i];
		}
	};
	dijkstra(0);
	auto D1 = D;
	auto W1 = W;
	D.assign(n, 1ll<<60);
	swap(g, r);
	dijkstra(n-1);
	vector < int > ans;
	for (int i = 0; i < n; i++)
	{
		if (D1[i] + D[i] != D1.back())
			continue;
		bool ok = true;
		for (int j = 0; j < CNT; j++)
			if (W[i][j] * W1[i][j] % MODS[j] != W1.back()[j])
			{
				ok = false;
				break;
			}
		if (ok)
			ans.emplace_back(i);
	}
	cout << ans.size() << "\n";
	for (auto i : ans)
		cout << i+1 << " ";
	cout << "\n";
}
