#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
	ll n, x;
	cin >> n >> x;

	map < ll , ll > cnt;
	cnt[0]++;

	ll sum=0, ans=0;
	for (int i = 0; i < n; i++)
	{
		ll a;
		cin >> a;
		sum += a;
		ans += cnt[sum-x];
		cnt[sum]++;
	}		

	cout << ans;
}
