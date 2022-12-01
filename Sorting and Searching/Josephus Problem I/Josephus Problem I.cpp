/*
Task:              2162 Josephus Problem I
Sender:            franfill
Submission time:   2021-07-03 12:50:29
Language:          C++11
Result:            ACCEPTED
/*
#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);
	int n;
	cin >> n;
	
	int s[n];
	for (int i = 0; i < n; i++) s[i] = (i+1)%n;
	
	int p = 0;
	for (p = 0; p != s[p]; p = s[p] = s[s[p]])
		cout << s[p] + 1 << " ";
	cout << p+1;
}
