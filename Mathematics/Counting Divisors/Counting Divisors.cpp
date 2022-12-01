/*
Task:              1713 Counting Divisors
Sender:            franfill
Submission time:   2021-11-25 10:50:08
Language:          C++17
Result:            ACCEPTED
*/
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	while(n--)
	{
		int x;
		cin >> x;
		int cnt = 0;
		for (int d = 1; d*d <= x; d++)
		{
			if (x % d == 0)
			{
				cnt += 2 - (d*d == x);
			}
		}
		cout << cnt << "\n";
	}
}
