/*
Task:              1664 Movie Festival Queries
Sender:            franfill
Submission time:   2022-12-04 18:38:06
Language:          C++17
Result:            ACCEPTED
*/
#include<bits/stdc++.h>
using namespace std;
using pii=pair < int , int >;
constexpr int P = 30;
constexpr int maxt = 1<<30;

template < typename F, typename S >
ostream & operator << (ostream & os, pair < F, S > p)
{
	os << "(" << p.first << " " << p.second << ")";
	return os;
}

int main()
{
	int n, q;
	cin >> n >> q;
	vector < pii > V(n);
	for (auto &[x, y] : V)
		cin >> x >> y;
	sort(V.begin(), V.end());
	n++;
	V.emplace_back(maxt, maxt);
	vector < int > imin(n, n);
	imin[n-1] = n-1;
	for (int i = n-2; i >= 0; i--)
		if (V[i].second < V[imin[i+1]].second)
			imin[i] = i;
		else
			imin[i] = imin[i+1];
	vector < vector < int > > nxt(P, vector < int > (n));
	nxt[0][n-1] = n-1;
	for (int i = 0; i < n-1; i++)
	{
		int j = lower_bound(V.begin(), V.end(), make_pair(V[i].second, -100)) - V.begin();
		nxt[0][i] = imin[j];
	}
	for (int p = 1; p < P; p++)
	{
		for (int i = 0; i < n; i++)
			nxt[p][i] = nxt[p-1][nxt[p-1][i]];
	}
	while(q--)
	{
		int a, b;
		cin >> a >> b;
		int st = lower_bound(V.begin(), V.end(), make_pair(a, -100)) - V.begin();
		st = imin[st];
		if (V[st].second > b)
		{
			cout << 0 << "\n";
			continue;
		}
		int en = st;
		int ans = 1;
		for (int p = P-1; p >= 0; p--)
		{
			int ne = nxt[p][en];
			if (V[ne].second <= b)
			{
				en = ne;
				ans += 1<<p;
			}
		}
		cout << ans << "\n";
	}
}
