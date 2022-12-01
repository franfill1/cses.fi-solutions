/*
Task:              1623 Apple Division
Sender:            franfill
Submission time:   2021-06-30 11:25:09
Language:          C++11
Result:            ACCEPTED
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector < int > p;

ll check(ll i, ll sum)
{
	ll temp = 0;
	for (int j = 0; j < p.size(); j++)
	{
		temp += p[j] * ((i & (1<<j))>>j);
	}
	return abs(temp - (sum - temp));		
}

int main()
{
	int n;
	cin >> n;
	p.resize(n);
	long long sum = 0;
	for (int i = 0; i < n; i++)
	 {
		 cin >> p[i];
		 sum += p[i];
	 }

	ll ans = 1ll<<60;
	for (ll i = 0; i < 1ll<<(n); i++)
	{
		ans = min(ans, check(i, sum));
	}
	cout << ans;
}
