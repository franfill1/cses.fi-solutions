/*
Task:              1071 Number Spiral
Sender:            franfill
Submission time:   2021-06-29 17:08:15
Language:          C++11
Result:            ACCEPTED
*/
#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long t;
	cin >> t;
	while(t--)
	{
		long long y, x;
		cin >> y >> x;

		long long b = max(x, y);
		long long p = b*b;
			
		if (p % 2) swap(x, y);
		long long ans = p - abs(1 - x) - abs(b - y);
		cout << ans << "\n";
	}
}
