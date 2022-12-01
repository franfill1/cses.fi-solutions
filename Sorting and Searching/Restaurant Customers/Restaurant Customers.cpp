/*
Task:              1619 Restaurant Customers
Sender:            franfill
Submission time:   2021-07-02 15:42:30
Language:          C++11
Result:            ACCEPTED
/*
#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	priority_queue < pair < int , int > > q;
	
	for (int i = 0; i < n; i++)
	{
		int a, b; cin >> a >> b;
		q.push({-a, 1});
		q.push({-b, -1});
	}

	int ans = 0;
	int p = 0;
	while(!q.empty())
	{
		p += q.top().second;
		ans = max(ans, p);
		q.pop();
	}

	cout << ans;
		
}
