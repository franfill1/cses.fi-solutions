#include<bits/stdc++.h>
using namespace std;
typedef long double ld;

int main()
{
	int n;
	cin >> n;
	vector < int > r(n);
	for (int &x : r) cin >> x;
	ld ans = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = i+1; j < n; j++)
		{
			if (r[i] <= r[j])
			{
				ans += ld(r[i]-1)/(r[j]*2);
			}
			else
			{
				ans += ld(2*r[i]-r[j]-1)/(r[i]*2);
			}
		}
	}
	cout << fixed << setprecision(6) << ans << "\n";
}

