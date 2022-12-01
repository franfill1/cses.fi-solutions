/*
Task:              2182 Divisor Analysis
Sender:            franfill
Submission time:   2021-11-25 12:56:45
Language:          C++17
Result:            ACCEPTED
/*
#include<bits/stdc++.h>
#define M 1000000007
using namespace std;
typedef long long ll;
typedef pair < ll , ll > pll;

ll modpow(ll b, ll e, ll m)
{
	if (e == 0) return 1;
	ll t = modpow(b, e/2, m);
	return ((t*t)%m * (e%2 ? b : 1))%m;
}

ll sumto(ll n)
{
	return n*(n+1)/2;
}

int main()
{
	int n;
	cin >> n;
	vector < ll > X(n), K(n);
	for (int i = 0; i < n; i++)
	{
		cin >> X[i] >> K[i];
	}

	ll cnt = 1;
	ll cnt2 = 1;
	bool f2 = 0;
	for (int i = 0; i < n; i++)
	{
		cnt *= K[i]+1;
		if (!f2 && K[i] % 2 == 1)
		{
			cnt2 *= (K[i]+1)/2;
			f2 = 1;
		}
		else
		{
			cnt2 *= K[i]+1;
		}
		cnt %= M;
		cnt2 %= M-1;
	}

	ll sum = 1;
	for (int i = 0; i < n; i++)
	{
		ll x = X[i], k = K[i];
		ll t = (((((modpow(x, k, M) - 1) * x)%M + M)%M * modpow(x-1, M-2, M))%M);
		sum += sum * t;
		sum %= M;
	}

	ll pro = 1;
	for (int i = 0; i < n; i++)
	{
		ll e = cnt2 * K[i]; 
		if (!f2) 
		{
			assert(K[i] % 2 == 0);
			e /= 2;
		}
		e %= M-1;
		pro *= modpow(X[i], e, M);
		pro %= M;
	}
	cout << cnt << " " << sum << " " << pro << "\n";
}
