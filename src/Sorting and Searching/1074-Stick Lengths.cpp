/*
Task:              1074 Stick Lengths
Sender:            franfill
Submission time:   2021-11-03 15:21:31
Language:          C++17
Result:            ACCEPTED
*/
#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
 	int n;
 	cin >> n;
 	int p[n];
 	for (int i = 0; i < n; i++)
 	{
 		cin >> p[i];
	}
	
	sort(p, p+n);
	long long ans = 0;
	for (int i = 0; i < n; i++)
	{
		ans += abs(p[i] - p[n/2]);
	}
	cout << ans << "\n";
}

