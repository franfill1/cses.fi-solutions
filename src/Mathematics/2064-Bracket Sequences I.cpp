/*
Task:              2064 Bracket Sequences I
Sender:            franfill
Submission time:   2021-11-29 12:34:17
Language:          C++17
Result:            ACCEPTED
*/
#include<iostream>
#include<vector>
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
	ll n;
	cin >> n;
	if (n%2) cout << 0 <<endl;
	else
	{
		n /= 2;
		cout << (((f[n*2]*inv(f[n]))%M * inv(f[n]))%M * inv(n+1))%M << endl;
	}
}
