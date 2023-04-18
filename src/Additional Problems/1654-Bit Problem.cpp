/*
Task:              1654 Bit Problem
Sender:            franfill
Submission time:   2023-04-08 13:58:20
Language:          C++17
Result:            ACCEPTED
*/
#include<bits/stdc++.h>
using namespace std;
const int P = 20, maxv = 1<<P, mask=maxv-1;

int dp1[maxv][P+1], dp2[maxv][P+1];

int main()
{
	int n;
	cin >> n;
	vector < int > v(n);
	for (auto &x : v)
	{
		cin >> x;
		dp1[x][0]++, dp2[x][0]++;
	}
	for (int x = 0; x < maxv; x++)
		for (int p = 0; p < P; p++)
			dp1[x][p+1] = dp1[x][p] + (x&(1<<p) ? dp1[x^(1<<p)][p] : 0);
	for (int x = maxv-1; x >= 0; x--)
		for (int p = 0; p < P; p++)
			dp2[x][p+1] = dp2[x][p] + (x&(1<<p) ? 0 : dp2[x^(1<<p)][p]);
	
	for (auto &x : v)
		cout << dp1[x][P] << " " << dp2[x][P] << " " << n - dp1[mask&~x][P] << "\n";
}
