/*
Task:              1661 Subarray Sums II
Sender:            franfill
Submission time:   2021-07-17 01:07:00
Language:          C++11
Result:            ACCEPTED
/*
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
