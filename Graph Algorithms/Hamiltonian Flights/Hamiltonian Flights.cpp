#include<bits/stdc++.h>
#pragma gcc optimize('O3')
using namespace std;
typedef long long ll;
const ll M = 1000000007;
 
int g[20][20];
ll memo[1<<19][19];
 
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
 
	int n, m;
	cin >> n >> m;
 
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b; a--; b--;
		g[a][b]++;
	}
 
	memo[1][0] = 1;
	for (int sub = 2; sub < (1<<(n-1)); sub++) 
	{
		for (int x = 0; x < n; x++) if (sub&(1<<x))
		{
			int nsub = sub ^ (1<<x);
			for (int y = 0; y < n; y++) if ((nsub&(1<<y)) && g[y][x])
			{
				memo[sub][x] += (memo[nsub][y] * g[y][x]) % M;
				memo[sub][x] %= M;
			}
		}
	}
 
	ll ans = 0;
	int sub = (1<<(n-1))-1;
	int x = n-1;
	for (int y = 0; y < x; y++) 
	{
		ans += memo[sub][y] * g[y][x];
		ans %= M;
	}
	
	cout << ans << "\n";
}
