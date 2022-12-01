/*
Task:              2209 Counting Necklaces
Sender:            franfill
Submission time:   2021-11-29 15:47:45
Language:          C++17
Result:            ACCEPTED
*/
#include<bits/stdc++.h>
#define M 1000000007
using namespace std;
typedef long long ll;

ll modpow(ll b, ll e)
{
	if (e == 0) return 1;
	ll t = modpow(b, e/2);
	return ((t*t)%M * (e % 2 ? b : 1))%M;
}

int main()
{
	ll n, m;
	cin >> n >> m;
	ll ans = 0;
	for (ll k = 1; k <= n; k++)
	{
		ans += modpow(m, __gcd(n, k));
		ans %= M;
	}
	ans *= modpow(n, M-2);
	ans %= M;
	cout << ans << "\n";
}
