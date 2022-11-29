#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct segtree
{
	int n;
	vector < ll > T;

	segtree(vector < ll > &V)
	{
		n = 1; while(n < V.size()) n*=2;
		T.resize(n*2);

		for (int i = 0; i < V.size(); i++)
		{
			T[i+n] = V[i];
		}
		for (int i = n-1; i > 0; i--)
		{
			T[i] = min(T[i*2], T[i*2+1]);
		}
	}

	void set(int k, ll u)
	{
		k += n;
		T[k] = u;
		while (k /= 2) T[k] = min(T[k*2], T[k*2+1]);
	}

	ll get(int a, int b)
	{
		b--;
		a += n; b += n;
		ll ans = 1ll<<60;
		while (a <= b)
		{
			if (a % 2 == 1) ans = min(ans, T[a++]);
			if (b % 2 == 0) ans = min(ans, T[b--]);
			a /= 2;
			b /= 2;
		}
		return ans;
	}
};

int main()
{
	int n, m;
	cin >> n >> m;
	vector < ll > P1(n), P2(n);

	for (int i = 0; i < n; i++)
	{
		ll el; cin >> el;
		P1[i] = el + i;
		P2[i] = el - i;
	}

	segtree seg1(P1), seg2(P2);

	while(m--)
	{
		int q; cin >> q;
		if (q == 1)
		{
			int k; ll x;
			cin >> k >> x; k--;
			seg1.set(k, x+k);
			seg2.set(k, x-k);
		}
		else
		{
			int k;
			cin >> k; k--;
			ll ans1 = seg1.get(k, n);
			ll ans2 = seg2.get(0, k);
			ans1 -= k;
			ans2 += k;
			cout << min(ans1, ans2) << "\n";;
		}
	}
}

