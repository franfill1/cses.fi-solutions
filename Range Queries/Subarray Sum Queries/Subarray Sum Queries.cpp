/*
Task:              1190 Subarray Sum Queries
Sender:            franfill
Submission time:   2021-08-02 19:45:32
Language:          C++11
Result:            ACCEPTED
/*
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct segtree
{
	struct node
	{
		ll t=0, l=0, r=0, s=0;
		node(ll v) : t(v) , l(max(0ll, v)), r(max(0ll, v)), s(max(0ll, v)) {}
		node() {}
	};
	
	void merge(node a, node b, node &c)
	{
		c.t = a.t + b.t;
		c.l = max(a.l, a.t + b.l);
		c.r = max(a.r + b.t, b.r);
		c.s = max(max(a.s, b.s), a.r + b.l);
	}

	int n;
	vector < node > T;

	segtree(vector < ll > &V)
	{
		n = 1; while(n < V.size()) n*=2;
		T.resize(n*2);

		for (int i = 0; i < V.size(); i++)
		{
			T[i+n] = V[i];
		}

		for (int i = n-1; i > 0; i--)
		{
			merge(T[i*2], T[i*2+1], T[i]);
		}
	}

	void set(int k, ll u)
	{
		k += n; T[k] = node(u);

		while(k /= 2) merge(T[k*2], T[k*2+1], T[k]);
	}

	ll get(int a, int b)
	{
		a += n; b += n;
		node na(0), nb(0);
		while(a <= b)
		{
			if (a % 2 == 1) merge(na, T[a++], na);
			if (b % 2 == 0) merge(T[b--], nb, nb);
			a /= 2; b /= 2;
		}

		merge(na, nb, na);
		return na.s;
	}
};

int main()
{
	int n, m;
	cin >> n >> m;
	vector < ll > V(n);
	for (ll &x : V) cin >> x;

	segtree seg(V);

	while(m--)
	{
		int k; ll u;
		cin >> k >> u; k--;
		seg.set(k, u);
		cout << seg.get(0, n-1) << "\n";
	}
}
