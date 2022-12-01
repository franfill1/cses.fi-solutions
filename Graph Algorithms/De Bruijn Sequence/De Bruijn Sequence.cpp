/*
Task:              1692 De Bruijn Sequence
Sender:            franfill
Submission time:   2021-07-26 23:29:45
Language:          C++11
Result:            ACCEPTED
/*
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int l;
	cin >> l;

	if (l == 1)
	{
		cout << "01\n";
		return 0;
	}

	int n = 1<<(l-1);
	int mask = n-1;
	
	vector < set < int > > g(n); 
	for (int i = 0; i < n; i++)
	{
		g[i].insert((i<<1) & mask);
		g[i].insert(((i<<1) & mask) +1);
	}

	stack < int > ans;
	stack < int > s;
	s.push(0);
	while(!s.empty())
	{
		int x = s.top();
		if (g[x].empty())
		{
			ans.push(x);
			s.pop();
		}
		else
		{
			int y = *g[x].begin();
			g[x].erase(y);
			s.push(y);
		}
	}
	
	for (int i = 0; i < l-1; i++) cout << 0;

	ans.pop();
	while(!ans.empty())
	{
		cout << ans.top() % 2;
		ans.pop();
	}
}
