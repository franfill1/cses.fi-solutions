/*
Task:              1748 Increasing Subsequence II
Sender:            franfill
Submission time:   2023-03-14 19:57:51
Language:          C++17
Result:            ACCEPTED
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll mod = 1000000007;

struct fenwick
{
	int n;
	vector < ll > t;
	fenwick(int n_) : n(n_+1), t(n_+1, 0)
	{
	}

	void add(int k, ll x)
	{
		for (k++; k < n; k += k&-k)
			t[k] = (t[k] + x) % mod;
	}

	ll get(int k)
	{
		ll ans = 0;
		for (; k; k -= k&-k)
			ans = (ans + t[k]) % mod;
		return ans;
	}
};

int main()
{
	int n;
	cin >> n;
	vector < int > v(n);
	map < int , int > m;
	for (auto &x : v)
	{
		cin >> x;
		m[x] = 0;
	}
	int c = 0;
	for (auto &[a, b] : m)
		b = c++;

	fenwick fen(m.size());
	ll ans = 0;
	for (auto &x : v)
	{	
		x = m[x];
		ll a = fen.get(x)+1;
		ans = (ans + a) % mod;
		fen.add(x, a);
	}
	cout << ans << "\n";
}
