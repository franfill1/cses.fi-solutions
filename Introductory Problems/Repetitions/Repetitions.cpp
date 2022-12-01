/*
Task:              1069 Repetitions
Sender:            franfill
Submission time:   2021-06-29 16:27:42
Language:          C++11
Result:            ACCEPTED
*/
#include<bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	cin >> s;
	int rep;
	int ans = 0;
	char l = ' ';
	for (char c : s)
	{
		if (c != l)
			rep = 0;
		rep++;
		ans = max(ans, rep);
		l = c;
	}
	cout << ans;
}
