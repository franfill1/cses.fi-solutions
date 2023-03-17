/*
Task:              1698 Swap Round Sorting
Sender:            franfill
Submission time:   2023-03-16 11:52:18
Language:          C++17
Result:            ACCEPTED
*/
#include <bits/stdc++.h>
using namespace std;

main()
{
	int n;
	cin >> n;
	vector < int > v(n);
	for (auto &x : v)
	{
		cin >> x;
		x--;
	}
	vector < vector < pair < int , int > > > ans;
	bool ok = false;
	while(!ok)
	{
		vector < bool > vis(n, false);
		ans.emplace_back(0);
		for (int i = 0; i < n; i++)
			if (!vis[i])
			{
				int x = v[i];
				vector < int > cyc(1, i);
				vis[i] = true;
				while (x != i)
				{
					vis[x] = true;
					cyc.emplace_back(x);
					x = v[x];
				}
				if (cyc.size() == 2)
				{
					ans.back().emplace_back(cyc[0], cyc[1]);
					swap(v[cyc[0]], v[cyc[1]]);
				}
				else if (cyc.size() > 2)
				{
					for (int j = 0; j+1 < cyc.size()-j-1; j++)
					{
						ans.back().emplace_back(cyc[j+1], cyc[cyc.size()-j-1]);
						swap(v[cyc[j+1]], v[cyc[cyc.size()-j-1]]);
					}
				}
			}
		ok = ans.back().size() == 0;
	}
	ans.resize(ans.size()-1);
	cout << ans.size() << "\n";
	for (auto &round : ans)
	{
		cout << round.size() << "\n";
		for (auto &p : round)
			cout << p.first+1 << " " << p.second+1 << "\n";
	}
}

