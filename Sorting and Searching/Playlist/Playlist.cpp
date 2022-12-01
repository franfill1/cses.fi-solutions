/*
Task:              1141 Playlist
Sender:            franfill
Submission time:   2021-07-02 23:48:43
Language:          C++11
Result:            ACCEPTED
*/
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	
	vector < int > k(n);
	for (int i = 0; i < n; i++) cin >> k[i];

	int a = 0;
	set < int > u;
	u.insert(k[0]);

	int ans = 1;

	for (int b = 1; b < n; b++)
	{
		while(u.count(k[b])) u.erase(k[a++]);
		u.insert(k[b]);
		ans = max(ans, (int)u.size());
	}

	cout << ans;
}
