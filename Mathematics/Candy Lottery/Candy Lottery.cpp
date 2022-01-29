#include<bits/stdc++.h>
using namespace std;
typedef long double ld;

int main()
{
	int n, k;
	cin >> n >> k;
	ld s = 0;
	ld ans = 0;
	for (int c = 1; c <= k; c++)
	{
		ld p = pow(ld(c)/k, n) - pow(ld(c-1)/k, n);
		ans += p*c;
	}
	cout << fixed << setprecision(6) << ans << "\n";
}
