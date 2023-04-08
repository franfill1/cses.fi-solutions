/*
Task:              1677 Network Breakdown
Sender:            franfill
Submission time:   2022-12-04 17:48:08
Language:          C++17
Result:            ACCEPTED
*/
#include<bits/stdc++.h>
using namespace std;

struct dsu
{
	vector < int > p, s;
	dsu(int n) : p(n) , s(n, 1)
	{
		iota(p.begin(), p.end(), 0);
	}

	int find(int x)
	{
		return x==p[x]?x:(p[x]=find(p[x]));
	}
	bool unite(int a, int b)
	{
		a = find(a), b = find(b);
		if (a == b)
			return false;
		if (s[a] < s[b])
			swap(a, b);
		p[b] = a;
		s[a] += s[b];
		return true;
	}
};

int main()
{
	int n, m, q;
	cin >> n >> m >> q;
	set < pair < int , int > > e;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		a--, b--;
		if (a > b)
			swap(a, b);
		e.insert(make_pair(a, b));
	}
	vector < pair < int , int > > br;
	for (int i = q-1; i >= 0; i--)
	{
		int a, b;
		cin >> a >> b;
		a--, b--;
		if (a > b)
			swap(a, b);
		br.emplace_back(a, b);
		e.erase(make_pair(a, b));
	}
	dsu d(n);
	int cnt = n;
	for (auto [a, b] : e)
	{
		cnt -= d.unite(a, b);
	}
	vector < int > ans;
	for (int i = q-1; i >= 0; i--)
	{
		ans.emplace_back(cnt);
		auto [a, b] = br[i];
		cnt -= d.unite(a, b);
	}
	for (int i = q-1; i >= 0; i--)
		cout << ans[i] << " ";
	cout << "\n";
}
