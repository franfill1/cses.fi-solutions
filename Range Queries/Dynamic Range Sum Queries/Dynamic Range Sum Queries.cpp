/*
Task:              1648 Dynamic Range Sum Queries
Sender:            franfill
Submission time:   2021-07-31 13:06:47
Language:          C++11
Result:            ACCEPTED
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct fenwick
{
	int n;
	vector < ll > T;

	fenwick(vector < ll > &v) : n(v.size()+1)
	{
		T.resize(n, 0);
		for (int i = 0; i < n; i++)
		{
			add(i, v[i]);
		}
	}

	void add(int k, ll u)
	{
		k++;
		while(k < n)
		{
			T[k] += u;
			k += k&-k;
		}
	}

	ll get(int k)
	{
		k++;
		ll ans = 0;
		while(k)
		{
			ans += T[k];
			k -= k&-k;
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

	fenwick f(V);

	while(q--)
	{
		int t;
		cin >> t;
		if (t == 1)
		{
			int k; ll u;
			cin >> k >> u;
			k--;
			f.add(k, u - V[k]);
			V[k] = u;
		}
		else
		{
			int a, b;
			cin >> a >> b;
			a-=2; b--;
			cout << f.get(b) - f.get(a) << "\n";
		}
	}
}
