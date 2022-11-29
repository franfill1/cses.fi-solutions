#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair < ll , ll > pll;

struct project
{
	ll a, b, p;
};

bool operator < (project a, project b)
{
	return a.a < b.a;
}

int main()
{
	int n;
	cin >> n;

	vector < project > v;
	for (int i = 0; i < n; i++)
	{
		ll a, b, p;
		cin >> a >> b >> p;
		v.push_back({a, b, p});
	}

	sort(v.begin(), v.end());

	vector < ll > memo(n+1, 0);

	for (int i = n-1; i >= 0; i--)
	{
		project temp = {v[i].b, 0, 0};
		memo[i] = max(memo[i+1], v[i].p + memo[upper_bound(v.begin(), v.end(), temp) - v.begin()]);
	}

	cout << memo[0];
}

