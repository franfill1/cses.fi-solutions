#include<bits/stdc++.h>
using namespace std;

int main()
{
	int N;
	cin >> N;
	vector < int > V(N);
	for (int i = 0; i < N; i++) cin >> V[i];

	sort(V.begin(), V.end());
	int ans = 0;
	int l = 0;
	for (int v : V)
	{
		if (v != l) ans++;
		l = v;
	}
	
	cout << ans;
}
