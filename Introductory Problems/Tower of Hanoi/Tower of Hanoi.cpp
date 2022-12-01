/*
Task:              2165 Tower of Hanoi
Sender:            franfill
Submission time:   2021-06-30 00:44:37
Language:          C++11
Result:            ACCEPTED
/*
#include<bits/stdc++.h>
using namespace std;

void move(int n, int from, int to)
{
	if (n == 0)
		return;
	else
	{
		move(n-1, from, 6 - from - to);
		cout << from << " " << to << "\n";
		move(n-1, 6 - from - to, to);
	}
}

int main()
{
	int n;
	cin >> n;
	cout << (1ll<<n)-1 << "\n";
	move(n, 1, 3);
}
