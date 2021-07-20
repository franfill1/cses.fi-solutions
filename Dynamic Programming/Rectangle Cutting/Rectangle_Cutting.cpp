#include<bits/stdc++.h>
using namespace std;

vector < vector < int > > memo;

int dp(int b, int h)
{
	if (b > h) swap(b, h);
	if (b == h) return 0;
	else if (memo[b][h] != -1) return memo[b][h];
	else
	{
		memo[b][h] = 1<<30;
		for (int i = 1; i < b; i++)
		{
			memo[b][h] = min(memo[b][h], 1 + dp(i, h) + dp(b-i, h));
		}

		for (int i = 1; i < h; i++)
		{
			memo[b][h] = min(memo[b][h], 1 + dp(b, i) + dp(b, h-i));
		}

		return memo[b][h];
	}
}

int main()
{
	int a, b;
	cin >> a >> b;
	if (a > b) swap(a, b);
	memo.resize(b+1, vector < int > (b+1, -1));
	cout << dp(a, b) << "\n";
}
