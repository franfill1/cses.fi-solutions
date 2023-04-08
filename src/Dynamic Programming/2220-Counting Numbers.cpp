/*
Task:              2220 Counting Numbers
Sender:            franfill
Submission time:   2023-02-21 09:40:18
Language:          C++17
Result:            ACCEPTED
*/
#include<bits/stdc++.h>
#define int long long
using namespace std;

string a, b;
vector < vector < vector < vector < vector < int > > > > > memo;

int calc(int i, bool gt, bool le, bool beg, int last)
{
	if (i == a.size())
		return 1;
	if (memo[i][gt][le][beg][last] != -1)
		return memo[i][gt][le][beg][last];
	int mi = 0, ma = 9;
	if (gt)
		mi = a[i] - '0';
	if (le)
		ma = b[i] - '0';
	assert(mi <= ma);
	
	int ans = 0;
	for (int c = mi; c <= ma; c++)
	{
		if (i != 0 && c == last && (c != 0 || beg))
			continue;
		ans += calc(i+1, gt && (c == mi), le && (c == ma), beg || (c != 0), c);
	}
	return memo[i][gt][le][beg][last] = ans;
}

main()
{
	cin >> a >> b;
	int n = b.size();
	a = string(n-a.size(), '0') + a;
	
	memo.resize(n, vector < vector < vector < vector < int > > > > (2, 
				   vector < vector < vector < int > > > (2, 
				   vector < vector < int > > (2,
				   vector < int > (10, -1)))));
	cout << calc(0, true, true, false, 0) << "\n";
}

