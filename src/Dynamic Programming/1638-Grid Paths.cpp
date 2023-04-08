/*
Task:              1638 Grid Paths
Sender:            franfill
Submission time:   2022-02-23 17:00:52
Language:          C++17
Result:            ACCEPTED
*/
#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;

int main()
{
	int N;
	cin >> N;
	vector < vector < char > > M(N);
	vector < vector < long long > > memo(N);
	
	for (int y = 0; y < N; y++)
	{
		M[y].resize(N);
		memo[y].resize(N);
	}

	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			cin >> M[x][y]; 
		}
	}
	
	if (M[0][0] == '.')
	{
		memo[0][0] = 1;
	}
	for (int x = 0; x < N; x++)
	{
		for (int y = 0; y < N; y++)
		{
			if (M[x][y] != '*')
			{
				if (x > 0)
				{
					memo[x][y] += memo[x-1][y];
					memo[x][y] %= mod;
				}
				if (y > 0)
				{
					memo[x][y] += memo[x][y-1];
					memo[x][y] %= mod;
				}
			}
		}
	}
	cout << memo[N-1][N-1] << "\n";
}

