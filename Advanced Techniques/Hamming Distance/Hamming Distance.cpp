/*
Task:              2136 Hamming Distance
Sender:            franfill
Submission time:   2022-11-29 19:52:03
Language:          C++17
Result:            ACCEPTED
*/
#include<bits/stdc++.h>
using namespace std;

int l[20000];

int main()
{
	int n, k, x, ans;
	char c;
	cin >> n >> k;
	ans = k;
	for (int i = 0; i < n; i++)
	{
		x = 0;
		for (int j = 0; j < k; j++)
		{
			cin >> c;	
			x<<=1;
			x += c - '0';
		}
		l[i] = x;
		for (int j = 0; j < i; j++)
			ans = min(ans, __builtin_popcount(x ^ l[j]));
	}
	cout << ans << "\n";
}
