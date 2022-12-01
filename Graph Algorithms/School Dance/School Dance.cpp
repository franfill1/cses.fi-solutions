/*
Task:              1696 School Dance
Sender:            franfill
Submission time:   2021-07-30 22:51:01
Language:          C++11
Result:            ACCEPTED
/*
#include<bits/stdc++.h>
using namespace std;
typedef pair < int , int > ii;

const int N = 1002;
int n;
int adj[N][N];
int back[N];

int find_flow()
{
	vector < bool > v(n);
	v[0] = 1;
	queue < ii > q;
	q.push({0, 1<<30});
	while(!q.empty())
	{
		int x = q.front().first, f = q.front().second;
		q.pop();
		for (int y = 0; y < n; y++) if (!v[y] && adj[x][y])
		{
			v[y] = 1;
			back[y] = x;
			int nf = min(f, adj[x][y]);
			if (y == n-1) return nf;
			q.push({y, nf});
		}
	}
	return 0;
}

int max_flow()
{
	int f = 0, nf;
	while(nf = find_flow())
	{
		f += nf;
		int x = n-1;
		while(x)
		{
			int y = back[x];
			adj[x][y] += nf;
			adj[y][x] -= nf;
			x = y;
		}
	}
	return f;
}

int main()
{
	int cb, cg, k;	
	cin >> cb >> cg >> k;

	n = cb + cg + 2;
	for (int i = 0; i < cb; i++)
		adj[0][i+1] = 1;
	for (int i = 0; i < cg; i++)
		adj[i+cb+1][n-1] = 1;

	vector < ii > eds;

	for (int i = 0; i < k; i++)
	{
		int a, b;
		cin >> a >> b;
		b += cb;
		adj[a][b] = 1<<30;
		eds.push_back({a, b});
	}

	int m = max_flow();

	cout << m << "\n";
	for (ii ed : eds)
	{
		if (adj[ed.first][ed.second] < (1<<30))
			cout << ed.first << " " << ed.second - cb << "\n";
	}

}
