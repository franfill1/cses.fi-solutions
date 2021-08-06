#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct segtree
{
	struct node
	{
		ll val=0, cnt=1, sum=0, set;
		bool toSet=false;
		node(ll v) : val(v) {}
		node() {}
	};

	int n;
	vector < node > T;

	segtree(vector < ll > &V)
	{
		n = 1; while(n < V.size()) n*=2;
		T.resize(n*2);
		for (int i = 0; i < V.size(); i++) T[i+n] = node(V[i]);
		for (int i = n-1; i; i--) 
		{
			T[i].val = T[i*2].val + T[i*2+1].val;
			T[i].cnt = T[i*2].cnt + T[i*2+1].cnt;
		}
	}

	void copyValues(node a, node &b)
	{
		if (a.toSet)
		{
			b.sum = a.sum;
			b.set = a.set;
			b.toSet = a.toSet;
		}
		else b.sum += a.sum;
	}

	void propagate(int k)
	{
		if (T[k].toSet)
		{
			T[k].val = T[k].cnt * T[k].set;
		}
		T[k].val += T[k].cnt * T[k].sum;
		if (k < n)
		{
			copyValues(T[k], T[k*2]);
			copyValues(T[k], T[k*2+1]);
		}
		T[k].toSet = false;
		T[k].sum = 0;
	}

	void add(int a, int b, ll v, int k=1, int x=0, int y=-1)
	{
		if(y == -1) y = n;

		if (a <= x && y <= b) T[k].sum += v;
		propagate(k);

		if (a <= x && y <= b) return;
		if (y <= a || b <= x) return;

		int m = (x+y)/2;
		add(a, b, v, k*2, x, m);
		add(a, b, v, k*2+1, m, y);
		T[k].val = T[k*2].val + T[k*2+1].val;
	}

	void set(int a, int b, ll v, int k=1, int x=0, int y=-1)
	{
		if(y == -1) y = n;

		if (a <= x && y <= b)
		{
			T[k].set = v;
			T[k].toSet = true;
			T[k].sum = 0;
		}
		propagate(k);

		if (a <= x && y <= b) return;
		if (y <= a || b <= x) return;
		int m = (x+y)/2;
		set(a, b, v, k*2, x, m);
		set(a, b, v, k*2+1, m, y);
		T[k].val = T[k*2].val + T[k*2+1].val;
	}

	ll get(int a, int b, int k=1, int x=0, int y=-1)
	{
		if(y == -1) y = n;
		propagate(k);
		if (a <= x && y <= b) return T[k].val;
		if (y <= a || b <= x) return 0;
		int m = (x+y)/2;
		return get(a, b, k*2, x, m) + get(a, b, k*2+1, m, y);
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
		int q; cin >> q;
		if (q == 1)
		{
			int a, b; ll x;
			cin >> a >> b >> x; a--;
			seg.add(a, b, x);
		}
		else if (q == 2)
		{
			int a, b; ll x;
			cin >> a >> b >> x; a--;
			seg.set(a, b, x);
		}
		else
		{
			int a, b;
			cin >> a >> b; a--;
			cout << seg.get(a, b) << "\n";
		}
	}
}
