/*
Task:              2180 Coin Arrangement
Sender:            franfill
Submission time:   2023-04-16 19:01:09
Language:          C++17
Result:            ACCEPTED
*/
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector < array < int , 2 > > g(n);
	for (int i = 0; i < n; i++)
		cin >> g[i][0];
	for (int i = 0; i < n; i++)
		cin >> g[i][1];

	long long ans = 0;
	for (int i = 0; i < n; i++)
	{
		g[i][0]--, g[i][1]--;
		int d = max(0, min(g[i][0], -g[i][1])) + min(0, max(g[i][0], -g[i][1]));
		ans += abs(d);
		ans += abs(g[i][0] + g[i][1]);
		g[i+1][0] += g[i][0] - d;
		g[i+1][1] += g[i][1] + d;
	}
	cout << ans << "\n";
}
