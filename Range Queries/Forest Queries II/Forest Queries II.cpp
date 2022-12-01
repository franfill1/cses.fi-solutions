/*
Task:              1739 Forest Queries II
Sender:            franfill
Submission time:   2021-08-03 17:04:52
Language:          C++11
Result:            ACCEPTED
/*
#include<bits/stdc++.h>
using namespace std;

struct fenwick
{
	int n;
	vector < int > T;

	fenwick(int in) : n(in+1)
	{
		T.resize(n, 0);
	}

	void add(int k, int x)
	{
		for(k++; k < n; k += k&-k) T[k] += x;
	}

	int get(int k)
	{
		int ans = 0;
		for (k++; k; k -= k&-k) ans += T[k];
		return ans;
	}

	int getA(int a, int b)
	{
		return get(b-1) - get(a-1);
	}
};

struct fenwick2d
{
	int n;
	vector < fenwick > T;

	fenwick2d(int in, int im) : n(in+1)
	{
		T.resize(n, fenwick(im));
	}

	void add(int k, int j, int x)
	{
		for (k++; k < n; k += k&-k) T[k].add(j, x);
	}

	int getA(int k, int a, int b)
	{
		int ans = 0;
		for (k++; k; k -= k&-k) ans += T[k].getA(a, b);
		return ans;
	}

	int getV(int k, int j, int a, int b)
	{
		return getA(j-1, a, b) - getA(k-1, a, b);
	}
};

int main()
{
	int n, q;
	cin >> n >> q;
	fenwick2d fen(n, n);
	vector < string > V(n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			char c; cin >> c;
			if (c == '*') fen.add(i, j, 1);
			V[i] += c;
		}
	}


	for (int i = 0; i < q; i++)
	{
		int t; cin >> t;
		if (t == 1)
		{
			int y, x; cin >> y >> x;
			y--; x--;
			if (V[y][x] == '*')
			{
				V[y][x] = '.';
				fen.add(y, x, -1);
			}
			else
			{
				V[y][x] = '*';
				fen.add(y, x, 1);
			}
		}
		else
		{
			int y1, x1, y2, x2; 
			cin >> y1 >> x1 >> y2 >> x2; y1--; x1--;
			cout << fen.getV(y1, y2, x1, x2) << "\n";
		}
	}
}
