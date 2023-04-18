/*
Task:              1757 Course Schedule II
Sender:            franfill
Submission time:   2023-04-08 16:20:22
Language:          C++17
Result:            ACCEPTED
*/
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	vector < vector < int > > g(n);
	vector < int > in_d(n, 0);
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		a--, b--;
		g[b].emplace_back(a);
		in_d[a]++;
	}
	priority_queue < int > pq;
	for (int i = 0; i < n; i++)
		if (in_d[i] == 0)
			pq.emplace(i);
	vector < int > ans(n);
	int it = n-1;
	while(!pq.empty())
	{
		int x = pq.top();
		pq.pop();
		ans[x] = it--;
		for (auto y : g[x])
			if (--in_d[y] == 0)
				pq.emplace(y);
	}
	vector < int > inv(n);
	for (int i = 0; i < n; i++)
		inv[ans[i]] = i;
	for (auto x : inv)
		cout << x+1 << " ";
	cout << "\n";
}
