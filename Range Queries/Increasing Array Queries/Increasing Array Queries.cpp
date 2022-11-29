#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct segtree
{
	struct node
	{
		int c=1;
		ll s=0, mi=0, ma=0, p=0;
		node(ll v) : s(v) , mi(v) , ma(v) {}
		node() {}
	};
	
	void merge(node a, node b, node &c)
	{
		c.c = a.c + b.c;
		c.s = a.s + b.s;
		c.mi = min(a.mi, b.mi);
		c.ma = max(a.ma, b.ma);
	}

	int n;
	vector < node > T;

	segtree(vector < ll > V)
	{
		n = 1; while(n < V.size()) n*=2;
		T.resize(n*2);
		for (int i = 0; i < V.size(); i++)
		{
			T[i+n] = node(V[i]);
		}
		for (int i = n-1; i; i--)
		{
			merge(T[i*2], T[i*2+1], T[i]);
		}
	}

	segtree(int in)
	{
		n = 1; while(n < in) n*=2;
		T.resize(n*2);
	}

	void propagate(int k)
	{
		if (T[k].p == 0) return;
		T[k].s = T[k].p * T[k].c;
		T[k].ma = T[k].mi = T[k].p;
		if (k < n)
		{
			T[k*2].p = T[k].p;
			T[k*2+1].p = T[k].p;
		}
		T[k].p = 0;
	}

	void set(int a, int b, ll v, int k=1, int x=0, int y=-1)
	{
		if (y == -1) y = n;
		if (a<=x && y<=b && T[k].ma <= v) T[k].p = v;
		propagate(k);
		if (a<=x && y<=b && T[k].mi >= v) return;
		if (b<=x || y<=a) return;
		
		int m = (x+y)/2;	
		set(a, b, v, k*2, x, m);
		set(a, b, v, k*2+1, m, y);
		merge(T[k*2], T[k*2+1], T[k]);
	}
	
	ll get(int a, int b, int k=1, int x=0, int y=-1)
	{
		if (y == -1) y = n;
		propagate(k);
		if (a<=x && y<=b) return T[k].s;
		if (b<=x || y<=a) return 0;

		int m = (x+y)/2; 
		return get(a, b, k*2, x, m) + get(a, b, k*2+1, m, y);
	}
};

int main()
{
	int n, m;
	cin >> n >> m;
	vector < ll > V(n);
	vector < ll > S(n+1, 0);
	for (int i = 0; i < n; i++)
	{
		cin >> V[i];
		S[i+1] = S[i] + V[i];
	}

	vector < vector < pair < int , int > > > Q(n); 
	for (int i = 0; i < m; i++)
	{
		int a, b; cin >> a >> b; a--;
		Q[a].push_back({b, i});
	}

	vector < ll > sol(m);

	segtree seg(n);
	for (int i = n-1; i >= 0; i--)
	{
		ll x = V[i];
		seg.set(i, n, x);
		for (pair < int , int > q : Q[i])
		{
			sol[q.second] = seg.get(0, q.first) - (S[q.first] - S[i]);
		}
	}

	for (ll a : sol) cout << a << "\n";
}

