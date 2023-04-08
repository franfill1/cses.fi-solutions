/*
Task:              1131 Tree Diameter
Sender:            franfill
Submission time:   2021-02-08 13:00:19
Language:          C++11
Result:            ACCEPTED
*/
#include <bits/stdc++.h>

using namespace std;

vector < vector < int > > t;
vector < int > ans;

int diam(int n, int from)
{
	int a1 = 0, a2 = 0;
	for (auto ne : t[n])
	{
		if (ne != from)
		{
			int temp = diam(ne, n);
			if (temp > a1)
			{
				a2 = a1;
				a1 = temp;
			}
			else if (temp > a2)
			{
				a2 = temp;
			}
		}
	}
	ans[n] = a1 + a2;
	return (a1 + 1);
}

int main()
{
	int N;
	cin >> N;
	t.resize(N);
	ans.resize(N);
	for (int i = 0; i < N - 1; i++)
	{
		int a, b;
		cin >> a >> b;
		a--; b--;
		t[a].push_back(b);
		t[b].push_back(a);
	}
	diam(0, -1);
	int a = 0;
	for (int i = 0; i < N; i++)
	{
		a = max(a, ans[i]);
	}
	cout << a;
}

