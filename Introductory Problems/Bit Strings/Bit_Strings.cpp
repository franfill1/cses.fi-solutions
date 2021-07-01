#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	long long ans = 1;
	for (long long i = 0; 1ll<<i <= n; i++)
	{
		if (n & 1ll<<i) ans *= p;
		p *= p;
		p %= (long long)1e9 + 7;
		ans %= (long long)1e9 + 7;
	}
	cout << ans;
}
