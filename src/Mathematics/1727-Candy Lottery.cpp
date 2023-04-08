/*
Task:              1727 Candy Lottery
Sender:            franfill
Submission time:   2022-01-29 15:51:44
Language:          C++17
Result:            ACCEPTED
*/
#include<bits/stdc++.h>
using namespace std;
typedef long double ld;

int main()
{
	int n, k;
	cin >> n >> k;
	ld s = 0;
	ld ans = 0;
	for (int c = 1; c <= k; c++)
	{
		ld p = pow(ld(c)/k, n) - pow(ld(c-1)/k, n);
		ans += p*c;
	}
	cout << fixed << setprecision(6) << ans << "\n";
}
