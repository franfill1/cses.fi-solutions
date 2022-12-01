/*
Task:              1099 Stair Game
Sender:            franfill
Submission time:   2022-01-28 19:55:55
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
		int ans = 0;
		int x;
		for (int i = 0; i < n; i++)
		{
			cin >> x;
			if (i % 2) ans ^= x;
		}
		cout << (ans?"first":"second") << "\n";
	}
}
