/*
Task:              1080 Empty String
Sender:            franfill
Submission time:   2023-03-13 15:25:11
Language:          C++17
Result:            ACCEPTED
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll mod = 1000000007;

ll modpow(ll b, ll e)
{
	if (e == 0)
		return 1;
	ll t = modpow(b, e/2);
	t = t * t % mod;
	if (e % 2)
		t = t * b % mod;
	return t;
}

ll inv(ll x)
{
	return modpow(x, mod-2);
}

ll fact[501], invf[501], dp[501][501];

ll bin(ll n, ll x)
{
	ll b = fact[n] * invf[x] % mod * invf[n-x] % mod;
	return b;
}

int main()
{
	fact[0] = 1;
	for (int i = 1; i <= 500; i++)
		fact[i] = fact[i-1] * i % mod;
	invf[500] = inv(fact[500]);
	for (int i = 499; i >= 0; i--)
		invf[i] = invf[i+1] * (i+1) % mod;
	string s;
	cin >> s;
	int n = s.size();
	for (int i = 0; i <= n; i++)
		dp[i][i] = 1;

	for (int l = 1; l*2 <= n; l++)
		for (int i = 0; i+l*2 <= n; i++)
		{
			int j = i + l*2;
			assert(j <= n);
			for (int k = i+1; k < j; k += 2)
				if (s[i] == s[k])
				{
					int la = k-i+1, lb = j-k-1;
					dp[i][j] += dp[i+1][k] * dp[k+1][j] % mod * bin(l, la/2) % mod;
					dp[i][j] %= mod;
				}
		}
	cout << dp[0][n] << "\n";
}
