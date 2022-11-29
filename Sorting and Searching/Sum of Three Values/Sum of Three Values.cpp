#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
	ll n, x;
	cin >> n >> x;
	
	vector < pair < ll , ll > > V(n);

	for (int i = 0; i < n; i++) 
	{
		cin >> V[i].first;
		V[i].second = i;
	}


	sort(V.begin(), V.end());

	for (int z = 0; z < n; z++)
	{
		ll j = n-1 - (z == n-1);
		for (int i = 0; i < j; i++)
		{
			if (i == z) 
			{
				i++;
				continue;
			}
			
			while(V[i].first + V[j].first + V[z].first > x)
			{
				j--;
				if (j == z) j--;
			}

			if (i == j) continue;

			if (V[i].first + V[j].first + V[z].first == x)
			{
				cout << V[i].second+1 << " " << V[j].second+1 << " " << V[z].second+1 << "\n";
				return 0;
			}
		}	
	}
	
	cout << "IMPOSSIBLE\n";
}

