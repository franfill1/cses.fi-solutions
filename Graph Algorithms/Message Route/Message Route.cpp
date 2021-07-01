#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;
	
	vector < vector < int > > g(N, vector < int > (0));
	
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b; a--; b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	
	queue < int > q;
	q.push(N-1);
	vector < int > back(N, -1);
	vector < int > D(N, -1);
	D[N-1] = 1;
	while(!q.empty())
	{
		int n = q.front();
		int d = D[n];
		q.pop();
		if (n == 0)
		{
			break;
		}
		for (int i = 0; i < g[n].size(); i++)
		{
			if (back[g[n][i]] == -1)
			{
				back[g[n][i]] = n;
				D[g[n][i]] = d + 1;
				q.push(g[n][i]);
			}
		}
	}
	if (back[0] == -1)
	{
		cout << "IMPOSSIBLE";
	}
	else
	{
		int n = 0;
		cout << D[0] << "\n";
		cout << n+1 << " ";
		while(n != N-1)
		{
			n = back[n];
			cout << n +1 << " ";
		}
	} 
}

