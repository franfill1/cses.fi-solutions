/*
Task:              1086 Writing Numbers
Sender:            franfill
Submission time:   2023-03-14 21:46:22
Language:          C++17
Result:            ACCEPTED
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ll n;
	cin >> n;

	int extra = 0;
	ll pp = 1;
	ll ans = 0;
	for (int i = 0; i < 17; i++)
		pp *= 10;
	auto calc = [&] (ll p, ll c, ll pp, ll extra) -> ll
	{
		return c * (p * pp/10 + extra * pp) + (c > 1) * pp;
	};
	for (int p = 17; p >= 0; p--)
	{
		ll c;
		for (c = 1; c < 10; c++)
			if (calc(p, c, pp, extra) > n)
				break;
		c--;
		n -= calc(p, c, pp, extra);
		if (c == 1)
			extra++;
		ans += c * pp;
		pp /= 10;
	}
	cout << ans-1 << "\n";
}
