/*
Task:              2194 Minimum Euclidean Distance
Sender:            franfill
Submission time:   2022-10-13 20:36:29
Language:          C++17
Result:            ACCEPTED
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
struct repair_cmp 
{
	bool operator ()(const pair < ll , ll > a, const pair < ll , ll > b) const
	{
		if (a.second == b.second)
			return a.first < b.first;
		return a.second < b.second;
	};
};
 
ll dist(pair < ll , ll > a, pair < ll , ll > b)
{
	ll dx = a.first - b.first;
	ll dy = a.second - b.second;
	return dx*dx + dy*dy;
}
 
int main()
{
	ll N;
	cin >> N;
	vector < pair < ll , ll > > V(N);
	for (auto &[x, y] : V)
		cin >> x >> y;
	sort(V.begin(), V.end());
	ll l = 0;
 
	set < pair < ll , ll > , repair_cmp > s;
	ll ans = dist(V[0], V[1]);
	for (ll i = 0; i < N; i++)
	{
		auto [x, y] = V[i];
		int sans = sqrt(ans) + 1;
		while(l < i && V[l].first < x-sans)
		{
			assert(s.size());
			s.erase(V[l]);
			l++;
		}
		for (auto p = s.lower_bound(make_pair(x-sans, y-sans)); p != s.end() && p->second <= y+sans; p++)
			ans = min(ans, dist(V[i], *p));	
		s.insert(V[i]);
	}
	cout << ans << "\n";
}
