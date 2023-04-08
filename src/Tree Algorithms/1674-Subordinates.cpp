/*
Task:              1674 Subordinates
Sender:            franfill
Submission time:   2021-02-08 12:05:59
Language:          C++11
Result:            ACCEPTED
*/
#include <bits/stdc++.h>

using namespace std;

vector < vector < int > > t;
vector < int > ans;

int dfs(int n)
{
	int a = 0;
	for (int i = 0; i < t[n].size(); i++)
	{
		a += dfs(t[n][i]);
	}
	ans[n] = a;
	return a+1;
}

int main()
{
	int N;
	cin >> N;
	t.resize(N);
	ans.resize(N);
	for (int i = 0; i < N-1; i++)
	{
		int el;
		cin >> el;
		el--;
		t[el].push_back(i+1);
	}
	dfs(0);
	for (int i = 0; i < N; i++)
	{
		cout << ans[i] << " ";
	}
}

