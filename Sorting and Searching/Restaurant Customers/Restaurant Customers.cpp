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

