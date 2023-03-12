/*
Task:              2420 Palindrome Queries
Sender:            franfill
Submission time:   2023-03-12 12:48:58
Language:          C++17
Result:            ACCEPTED
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

template < ll mod >
struct fenwick_mod
{
	int n;
	vector < ll > t;

	fenwick_mod(int n_) : n(n_+1), t(n_+1, 0)
	{
	}

	void add(int k, ll val)
	{
		for (k++; k < n; k += k&-k)
			t[k] = (t[k] + val) % mod;
	}

	ll get(int k)
	{
		ll ans = 0;
		for(;k > 0; k -= k&-k)
			ans = (ans + t[k]) % mod;
		return ans;
	}
};

ll modpow(ll b, ll e, ll mod)
{
	if (e == 0)
		return 1;
	ll t = modpow(b, e/2, mod);
	t = t * t % mod;
	if (e % 2)
		t = t * b % mod;
	return t;
}

template < ll base, ll mod >
struct dyn_rolling_hash
{
	int n;
	fenwick_mod < mod > fen;
	vector < ll > v, p;

	dyn_rolling_hash(int n_) : n(n_), fen(n_), v(n_, 0), p(n_)
	{
		p[0] = 1;
		for (int i = 1; i < n; i++)
			p[i] = p[i-1] * base % mod;
	}

	void set(int i, char c)
	{
		fen.add(i, (-v[i]*p[i]) % mod);
		v[i] = c;
		fen.add(i, (v[i]*p[i]) % mod);
	}

	ll get(int l, int r)
	{
		ll ans = (fen.get(r) - fen.get(l)) % mod;
		ans = (ans + mod) % mod;
		ans *= modpow(p[l], mod-2, mod);
		ans %= mod;
		return ans;
	}
};

int main()
{
	int n, q;
	cin >> n >> q;
	dyn_rolling_hash<243, 1000000007> hf(n), hr(n);
	string s;
	cin >> s;
	for (int i = 0; i < n; i++)
	{
		hf.set(i, s[i]);
		hr.set(n-i-1, s[i]);
	}

	while(q--)
	{
		int t;
		cin >> t;
		if (t == 1)
		{
			int k;
			char x;
			cin >> k >> x;
			k--;
			hf.set(k, x);
			hr.set(n-k-1, x);
		}
		else 
		{
			int a, b;
			cin >> a >> b;
			a--;
			ll f = hf.get(a, b);
			ll r = hr.get(n-b, n-a);
			if (f == r)
				cout << "YES\n";
			else
				cout << "NO\n";
		}
	}
}
