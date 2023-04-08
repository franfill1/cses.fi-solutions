/*
Task:              1709 Coin Grid
Sender:            franfill
Submission time:   2023-04-02 19:34:28
Language:          C++17
Result:            ACCEPTED
*/
#include<bits/stdc++.h>
using namespace std;
const int maxn = 100;
const int maxt = 2 * maxn + 2;

int cap[maxt][maxt];
int dis[maxt], par[maxt];

int find_path(int s, int t)
{
	fill(dis, dis+maxt, 0);	
	dis[s] = 1<<30;
	queue < int > q;
	q.emplace(s);
	while(!q.empty())
	{
		int x = q.front();
		q.pop();
		for (int y = 0; y < maxt; y++)
			if (dis[y] == 0 && cap[x][y])
			{
				par[y] = x;
				dis[y] = min(dis[x], cap[x][y]);
				q.emplace(y);
			}
	}
	return dis[t];
}

int max_flow(int s, int t)
{
	int flow = 0, new_flow;
	while((new_flow = find_path(s, t)))
	{
		flow += new_flow;
		int x = t;
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
	string s;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		for (int j = 0; j < n; j++)
			if (s[j] == 'o')
				cap[i+1][maxn+j+1] = 1;
	}	
	for (int i = 0; i < n; i++)
		cap[0][i+1] = 1;
	for (int j = 0; j < n; j++)
		cap[maxn+j+1][maxt-1] = 1;

	int f = max_flow(0, maxt-1);
	cout << f << "\n";
	for (int i = 1; i <= n; i++)
		if (dis[i] == 0)
			cout << 1 << " " << i << "\n";
	for (int j = 1; j <= n; j++)
		if (dis[maxn+j])
			cout << 2 << " " << j << "\n";
}
