/*
Task:              1618 Trailing Zeros
Sender:            franfill
Submission time:   2021-06-29 23:32:45
Language:          C++11
Result:            ACCEPTED
/*
#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long n;
	cin >> n;
	long long ans = 0;
	long long pow = 5;
	for (int i = 1; pow <= n; i++)
	{
		ans += n / pow;
		pow *= 5;
	}
	cout << ans;
}
