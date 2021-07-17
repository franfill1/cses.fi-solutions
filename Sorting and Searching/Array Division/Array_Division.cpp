#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, k;
vector < ll > v;

bool check(ll x)
{
	int u = 1;
	ll sum = 0;
	for (int i = 0; i < n; i++)
	{
		if (v[i] > x)
			return false;
		if (sum + v[i] > x)
		{
			u++;
			sum = 0;
		}
		sum += v[i];
	}
	return u <= k;
}

int main()
{
	cin >> n >> k;
	v.resize(n);
	for (int i = 0; i < n; i++) cin >> v[i];

	ll a = 0, b = 1;
	while(!check(b)) b *= 2;	

	while(a != b-1)
	{
		ll m = (a+b)/2;
		if (check(m)) b = m;
		else a = m;
	}
	cout << b << "\n";
}
