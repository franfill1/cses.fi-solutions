#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct node
{
	ll t=0, l=0;
};

ostream& operator << (ostream& os, node n)
{
	os << "{t: " << n.t << ", l: " << n.l << "}";
	return os;
}

struct segtree
{
	void merge(node a, node b, node &c)
	{
		c.t = a.t + b.t;
		c.l = max(a.l, a.t + b.l);
	}

	int n;
	vector < node > T;

	segtree(vector < ll > &V) 
	{
		n = 1;
		while(n < V.size()) n*=2;

		T.resize(n*2);

		for (int i = 0; i < V.size(); i++)
		{
			T[i+n].t = T[i+n].l = V[i];
		}

		for (int i = n-1; i > 0; i--)
		{
			merge(T[i*2], T[i*2+1], T[i]);
		}
	}

	void set(int k, ll u)
	{
		k += n;
		T[k].l = T[k].t = u;
		while(k /= 2)
		{
			merge(T[k*2], T[k*2+1], T[k]);
		}
	}

	ll get(int a, int b)
	{
		a += n; b += n;
		node na, nb;

		while (a <= b)
		{
			if (a % 2 == 1)
			{
				merge(na, T[a], na);
				a++;
			}
			if (b % 2 == 0) 
			{
				merge(T[b--], nb, nb);
			}
			a /= 2;
			b /= 2;
		}

		merge(na, nb, na);
		return na.l;
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
		int q;
		cin >> q;
		if (q == 1)
		{
			int k; ll u;
			cin >> k >> u; k--;
			seg.set(k, u);
		}
		else
		{
			int a, b;
			cin >> a >> b; a--; b--;
			cout << seg.get(a, b) << "\n";
		}
	}
}

