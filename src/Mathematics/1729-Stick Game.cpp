/*
Task:              1729 Stick Game
Sender:            franfill
Submission time:   2022-01-28 20:37:04
Language:          C++17
Result:            ACCEPTED
*/
#include<bits/stdc++.h>
using namespace std;
int p[100];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	bitset < 1000001 > s;
	int n, k, i, j;
	cin >> n >> k;
	for (i = 0; i < k; i++) 
	{
		cin >> p[i];
		s.set(p[i]);
	}
	sort(p, p+k);

	for (i = 1; i <= n; i++)
	{
		if (s.test(i))
		{
			putchar_unlocked('W');
		}
		else
		{
			putchar_unlocked('L');
			for (j = 0; j < k; j++) 
			{
				if (i + p[j] > n) break;
				s.set(i + p[j]);
			}
		}
	}
}
