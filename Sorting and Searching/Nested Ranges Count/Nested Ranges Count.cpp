/*
Task:              2169 Nested Ranges Count
Sender:            franfill
Submission time:   2021-12-24 15:56:26
Language:          C++17
Result:            ACCEPTED
*/
#include<bits/stdc++.h>
using namespace std;

struct range
{
	int x, y, p;
};

bool operator < (range a, range b)
{
	if (a.y == b.y) return a.x > b.x;
	return a.y < b.y;
}

bool sortx(range a, range b)
{
	return a.x < b.x;
}

struct fenwick
{
	int n;
	vector < int > v;

	fenwick(int ni) : n(ni)
	{
		v.resize(n);
	}

	int get(int k)
	{
		if (k < 0) return 0;
		int ans = 0;
		while(k)
		{
			ans += v[k];
			k -= k&-k;
		}
		return ans;
	}

	void add(int k, int x)
	{
		while(k < n)
		{
			v[k] += x;
			k += k&-k;
		}
	}
};

int main()
{
	int n;
	cin >> n;

	vector < range > v;
	vector < range > alt;
	map < int , int > enc;
	vector < int > c(n);

	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		v.push_back({x, y, i});
		alt.push_back({x, y, i});
	}

	sort(v.begin(), v.end());
	sort(alt.begin(), alt.end(), sortx);

	for (int i = 0; i < n; i++)
		if (!enc.count(alt[i].x)) enc[alt[i].x] = enc.size()+1;
	
	for (range &r : v) r.x = enc[r.x];

	fenwick f(n+1);

	for (int i = 0; i < n; i++)
	{
		c[v[i].p] = i - f.get(v[i].x-1);
		f.add(v[i].x, 1);
	}
	for (int b : c) cout << b << " ";
	cout << "\n";

	f = fenwick(n+1);
	
	for (int i = n-1; i >= 0; i--)
	{
		c[v[i].p] = f.get(v[i].x);
		f.add(v[i].x, 1);
	}
	for (int b : c) cout << b << " ";
}
