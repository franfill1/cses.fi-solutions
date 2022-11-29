#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		int ans = 0, x;
		while(n--)
		{
			cin >> x;
			ans ^= x;
		}
		cout << (ans?"first":"second") << "\n";
	}
}

