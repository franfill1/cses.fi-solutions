#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct query
{
	int b, i;
};

struct fenwick
{
	int n;
	vector < int > T;

	fenwick(int in) : n(in+1)
	{
		T.resize(n, 0);
	}

	void add(int k, int u)
	{
		for (k++; k < n; k += k&-k) T[k] += u;
	}

	int get(int k)
	{
		int ans = 0;
		for (k++; k > 0; k -= k&-k) ans += T[k];
		return ans;
	}
};

int main()
{
	int n, m;
	cin >> n >> m;
	vector < ll > V(n);
	for (ll &x : V) cin >> x;

	vector < vector < query > > Q(n);
	for (int i = 0; i < m; i++)
	{
		query q; int a;
		cin >> a >> q.b;
		a--; q.b--;
		q.i = i;
		Q[a].push_back(q);
	}

	vector < int > an(m);
	map < ll , int > last;
	fenwick fen(n);

	for (int a = n-1; a >= 0; a--)
	{
		ll v = V[a];
		if (last.count(v)) fen.add(last[v], -1);
		last[v] = a;
		fen.add(a, 1);

		for (query q : Q[a])
		{
			an[q.i] = fen.get(q.b);
		}
	}

	for (int a : an) cout << a << "\n";

}
