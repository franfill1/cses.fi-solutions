#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int a, b;
		cin >> a >> b;
		if (a > b) swap(a, b);
		if (a < b - a)
		{
			cout << "NO\n";
		}
		else
		{
			a = b = 2*a-b;
			if (a % 3)
				cout << "NO\n";
			else
				cout << "YES\n";
		}
	}
}
