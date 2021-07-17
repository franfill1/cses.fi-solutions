#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector < pair < int , int > > V(n);
	for (int i = 0; i < n; i++) cin >> V[i].second >> V[i].first;
	sort(V.begin(), V.end());

	int t = 0;
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		if (V[i].second >= t)
		{
			ans++;
			t = V[i].first;
		}
	}

	cout << ans;
}
