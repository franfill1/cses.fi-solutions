/*
Task:              1735 Range Updates and Sums
Sender:            franfill
Submission time:   2021-11-14 14:14:53
Language:          C++17
Result:            ACCEPTED
*/
#include<bits/stdc++.h>
#define int long long
using namespace std;

struct segtree
{
	struct node
	{
		int val=0, sum=0, set, siz=1;
		bool toSet = false;
		node(int _v) : val(_v){};
		node() {};
	};

	vector < node > T;
	int n;

	segtree(vector < int > A)
	{
		n = 1;
		while(n < A.size()) n<<=1;
		T.resize(n<<1);

		for (int i = 0; i < A.size(); i++) 
		{
			T[i+n] = node(A[i]);
		}
		for (int i = n-1; i; i--) 
		{
			T[i].val = T[i*2].val + T[i*2+1].val;
			T[i].siz = T[i*2].siz + T[i*2+1].siz;
		}
	}

	void propagate(int k)
	{
		auto &[val, sum, set, siz, toSet] = T[k];
		if (toSet)
		{
			val = set * siz;
		}
		val += sum * siz;

		if (k < n)
		{
			if (toSet)
			{
				T[k*2].toSet = 1;
				T[k*2].set = T[k].set;
				T[k*2].sum = 0;
				T[k*2+1].toSet = 1;
				T[k*2+1].set = T[k].set;
				T[k*2+1].sum = 0;
			}
			T[k*2].sum += T[k].sum;
			T[k*2+1].sum += T[k].sum;
		}
		sum = 0;
		toSet = false;
	}

	void sum(int l, int r, int v, int k=1, int x=0, int y=-1)
	{
		if (y == -1) y = n;
		if (l <= x && y <= r)
		{
			T[k].sum += v;
		}
		propagate(k);
		if (l <= x && y <= r) return;
		if (l >= y || x >= r) return;
		int m = (x+y)/2;
		sum(l, r, v, k*2, x, m);
		sum(l, r, v, k*2+1, m, y);
		T[k].val = T[k*2].val + T[k*2+1].val;
	}

	void set(int l, int r, int v, int k=1, int x=0, int y=-1)
	{
		if (y == -1) y = n;
		if (l <= x && y <= r)
		{
			T[k].sum = 0;
			T[k].set = v;
			T[k].toSet = true;
		}
		propagate(k);
		if (l <= x && y <= r) return;
		if (l >= y || x >= r) return;
		int m = (x+y)/2;
		set(l, r, v, k*2, x, m);
		set(l, r, v, k*2+1, m, y);
		T[k].val = T[k*2].val + T[k*2+1].val;
	}

	int get(int l, int r, int k=1, int x=0, int y=-1)
	{
		if (y == -1) y = n;
		propagate(k);
		if (l <= x && y <= r) 
		{
			return T[k].val;
		}
		if (l >= y || x >= r) return 0;
		int m = (x+y)/2;
		return get(l, r, k*2, x, m) + get(l, r, k*2+1, m, y);
	}
};

signed main()
{
	int n, q;
	cin >> n >> q;
	vector < int > a(n);
	for (int &v : a) cin >> v;
	segtree seg(a);

	while(q--)
	{
		int t, a, b;
		cin >> t >> a >> b;
		a--;
		if (t == 1)
		{
			int x;
			cin >> x;
			seg.sum(a, b, x);
		}
		else if (t == 2)
		{
			int x;
			cin >> x;
			seg.set(a, b, x);
		}
		else
		{
			cout << seg.get(a, b) << "\n";
		}
	}
}
