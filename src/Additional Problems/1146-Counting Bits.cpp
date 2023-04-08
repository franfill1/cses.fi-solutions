/*
Task:              1146 Counting Bits
Sender:            franfill
Submission time:   2022-11-20 09:54:01
Language:          C++17
Result:            ACCEPTED
*/
#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main()
{
	long long n;
	cin >> n;
	n++;
	long long ans = 0;
	for (int p = 0; p < 60; p++)
	{
		ll cnt = n / (2ll<<p);
		ans += cnt * (1ll<<p);
		ll r = n % (2ll<<p);
		ans += max(r - (1ll<<p), 0ll);
	}
	cout << ans << "\n";
}
