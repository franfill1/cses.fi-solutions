/*
Task:              2087 Houses and Schools
Sender:            franfill
Submission time:   2022-10-19 19:44:46
Language:          C++17
Result:            ACCEPTED
/*
#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main()
{
	int n, k;
	cin >> n >> k;
	vector < ll > c(n);
	for (auto &x : c)
		cin >> x;

	vector < ll > pre1(n+1,0), pre2(n+1,0);
	for (int i = 1; i <= n; i++)
	{
		pre1[i] = pre1[i-1] + c[i-1];
		pre2[i] = pre2[i-1] + c[i-1]*(i-1);
	}

	auto gol = [&] (int i, int j) -> ll
	{
		//tutti le case in [i, j) vanno in i
		return (pre2[j] - pre2[i]) - (pre1[j] - pre1[i])*i;
	};

	auto gor = [&] (int i, int j) -> ll
	{
		//tutte le case in [i, j) vanno in j
		return (pre1[j] - pre1[i])*j - (pre2[j] - pre2[i]);
	};

	auto split = [&] (int i, int j) -> ll
	{
		//le case in [i, j) si dividono a seconda della convenienza
		int k = (i+j+1)/2;
		return gol(i, k) + gor(k, j);
	};

	vector < ll > dp(n), buf(n);

	auto update = [&] (int l, int r, int il, int ir, auto update) -> void
	{
		int m = (l+r)/2;
		int im = il;
		buf[m] = 1ll<<62;
		for (int i = il; i < min(m, ir); i++)
		{
			ll val = dp[i] + split(i,m);
			if(val < buf[m])
				buf[m] = val, im = i;
		}
		if (l < r-1)
		{
			update(l, m, il, im+1, update);
			update(m, r, im, ir, update);
		}
	};

	for (int i = 0; i < n; i++)
		dp[i] = gor(0, i);

	for (int i = 1; i < k; i++)
	{
		update(0, n, 0, n, update);
		dp = buf;
	}
	ll ans = 1ll<<60;
	for (int i = 0; i < n; i++)
		ans = min(ans, dp[i] + gol(i, n));

	cout << ans << "\n";
}
