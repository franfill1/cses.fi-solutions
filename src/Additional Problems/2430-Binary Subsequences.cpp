/*
Task:              2430 Binary Subsequences
Sender:            franfill
Submission time:   2023-04-19 13:09:49 +0300
Language:          C++17
Result:            ACCEPTED
*/
#include<bits/stdc++.h>
using namespace std;
 
int calc(int a, int b)
{
	if (a == 0 && b == 0)
		return 0;
	if (a == b)
		return 1<<30;
	int t = calc(b, a % (b+1));
	return t + a / (b+1);
}
 
int main()
{
	int n;
	cin >> n;
	int be = -1, bev = 1<<30;
	for (int i = 0; i*2 < n; i++)
	{
		int t = calc(i, n-i);
		if (t < bev)
			be = i, bev = t;
	}
 
	int a = be, b = n-be;
	string ans = "";
	while (a != 0 || b != 0)
		if (a > b)
			a -= b+1, ans += "1";
		else
			b -= a+1, ans += "0";
	cout << ans << "\n";
}
