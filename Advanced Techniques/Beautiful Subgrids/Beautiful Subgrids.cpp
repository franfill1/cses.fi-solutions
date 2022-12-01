/*
Task:              2137 Beautiful Subgrids
Sender:            franfill
Submission time:   2022-11-29 20:02:18
Language:          C++17
Result:            ACCEPTED
*/
#include<bits/stdc++.h>
#pragma GCC target("popcnt")
using namespace std;
bitset < 3000 > g[3000];
int main()
{
	int c;
	c = getchar_unlocked();
	int n = 0;
	while(c != '\n')
	{
		n *= 10;
		n += c - '0';
		c = getchar_unlocked();
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			c = getchar_unlocked();
			if (c == '1')
				g[i].set(j, 1);
		}
		c = getchar_unlocked();
	}
	long long ans = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < i; j++)
		{
			long long x = (g[i] & g[j]).count();
			ans += x*(x-1)/2;
		}
	cout << ans << "\n";
}
