/*
Task:              1712 Exponentiation II
Sender:            franfill
Submission time:   2021-11-25 10:40:18
Language:          C++17
Result:            ACCEPTED
*/
#include<bits/stdc++.h>
#define M 1000000007
using namespace std;
typedef long long ll;

ll modpow(ll b, ll e, ll m)
{
	if (e == 0) return 1;
	ll t = modpow(b, e/2, m);
	return ((t*t)%m * (e%2 ? b : 1))%m;
}

int main()
{
	int n;
	cin >> n;
	while(n--)
	{
		ll a, b, c;
		cin >> a >> b >> c;
		cout << modpow(a, modpow(b, c, M-1), M) << "\n";
	}
}
