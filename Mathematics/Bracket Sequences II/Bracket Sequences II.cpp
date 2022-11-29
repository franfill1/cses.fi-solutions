#include<bits/stdc++.h>
#define M 1000000007
using namespace std;
typedef long long ll;
 
ll modpow(ll b, ll e)
{
	if (e==0) return 1;
	ll t = modpow(b, e/2);
	return ((t*t)%M * (e%2?b:1))%M;
}
 
ll inv(ll n)
{
	return modpow(n, M-2);
}
 
int main()
{
	vector < ll > f(2000001,1);
	for (int i=1; i < f.size(); i++)
	{
		f[i] = f[i-1]*i;
		f[i]%=M;
	}
	ll N;
	cin >> N;
	string s;
	cin >> s;

	ll K = s.size();
	ll k = 0;
	for (char c : s)
	{
		if (c == '(') k++;
		else k--;
		if (k < 0)
		{
			cout << "0\n";
			return 0;
		}
	}
	
	ll n = N-K;
	if (N % 2 || k > n)
	{
		cout << "0\n";
		return 0;
	}
	else 
	{
		ll m = (n+k)/2;
		ll t = ((f[n] * inv(f[m]))%M * inv(f[n-m]))%M; 
		if (n > m)
		{
			ll x = ((f[n] * inv(f[m+1]))%M * inv(f[n-m-1]))%M;
			t = ((t-x)%M + M)%M;
		}
		cout << t << "\n";
	}

}

