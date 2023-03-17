/*
Task:              1665 Coding Company
Sender:            franfill
Submission time:   2023-03-13 13:23:39
Language:          C++17
Result:            ACCEPTED
*/
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
using ll = long long;
constexpr ll mod = 1000000007;
constexpr ll maxk = 5000;

ll dp[101][51][2*maxk+1];
int main()
{
	int n, K;
	cin >> n >> K;
	K += maxk;
	vector < ll > v(n);
	for (auto &x : v)
		cin >> x;
	sort(v.begin(), v.end());
	for (int k=0; k <= K; k++)
		dp[n][0][k] = 1;
	for (int i = n-1; i >= 0; i--)
		for (int o = 0; o <= 50; o++)
			for (int k = 0; k <= 2*maxk; k++)
			{
				dp[i][o][k] = (o+1)*dp[i+1][o][k] % mod;
				if (o && k + v[i] <= 2*maxk)
					dp[i][o][k] += dp[i+1][o-1][k+v[i]] * o % mod;
				if (o < 50 && k - v[i] >= 0)
					dp[i][o][k] += dp[i+1][o+1][k-v[i]];
				dp[i][o][k] %= mod;
			}
	cout << dp[0][0][maxk] << "\n";
}
