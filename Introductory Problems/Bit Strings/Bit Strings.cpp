/*
Task:              1617 Bit Strings
Sender:            franfill
Submission time:   2022-01-18 17:18:08
Language:          C++17
Result:            ACCEPTED
/*
#include<iostream>
#define M 1000000007
using namespace std;
typedef long long ll;

ll modpow(ll b, ll e)
{
	if (e == 0)
	{
		return 1;
	}
	ll temp = modpow(b, e/2);
	ll ans = (temp * temp) % M;
	if (e % 2 == 1)
	{
		ans *= b;
		ans %= M;
	}
	return ans;
}

int main()
{
	ll N;
	cin >> N;
	cout << modpow(2, N) << "\n";
}
