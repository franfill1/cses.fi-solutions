/*
Task:              1716 Distributing Apples
Sender:            franfill
Submission time:   2021-11-26 18:37:06
Language:          C++17
Result:            ACCEPTED
/*
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
	vector < ll > fact(2000001, 1);
	for (int i = 2; i < fact.size(); i++)
	{
		fact[i] = (fact[i-1] * i)%M;
	}
	int n, m;
	cin >> n >> m;
	cout << ((fact[n+m-1] * modpow(fact[n-1], M-2))%M * modpow(fact[m], M-2))%M << "\n";
}
