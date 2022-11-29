#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
	ll n, k;
	cin >> n >> k;
	vector < ll > a(k);
	for (ll &v : a) cin >> v;

	vector < __int128_t > p(1ll<<k, 1);

	ll ans = 0;
	for (int i = 1; i < 1<<k; i++)
	{
		int f = 31 - __builtin_clz(i);
		int j = i - (1<<(f));
		if (p[j] > n) 
		{
			p[i] = p[j];
			continue;
		}
		p[i] = p[j] * a[f];
		if (p[i] > n) continue;

		ll c = __builtin_popcount(i);
		ll t = n / p[i];
		if (c % 2) ans += t;
		else ans -= t;
	}
	cout << ans << "\n";
}

