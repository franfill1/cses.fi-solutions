/*
Task:              2432 Grid Puzzle I
Sender:            franfill
Submission time:   2023-04-09 11:44:48
Language:          C++17
Result:            ACCEPTED
*/
#include<bits/stdc++.h>
using namespace std;
 
const int maxn = 50, maxv = 2*maxn+2;
int cap[maxv][maxv], par[maxv], dis[maxv];
 
int find_path(int s, int f)
{
	fill(dis, dis+maxv, 0);
	queue < int > q;
	q.emplace(s);
	dis[s] = 1<<30;
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		for (int y = 0; y < maxv; y++)
			if (cap[x][y] && dis[y] == 0)
			{
				par[y] = x;
				dis[y] = min(dis[x], cap[x][y]);
				q.emplace(y);
				if (y == f)
					return dis[y];
			}
	}
	return dis[f];
}
 
int maxflow(int s, int f)
{
	int flow = 0, new_flow;
	while((new_flow = find_path(s, f)))
	{
		flow += new_flow;
		int x = f;
		while(x != s)
		{
			int y = par[x];
			swap(x, y);
			cap[x][y] -= new_flow;
			cap[y][x] += new_flow;
		}
	}
	return flow;
}
 
int main()
{
	int n;
	cin >> n;
	vector < int > a(n), b(n);
	int sa = 0, sb = 0;
	for (auto &x : a)
		cin >> x;
	for (auto &x : b)
		cin >> x;
	for (int i = 0; i < n; i++)
		cap[0][i+1] = a[i], sa += a[i];
	for (int i = 0; i < n; i++)
		cap[maxn+i+1][maxv-1] = b[i], sb += b[i];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cap[i+1][maxn+j+1] = 1;
 
	if (sa != sb)
		cout << -1 << "\n";
	else
	{
		int f = maxflow(0, maxv-1);
		if (f != sa)
			cout << -1 << "\n";
		else
		{
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
					if (!cap[i+1][maxn+j+1])
						cout << "X";
					else
						cout << ".";
				cout << "\n";
			}
		}
	}
}
