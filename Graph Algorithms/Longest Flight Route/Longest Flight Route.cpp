/*
Task:              1680 Longest Flight Route
Sender:            franfill
Submission time:   2021-07-21 16:38:56
Language:          C++11
Result:            ACCEPTED
/*
#include<bits/stdc++.h>
using namespace std;

vector < vector < int > > g;
stack < int > ts;
vector < bool > vis;

void toposort(int n)
{
	vis[n] = true;
	for (int ne : g[n])
	{
		if (!vis[ne])
			toposort(ne);
	}
	ts.push(n);
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
	vis.resize(n, false);

	toposort(0);

	vector < int > D(n, -1<<30);
	vector < int > F(n, -1);
	D[0] = 1;
	
	while(!ts.empty())
	{
		int p = ts.top();
		ts.pop();
		for (int ne : g[p])
		{
			if (D[ne] < D[p] + 1)
			{
				D[ne] = D[p] +1;
				F[ne] = p;
			}
		}
	}

	if (D[n-1] == -1<<30)
	{
		cout << "IMPOSSIBLE\n";
	}
	else
	{
		cout << D[n-1] << "\n";
		stack < int > ans;
		int p = n-1;
		while(p != 0)
		{
			ans.push(p);
			p = F[p];
		}
		cout << 1 << " ";
		while(!ans.empty())
		{
			cout << ans.top()+1 << " "; ans.pop();
		}
	}
}
