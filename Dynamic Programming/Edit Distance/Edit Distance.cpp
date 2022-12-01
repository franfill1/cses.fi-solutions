/*
Task:              1639 Edit Distance
Sender:            franfill
Submission time:   2021-07-19 15:19:25
Language:          C++11
Result:            ACCEPTED
*/
#include<bits/stdc++.h>
using namespace std;

string a, b;

vector < vector < int > > memo;

int dp(int i, int j)
{
	if (i == a.size() && j == b.size()) return 0;
	else if (i > a.size() || j > b.size()) return 1<<30;
	if (memo[i][j] != -1) return memo[i][j];
	else 
	{
		memo[i][j] = min(dp(i+1, j) + 1, dp(i, j+1) + 1);
		memo[i][j] = min(memo[i][j], dp(i+1, j+1) + (a[i] != b[j]));

		return memo[i][j];
	}
}

int main()
{
	cin >> a >> b;

	if (a.size() > b.size()) swap(a, b);

	memo.resize(a.size()+1, vector < int > (b.size()+1, -1));
	
	cout << dp(0, 0);
}
