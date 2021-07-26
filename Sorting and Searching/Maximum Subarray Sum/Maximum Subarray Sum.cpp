#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;

	long long s = 0;
	long long ans = -1ll<<60;
	while(n--)
	{
		long long e; cin >> e;
		s += e;
		ans = max(ans, s);
		s = max(0ll, s);
	}
	cout << ans;
}
