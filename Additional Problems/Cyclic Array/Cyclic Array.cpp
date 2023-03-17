/*
Task:              1191 Cyclic Array
Sender:            franfill
Submission time:   2023-03-14 20:59:03
Language:          C++17
Result:            ACCEPTED
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int P = 30;

int main()
{
	int n;
	ll k;
	cin >> n >> k;
	vector < int > v(n);
	for (auto &x : v)
		cin >> x;
	for (int i = 0; i < n; i++)
		v.emplace_back(v[i]);
	v.emplace_back(0);
	vector < vector < int > > nxt(P, vector < int > (2*n+1));
	for (int p = 0; p < P; p++)
		nxt[p][2*n] = 2*n;
	auto lift = [&] (int x, int j) -> int
	{
		for (int p = 0; p < P; p++)
			if (j & (1<<p))
				x = nxt[p][x];
		return x;
	};
	int r = 2*n;
	ll s = 0;
	int ans = n;
	for (int l = 2*n-1; l >= 0; l--)
	{
		s += v[l];
		while(s > k)
			s -= v[--r];
		assert(r > l);
		assert(0 < s && s <= k);
		nxt[0][l] = r;
		for (int p = 1; p < P; p++)
			nxt[p][l] = nxt[p-1][nxt[p-1][l]];
		if (l < n)
		{
			int a=0, b=n;
			while(a < b-1)
			{
				int m = (a+b)/2;
				if (lift(l, m) >= l+n)
					b = m;
				else
					a = m;
			}
			ans = min(ans, b);
		}
	}
	cout << ans << "\n";
}
