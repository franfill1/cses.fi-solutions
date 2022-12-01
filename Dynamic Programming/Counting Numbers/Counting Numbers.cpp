/*
Task:              2220 Counting Numbers
Sender:            franfill
Submission time:   2022-04-28 11:31:29
Language:          C++17
Result:            ACCEPTED
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main()
{
	string a, b;
	cin >> a >> b;
 
	int n = b.length();
	
	vector < ll > pows(n + 1, 1);
	for (int i = 1; i <= n; i++)
		pows[i] = 9 * pows[i-1];
 
	while(a.length() < n)
	{
		a = "0" + a;
	}
 
	int i = 0;
	while(i < n && a[i] == b[i])
	{
		if (i < n-1 && a[i] == a[i+1] && b[i] == b[i+1])
		{
			cout << 0 << "\n";
			return 0;
		}
		i++;
	}
 
	if (i == n)
	{
		cout << 1 << "\n";
		return 0;
	}
 
	ll ans = (b[i] - a[i] - 1 - (i > 0 && a[i-1] > a[i] && a[i-1] < b[i])) * pows[n-1];
 
	bool aok = true, bok = true;
 
	for (i++; i < n; i++)
	{
		if (aok) ans += pows[n - i - 1] * ('0' + 9 - a[i] - (a[i-1] > a[i]));
		if (bok) ans += pows[n - i - 1] * (b[i] - '0' - (b[i-1] < b[i]));
 
		if (a[i] == a[i-1] && a[i] != '0') aok = false;
		if (b[i] == b[i-1]) bok = false;
	}
	aok = true;
	i = 0;
	while(a[i] == '0') i++;
	for (;i < n-1; i++) if (a[i] == a[i+1]) aok = false;
	if (aok) ans++;
	bok = true;
	for (int i = 0; i < n-1; i++) if (b[i] == b[i+1]) bok = false;
	if (a!= b && bok) ans++;
	cout << ans << "\n";
}
