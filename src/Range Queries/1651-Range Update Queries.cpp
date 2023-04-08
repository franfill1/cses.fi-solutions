/*
Task:              1651 Range Update Queries
Sender:            franfill
Submission time:   2022-12-19 20:27:23
Language:          C++17
Result:            ACCEPTED
*/
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
struct fenwick
{
	ll n;
	vector < ll > T;
	fenwick(ll n_) : n(n_), T(n_+1,0) {}

	void add_prefix(ll k, ll x)
	{
		for (k++; k <= n; k += k&-k)
			T[k] += x;
	}

	void add_range(ll l, ll r, ll x)
	{
		add_prefix(r, -x);
		add_prefix(l, x);
	}

	ll get(ll k)
	{
		ll ans = 0;
		for (k++; k > 0; k -= k&-k)
			ans += T[k];
		return ans;
	}
};

int main()
{
	ll n, q;
	cin >> n >> q;
	fenwick fen(n);
	for (ll i = 0; i < n; i++)
	{
		ll x;
		cin >> x;
		fen.add_range(i, i+1, x);
	}

	while(q--)
	{
		ll t;
		cin >> t;
		if (t == 1)
		{
			ll a, b, x;
			cin >> a >> b >> x;
			a--;
			fen.add_range(a, b, x);
		}
		else
		{
			ll p;
			cin >> p;
			p--;
			cout << fen.get(p) << "\n";
		}
	}
}
