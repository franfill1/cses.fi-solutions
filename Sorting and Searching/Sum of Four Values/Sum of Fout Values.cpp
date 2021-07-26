#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	ll n, x;
	cin >> n >> x;

	vector < pair < ll , ll > > v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i].first;
		v[i].second = i+1;
	}
	sort(v.begin(), v.end());

	for (int z = 0; z < n; z++)
	{
		for (int w = z+1; w < n; w++)
		{
			if (z == w) continue;
			if (v[z].first + v[w].first > x) break;
			int j = n-1;
			while(j == z || j == w) j--; 
			for (int i = w+1; i < j; i++)
			{
				if (i == z || i == w) continue;
				
				while(v[i].first + v[j].first + v[z].first + v[w].first > x)
				{
					j--;
					while(j == z || j == w) j--;
				}
				
				if (j <= i) continue;

				if (v[i].first + v[j].first + v[z].first + v[w].first == x)
				{
					cout << v[i].second << " " << v[j].second << " " << v[z].second << " " << v[w].second;
					return 0;
				}
			}
		}
	}
	cout << "IMPOSSIBLE";
}
