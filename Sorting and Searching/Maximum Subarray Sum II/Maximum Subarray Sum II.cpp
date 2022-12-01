/*
Task:              1644 Maximum Subarray Sum II
Sender:            franfill
Submission time:   2021-07-17 15:35:59
Language:          C++11
Result:            ACCEPTED
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair < ll , ll > pll;

struct minqueue
{
	deque<pll> dq;
	
	void push(ll v, ll i)
	{
		while(!dq.empty() && dq.back().first > v)
			dq.pop_back();
		dq.push_back({v, i});
	}

	void pop(ll i)
	{
		if (dq.front().second == i) dq.pop_front();
	}

	ll get()
	{
		return dq.front().first;
	}
};

int main()
{
	int n, a, b;
	cin >> n >> a >> b;
	
	vector < ll > pre(n+1, 0);
	for (int i = 1; i <= n; i++)
	{
		ll el; cin >> el;
		pre[i] = pre[i-1] + el;
	}

	minqueue q;
	
	ll ans = -(1ll<<60);
	for (int i = a; i <= n; i++)
	{
		q.push(pre[i-a], i-a);
		q.pop(i-b-1);
		ans = max(ans, pre[i] - q.get());	
	}

	cout << ans;
}
