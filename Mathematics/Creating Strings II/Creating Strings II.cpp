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

	string s;
	cin >> s;
	ll ans = fact[s.size()];

	vector < int > cnt(26);
	for (char c : s) cnt[c-'a']++;

	for (int i = 0; i < 26; i++)
	{
		ans *= modpow(fact[cnt[i]], M-2);
		ans %= M;
	}
	cout << ans << "\n";
}

