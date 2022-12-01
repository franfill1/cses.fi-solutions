/*
Task:              1161 Stick Divisions
Sender:            franfill
Submission time:   2022-02-08 17:27:05
Language:          C++17
Result:            ACCEPTED
/*
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
	ll x, n;
	cin >> x >> n;
	priority_queue < ll , vector < ll > , greater < ll > > pq;
	while(n--)
	{
		cin >> x;
		pq.push(x);
	}
	ll ans = 0;
	while(pq.size() > 1)
	{
		x = pq.top();
		pq.pop();
		ans += pq.top() + x;
		pq.push(pq.top() + x);
		pq.pop();
	}
	cout << ans << "\n";
}
