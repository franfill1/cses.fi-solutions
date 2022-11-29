#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll query(ll n, ll k)
{
	if (n == 1 && k == 1)
	{
		return 0;
	}

	if (k*2-1 < n)
	{
		return k*2-1;
	}

	ll u = n/2 + n%2; 

	ll ans = query(n-u, k-u)*2;
	if (n % 2)
	{
		ans += 2;
	}
	return ans;
}

int main()
{
	int q;
	cin >> q;
	while(q--)
	{
		ll n, k;
		cin >> n >> k;
		cout << query(n, k) + 1 << "\n";
	}
	return 0;
}

