#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll M = 1000000007;

int main()
{
	int n;
	cin >> n;
	
	int sum = n * (n+1) / 2;

	if (sum % 2)
	{
		cout << 0 << "\n";
	}
	else
	{
		ll tar = sum / 2;

		vector < ll > cnt(tar+1, 0);
		cnt[0] = 1;

		for (int i = 1; i < n; i++)
		{
			for (int s = tar - i; s >= 0; s--)
			{
				cnt[s + i] += cnt[s];
				cnt[s + i] %= M;
			}
		}
		cout << cnt[tar] << "\n";
	}
}

