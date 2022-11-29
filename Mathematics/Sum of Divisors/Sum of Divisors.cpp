#include<bits/stdc++.h>
#define M 1000000007
using namespace std;
typedef long long ll;

ll sumTo(ll n)
{
	n %= M;
	return ((n)*(n+1)/2)%M;
}

ll sumBet(ll a, ll b)
{
	return ((sumTo(b-1) - sumTo(a-1))%M + M) %M;
}

int main()
{
	ll n;
	cin >> n;

	ll ans = 0;
	ll d=1;
	while(d <= n)
	{
		ll v = n/d;
		ll r = n%d;
		ll nd = d + r/v + 1;
		ans += (v * sumBet(d, nd)) % M; 
		ans %= M;
		d = nd;
	}
	cout << ans << "\n";
}

