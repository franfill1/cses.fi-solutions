/*
Task:              2183 Missing Coin Sum
Sender:            franfill
Submission time:   2021-07-02 22:34:32
Language:          C++11
Result:            ACCEPTED
*/
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
	int n; cin >> n;
	
	vector<ll> x(n);
	for (ll &i : x) cin >> i;

	sort(x.begin(), x.end());
	ll sum = 0;
	for (int i = 0; i < n; i++)
	{
		if (x[i] > sum + 1) break;
		sum += x[i];
	}
	cout << sum+1 << "\n";
}
