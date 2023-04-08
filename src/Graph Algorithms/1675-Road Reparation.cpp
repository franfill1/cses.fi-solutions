/*
Task:              1675 Road Reparation
Sender:            franfill
Submission time:   2021-07-26 20:38:58
Language:          C++11
Result:            ACCEPTED
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct edge
{
	int a, b;
	ll c;
};

bool operator < (edge a, edge b) 
{
	return (a.c < b.c);
}

struct dsu
{
	int n;
	vector < int > pa;
	vector < int > siz;

	dsu(int in) : n(in)
	{
		pa.resize(n);
		for (int i = 0; i < n; i++) pa[i] = i;
		siz.resize(n, 1);
	}

	int getR(int x)
	{
		if (x == pa[x]) return x;
		else return pa[x] = getR(pa[x]);
	}

	void unite(int a, int b)
	{
		a = getR(a); b = getR(b);
		if (siz[a] < siz[b]) swap(a, b);

		pa[b] = a;
		siz[a] += siz[b];
	}

	bool same(int a, int b) 
	{
		return getR(a) == getR(b);
	}
};

int main()
{
	int n, m;
	cin >> n >> m;

	vector<edge> list;
	dsu s(n);
	for (int i = 0; i < m; i++)
	{
		int a, b; ll c;
		cin >> a >> b >> c; a--; b--;
		list.push_back({a, b, c});
	}
	
	sort(list.begin(), list.end());

	ll ans = 0;
	int t = 1;

	for(int i = 0; i < m && t < n; i++)
	{
		int a = list[i].a, b = list[i].b; ll c = list[i].c;
		if (!s.same(a, b))
		{
			ans += c;
			t++;
			s.unite(a, b);
		}
	}
	if (t < n) cout << "IMPOSSIBLE\n";
	else cout << ans << "\n";
}
