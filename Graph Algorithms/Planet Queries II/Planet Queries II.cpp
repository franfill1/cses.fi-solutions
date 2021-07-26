#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct lifting
{
	int n, P = 33;
	vector < vector < int > > anc;

	vector < int > D;
	vector < int > L;
	vector < int > R;

	int dfs(int x)
	{
		if (D[x] == -2) return D[x] = -1;
		else if (D[x] != -1) return D[x];
		D[x] = -2;

		int temp = dfs(anc[0][x]) + 1;
		if (D[x] != -2 && L[x] == -1)
		{
			D[x] = temp;
			setl(x, temp+1, x);
			return 0;
		}
		if (R[x] == -1) R[x] = R[anc[0][x]];
		return D[x] = temp;
	}

	void setl(int x, int l, int c)
	{
		L[x] = l;
		R[x] = x;
		if (anc[0][x] != c) setl(anc[0][x], l, c);
	}
		

	lifting(vector < int > next) : n(next.size())
	{
		anc.resize(P, vector < int > (n));
		D.resize(n, -1);
		L.resize(n, -1);
		R.resize(n, -1);

		anc[0] = next;

		for (int p = 1; p < P; p++)
		{
			for (int x = 0; x < n; x++)
			{
				anc[p][x] = anc[p-1][anc[p-1][x]];
			}
		}

		for (int x = 0; x < n; x++) dfs(x);
	}

	int lift(int x, ll k)
	{
		for (int p = 0; p < P; p++)
		{
			if((1ll<<p) & k)
			{
				x = anc[p][x];
			}
		}
		return x;
	}

	int check(int a, int b)
	{
		if (R[a] != a && R[b] != b)
		{
			int g = D[a] - D[b];
			if (lift(a, g) == b) return g;
		}
		else if (R[b] == b)
		{
			int ra = R[a];

			int d = D[ra] - D[b];

			if (d < 0) d += L[ra];

			int g = D[a] + d;
			if (lift(a, g) == b) return g;
		}
		return -1;
	}
};

int main()
{
	int n, q;
	cin >> n >> q;
	vector < int > next(n);
	for (int i = 0; i < n; i++)
	{
		cin >> next[i]; next[i]--;
	}
	
	lifting calc(next);

	while(q--)
	{
		int a, b;
		cin >> a >> b; a--; b--;
		cout << calc.check(a, b) << "\n";
	}
}
