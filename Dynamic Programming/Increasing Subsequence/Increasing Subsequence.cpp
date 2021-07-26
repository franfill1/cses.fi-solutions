#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct fenwick
{
	int n;
	vector < int > v;

	fenwick(int in) : n(in)
	{
		v.resize(n);
	}
	
	int get(int k)
	{
		int ans = 0;
		while(k)
		{
			ans = max(ans, v[k]);
			k -= k&-k;
		}
		return ans;
	}

	void set(int k, int x)
	{
		while(k < n)
		{
			v[k] = max(v[k], x);
			k += k&-k;
		}
	}
};

int main()
{
	int n;
	cin >> n;
	
	vector < ll > v(n);
	for (ll &e : v) cin >> e;

	vector < ll > vs = v;
	sort(vs.begin(), vs.end());

	unordered_map < ll , int > enc;
	for (ll e : vs)
	{
		if (!enc.count(e))
		{
			enc[e] = enc.size()+1;
		}
	}

	for (ll &e : v) e = enc[e];

	fenwick f(n+1);
	int ans = 1;
	for (int i = 0; i < n; i++)
	{
		int x = 1 + f.get(v[i] - 1);
		ans = max(ans, x);
		f.set(v[i], x);
	}

	cout << ans;
} 
