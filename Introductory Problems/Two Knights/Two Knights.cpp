/*
Task:              1072 Two Knights
Sender:            franfill
Submission time:   2021-06-29 21:49:15
Language:          C++11
Result:            ACCEPTED
/*
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;

	long long sol = 0;
	cout << sol << "\n";
	for (long long i = 2; i <= n; i++)
	{
		sol = i * i * (i-1) / 2 + i*i*i*(i-1)/2;
		sol -= 2 * (i-1) * i - (i-1) * 4;
		sol -= 2 * (i-2) * i - 2 * (i-2);
		cout << sol << "\n";
	}
}
