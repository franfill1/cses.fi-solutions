#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 1ll<<60;

struct edge
{
	int a, b;
	ll c;
};

int main()
{
	int n, m;
	cin >> n >> m;
	
	vector < edge > l;
	for (int i = 0; i < m; i++)
	{
		int a, b; ll c;
		cin >> a >> b >> c; a--; b--;
		l.push_back({a, b, c});
	}

	vector < ll > D(n, inf);
	vector < ll > from(n, -1);
	D[0] = 0;

	int en;
	for (int i = 0; i < n; i++)
	{
		en = -1; 
		for (edge e : l)
		{
			if (D[e.a] + e.c < D[e.b])
			{
				D[e.b] = D[e.a] + e.c;
				en = e.b;
				from[e.b] = e.a;
			}
		}
	}

	if (en == -1) cout << "NO\n";
	else
	{
		cout << "YES\n";
		for (int i = 0; i < n; i++) en = from[en];
		stack < int > ans;
		ans.push(en);
		for (int x = from[en]; x != en; x = from[x])
		{
			ans.push(x);
		}
		ans.push(en);
		while(!ans.empty())
		{
			cout << ans.top()+1 << " ";
			ans.pop();
		}
	}
}

