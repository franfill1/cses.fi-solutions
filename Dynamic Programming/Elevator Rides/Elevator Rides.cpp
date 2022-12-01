/*
Task:              1653 Elevator Rides
Sender:            franfill
Submission time:   2021-07-20 12:04:32
Language:          C++11
Result:            ACCEPTED
/*
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair < ll , ll > pll;

vector < ll > w;
ll x;
vector < pll > memo;
int n;

pll dp (int sub)
{
	if (sub == 0)
		return {1, 0};
	else if (memo[sub].first != -1)
		return memo[sub];
	else
	{
		memo[sub] = {n+1, 0};
		for (int p = 0; p < n; p++)
		{
			if ((1<<p) & sub)
			{
				pll temp = dp(sub - (1<<p));
				if (temp.second + w[p] <= x)
				{
					temp.second += w[p];
				}
				else
				{
					temp.first++;
					temp.second = w[p];
				}
				memo[sub] = min(memo[sub], temp);
			}
		}
		return memo[sub];
	}
}

int main()
{
	cin >> n >> x;

	w.resize(n);
	memo.resize(1<<(n), {-1, 0});

	for (int i = 0; i < n; i++)
	{
		cin >> w[i];
	}
	
	cout << dp((1<<n)-1).first;
}
