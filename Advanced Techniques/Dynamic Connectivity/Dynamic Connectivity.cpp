#include<bits/stdc++.h>
using namespace std;
using edge = pair < int , int >;

struct dsu
{
	int cnt;
	stack < edge > history;
	vector < int > size;
	vector < int > parent;

	dsu(int n) : size(n, 1), parent(n), cnt(n)
	{
		iota(parent.begin(), parent.end(), 0);
	}

	int find(int x)
	{
		if (x == parent[x])
			return x;
		else return find(parent[x]);
	}

	void add(edge ed)
	{
		auto [a, b] = ed;
		a = find(a), b = find(b);
		if (a != b)
		{
			cnt--;
			if (size[a] < size[b])
				swap(a, b);
			parent[b] = a;
			size[a] += size[b];
			history.emplace(a, b);
		}
		else
			history.emplace(-1, -1);
	}

	void rollback(int t)
	{
		assert(t <= history.size());
		for (int i = 0; i < t; i++)
		{
			auto [a, b] = history.top();
			history.pop();
			if (a != -1)
			{
				cnt++;
				parent[b] = b;		
				size[a] -= size[b];
			}
		}
	}
};

struct segtree
{
	int n;
	vector < vector < edge > > V;
	segtree(int n_)
	{
		for (n=1;n<n_;n*=2);
		V.resize(n*2);
	}

	void add(int l, int r, edge ed, int k=1, int x=0, int y=-1)
	{
		if (y == -1)
			y = n;
		if (l <= x && y <= r)
		{
			V[k].emplace_back(ed);
			return;
		}
		if (r <= x || y <= l)
			return;
		int m = (x+y)/2;
		add(l, r, ed, k*2, x, m);
		add(l, r, ed, k*2+1, m, y);
	}

	void get(dsu &d, vector < int > &res, int k=1, int x=0, int y=-1)
	{
		res.resize(n);
		if (y == -1)
			y = n;
		for (auto ed : V[k])
			d.add(ed);
		if (x == y-1)
			res[x] = d.cnt;
		else
		{
			int m = (x+y)/2;
			get(d, res, k*2, x, m);
			get(d, res, k*2+1, m, y);
		}
		d.rollback(V[k].size());
	}
};

int main()
{
	int n, m, k;
	cin >> n >> m >> k;
	map < edge , int > last;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		a--, b--;
		if (a > b)
			swap(a, b);
		edge ed(a, b);
		last[ed] = 0;
	}
	segtree seg(k+2);
	for (int i = 1; i <= k; i++)
	{
		int t, a, b;
		cin >> t >> a >> b;
		a--, b--;
		if (a > b)
			swap(a, b);
		edge ed(a, b);
		if (t == 1)
			last[ed] = i;
		else
		{
			seg.add(last[ed], i, ed);
			last.erase(ed);
		}
	}
	for (auto [ed, t] : last)
		seg.add(t, k+1, ed);
	vector < int > ans(k+2);
	dsu d(n);
	seg.get(d, ans);
	for (int i = 0; i <= k; i++)
		cout << ans[i] << " ";
	cout << "\n";
}

