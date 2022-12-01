/*
Task:              1632 Movie Festival II
Sender:            franfill
Submission time:   2021-07-17 18:34:06
Language:          C++11
Result:            ACCEPTED
/*
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
	int n, k;
	cin >> n >> k;

	vector < pair < ll , ll > > v(n);
	for (int i = 0; i < n; i++) cin >> v[i].second >> v[i].first;
	sort(v.begin(), v.end());

	multiset<ll> s;	
	for (int i = 0; i < k; i++) s.insert(0);

	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		auto it = s.upper_bound(v[i].second);
		if (it != s.begin())
		{
			s.erase(prev(it));
			s.insert(v[i].first);
			ans++;
		}
	}
	cout << ans << "\n";
}
