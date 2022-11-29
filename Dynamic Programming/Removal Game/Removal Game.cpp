#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector < ll > v;
vector < vector < ll > > memo;

ll dp(int i, int j, ll sum)
{
	if (i == j) return 0;	
	else if (memo[i][j] != -1) return memo[i][j];
	else
	{
		memo[i][j] = sum - min(dp(i+1, j, sum - v[i]), dp(i, j-1, sum - v[j - 1]));
		return memo[i][j];
	}
}

int main()
{
	int n;
	cin >> n;
	v.resize(n);
	ll sum = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
		sum += v[i];
	}

	memo.resize(n+1, vector < ll > (n+1, -1));
	cout << dp(0, n, sum);
}

