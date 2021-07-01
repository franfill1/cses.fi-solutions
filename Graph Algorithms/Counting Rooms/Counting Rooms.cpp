#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;
	vector < string > m(N);
	for (int i = 0; i < N; i++)
	{
		cin >> m[i];
	}
	int ans = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (m[i][j] == '.')
			{
				ans++;
				queue < pair < int , int > > q;
				m[i][j] = '#';
				q.push(make_pair(i, j));
				while(!q.empty())
				{
					int x = q.front().first, y = q.front().second;
					q.pop();					
					vector < int > dx {0, 0, 1, -1};
					vector < int > dy {1, -1, 0, 0};
					
					for (int k = 0; k < 4; k++)
					{
						int nx = x + dx[k], ny = y + dy[k];
						if (nx >= 0 && nx < N && ny >= 0 && ny < M && m[nx][ny] == '.')
						{
							m[nx][ny] = '#';
							q.push(make_pair(nx, ny));
						}
					}
				}
			}
		}
	}
	cout << ans;
}

