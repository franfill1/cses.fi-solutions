/*
Task:              1704 Network Renovation
Sender:            franfill
Submission time:   2023-03-13 19:07:34
Language:          C++17
Result:            ACCEPTED
*/
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector < vector < int > > g(n);
	for (int i = 0; i < n-1; i++)
	{
		int a, b;
		cin >> a >> b;
		a--, b--;
		g[a].emplace_back(b);
		g[b].emplace_back(a);
	}

	vector < int > size(n);
	auto calc_size = [&] (int x, int p, auto calc_size) -> int
	{
		if (g[x].size() == 1)
			size[x] = 1;
		for (auto y : g[x])
			if (y != p)
				size[x] += calc_size(y, x, calc_size);
		return size[x];
	};
	calc_size(0, 0, calc_size);

	int c = g[0].size() > 1 ? 0 : g[0][0];
	int l = c == 0 ? -1 : 0;
	bool ok = false;
	while(!ok)
	{
		ok = true;
		for (auto y : g[c])
			if (y != l)
				if (size[y]*2 >= size[0])
				{
					l = c;
					ok = false, c = y;
					break;
				}
	}

	vector < set < int > > leaves(n);
	auto calc_leaves = [&] (int x, int p, auto calc_leaves) -> void
	{
		if (g[x].size() == 1)
		{
			assert(x != c);
			leaves[x].insert(x);
		}
		for (int y : g[x])
			if (y != p)
			{
				calc_leaves(y, x, calc_leaves);
				if (leaves[y].size() > leaves[x].size())
					swap(leaves[y], leaves[x]);
			}
		for (int y : g[x])
			if (y != p)
				for (int l : leaves[y])
					leaves[x].insert(l);
	};
	priority_queue < pair < int , int > > pq;
	for (int x : g[c])
	{
		calc_leaves(x, c, calc_leaves);
		pq.emplace(leaves[x].size(), x);
	}
	vector < pair < int , int > > ans;
	while(pq.size() > 1)
	{
		auto [ca, a] = pq.top();	
		pq.pop();
		auto [cb, b] = pq.top();	
		pq.pop();
		int la = *leaves[a].begin();
		int lb = *leaves[b].begin();
		ans.emplace_back(la, lb);
		leaves[a].erase(la);
		leaves[b].erase(lb);

		if (ca > 1)
			pq.emplace(ca-1, a);
		if (cb > 1)
			pq.emplace(cb-1, b);
	}
	//assert(pq.size() == 0 || pq.top().first == 1);
	if (pq.size() == 1)
	{
		int l = *leaves[pq.top().second].begin();
		ans.emplace_back(l, c);
	}
	cout << ans.size() << "\n";
	for (auto [x, y] : ans)
		cout << x+1 << " " << y+1 << "\n";
}
