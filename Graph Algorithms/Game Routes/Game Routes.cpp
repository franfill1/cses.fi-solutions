#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll M = 1000000007;

vector < vector < ll > > g;
vector < bool > vis;
stack < ll > ts;

void toposort(ll p)
{
	vis[p] = true;
	for (ll ne : g[p])
		if (!vis[ne]) toposort(ne);
	ts.push(p);
}

int main()
{
	ll n, m;
	cin >> n >> m;

	g.resize(n); vis.resize(n, false);

	for (ll i = 0; i < m; i++)
	{
		ll a, b;
		cin >> a >> b;
		a--; b--;
		g[a].push_back(b);
	}

	toposort(0);

	vector < ll > W(n, 0);
	W[0] = 1;

	while(!ts.empty())
	{
		ll p = ts.top(); ts.pop();
		for (ll ne : g[p])
			W[ne] = (W[p] + W[ne])%M;
	}
	
	cout << W[n-1];
}
