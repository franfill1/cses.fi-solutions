/*
Task:              1164 Room Allocation
Sender:            franfill
Submission time:   2021-07-03 15:40:57
Language:          C++11
Result:            ACCEPTED
*/
#include<bits/stdc++.h>
using namespace std;

struct person
{
	int a, b, p;
};

bool operator < (person a, person b)
{
	if (a.a == b.a) return a.b < b.b;
	return a.a < b.a;
}

int main()
{
	int n;
	cin >> n;
	vector < person > p;
	for (int i = 0; i < n; i++) 
	{
		int a, b;
		cin >> a >> b;
		p.push_back({a, b, i});
	}

	int ans = 0;
	vector < int > id(n);
	multimap < int , int > r;
	sort(p.begin(), p.end());

	for (int i  = 0; i < n; i++)
	{
		auto it = r.lower_bound(p[i].a);

		int room = r.size();
		if (it == r.begin()) ans++;
		else 
		{
			room = (*(--it)).second;
			r.erase(it);
		}

		id[p[i].p] = room+1;

		r.insert({p[i].b, room});
	}
	cout << ans << "\n";
	for (int r : id) cout << r << " ";
}
