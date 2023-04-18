/*
Task:              1741 Area of Rectangles
Sender:            franfill
Submission time:   2023-04-18 10:08:54
Language:          C++17
Result:            ACCEPTED
*/
#include<bits/stdc++.h>
using namespace std;
const int maxY = 1000001;

struct segtree
{
	struct node
	{
		int mi = 0, cnt = 1, laz = 0;
	};
	
	vector < node > T;
	int n;
	void merge(int c, int a, int b)
	{
		if (T[a].mi > T[b].mi)
			swap(a, b);
		T[c].mi = T[a].mi;
		T[c].cnt = T[a].cnt;
		if (T[a].mi == T[b].mi)
			T[c].cnt += T[b].cnt;
	}
	
	segtree(int n_)
	{
		for (n = 1; n < n_; n<<=1);
		T.resize(2*n);
		for (int k = n-1; k >= 1; k--)
		merge(k, k*2, k*2+1);
		
	}
	
	void propagate(int k)
	{
		T[k].mi += T[k].laz;
		if (k < n)
		{
			T[k*2].laz += T[k].laz;
			T[k*2+1].laz += T[k].laz;
		}
		T[k].laz = 0;
	}
	
	void add(int l, int r, int v, int k=1, int x=0, int y=-1)
	{
		if (y == -1)
			y = n;
		if (l <= x && y <= r)
			T[k].laz += v;
		propagate(k);
		if (l <= x && y <= r)
			return;
		if (r <= x || y <= l)
			return;
		int m = (x+y)/2;
		add(l, r, v, k*2, x, m);
		add(l, r, v, k*2+1, m, y);
		merge(k, k*2, k*2+1);
	}
	
	int get()
	{
		if (T[1].mi > 0)
			return n;
		return n - T[1].cnt;
	}
};

main()
{
	int n;
	cin >> n;
	vector < array < int , 3 > > q;
	for (int i = 0; i < n; i++)
	{
		int x1, x2, y1, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		y1 += maxY;
		y2 += maxY;
		if (y1 > y2)
			swap(y1, y2);		
		if (x1 > x2)
			swap(x1, x2);
		array < int , 3 > qa, qb;
		qa[0] = x1, qa[1] = y1, qa[2] = y2;
		q.push_back(qa);
		qb[0] = x2, qb[1] = -y1, qb[2] = -y2;
		q.push_back(qb);
	}
	sort(q.begin(), q.end());
	segtree seg(maxY*2+1);
	long long ans = 0;
	long long cur = -maxY;
	for (int i = 0; i < q.size(); i++)
	{
		int x = q[i][0], y1 = q[i][1], y2 = q[i][2];
		ans += (x-cur) * seg.get();
		cur = x;
		int v = 1;
		if (y1 < 0)
			v = -1, y1 = -y1, y2 = -y2;
		seg.add(y1, y2, v);
	}
	cout << ans << "\n";
}

