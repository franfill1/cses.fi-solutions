#include <bits/stdc++.h>
#define M 1000000007

using namespace std;

vector < int > coins;

vector < vector < int > > memo;

int main()
{
	int N, X;
	cin >> N >> X;
	
	coins.resize(N);
	for (int i = 0; i < N; i++)
	{
		cin >> coins[i];
	}
	
	memo.resize(N+1, vector < int > (X + 1, -1));
	
	for (int x = 1; x <= X; x++)
	{
		memo[0][x] = 0;
	}
	
	for (int n = 0; n <= N; n++)
	{
		memo[n][0] = 1;
	}
	
	for (int n = 1; n <= N; n++)
	{
		for (int x = 1; x <= X; x++)
		{
			memo[n][x] = memo[n-1][x];
			if (x - coins[n-1] >= 0)
			{
				memo[n][x] += memo[n][x - coins[n-1]];
			}
			memo[n][x] %= M;
		}
	}
	
	cout << memo[N][X];
}

