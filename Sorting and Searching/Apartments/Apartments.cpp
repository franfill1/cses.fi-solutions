/*
Task:              1084 Apartments
Sender:            franfill
Submission time:   2021-07-01 13:58:22
Language:          C++11
Result:            ACCEPTED
/*
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
	ll n, m, k;
	cin >> n >> m >> k;
	
	vector < ll > a(n);
	for (ll i = 0; i < n; i++) cin >> a[i];
	
	vector < ll > b(m);
	for (ll i = 0; i < m; i++) cin >> b[i];

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	ll j = 0;
	ll ans = 0;
	for (ll i = 0; i < n; i++)
	{
		while(j < m && b[j] < a[i]-k) j++;
		if (j == m) break;
		if (b[j] <= a[i]+k)
		{
			ans++;
			j++;
		}
	}
	cout << ans;
}
