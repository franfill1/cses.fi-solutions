/*
Task:              1620 Factory Machines
Sender:            franfill
Submission time:   2021-07-03 15:52:25
Language:          C++11
Result:            ACCEPTED
*/
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector < ll > k;
ll t;

bool check(ll a)
{
	ll tot = 0;
	for (ll m : k) tot += a / m;
	return tot >= t;
}

int main()
{
	ll n;
	cin >> n >> t;

	k.resize(n);
	for (ll i = 0; i < n; i++) cin >> k[i];

	ll a = 0, b = 1;
	while(!check(b)) b *= 2;

	while(a < b-1)
	{
		ll m = (a+b) / 2;
		if (check(m))
			b = m;
		else
			a = m;
	}
	cout << b;
}

