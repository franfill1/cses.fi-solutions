#include <bits/stdc++.h>

using namespace std;

int N, M;
vector < string > m;
vector < string > ans;
vector < vector < int > > D;
int sx, sy;
int fx, fy;
int inf = 1<<30;

int main()
{
	cin >> N >> M;
	m.resize(N);
	ans.resize(N);
	D.resize(N, vector < int > (M, inf));
	for (int i = 0; i < N; i++)
	{
		cin >> m[i];
		for (int j = 0; j < M; j++)
		{
			ans[i] += ' ';
			if (m[i][j] == 'A')
			{
				m[i][j] = '.';
				sx = i; sy = j;
			}
			if (m[i][j] == 'B')
			{
				fx = i; fy = j;
			}
		}
	}
	
	queue < pair < int , int > > q;
	q.push(make_pair(fx, fy));
	D[fx][fy] = 0;
	while(!q.empty())
	{
		int x = q.front().first, y = q.front().second;
		q.pop();					
		vector < int > dx {0, 0, 1, -1};
		vector < int > dy {1, -1, 0, 0};
		vector < int > mov {'L', 'R', 'U', 'D'};
		
		for (int k = 0; k < 4; k++)
		{
			int nx = x + dx[k], ny = y + dy[k];
			if (nx >= 0 && nx < N && ny >= 0 && ny < M && m[nx][ny] == '.')
			{
				D[nx][ny] = D[x][y] + 1;
				ans[nx][ny] = mov[k];
				m[nx][ny] = '#';
				q.push(make_pair(nx, ny));
			}
		}
	}
	
	map < char , int > movX {{'D', 1}, {'U', -1}};
	map < char , int > movY {{'R', 1}, {'L', -1}};
	
	int x = sx, y = sy;
	if (m[x][y] == '#')
	{
		cout << "YES\n" << D[x][y] << "\n";
		while(x != fx || y != fy)
		{
			cout << ans[x][y];
			int nx = x + movX[ans[x][y]];
			int ny = y + movY[ans[x][y]];
			x = nx; y = ny;
		}
	}
	else
	{
		cout << "NO\n";
	}

}

