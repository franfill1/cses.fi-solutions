/*
Task:              1142 Advertisement
Sender:            franfill
Submission time:   2022-10-24 16:11:45
Language:          C++17
Result:            ACCEPTED
/*
#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using pll = pair < ll , ll >;

int main()
{
	priority_queue < pll , vector < pll > , greater < pll > > pq;
	set < ll > rem;
	multiset < ll > dims;
	int n;	
	cin >> n;
	rem.insert(0);
	rem.insert(n+1);
	dims.insert(n);

	for (int i = 0; i < n; i++)
	{
		ll x;
		cin >> x;
		pq.emplace(x, i+1);
	}

	ll ans = 0;
	while(pq.size())
	{
		auto [x, i] = pq.top();
		pq.pop();
		ans = max(ans, (*prev(dims.end()))*x);
		auto it = rem.upper_bound(i);
		ll dim = *it - *prev(it) - 1;
		dims.erase(dims.find(dim));
		dims.insert(i - *prev(it) - 1);
		dims.insert(*it - i - 1);
		rem.insert(i);
	}
	cout << ans << "\n";
}
