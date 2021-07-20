#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll M = 1000000007;
int n;
int m;
vector < vector < ll > > memo;

bool check(int a, int b)
{
	bool op = false;
	if (a & b) return false;
	int c = a | b;
	if ((n - __builtin_popcount(c)) % 2) return false;

	for (int i = 0; i < n; i++)
	{
		if ((1<<i) & c && op) return false;
		else if ((1<<i) & c) op = false;
		else op = !op;
	}

	return true;
}

int dp(int c, int r)
{
	if (r == m) return c == 0;
	else if (memo[c][r] != -1) return memo[c][r];
	else
	{
		memo[c][r] = 0;
		for (int s = 0; s < (1<<n); s++)
		{
			if (check(c, s))
			{
				memo[c][r] += dp(s, r+1);
				memo[c][r] %= M;
			}
		}
		return memo[c][r];
	}
}

int main()
{
	cin >> n >> m;
	memo.resize(1<<n, vector < ll > (m, -1));
	cout << dp(0, 0);
}
