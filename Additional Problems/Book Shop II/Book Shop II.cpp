#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair < ll , ll > pll;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll N, X;
	cin >> N >> X;
	vector < ll > H(N), S(N), K(N);
	for (ll &h : H) cin >> h;
	for (ll &s : S) cin >> s;
	for (ll &k : K) cin >> k;

	vector < ll > buff(X+1, 0);
	ll ans = 0;
	for (ll n = 1; n <= N; n++)
	{
		ll k = K[n-1];
		for (ll p = 0; k > 0; p++)
		{
			ll c = 1<<p;
			if (k < c) c = k;
			k -= c;
			ll h = c * H[n-1], s = c * S[n-1];
			for (ll x = X-h; x>=0; x--)
			{
				buff[x+h] = max(buff[x+h], buff[x] + s);
				ans = max(ans, buff[x+h]);
			}
		}
	}
	cout << ans << "\n";
}

