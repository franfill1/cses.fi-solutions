/*
Task:              2079 Finding a Centroid
Sender:            franfill
Submission time:   2021-05-31 22:19:24
Language:          C++11
Result:            ACCEPTED
/*
#include <bits/stdc++.h>

using namespace std;

vector < vector < int > > g;
vector < int > siz;
int N;

int sizeCalc(int n, int p = -1)
{
	siz[n] = 1;
	for (int ne : g[n])
	{
		if (ne != p)
		{
			siz[n] += sizeCalc(ne, n);
		}
	}
	return siz[n];
}

int centroid(int n, int p = -1)
{
	for (int ne : g[n])
	{
		if (ne != p)
		{
			if (siz[ne] > N/2) return centroid(ne, n);
		}
	}
	return n;
}

int main()
{
	cin >> N;
	g.resize(N);
	siz.resize(N);
	for (int i = 0; i < N-1; i++)
	{
		int a, b; cin >> a >> b; a--; b--;
		g[a].push_back(b); g[b].push_back(a);
	}
	sizeCalc(0);
	cout << centroid(0) + 1;
}

