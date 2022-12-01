/*
Task:              1724 Graph Paths II
Sender:            franfill
Submission time:   2021-11-30 23:29:29
Language:          C++17
Result:            ACCEPTED
/*
#include<bits/stdc++.h>
#define M 1000000007
using namespace std;
typedef long long ll;
 
struct matrix
{
	vector < vector < ll > > m;
 
	matrix(vector < vector < ll > > _m) : m(_m) {}
 
	matrix operator * (matrix oth)
	{
		assert(oth.m.size() != 0);
		vector < vector < ll > > ans(m.size(), vector < ll > (oth.m[0].size(), 1ll<<60));
		for (ll i = 0; i < m.size(); i++)
		{
			for (ll j = 0; j < oth.m[i].size(); j++)
			{
				assert(m[i].size() == oth.m.size());
				for (ll k = 0; k < m[i].size(); k++)
				{
					ans[i][j] = min(ans[i][j], m[i][k] + oth.m[k][j]);
				}
			}
		}
		return matrix(ans);
	}
 
	vector < ll >& operator [] (ll i)
	{
		return m[i];
	}
};
 
matrix id({{1, 0}, {0, 1}});
 
matrix modpow(matrix b, ll e)
{
	assert(e);
	if (e == 1) return b;
	matrix t = modpow(b, e/2);
	t = t * t;
	if (e % 2) t = t * b;
	return t;
}
 
int main()
{
	ll n, m, k;
	cin >> n >> m >> k;
	vector < vector < ll > > adj(n, vector < ll > (n, 1ll<<60));
	for (int i = 0; i < m; i++)
	{
		ll a, b, c;
		cin >> a >> b >> c;
		a--; b--;
		adj[a][b] = min(adj[a][b], c);
	}
	matrix b(adj);
	b = modpow(b, k);
	cout << (b[0][n-1] == 1ll<<60 ? -1 : b[0][n-1]) << "\n";
}
