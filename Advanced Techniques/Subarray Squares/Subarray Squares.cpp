#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
	int n, k;
	cin >> n >> k;
	vector < ll > v(n), pre(n+1, 0);
	vector < ll > dp(n+1, 0);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
		pre[i+1] = pre[i] + v[i];
		dp[i] = pre[i]*pre[i];
	}
	
	vector < ll > buf(n+1);

	auto update = [&] (int l, int r, int il, int ir, auto update) -> void
	{
		int m = (l+r)/2;
		buf[m] = numeric_limits<ll>::max();
		int im = 0;
		for (int i = il; i < min(ir, m+1); i++)
		{
			ll sum = pre[m] - pre[i];
			ll val = dp[i] + sum*sum;
			if (val < buf[m])
				im = i, buf[m] = val;
		}
		if (l != r-1)
		{
			update(l, m, il, im+1, update);
			update(m, r, im, ir, update);
		}
	};

	for (int i = 1; i < k; i++)
	{
		buf.assign(n+1, -1);
		update(0, n+1, 0, n, update);
		for (auto x : buf)
			assert(x != -1);
		dp = buf;
	}
	cout << dp[n] << "\n";
}

