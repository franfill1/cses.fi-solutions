#include <bits/stdc++.h>
#define M 1000000007

using namespace std;

vector < int > coins;
vector < int > memo;

int dp (int x)
{
	if (x < 0)
	{
		return 0;
	}
	else if (x == 0)
	{
		return 1;
	}
	else if (memo[x] != -1)
	{
		return memo[x];
	}
	else
	{
		memo[x] = 0;
		for (int coin : coins)
		{
			memo[x] += dp(x - coin);
			memo[x] %= M;
		}
		return memo[x];
	}
}

int main()
{
	int N, X;
	cin >> N >> X;
	
	coins.resize(N);
	memo.resize(X+1, -1);
	for (int i = 0; i < N; i++)
	{
		cin >> coins[i];
	}
	
	cout << dp(X);
}

