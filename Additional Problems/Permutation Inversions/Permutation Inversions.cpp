/*
Task:              2229 Permutation Inversions
Sender:            franfill
Submission time:   2022-12-02 19:17:07
Language:          C++17
Result:            ACCEPTED
*/
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
constexpr int MOD = 1000000007;
int dp[510][501*250+10];
int pre[510][501*250+20];
int main()
{
	int n, k;
	cin >> n >> k;
	dp[0][0] = 1;
	pre[0][1] = 1;
	for (ll i = 1; i <= n; i++)
		for (ll c = 0; c <= k; c++)
		{
			if (c <= i*(i-1)/2)
			{
				if (i > c)
					dp[i][c] = pre[i-1][c+1];
				else
					dp[i][c] = (pre[i-1][c+1] - pre[i-1][c-i+1] + MOD) % MOD;
			}
			pre[i][c+1] = (pre[i][c] + dp[i][c]) % MOD;
		}
	cout << dp[n][k]<< "\n";
}
