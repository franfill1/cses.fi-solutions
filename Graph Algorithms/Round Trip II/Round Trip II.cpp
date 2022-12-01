/*
Task:              1678 Round Trip II
Sender:            franfill
Submission time:   2021-07-21 16:17:17
Language:          C++11
Result:            ACCEPTED
/*
#include<bits/stdc++.h>
using namespace std;

vector < vector < int > > g;
vector < int > state;
stack < int > cyc;

bool dfs(int n)
{
	state[n] = 1;
	for (int ne : g[n])
	{
		cyc.push(ne);
		if (state[ne] == 1 || state[ne] == 0 && dfs(ne)) return 1;
		cyc.pop();
	}
	state[n] = 2;
	return false;
}


int main()
{
	int n, m;
	cin >> n >> m;

	g.resize(n);
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b; a--; b--;
		g[a].push_back(b);		
	}
	
	state.resize(n, 0);
	for (int i = 0; i < n; i++)
	{
		cyc.push(i);
		if (state[i] == 0 && dfs(i))
		{
			int s = cyc.top(); cyc.pop();
			stack < int > ans;
			ans.push(s);
			while(s != cyc.top())
			{
				ans.push(cyc.top());
				cyc.pop();
			}
			ans.push(s);

			cout << ans.size() << "\n";
			while(!ans.empty())
			{
				cout << ans.top()+1 << " ";
				ans.pop();
			}
			return 0;
		}
	}

	cout << "IMPOSSIBLE\n";
}
