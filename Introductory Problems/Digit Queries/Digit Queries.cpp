/*
Task:              2431 Digit Queries
Sender:            franfill
Submission time:   2021-06-30 12:49:58
Language:          C++11
Result:            ACCEPTED
/*
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
	int q;
	cin >> q;
	while(q--)
	{
		ll k;
		cin >> k;
		ll p = 1;
		ll i;
		for (i = 1; p*i*9 < k; i++)
		{
			k -= p*i*9; p*=10;
		}
		ll c = (k) / i;
		ll n = p + c - (k % i == 0);
		ll o =((-k % i)+i)%i;
		while(o--)
		{
			n /= 10; k--;
		}
		cout << n % 10 << "\n";
	}
}
