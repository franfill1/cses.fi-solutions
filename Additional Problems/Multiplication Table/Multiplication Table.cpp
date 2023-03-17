/*
Task:              2422 Multiplication Table
Sender:            franfill
Submission time:   2022-12-02 18:18:57
Language:          C++17
Result:            ACCEPTED
*/
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main()
{
	ll n;
	cin >> n;
	ll a = 0, b = n*n;	
	while(a != b-1)
	{
		ll m = (a+b)/2;
		ll cnt = 0;
		for (int i = 1; i <= n; i++)
			cnt += min(n, m / i);
		if (cnt > n*n/2)
			b = m;	
		else
			a = m;
	}
	cout << b << "\n";
}
