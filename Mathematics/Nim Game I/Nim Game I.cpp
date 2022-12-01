/*
Task:              1730 Nim Game I
Sender:            franfill
Submission time:   2022-01-28 20:03:46
Language:          C++17
Result:            ACCEPTED
/*
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		int ans = 0, x;
		while(n--)
		{
			cin >> x;
			ans ^= x;
		}
		cout << (ans?"first":"second") << "\n";
	}
}
