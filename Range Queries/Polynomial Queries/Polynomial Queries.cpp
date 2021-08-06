#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct segtree
{
	struct node
	{
		ll val=0, sum=0, inc=0, cnt=1;
		node() {}
	};

	vector < node > T;
	int n;

	segtree(vector < ll > &V)
	{
		n = 1; while(n < V.size()) n *= 2;
		T.resize(n*2);
		
		for (int i = 0; i < V.size(); i++) T[i+n].val = V[i];
		
		for (int i = n-1; i; i--)
		{
			T[i].val = T[i*2].val + T[i*2+1].val;
			T[i].cnt = T[i*2].cnt + T[i*2+1].cnt;
		}
	}

	void propagate(int k)
	{
		T[k].val += T[k].sum * T[k].cnt;
		T[k].val += T[k].inc * T[k].cnt * (T[k].cnt + 1) / 2;
		if (k < n)
		{
			T[k*2].sum += T[k].sum;
			T[k*2].inc += T[k].inc;
			T[k*2+1].sum += T[k].sum + T[k*2].cnt*T[k].inc;
			T[k*2+1].inc += T[k].inc;
		}
		T[k].sum = 0;
		T[k].inc = 0;
	}
	
	void increase(int a, int b, int k=1, int x=0, int y=-1)
	{
		if (y == -1) y = n;
		if (a <= x && y <= b)
		{
			T[k].inc++;
			T[k].sum += x-a;
		}
		propagate(k);
		if (a <= x && y <= b) return;
		if (y <= a || b <= x) return;
		int m = (x+y)/2;
		increase(a, b, k*2, x, m);
		increase(a, b, k*2+1, m, y);
		T[k].val = T[k*2].val + T[k*2+1].val;
	}

	ll get(int a, int b, int k=1, int x=0, int y=-1)
	{
		if (y == -1) y = n;
		propagate(k);
		if (a <= x && y <= b) return T[k].val;
		if (b <= x || y <= a) return 0;
		int m = (x+y)/2;
		return get(a, b, k*2, x, m) + get(a, b, k*2+1, m, y);
	}
};

int main()
{
	int n, q;
	cin >> n >> q;
	vector < ll > V(n);
	for (ll &x : V) cin >> x;

	segtree seg(V);

	while(q--)
	{
		int t, a, b;
		cin >> t >> a >> b;
		if (t == 1)
		{
			seg.increase(a-1, b);
		}
		else
		{
			cout << seg.get(a-1, b) << "\n";
		}
	}
}
