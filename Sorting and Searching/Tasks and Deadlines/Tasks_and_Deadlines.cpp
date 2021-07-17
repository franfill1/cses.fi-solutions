#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
	ll n;
	cin >> n;
	
	ll ans = 0;
	vector < ll > v(n);
	for (ll i = 0; i < n; i++)
	{
		ll a, d;
		cin >> a >> d;
		ans += d;
		v[i] = a;
	}

	sort(v.begin(), v.end());

	ll t = 0;
	for (ll i = 0; i < n; i++)
	{
		t += v[i]; ans -= t;
	}
	cout << ans;
}
