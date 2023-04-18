/*
Task:              1148 Maximum Building II
Sender:            franfill
Submission time:   2023-04-17 18:11:39
Language:          C++17
Result:            ACCEPTED
*/
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	vector < int > up(m, -1);
	set < pair < int , int > > ups;
	vector < vector < int > > d(n+2, vector < int > (m+2, 0));

	auto add = [&] (int x0, int x1, int y0, int y1, int v) -> void
	{
		d[x0][y0] += v, d[x0][y1] -= v, d[x1][y0] -= v, d[x1][y1] += v;
	};

	for (int i = 0; i < m; i++)
		ups.insert(make_pair(-up[i], i));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			char c;
			cin >> c;
			if (c == '*')
			{
				ups.erase(make_pair(-up[j], j));
				up[j] = i;
				ups.insert(make_pair(-up[j], j));
			}
		}

		set < int > pos;
		pos.insert(-1);
		pos.insert(m);

		for (auto [u, j] : ups)
		{
			u = -u;
			auto it = pos.upper_bound(j);
			int l = *prev(it), r = *it;
			int a = min(j-l-1, r-j-1), b = max(j-l-1, r-j-1);

			for (int w = b+2; w <= a+b+1; w++)
				add(1, i-u+1, w, w+1, a+b+2-w);
			add(1, i-u+1, a+1, b+2, a+1);
			for (int w = 1; w <= a; w++)
				add(1, i-u+1, w, w+1, w);

			pos.insert(j);
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			d[i][j] += d[i-1][j] + d[i][j-1] - d[i-1][j-1];
			cout << d[i][j] << " ";
		}
		cout << "\n";
	}
}
