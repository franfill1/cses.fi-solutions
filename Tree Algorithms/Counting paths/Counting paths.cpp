#include <bits/stdc++.h>

using namespace std;

vector < vector < int > > t;
vector < int > dep;
vector < vector < int > > table;
vector < int > val;
vector < int > ans;
int mp = 0;

int anc(int x, int k)
{
	int p = mp-1;
	while(x != -1 && k > 0)
	{
		if (k >= 1<<p)
		{
			x = table[p][x];
			k -= 1<<p;
		}
		p--;
	}
	return x;
}

int lowAnc(int a, int b)
{
	a = anc(a, dep[a] - dep[b]);
	b = anc(b, dep[b] - dep[a]);
	if (a == b)
	{
		return a;
	}
	else
	{
		for (int p = mp-1; p >= 0; p--)
		{
			if (table[p][a] != table[p][b])
			{
				a = table[p][a];
				b = table[p][b];
			}
		}
		return table[0][a];
	}
}

int firstTra(int n, int from, int de)
{
	dep[n] = de;
	table[0][n] = from;
	for (auto ne : t[n])
	{
		if (ne != from)
		{
			firstTra(ne, n, de+1);
		}
	}
}

int dfs(int n, int from)
{
	ans[n] = val[n];
	for (auto ne : t[n])
	{
		if (ne != from)
		{
			ans[n] += dfs(ne, n);
		}
	}
	return ans[n];
}

int main()
{
	int N, M;
	cin >> N >> M;
	
	while(1<<mp <= N) mp++;
	table.resize(mp, vector < int > (N));
	t.resize(N); dep.resize(N); val.resize(N); ans.resize(N);
	
	for (int i = 0; i < N-1; i++)
	{
		int a, b;
		cin >> a >> b;
		a--; b--;
		t[a].push_back(b);
		t[b].push_back(a);
	}
	firstTra(0, -1, 0);
	
	for (int p = 1; p < mp; p++)
	{
		for (int i = 0; i < N; i++)
		{
			table[p][i] = table[p-1][i];
			if (table[p][i] >= 0) table[p][i] = table[p-1][table[p][i]];
		}
	}
	
	while(M--)
	{
		int a, b;
		cin >> a >> b;
		a--; b--;
		int lc = lowAnc(a, b);
		int anc = table[0][lc];
		if (lc != a && lc != b)
		{
			val[a]++;
			val[b]++;
			val[lc]--;
			if(anc >= 0) val[anc]--;
		}
		else if (lc != a)
		{
			val[a]++;
			if(anc >= 0) val[anc]--;
		}
		else if (lc != b)
		{
			val[b]++;
			if (anc >= 0) val[anc]--;
		}
		else
		{
			val[lc]++;
			if (anc >= 0) val[anc]--;
		}
	}
	
	dfs(0, -1);
	for (int i = 0; i < N; i++)
	{
		cout << ans[i] << " ";
	}
}
