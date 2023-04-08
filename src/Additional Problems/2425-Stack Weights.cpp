/*
Task:              2425 Stack Weights
Sender:            franfill
Submission time:   2023-03-15 10:56:35
Language:          C++17
Result:            ACCEPTED
*/
#include<vector>
#include<iostream>
using namespace std;

struct segtree
{
	int n;
	vector < int > mi, ma, la;
	segtree(int n_)
	{
		for(n=1;n<n_;n<<=1);
		mi.resize(n*2, 0);
		ma.resize(n*2, 0);
		la.resize(n*2, 0);
	}

	void propagate(int k)
	{
		mi[k] += la[k];
		ma[k] += la[k];
		if (k < n)
			la[k*2] += la[k],
			la[k*2+1] += la[k];
		la[k]=0;
	}

	void add(int l, int r, int v, int k=1, int x=0, int y=-1)
	{
		if (y==-1)
			y=n;
		if (l <= x && y <= r)
			la[k] += v;
		propagate(k);
		if (r <= x || y <= l)
			return;
		if (l <= x && y <= r)
			return;
		int m = (x+y)/2;
		add(l, r, v, k*2, x, m);
		add(l, r, v, k*2+1, m, y);
		mi[k]=min(mi[k*2],mi[k*2+1]);
		ma[k]=max(ma[k*2],ma[k*2+1]);
	}
	int getmi()
	{
		propagate(1);
		return mi[1];
	}
	int getma()
	{
		propagate(1);
		return ma[1];
	}
};

int main()
{
	int n;
	cin >> n;
	segtree seg(n);
	for (int i=0;i<n;i++)
	{
		int x, p;
		cin >> x >> p;
		if(p==1)
			seg.add(0, x, 1);
		else
			seg.add(0, x, -1);
		if (seg.getmi() >= 0)
			cout << ">\n";
		else if (seg.getma() <= 0)
			cout << "<\n";
		else
			cout << "?\n";
	}
}
