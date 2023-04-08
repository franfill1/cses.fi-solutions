/*
Task:              1706 School Excursion
Sender:            franfill
Submission time:   2023-03-17 22:52:56
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
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		a--, b--;
		g[a].emplace_back(b);
		g[b].emplace_back(a);
	}

	vector < bool > vis(n, false);
	vector < int > sizs;
	queue < int > q;

	for (int i = 0; i < n; i++)
		if (!vis[i])
		{
			vis[i] = true;
			q.emplace(i);
			sizs.emplace_back(0);
			while(!q.empty())
			{
				int x = q.front();
				q.pop();
				sizs.back()++;
				for (auto y : g[x])
					if (!vis[y])
					{
						vis[y] = true;
						q.emplace(y);
					}
			}
		}

	bitset < 100001 > b;
	b.set(0);
	for (int s : sizs)
		b |= b<<s;

	for (int i = 1; i <= n; i++)
		cout << b.test(i);
	cout << "\n";
}
