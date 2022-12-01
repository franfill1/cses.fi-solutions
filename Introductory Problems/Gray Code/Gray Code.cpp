/*
Task:              2205 Gray Code
Sender:            franfill
Submission time:   2021-06-30 00:33:17
Language:          C++11
Result:            ACCEPTED
/*
#include<bits/stdc++.h>
using namespace std;

int v = 0;
int N;

void print()
{
	for (int i = 0; i < N; i++)
		cout << ((v & (1<<i))>>i);
	cout << "\n";
}

void genGray(int n)
{
	if (n == 0) print();
	else
	{
		genGray(n-1);
		v ^= 1<<(n-1);
		genGray(n-1);
	}
}

int main()
{
	cin >> N;
	genGray(N);
}
