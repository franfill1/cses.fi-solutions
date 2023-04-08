/*
Task:              2088 Knuth Division
Sender:            franfill
Submission time:   2022-10-15 20:49:38
Language:          C++17
Result:            ACCEPTED
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
	int N;
	cin >> N;
	vector < ll > v(N);
	vector < ll > pre(1, 0);
	for (auto &x : v)
	{
		cin >> x;
		pre.emplace_back(pre.back() + x);
	}
	vector < vector < ll > > dp(N, vector < ll > (N+1, 1ll<<60)), opt(N, vector < ll > (N+1, 0));
	for (int l = 1; l <= N; l++)
		for (int i = 0, j = l; j <= N; i++, j++)
		{
			if (l == 1)
			{
				dp[i][j] = 0, opt[i][j] = i;
				continue;
			}
			for (int k = max(opt[i][j-1], (ll)i+1); k < min(opt[i+1][j]+1, (ll)j); k++)
			{
				if (dp[i][k] + dp[k][j] < dp[i][j])
					opt[i][j] = k, dp[i][j] = dp[i][k] + dp[k][j];
			}
			dp[i][j] += pre[j] - pre[i];		
		}
	cout << dp[0][N];
}
