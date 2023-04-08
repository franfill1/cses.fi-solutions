/*
Task:              2168 Nested Ranges Check
Sender:            franfill
Submission time:   2021-07-03 13:37:37
Language:          C++11
Result:            ACCEPTED
*/
#include<bits/stdc++.h>
using namespace std;

struct range
{
	int x, y, p;
};

bool operator < (range a, range b)
{
	if (a.y == b.y) return a.x > b.x;
	return a.y < b.y;
}

int main()
{
	int n;
	cin >> n;

	vector < range > v;
	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		v.push_back({x, y, i});
	}

	sort(v.begin(), v.end());
	
	int l = -1;
	vector < int > c(n);
	
	for (int i = 0; i < n; i++)
	{
		c[v[i].p] = (l >= v[i].x);
		l = max(l, v[i].x);
	}
	for (bool b : c) cout << b << " ";
	cout << "\n";
	
	l = 1<<30;
	for (int i = n-1; i >= 0; i--)
	{
		c[v[i].p] = (l <= v[i].x);
		l = min(l, v[i].x);
	}
	for (bool b : c) cout << b << " ";
}
