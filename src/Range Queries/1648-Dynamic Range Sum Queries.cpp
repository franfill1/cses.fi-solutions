/*
Task:              1648 Dynamic Range Sum Queries
Sender:            franfill
Submission time:   2022-12-20 17:35:15
Language:          C++17
Result:            ACCEPTED
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

struct fenwick
{
	int n;
	vector < ll > T;
	fenwick(int n_) : n(n_) , T(n_+1, 0){}
	
	void add(int k, ll x)
	{
		for (k++; k <= n; k += k&-k)
			T[k] += x;
	}
	
	ll get_prefix(int k)
	{
		ll ans = 0;
		for (k++; k > 0; k -= k&-k)
			ans += T[k];
		return ans;
	}

	ll get_range(int l, int r)
	{
		return get_prefix(r-1) - get_prefix(l-1);
	}
};

int main()
{
	int n, q;
	cin >> n >> q;
	fenwick fen(n);
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		fen.add(i, x);
	}
	while(q--)
	{
		int t;
		cin >> t;
		if (t == 1)
		{
			int k, x;
			cin >> k >> x;
			k--;
			fen.add(k, x - fen.get_range(k, k+1));
		}
		else
		{
			int a, b;
			cin >> a >> b;
			a--;
			cout << fen.get_range(a, b) << "\n";
		}
	}
}
