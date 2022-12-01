/*
Task:              1662 Subarray Divisibility
Sender:            franfill
Submission time:   2021-07-17 12:57:16
Language:          C++11
Result:            ACCEPTED
/*
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
	int n;
	cin >> n;

	vector < int > r (n, 0);
	r[0]++;
	ll ans = 0, sum = 0;
	for (int i = 0; i < n; i++)
	{
		ll el;
		cin >> el;
		sum += el;
		sum = (sum%n + n)%n;
		ans += r[sum]++;
	}
	cout << ans << "\n";
}
