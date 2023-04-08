/*
Task:              2228 Counting Sequences
Sender:            franfill
Submission time:   2023-03-14 14:50:15
Language:          C++17
Result:            ACCEPTED
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll mod = 1000000007;
constexpr int maxk = 1000000;

ll modpow(ll b, int e)
{
	ll r = 1;
	for (int p = 1; p <= e; p <<= 1)
	{
		if (e & p)
			r = r * b % mod;
		b = b * b % mod;
	}
	return r;
}

ll fact[maxk+1], invfact[maxk+1], npow[maxk+1];
bool iscomp[maxk+1];

int main()
{
	int n, k;
	cin >> n >> k;
	fact[0] = 1;
	for (int i = 1; i <= k; i++)
		fact[i] = fact[i-1] * i % mod;
	invfact[k] = modpow(fact[k], mod-2);
	for (int i = k-1; i >= 0; i--)
		invfact[i] = invfact[i+1] * (i+1) % mod;

	ll ans = 0;
	for (int i = 0; i < k; i++)
	{
		ll bin = fact[k] * invfact[i] % mod * invfact[k-i] % mod;
		ans = (ans + bin * modpow(k-i, n) % mod * (i % 2 ? -1 : 1)) % mod;
	}
	ans = (ans + mod) % mod;
	cout << ans << "\n";
}
