#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

int main()
{
	int n;
	int a, b;
	cin >> n >> a >> b;
	vector < ld > v(b+1, 0);
	v[0] = 1;
	for (int i = 0; i < n; i++)
	{
		vector < ld > bf(b+1, 0);
		for (int j = 0; j < b; j++)
		{
			for (int k = 1; k <= 6 && j+k <= b; k++)
			{
				bf[j+k] += v[j] / 6;
			}
		}
		v = bf;
	}
	ld ans = 0;
	for (int i = a; i <= b; i++)
	{
		ans += v[i];
	}
	cout << setprecision(6) << fixed << ans << "\n"; 
}
