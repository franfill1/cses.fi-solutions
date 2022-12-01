/*
Task:              1090 Ferris Wheel
Sender:            franfill
Submission time:   2021-07-01 14:06:17
Language:          C++11
Result:            ACCEPTED
*/
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
	int n; ll x;
	cin >> n >> x;

	vector < ll > p(n);
	for (int i = 0; i < n; i++) cin >> p[i];
	sort(p.begin(), p.end());

	int l = 0;
	int ans = 0;
	for (int r = n-1; r >= l; r--)
		if (l != r && p[r] + p[l] <= x) l++;
	
	cout << n-l;
}
