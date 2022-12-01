/*
Task:              1689 Knight's Tour
Sender:            franfill
Submission time:   2021-07-30 21:53:36
Language:          C++11
Result:            ACCEPTED
*/
#include<bits/stdc++.h>
using namespace std;

int t[8][8];

bool isValid(int y, int x)
{
	return (y >= 0 && y < 8 && x >= 0 && x < 8 && t[y][x] == 0);
}

int calc(int y, int x)
{
	if(!isValid(y, x)) return 9;

	int cnt = 0;
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			for (int k = 0; k < 2; k++)
			{
				int mx, my, nx, ny, np;

				mx = 2 * (i? 1 : -1); my = 1 * (j? 1 : -1);
				if (k) swap(mx, my);

				nx = x + mx; ny = y + my;
				cnt += isValid(ny, nx);
			}
		}
	}

	return cnt;
}


int main()
{
	int x, y; 
	cin >> x >> y;
	x--; y--;

	int c = 1;
	int p = 0;

	while(p != 9)
	{
		p = 9;
		t[y][x] = c++;
		pair < int , int > b;
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				for (int k = 0; k < 2; k++)
				{
					int mx, my, nx, ny, np;

					mx = 2 * (i? 1 : -1); my = 1 * (j? 1 : -1);
					if (k) swap(mx, my);

					nx = x + mx; ny = y + my;
					np = calc(ny, nx);
					if (np <= p)
					{
						p = np;
						b = {ny, nx};
					}
				}
			}
		}
		y = b.first; x = b.second;
	}

		
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			cout << t[i][j] << " ";
			if (t[i][j] < 10) cout << " ";
		}
		cout << "\n";
	}
}
