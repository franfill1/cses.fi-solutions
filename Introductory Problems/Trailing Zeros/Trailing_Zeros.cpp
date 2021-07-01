#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long n;
	cin >> n;
	long long ans = 0;
	long long pow = 5;
	for (int i = 1; pow <= n; i++)
	{
		ans += n / pow;
		pow *= 5;
	}
	cout << ans;
}
