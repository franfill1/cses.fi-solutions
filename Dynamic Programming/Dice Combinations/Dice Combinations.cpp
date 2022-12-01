/*
Task:              1633 Dice Combinations
Sender:            franfill
Submission time:   2021-03-17 18:45:48
Language:          C++11
Result:            ACCEPTED
/*
#include <bits/stdc++.h>
#define M 1000000007

using namespace std;

vector < int > memo;

int dp (int n)
{
	if (memo[n] != -1)
	{
		return memo[n];
	}
	else if (n == 0)
	{
		return 1;
	}
	else
	{
		memo[n] = 0;
		for (int i = 1; i <= 6; i++)
		{
			if (n - i >= 0)
			{
				memo[n] += dp(n-i);
				memo[n] %= M;
			}
		}
		return memo[n];
	}
}

int main()
{
	int N;
	cin >> N;
	
	memo.resize(N+1, -1);
	
	cout << dp(N);
}

