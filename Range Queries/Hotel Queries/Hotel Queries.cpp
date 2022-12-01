/*
Task:              1143 Hotel Queries
Sender:            franfill
Submission time:   2021-07-31 14:42:12
Language:          C++11
Result:            ACCEPTED
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct segtree
{
	int n;
	vector < ll > V;
	
	segtree(vector < ll > &A)
	{
		n = 1;
		while(n < A.size()) n *= 2;

		V.resize(n*2);
		for (int i = 0; i < A.size(); i++)
		{
			V[i+n] = A[i];
		}
		for (int i = n-1; i > 0; i--)
		{
			V[i] = max(V[i*2], V[i*2+1]);
		}
	}

	void add(int k, ll u)
	{
		k += n;
		V[k] += u;
		while (k /= 2) V[k] = max(V[k*2], V[k*2+1]);
	}

	ll lowB(ll v, int k=1)
	{
		if (V[k] < v) return -1;
		if (k >= n) return k-n;
		ll ans = lowB(v, k*2);
		if (ans == -1) ans = lowB(v, k*2+1);
		return ans;
	}
};

int main()
{
	int n, m;
	cin >> n >> m;
	vector < ll > h(n);
	for (ll &x : h) cin >> x;

	segtree seg(h);

	while(m--)
	{
		ll r;
		cin >> r;
		int i = seg.lowB(r);
		cout << i+1 << " ";
		seg.add(i, -r);
	}
}
