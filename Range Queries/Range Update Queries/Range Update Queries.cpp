/*
Task:              1651 Range Update Queries
Sender:            franfill
Submission time:   2021-07-31 13:48:33
Language:          C++11
Result:            ACCEPTED
/*
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct fenwick
{
	int n;
	vector < ll > T;

	fenwick(vector < ll > &A) : n(A.size()+1)
	{
		T.resize(n, 0);

		for (int i = 0; i < n; i++)
		{
			radd(i, i+1, A[i]);
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

	void radd(int a, int b, ll u)
	{
		add(a, u);
		add(b, -u);
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
	
	fenwick fen(V);

	while(q--)
	{
		int t;
		cin >> t;
		if (t == 1)
		{
			int a, b; ll u;
			cin >> a >> b >> u; a--;
			fen.radd(a, b, u);
		}
		else
		{
			int k;
			cin >> k;
			k--;
			cout << fen.get(k) << "\n";
		}
	}
}
