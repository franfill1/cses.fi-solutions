#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	vector < string > G(n);
	vector < set < int > > V(m);
	for (int i = 0; i < n; i++) cin >> G[i];
	for (int i = 0; i < m; i++)
	{
		V[i].insert(-1);
		V[i].insert(n);
		for (int j = 0; j < n; j++) if (G[j][i] == '*')
		{
			V[i].insert(j);
		}
	}
	
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		int top = -1, bot = n, l=-1, r;
		for (int j = 0; j < m; j++)
		{
			r = j;
			ans = max(ans, (r-l-1)*(bot-top-1));	
			if (G[i][j] == '*')
			{
				top = -1, bot = n, l = j;
			}	
			else
			{
				auto it = V[j].lower_bound(i);
				bot = min(bot, *it);
				top = max(top, *prev(it));
			}
		}
		r = m;
		ans = max(ans, (r-l-1)*(bot-top-1));
	}
	cout << ans << "\n";
}

