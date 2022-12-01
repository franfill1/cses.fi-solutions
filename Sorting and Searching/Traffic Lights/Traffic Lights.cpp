/*
Task:              1163 Traffic Lights
Sender:            franfill
Submission time:   2021-07-03 00:04:27
Language:          C++11
Result:            ACCEPTED
*/
#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int x, n;
	cin >> x >> n;

	set < int > t {0, x};
	multiset < int > a {x};
	while(n--)
	{
		int p;
		cin >> p;
		auto it = t.upper_bound(p);
		int r = *(it--);
		int l = *it;
		
		a.erase(a.find(r-l));
		a.insert(p-l); a.insert(r-p);
		t.insert(p);

		it = a.end();
		cout << *(--it) << " ";
	}
}
