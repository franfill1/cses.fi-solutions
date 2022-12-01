/*
Task:              1647 Static Range Minimum Queries
Sender:            franfill
Submission time:   2021-07-31 12:58:33
Language:          C++11
Result:            ACCEPTED
/*
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct sparseTable
{
	int n;
	vector < vector < ll > > t;
	
	sparseTable(vector < ll > &v) : n(v.size())
	{
		int P = 1;
		while(1<<P <= n) P++;

		t.resize(P, vector < ll > (n));
		t[0] = v;

		for (int p = 1; p < P; p++)
		{
			for (int x = 0; (x+(1<<(p))-1) < n; x++)
			{
				t[p][x] = min(t[p-1][x], t[p-1][x + (1<<(p-1))]);
			}
		}
	}

	ll get(int a, int b)
	{
		int p = 0;
		while(1<<p <= (b-a)) p++;
		p--;
		return min(t[p][a], t[p][b-(1<<p)]);
	}
};

int main()
{
	int n, q;
	cin >> n >> q;

	vector < ll > V(n);
	for (ll &v : V) cin >> v;

	sparseTable s(V);
	
	while(q--)
	{
		int a, b;
		cin >> a >> b;
		a--;
		cout << s.get(a, b) << "\n";;
	}
}
