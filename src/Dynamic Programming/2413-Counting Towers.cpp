/*
Task:              2413 Counting Towers
Sender:            franfill
Submission time:   2021-07-19 14:57:23
Language:          C++11
Result:            ACCEPTED
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll M = 1000000007;

vector < vector < ll > > memo(2, vector < ll > (0));

ll calc(bool w, int n)
{
	if (n == 1) return 1;
	else if (memo[w][n] != -1)
		return memo[w][n];
	else
	{
		memo[w][n] = 0;
		if (w == 0)
		{
			memo[w][n] = (calc(0, n-1) * 2)%M + calc(1, n-1)%M;
			memo[w][n] %= M;
		}
		else
		{
			memo[w][n] = calc(0, n-1)%M + 4 * calc(1, n-1)%M;
			memo[w][n] %= M;
		}
		return memo[w][n];
	}
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;

		memo[0].resize(n+1, -1);
		memo[1].resize(n+1, -1);

		cout << (calc(0, n) + calc(1, n))%M << "\n";
	}
}
