/*
Task:              1754 Coin Piles
Sender:            franfill
Submission time:   2021-06-29 23:37:42
Language:          C++11
Result:            ACCEPTED
/*
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int a, b;
		cin >> a >> b;
		if (a > b) swap(a, b);
		if (a < b - a)
		{
			cout << "NO\n";
		}
		else
		{
			a = b = 2*a-b;
			if (a % 3)
				cout << "NO\n";
			else
				cout << "YES\n";
		}
	}
}
