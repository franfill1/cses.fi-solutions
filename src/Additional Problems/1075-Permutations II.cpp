/*
Task:              1075 Permutations II
Sender:            franfill
Submission time:   2023-06-14 19:24:21 +0300
Language:          C++17
Result:            ACCEPTED
*/
#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const ll mod = 1000000007;
const int maxn = 1000;
ll dp[maxn+1][maxn+1][3];

int main()
{
	int n;
	cin >> n;

	dp[0][0][0] = 1;
	for (int i = 0; i < n; i++)
	{
		for (int comp = 0; comp < n; comp++)
		{
			dp[i+1][comp+1][2] = (dp[i][comp][0] + dp[i][comp][1] + dp[i][comp][2]) % mod;
			dp[i+1][comp][1] = (dp[i][comp][0] * comp * 2 % mod + dp[i][comp][1] * (comp*2-1) % mod + dp[i][comp][2] * (comp*2-2) % mod) % mod;
			dp[i+1][comp-1][0] = (dp[i][comp][0] * (comp)*(comp-1) % mod +
													 dp[i][comp][1] * (comp-1)*(comp-1) % mod +
													 dp[i][comp][2] * (comp-1)*(comp-2) % mod) % mod;
		}
	}

	assert(n == 1 || dp[n][1][2] == 0);
	cout << (dp[n][1][0] + dp[n][1][1] + dp[n][1][2]) % mod << "\n";
}
