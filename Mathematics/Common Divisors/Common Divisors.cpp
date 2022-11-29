#include<bits/stdc++.h>
#define MAXX 1000001
using namespace std;

bool f[MAXX];

int main()
{
	int n;
	cin >> n;
	int ans = 1;
	while(n--)
	{
		int x;
		cin >> x;
		for (int d = 1; d*d <= x; d++)
		{
			if (x % d == 0)
			{
				if (f[d]) ans = max(ans, d);
				f[d] = 1;
				if (d*d != x)
				{
					if (f[x/d]) ans = max(ans, x/d);
					f[x/d] = 1;
				}
			}
		}
	}
	cout << ans << "\n";
}

