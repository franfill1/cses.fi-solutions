/*
Task:              2215 Monotone Subsequences
Sender:            franfill
Submission time:   2023-03-14 18:25:38
Language:          C++17
Result:            ACCEPTED
*/
#include<bits/stdc++.h>
using namespace std;

void solve()
{
	int n, k;
	cin >> n >> k;
	if (k * k < n)
	{
		cout << "IMPOSSIBLE\n";
		return;
	}
	int l=0, r=k;
	while(l != n)
	{
		for (int i = r; i > l; i--)
			cout << i << " ";
		l = r;
		r = min(n, r+k);
	}
	cout << "\n";
}

int main()
{
	int t;
	cin >> t;
	while(t--)
		solve();
}
