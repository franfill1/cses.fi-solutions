/*
Task:              2419 Xor Pyramid
Sender:            franfill
Submission time:   2022-10-18 14:51:42
Language:          C++17
Result:            ACCEPTED
*/
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int N;
	cin >> N;
	vector < int > V(N);
	for (auto &x : V)
		cin >> x;

	int s = N-1;
	for (int p = 0; (1<<p) <= s; p++)
		if (s & (1<<p))
		{
			s -= 1<<p;
			N -= 1<<p;
			for (int i = 0; i < N; i++)
				V[i] ^= V[i+(1<<p)];
		}
	cout << V[0] << "\n";
}
