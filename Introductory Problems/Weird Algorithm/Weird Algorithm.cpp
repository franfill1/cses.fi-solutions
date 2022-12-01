/*
Task:              1068 Weird Algorithm
Sender:            franfill
Submission time:   2021-06-29 16:24:04
Language:          C++11
Result:            ACCEPTED
/*
#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long n;
	cin >> n;
	cout << n << " ";
	while(n != 1)
	{
		if (n % 2)
			n = n*3+1;
		else
			n /= 2;
		cout << n << " ";
	}
}
