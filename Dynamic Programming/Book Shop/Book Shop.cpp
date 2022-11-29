#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N, X;
	cin >> N >> X;
	
	vector < int > h(N);
	for (int i = 0; i < N; i++)
	{
		cin >> h[i];
	}
	
	vector < int > s(N);
	for (int i = 0; i < N; i++)
	{
		cin >> s[i];
	}
	
	vector < vector < int > > memo(N+1, vector < int > (X + 1));
	
	for (int x = 0; x <= X; x++)
	{
		memo[0][x] = 0;	
	}
	for (int n = 0; n <= N; n++)
	{
		memo[n][0] = 0;
	}
	
	for (int n = 1; n <= N; n++)
	{
		for (int x = 1; x <= X; x++)
		{
			memo[n][x] = memo[n-1][x];
			if (x >= h[n-1])
			{
				memo[n][x] = max(memo[n][x], memo[n-1][x - h[n-1]] + s[n-1]);
			}
		}
	}
	
	cout << memo[N][X];
}


