/*
Task:              1746 Array Description
Sender:            franfill
Submission time:   2021-03-17 23:59:10
Language:          C++11
Result:            ACCEPTED
*/
#include <bits/stdc++.h>
#define MD 1000000007

using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;
	
	vector < int > v(N);
	for (int i = 0; i < N; i++)
	{
		cin >> v[i];
	}
	vector < vector < int > > memo(N, vector < int > (M+1, 0));
	
	int ans = 0;
	if (v[0] == 0)
	{
		for (int i = 1; i <= M; i++)
		{
			memo[0][i] = 1;
			ans++;
 		}
	}
	else
	{
		memo[0][v[0]] = 1;
		ans++;
	}
	

	for (int i = 1; i < N; i++)
	{
		ans = 0;
		if (v[i] == 0)
		{
			for (int j = 1; j <= M; j++)
			{
				memo[i][j] = memo[i-1][j-1] + memo[i-1][j];
				memo[i][j] %= MD;
				if (j < M) memo[i][j] += memo[i-1][j+1];
				memo[i][j] %= MD;
				
				ans += memo[i][j];
				ans %= MD;
			}
		}
		else
		{
			memo[i][v[i]] = memo[i-1][v[i]-1] + memo[i-1][v[i]];
			memo[i][v[i]] %= MD;
			if (v[i] < M) memo[i][v[i]] += memo[i-1][v[i]+1];
			memo[i][v[i]] %= MD;
			
			ans = memo[i][v[i]];
			ans %= MD;
		}
	}
	
	cout << ans;
}

