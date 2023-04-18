/*
Task:              1078 Grid Paths
Sender:            franfill
Submission time:   2023-04-16 17:48:47
Language:          C++17
Result:            ACCEPTED
*/
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll mod = 1000000007;
const int MAXC = 1000000, MAXF = MAXC*2+1;
ll fact[MAXF], ifact[MAXF];

ll modpow(ll b, int e)
{
	if (e == 0)
		return 1;
	ll t = modpow(b, e/2);
	t = t * t % mod;
	if (e % 2)
		t = t * b % mod;
	return t;
}

ll bin(int n, int x)
{
	if (x < 0 || x > n)
		return 0ll;
	return fact[n] * ifact[n-x] % mod * ifact[x] % mod;
}

int main()
{
	fact[0] = 1;
	for (int i = 1; i < MAXF; i++)
		fact[i] = fact[i-1] * i % mod;
	ifact[MAXF-1] = modpow(fact[MAXF-1], mod-2);
	for (int i = MAXF-2; i >= 0; i--)
		ifact[i] = ifact[i+1] * (i+1) % mod;
	int n, m;
	cin >> n >> m;
	vector < pair < int , int > > v(m);
	for (auto &[x, y] : v)
		cin >> x >> y;
	v.emplace_back(1, 1);
	v.emplace_back(n, n);
	sort(v.begin(), v.end());
	vector < ll > dp(m+2, 1);
	auto count_paths = [&] (int i, int j)
	{
		int dx = v[j].first - v[i].first;
		int dy = v[j].second - v[i].second;
		return bin(dx + dy, dx);
	};
	for (int i = 1; i < m+2; i++)
	{
		dp[i] = count_paths(0, i);
		for (int j = 1; j < i; j++)
			dp[i] -= dp[j] * count_paths(j, i) % mod;
		dp[i] %= mod;
	}
	cout << (dp.back()+mod)%mod << "\n";
}
