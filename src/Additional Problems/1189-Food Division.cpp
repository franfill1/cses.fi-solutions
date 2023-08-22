/*
Task:              1189 Food Division
Sender:            franfill
Submission time:   2023-04-23 16:08:36 +0300
Language:          C++17
Result:            ACCEPTED
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	int n;
	cin >> n;
	vector < ll > vals, a(n), b(n);
	for (auto &x : a)
		cin >> x;
	for (auto &x : b)
		cin >> x;
	ll cur = 0;
	for (int i = 0; i < n; i++)
	{
		cur += a[i]-b[i];
		vals.emplace_back(cur);
	}
	nth_element(vals.begin(), vals.begin() + n/2, vals.end());
	ll ans = 0, m = vals[n/2];
	for (int i = 0; i < n; i++)
		ans += abs(vals[i]-m);
	cout << ans << "\n";
}
