#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
	int n, k;
	cin >> n >> k;

	map < ll , int > cnt;
	vector < ll > v(n);

	int i = 0;

	ll ans = 0;
	for (int j = 0; j < n; j++)
	{
		cin >> v[j];
		cnt[v[j]]++;	

		while(cnt.size() > k)
		{
			cnt[v[i]]--;
			if (cnt[v[i]] == 0) cnt.erase(v[i]);
			i++;
		}

		ans += j - i + 1;
	}
	cout << ans;
}
