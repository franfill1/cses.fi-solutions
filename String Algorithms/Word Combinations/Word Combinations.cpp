#include<bits/stdc++.h>
#define M 1000000007
using namespace std;
typedef long long ll;
 
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string s;
	cin >> s;
	int n = s.size();
	int k; cin >> k;
	vector < vector < int > > g(1, vector < int > (26, -1));
	vector < bool > end(1, 0);
	string w;
	while(k--)
	{
		cin >> w;
		int x = 0;
		for (int i = 0; i < w.size(); i++)
		{
			int c = w[i] - 'a';
			if (g[x][c] == -1)
			{
				g[x][c] = g.size();
				g.push_back(vector < int > (26, -1));
				end.push_back(0);
			}
			x = g[x][c];
		}
		end[x] = true;
	}
 
	vector < ll > dp(n+1, 1);
	for (int i = n-1; i >= 0; i--)
	{
		dp[i] = 0;
		int x = 0;
		for (int j = i; j < n && x != -1; j++)
		{
			int c = s[j] - 'a';
			x = g[x][c];
			if (x != -1 && end[x])
			{
				dp[i] += dp[j+1];
				dp[i] %= M;
			}
		}
	}
	cout << dp[0] << "\n";
}

