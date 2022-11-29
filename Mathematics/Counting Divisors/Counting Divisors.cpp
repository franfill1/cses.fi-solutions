#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	while(n--)
	{
		int x;
		cin >> x;
		int cnt = 0;
		for (int d = 1; d*d <= x; d++)
		{
			if (x % d == 0)
			{
				cnt += 2 - (d*d == x);
			}
		}
		cout << cnt << "\n";
	}
}

