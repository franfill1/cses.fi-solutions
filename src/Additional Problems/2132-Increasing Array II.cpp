/*
Task:              2132 Increasing Array II
Sender:            franfill
Submission time:   2023-04-09 21:19:47
Language:          C++17
Result:            ACCEPTED
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	int n;
	cin >> n;
	priority_queue < int > pq;
	ll st = 0;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		st += x;
		pq.emplace(x);
		pq.emplace(x);
		pq.pop();
	}

	int x = numeric_limits<int>::max();
	while(!pq.empty())
	{
		int x1 = pq.top();	
		st -= (ll)(n-pq.size()) * (x-x1);
		x = x1;
		pq.pop();
	}
	st -= x*n;
	cout << st << "\n";
}
