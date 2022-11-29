#include<bits/stdc++.h>
#define maxn 1222 
using namespace std;

int main()
{
	int t;
	cin >> t;
	vector < int > v(maxn+1, 0);
	for (int i = 3; i <= maxn; i++)
	{
		vector < bool > b(maxn, 0);
		for (int j = i-1; j > i/2; j--)
		{
			b[v[j]^v[i-j]] = 1;
		}
		v[i] = 0;
		while(b[v[i]]) v[i]++;
	}

	while(t--)
	{
		int n;
		cin >> n;
		if (n > maxn) cout << "first\n";
		else cout << (v[n]?"first":"second") << "\n";
	}
}

