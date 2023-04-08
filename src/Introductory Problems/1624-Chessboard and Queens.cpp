/*
Task:              1624 Chessboard and Queens
Sender:            franfill
Submission time:   2021-06-30 11:47:04
Language:          C++11
Result:            ACCEPTED
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll ans = 0;
vector < string > c(8);
vector < bool > diag1(15, false);
vector < bool > diag2(15, false);
vector < bool > col(8, false);

void count(int y)
{
	if (y == 8) ans++;
	else
	{
		for (int x = 0; x < 8; x++)
		{
			if (c[x][y] != '*' && !col[x] && !diag1[x+y] && !diag2[x + 8 - y - 1])
			{
				col[x] = diag1[x+y] = diag2[x + 8 - y - 1] = true;
				count(y+1);
				col[x] = diag1[x+y] = diag2[x + 8 - y - 1] = false;
			}
		}
	}
}

int main()
{
	for (int i = 0; i < 8; i++) cin >> c[i];
	count(0);
	cout << ans;
}
