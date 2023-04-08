/*
Task:              1112 Required Substring
Sender:            franfill
Submission time:   2023-03-12 12:04:24
Language:          C++17
Result:            ACCEPTED
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll mod = 1000000007;
constexpr ll alph = 'z' - 'a' + 1;

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

int main()
{
	int n;
	cin >> n;
	string s;
	cin >> s;
	int m = s.size();
	vector < int > z(m, m);
	int l = 0, r = 0;
	for (int i = 1; i < m; i++)
	{
		if (i + z[i] >= r)
		{
			l = r = i;
			while(r < m && s[r-l] == s[r])
				r++;
			z[i] = r-l;
		}
		else
			z[i] = z[i-l];
	}

	vector < ll > dp(n);
	ll ans = 0;
	for (int i = 0; i + m <= n; i++)
	{
		dp[i] = modpow(alph, i);
		int j;
		for (j = 0; j + m <= i; j++)
			dp[i] = (dp[i] - (dp[j] * modpow(alph, i-j-m))) % mod;
		for (; j < i; j++)
			if (z[i-j]+i-j==m)
				dp[i] = (dp[i] - dp[j]) % mod;
		ans = (ans + dp[i] * modpow(alph, n-i-m)) % mod;
	}
	ans = (ans + mod) % mod;
	cout << ans << "\n";
}
