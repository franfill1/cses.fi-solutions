#include <bits/stdc++.h>

int INF = 1<<30;

using namespace std;

vector < int > memo;
vector < int > coins;

int dp (int x)
{
	if (x < 0)
	{
		return INF;
	}
	else if (memo[x] != -1)
	{
		return memo[x];
	}
	else if (x == 0)
	{
		return 0;
	}
	else
	{
		memo[x] = INF;
		for (int coin : coins)
		{
			if (x - coin >= 0)
			{
				memo[x] = min(memo[x], dp(x - coin) + 1);
			}
		}
		return memo[x];
	}
}

int main()
{
	int N, X;
	cin >> N >> X;
	
	memo.resize(X+1, -1);
	coins.resize(N);
	
	for (int i = 0; i < N; i++)
	{
		cin >> coins[i];
	}
	
	cout << (dp(X) == INF ? -1 : dp(X));
}

