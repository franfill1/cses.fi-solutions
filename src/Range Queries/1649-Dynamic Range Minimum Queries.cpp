/*
Task:              1649 Dynamic Range Minimum Queries
Sender:            franfill
Submission time:   2021-07-31 13:18:12
Language:          C++11
Result:            ACCEPTED
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct segtree
{
	int n;
	vector < ll > v;

	segtree(vector < ll > &a)
	{
		n = 1;
		while(n < a.size()) n *= 2;
		v.resize(2*n, 1ll<<60);
		for (int i = 0; i < a.size(); i++)
		{
			v[n+i] = a[i];
		}
		for (int i = n-1; i > 0; i--)
		{
			v[i] = min(v[i*2], v[i*2+1]);
		}
	}

	void set(int k, ll u)
	{
		k += n;
		v[k] = u;
		while(k /= 2) v[k] = min(v[k*2], v[k*2+1]);
	}

	ll get(int a, int b)
	{
		ll ans = 1ll<<60;
		a += n; b += n;
		while(a <= b)
		{
			if (a % 2) ans = min(ans, v[a++]);
			if (b % 2 == 0) ans = min(ans, v[b--]);

			a /= 2;
			b /= 2;
		}
		return ans;
	}
};

int main()
{
	int n, q;
	cin >> n >> q;
	vector < ll > V(n);
	for (ll &v : V) cin >> v;

	segtree seg(V);

	while(q--)
	{
		int t;
		cin >> t;
		if (t == 2)
		{
			int a, b;
			cin >> a >> b;
			a--; b--;
			cout << seg.get(a, b) << "\n";
		}
		else
		{
			int k; ll u;
			cin >> k >> u; k--;
			seg.set(k, u);
		}
	}
}
