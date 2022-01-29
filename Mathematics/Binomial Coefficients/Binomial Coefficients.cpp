#include<bits/stdc++.h>
#define M 1000000007
typedef long long ll;
using namespace std;

ll modpow(ll b, ll e)
{
	if (e == 0) return 1;
	ll t = modpow(b, e>>1);
	return ((t*t)%M * (e % 2 ? b : 1))%M;
}

int main()
{
	vector < ll > fact(1000001, 1);
	for (int i = 2; i < fact.size(); i++)
	{
		fact[i] = (fact[i-1] * i)%M;
	}
	int n;
	cin >> n;
	while(n--)
	{
		ll a, b;
		cin >> a >> b;
		cout << (((fact[a] * modpow(fact[b], M-2))%M * modpow(fact[a-b], M-2))%M) << "\n";
	}
}
