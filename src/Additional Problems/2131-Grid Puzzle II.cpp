/*
Task:              2131 Grid Puzzle II
Sender:            franfill
Submission time:   2023-04-09 12:03:56
Language:          C++17
Result:            ACCEPTED
*/
#include<bits/stdc++.h>
using namespace std;

constexpr int maxn = 50, maxv = 2*maxn+2;

int cap[maxv][maxv], pri[maxv][maxv], flo[maxv], dis[maxv], par[maxv];
bool inq[maxv];

int find_path(int s, int f)
{
	fill(flo, flo+maxv, 0);
	fill(dis, dis+maxv, -(1<<30));
	flo[0] = 1<<30, dis[0] = 0;
	queue < int > q;
	inq[0] = true;
	q.emplace(0);
	while(!q.empty())
	{
		int x = q.front();
		q.pop();
		inq[x] = false;

		for (int y = maxv-1; y; y--)
		{
			if (cap[x][y] && dis[y] < dis[x] + pri[x][y])
			{
				flo[y] = min(flo[x], cap[x][y]);
				dis[y] = dis[x] + pri[x][y];
				par[y] = x;
				if (!inq[y])
				{
					inq[y] = true;
					q.emplace(y);
				}
			}
		}
	}
	return flo[f];
}

pair < int , int > maxcostflow(int s, int f)
{
	int flow = 0, new_flow, cost = 0;
	while((new_flow = find_path(s, f)))
	{
		flow += new_flow;
		int x = f;
		while(x != s)
		{
			int y = par[x];		
			swap(x, y);
			cost += new_flow * pri[x][y];
			cap[x][y] -= new_flow;
			cap[y][x] += new_flow;
		}
	}
	return {flow, cost};
}

int main()
{
	int n;
	cin >> n;
	int sa=0, sb=0;
	for (int i = 0; i < n; i++)
	{
		cin >> cap[0][i+1];
		sa += cap[0][i+1];
	}
	for (int i = 0; i < n; i++)
	{
		cin >> cap[maxn+i+1][maxv-1];
		sb += cap[maxn+i+1][maxv-1];
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			cap[i+1][maxn+j+1] = 1;
			cin >> pri[i+1][maxn+j+1];
			pri[maxn+j+1][i+1] = -pri[i+1][maxn+j+1];
		}

	if (sa != sb)
		cout << -1 << "\n";
	else
	{
		auto [flow, cost] = maxcostflow(0, maxv-1);
		if (flow < sa)
			cout << -1 << "\n";
		else
		{
			cout << cost << "\n";
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
