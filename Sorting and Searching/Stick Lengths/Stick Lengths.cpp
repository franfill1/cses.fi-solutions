#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector < int > v(n);
	for (int &x : v) cin >> x;
	
	sort(v.begin(), v.end());

	int t = v[v.size()/2];
	long long ans = 0;
	for (int x : v) ans += abs(x - t);
	cout << ans;
}
