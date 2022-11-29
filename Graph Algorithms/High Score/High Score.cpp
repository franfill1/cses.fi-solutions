#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
	int n, m;
	cin >> n >> m;
	vector < vector < pair < int , ll > > > g(n);
	vector < vector < int > > r(n);
	for (int i = 0; i < m; i++)
	{
		int a, b; ll x;
		cin >> a >> b >> x; a--; b--;
		g[a].push_back({b, x});
		r[b].push_back(a);
	}
	queue < int > q;
	set < int > us1 {0};
	q.push(0);
	while(!q.empty())
	{
		int a = q.front();
		q.pop();
		for (auto [b, x] : g[a]) if (!us1.count(b))
		{
			us1.insert(b);
			q.push(b);
		}
	}

	set < int > us2 {n-1};
	q.push(n-1);
	while(!q.empty())
	{
		int a = q.front();
		q.pop();
		for (int b : r[a]) if (!us2.count(b))
		{
			us2.insert(b);
			q.push(b);
		}
	}

	vector < ll > D(n, -1ll<<60);
	D[0] = 0;
	bool ok = false;
	int it = 0;
	while(!ok && (it++ <= 2*n))
	{
		ok = true;
		for (int a : us1)
		{
			for (auto [b, x] : g[a]) if (us2.count(b) && D[a] + x > D[b])
			{
				ok = false;
				D[b] = D[a] + x;
			}
		}
	}
	
	if (ok) cout << D[n-1] << "\n";
	else cout << "-1\n";
}

