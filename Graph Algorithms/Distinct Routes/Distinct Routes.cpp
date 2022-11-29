#include<bits/stdc++.h>
using namespace std;
typedef pair < int , int > ii;

const int N = 500;
int n;
int adj[N][N];
int ori[N][N];
int back[N];

int ff()
{
	vector < bool > v(n, 0);
	v[0] = 1;
	queue < ii > q;
	q.push({0, 1<<30});
	while(!q.empty())
	{
		int x = q.front().first, f = q.front().second;
		q.pop();
		for (int y = 0; y < n; y++) if (!v[y] && adj[x][y])
		{
			int nf = min(f, adj[x][y]);
			v[y] = 1;
			back[y] = x;
			if (y == n-1) return nf;
			q.push({y, nf});
		}
	}
	return 0;
}

int mf()
{
	int f = 0, nf;
	while(nf = ff())
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
	int m;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b; cin >> a >> b; a--; b--;
		adj[a][b]++;
		ori[a][b]++;
	}

	int cnt = mf();

	vector < vector < int > > pt(cnt);

	for (int i = 0; i < cnt; i++)
	{
		int x = 0;
		pt[i].push_back(x);
		while(x != n-1)
		{
			int y;
			for (y = 0; y < n; y++) 
				if (ori[x][y] && !adj[x][y]) break;

			assert(y != n);
			ori[x][y] = 0;
			pt[i].push_back(y);
			x = y;
		}
	}

	cout << cnt << "\n";
	for (int i = 0; i < cnt; i++)
	{
		cout << pt[i].size() << "\n";
		for (int x : pt[i]) cout << x+1 << " ";
		cout << "\n";
	}
}

