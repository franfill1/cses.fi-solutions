#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
	ll n, x;
	cin >> n >> x;
	
	vector < pair < ll , ll > > a(n);
	for (ll i = 0; i < n; i++)
	{
		cin >> a[i].first;
		a[i].second = i;
	}

	sort(a.begin(), a.end());

	ll j = n-1;
	for (ll i = 0; i < j; i++)
	{
		while(a[i].first + a[j].first > x) j--;
		if (i >= j) break;
		if (a[i].first + a[j].first == x)
		{
			cout << a[i].second +1 << " " << a[j].second+1 << "\n";
			return 0;
		}
	}
	cout << "IMPOSSIBLE";
}

