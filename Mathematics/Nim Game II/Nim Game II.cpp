/*
Task:              1098 Nim Game II
Sender:            franfill
Submission time:   2022-01-28 20:06:54
Language:          C++17
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
		int n;
		cin >> n;
		int ans=0, x;
		while(n--)
		{
			cin >> x;
			ans ^= (x%4);
		}
		cout << (ans?"first":"second") << "\n";
	}
}
