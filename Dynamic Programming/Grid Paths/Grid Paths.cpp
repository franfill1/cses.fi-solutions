#include <bits/stdc++.h>
#define M 1000000007

using namespace std;

vector < string > ma;
vector < vector < int > > memo;

int dp (int i, int j)
{
	if (i >= memo.size() || j >= memo[0].size() || ma[i][j] == '*')
	{
		return 0;
	}
	else if (i == memo.size() - 1 && j == memo[0].size() - 1)
	{
		return 1;
	}
	else if (memo[i][j] != -1)
	{
		return memo[i][j];
	}
	else
	{
		memo[i][j] = dp(i+1, j) + dp(i, j+1);
		memo[i][j] %= M;
		return memo[i][j];
	}
}

int main()
{
	int N;
	cin >> N;
	ma.resize(N);
	memo.resize(N, vector < int > (N, -1));
	
	for (int i = 0; i < N; i++)
	{
		cin >> ma[i];
	}
	
	cout << dp(0, 0);
}

