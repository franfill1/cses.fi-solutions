/*
Task:              1645 Nearest Smaller Values
Sender:            franfill
Submission time:   2021-07-17 00:55:34
Language:          C++11
Result:            ACCEPTED
/*
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
	int n;
	cin >> n;

	stack < pair < ll , ll > > s;
	s.push({0, 0});

	for (int i = 0; i < n; i++)
	{
		ll el;
		cin >> el;
		while(s.top().first >= el) s.pop();
		
		cout << s.top().second << " ";
		s.push({el, i+1});
	}
}
