/*
Task:              1195 Flight Discount
Sender:            franfill
Submission time:   2021-07-21 12:34:00
Language:          C++11
Result:            ACCEPTED
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair < int , ll > edge;
const ll inf = 1ll<<60;

struct state
{
	int p;
	ll d;
	bool u;
};

bool operator > (state a, state b)
{
	return a.d > b.d;
}

int main()
{
	int n, m;
	cin >> n >> m;
	
	vector < vector < edge > > g(n);
	for (int i = 0; i < m; i++)
	{
		int a, b; 
		cin >> a >> b; a--; b--;
		ll c; 
		cin >> c;
		g[a].push_back({b, c});
	}

	vector < vector < ll > > D(2, vector < ll > (n, inf));
	D[0][0] = 0;

	priority_queue < state , vector < state > , greater < state > > pq;
	pq.push({0, 0, 0});

	while(!pq.empty())
	{
		int p = pq.top().p; ll d = pq.top().d; bool u = pq.top().u;
		pq.pop();

		if (d > D[u][p]) continue;

		for (edge ed : g[p])
		{
			int ne = ed.first;
			ll w = ed.second;
			ll nd = d + w;
			if (nd < D[u][ne])
			{
				D[u][ne] = nd;
				pq.push({ne, nd, u});
			}
			if (!u)
			{
				nd = d + w/2;
				if (nd < D[1][ne])
				{
					D[1][ne] = nd;
					pq.push({ne, nd, 1});
				}
			}
		}
	}

	cout << D[1][n-1];
}
