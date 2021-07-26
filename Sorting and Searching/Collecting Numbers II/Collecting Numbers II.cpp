#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;

	vector < int > x(n);
	for (int i = 0; i < n; i++)
	{
		 cin >> x[i];
		 x[i]--;
	}

	vector < int > p(n);
	for (int i = 0; i < n; i++) p[x[i]] = i;

	int l = -1, ans = 1;
	for (int i = 0; i < n; i++)
	{
		if (p[i] < l) ans++;
		l = p[i];
	}

	while (m--)
	{
		int a, b;
		cin >> a >> b; a--; b--;
		if (a > b) swap(a, b);
		assert(p[x[a]] == a && p[x[b]] == b);
		if (x[a] > 0 && p[x[a]-1] > a && p[x[a]-1] < b) ans--;
		if (x[a] < n-1 && p[x[a]+1] > a && p[x[a]+1] < b) ans++;
		if (x[b] > 0 && p[x[b]-1] > a && p[x[b]-1] < b) ans++;
		if (x[b] < n-1 && p[x[b]+1] > a && p[x[b]+1] < b) ans--;

		if (x[a] == x[b]-1) ans++;
		if (x[b] == x[a]-1) ans--;
		p[x[a]] = b; p[x[b]] = a;
		swap(x[a], x[b]);
		cout << ans << "\n";
	}
}
