#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

string s;
ll ans = 0;
const int N = 7;

bool M[N][N];

void prova(int x, int y, int m)
{
	if (x + N-1-y > N*N-1-m) return;
	else if (x == 0 && y == N-1 && m == N*N-1)
	{
		 ans++;
		 return;
	}
	else if (x == 0 && y == N-1) return;
	else if (m == N*N-1) return;
	else if (x > 0 && x < N-1 && !M[y][x+1] && !M[y][x-1] && ((y == 0 && M[y+1][x]) || (y == N-1 && M[y-1][x]))) return;
	else if (y > 0 && y < N-1 && !M[y+1][x] && !M[y-1][x] && ((x == 0 && M[y][x+1]) || (x == N-1 && M[y][x-1]))) return;
	else if (y > 0 && y < N-1 && x > 0 && x < N-1 && !M[y][x-1] && !M[y][x+1] && M[y+1][x] && M[y-1][x]) return;
	else if (y > 0 && y < N-1 && x > 0 && x < N-1 && !M[y-1][x] && !M[y+1][x] && M[y][x+1] && M[y][x-1]) return;
	else 
	{
		M[y][x] = 1;
		if (s[m] != '?')
		{
			char c = s[m];
			if (x < N-1 && !M[y][x+1] && c == 'R')
				prova(x+1, y, m+1);
			if (x > 0 && !M[y][x-1] && c == 'L')
				prova(x-1, y, m+1);
			if (y < N-1 && !M[y+1][x] && c == 'D')
				prova(x, y+1, m+1);
			if (y > 0 && !M[y-1][x] && c == 'U')
				prova(x, y-1, m+1);
		}
		else
		{
			if (x < N-1 && !M[y][x+1])
				prova(x+1, y, m+1);
			if (x > 0 && !M[y][x-1])
				prova(x-1, y, m+1);
			if (y < N-1 && !M[y+1][x])
				prova(x, y+1, m+1);
			if (y > 0 && !M[y-1][x])
				prova(x, y-1, m+1);
		}
		M[y][x] = 0;
	}
}

int main()
{
	cin >> s;
	prova(0, 0, 0);
	cout << ans;
}
