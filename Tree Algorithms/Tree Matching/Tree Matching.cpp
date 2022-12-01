/*
Task:              1130 Tree Matching
Sender:            franfill
Submission time:   2021-02-08 12:21:22
Language:          C++11
Result:            ACCEPTED
/*
#include <bits/stdc++.h>

using namespace std;

vector < vector < int > > t;
vector < vector < int > > memo;

int dp(int n, bool st, int from)
{
	if(memo[n][st] != -1)
	{
		return memo[n][st];
	}
	int ans = 0;
	int temp = 0;
	for (auto ne : t[n])
	{
		if (ne == from) continue;
		temp += dp(ne, 1, n);
	}
	ans = temp;
	if (st)
	{
		for (auto ne : t[n])
		{
			if (ne == from) continue;
			temp -= dp(ne, 1, n);
			temp += dp(ne, 0, n) + 1;
			ans = max(ans, temp);
			temp -= dp(ne, 0, n) + 1;
			temp += dp(ne, 1, n);
		}
	}
	memo[n][st] = ans;
	return ans;
}

int main()
{
	int N;
	cin >> N;
	t.resize(N);
	memo.resize(N, vector < int > (2, -1));
	for (int i = 0; i < N-1; i++)
	{
		int a, b;
		cin >> a >> b;
		a--; b--;
		t[a].push_back(b);
		t[b].push_back(a);
	}
	cout << dp(0, 1, -1);
}

