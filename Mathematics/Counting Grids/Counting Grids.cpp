/*
Task:              2210 Counting Grids
Sender:            franfill
Submission time:   2021-11-29 16:17:58
Language:          C++17
Result:            ACCEPTED
/*
#include<bits/stdc++.h>
#define M 1000000007
using namespace std;
typedef long long ll;

ll modpow(ll b, ll e)
{
	if (e == 0) return 1;
	ll t = modpow(b, e/2);
	return ((t*t)%M * (e % 2 ? b : 1))%M;
}

int main()
{
	int n;
	cin >> n;
	ll m = n/2;
	ll t = ((m*m)%(M-1) + m*(n%2))%(M-1);
	ll r1 = modpow(2, t+(n%2));
	ll r2 = modpow(2, 2*t+(n%2));
	ll r3 = r1;
	ll r4 = modpow(2, 4*t+(n%2));
	cout << ((r1 + r2 + r3 + r4)%M * modpow(4, M-2))%M << "\n";
}
