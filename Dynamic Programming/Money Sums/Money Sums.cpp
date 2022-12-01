/*
Task:              1745 Money Sums
Sender:            franfill
Submission time:   2021-07-19 15:36:32
Language:          C++11
Result:            ACCEPTED
*/
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;

	vector < int > x(n);
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> x[i];
		sum += x[i];
	}

	vector < bool > c(sum+1, false);
	c[0] = true;
	int ans = 0;

	for (int i = 0; i < n; i++)
	{
		for (int s = sum - x[i]; s >= 0; s--)
			if (c[s] && !c[s+x[i]])
			{ 
				ans++;
				c[s+x[i]] = true;
			}
	}

	cout << ans << "\n";

	for (int i = 1; i <= sum; i++)
		if (c[i]) cout << i << " ";
}
