#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
	int n; cin >> n;
	
	vector<ll> x(n);
	for (ll &i : x) cin >> i;

	sort(x.begin(), x.end());
	ll sum = 0;
	for (int i = 0; i < n; i++)
	{
		if (x[i] > sum + 1) break;
		sum += x[i];
	}
	cout << sum+1 << "\n";
}
