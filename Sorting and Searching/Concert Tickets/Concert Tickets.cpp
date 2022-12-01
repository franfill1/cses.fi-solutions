/*
Task:              1091 Concert Tickets
Sender:            franfill
Submission time:   2021-07-02 15:39:10
Language:          C++11
Result:            ACCEPTED
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
	int n, m;
	cin >> n >> m;
	
	multiset < int > h;
	for (int i = 0; i < n; i++)
	{
		int el;
		cin >> el;
		h.insert(el);
	}

	while(m--)
	{
		int t;
		cin >> t;

		auto it = h.upper_bound(t);
		if (it != h.begin())
		{
			it--;
			cout << *it;
			h.erase(it);
		}
		else cout << -1;
		cout << "\n";
	}
}
