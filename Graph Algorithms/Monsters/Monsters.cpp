#include<bits/stdc++.h>
using namespace std;
typedef pair < int , int > ii;

vector < ii > moves {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
vector < char > names {'R', 'L', 'D', 'U'};

int main()
{
	int n, m;
	cin >> n >> m;

	queue < ii > q;
	queue < ii > e;
	
	vector < vector < int > > D(n, vector < int > (m, 1<<30));
	vector < vector < char > > M(n, vector < char > (m, ' '));
	vector < vector < ii > > B(n, vector < ii > (m, {0, 0}));
	
	ii st = {-1, -1};

	vector < string > lab(n);
	for (int i = 0; i < n; i++)
	{
		cin >> lab[i];
		for (int j = 0; j < m; j++)
		{
			if (lab[i][j] == 'M')
			{
				e.push({i, j});
				D[i][j] = 0;
			}
			else if (lab[i][j] == 'A')
			{
				q.push({i, j});
				st = {i, j};
			}
		}
	}


	while(!e.empty())
	{
		int x = e.front().first, y = e.front().second;
		e.pop();

		for (ii move : moves)
		{
			int nx = x + move.first, ny = y + move.second;
			if (nx >= 0 && nx < n && ny >= 0 && ny < m && lab[nx][ny] != '#' && D[nx][ny] > D[x][y] + 1)
			{
				D[nx][ny] = D[x][y] + 1;
				e.push({nx, ny});
			}	
		}
	}

	D[st.first][st.second] = 0;
	st = {-1, -1};
	while(!q.empty())
	{
		int x = q.front().first, y = q.front().second;
		q.pop();
		if (x == 0 || x == n-1 || y == 0 || y == m-1)
		{
			st = {x, y};
			break;
		}

		for (int i = 0; i < moves.size(); i++)
		{
			ii move = moves[i];
			int nx = x + move.first, ny = y + move.second;
			if (nx >= 0 && nx < n && ny >= 0 && ny < m)
			{
				if (lab[nx][ny] != '#' && D[nx][ny] > D[x][y] + 1)
				{
					D[nx][ny] = D[x][y] + 1;
					M[nx][ny] = names[i];
					B[nx][ny] = {x, y};
					q.push({nx, ny});
				}
			}
		}
	}

	if (st.first == -1)
	{
		cout << "NO\n";
	}
	else
	{
		cout << "YES\n";
		stack < char > l;	
		while(M[st.first][st.second] != ' ')
		{
			l.push(M[st.first][st.second]);
			st = B[st.first][st.second];
		}
		cout << l.size() << "\n";
		while(!l.empty())
		{
			cout << l.top(); l.pop();
		}
	}
}
