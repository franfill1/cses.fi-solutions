#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long N;
	cin >> N;
	long long l;
	cin >> l;
	long long ans = 0;
	for (int i = 1; i < N; i++)
	{
		long long el;
		cin >> el;
		if (el > l)
			l = el;
		else
			ans += l - el;
	}
	cout << ans;
}

