#include<bits/stdc++.h>
using namespace std;
typedef long double ld;

int main()
{
	int k;
	cin >> k;
	vector < array < array < ld , 8 > , 8 > > m(64);
	for (int i = 0; i < 64; i++)
	{
		int x = i % 8, y = i / 8;
		for (int x = 0; x < 8; x++) for (int y = 0; y < 8; y++) assert(m[i][x][y] == 0);
		m[i][x][y] = 1;
		for (int j = 0; j < k; j++)
		{
			array < array < ld , 8 > , 8 > b;
			for (int x = 0; x < 8; x++) for (int y = 0; y < 8; y++) b[x][y] = 0;
			for (int x = 0; x < 8; x++)
			{
				for (int y = 0; y < 8; y++)
				{
					int c = 2 + (x != 0 && x != 7) + (y != 0 && y != 7);
					ld n = m[i][x][y] / c;
					if (x != 0) b[x-1][y] += n;
					if (x != 7) b[x+1][y] += n;
					if (y != 0) b[x][y-1] += n;
					if (y != 7) b[x][y+1] += n;
				}
			}
			ld a = 0;
			for (int x = 0; x < 8; x++) for (int y = 0; y < 8; y++) a += b[x][y];
			m[i] = b;
		}
	}

	ld ans = 0;
	for (int x = 0; x < 8; x++)
	{
		for (int y = 0; y < 8; y++)
		{
			ld temp = 1;
			for (int i = 0; i < 64; i++)
			{
				temp *= ld(1) - m[i][x][y];
			}
			ans += temp;
		}
	}
	cout << fixed << setprecision(6) << ans << "\n";
}

