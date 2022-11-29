#include <bits/stdc++.h>

using namespace std;

vector < vector < int > > mat;
vector < vector < int > > t;
vector < int > dep;
int mp = 0;

int anc(int x, int k)
{
	int p = mp;
	while(k > 0 && x != -1)
	{
		while(1<<p > k)
		{
			p--;
		}
		k -= 1<<p;
		x = mat[p][x];
	}
	return x;
}

void dfs(int n, int from, int d)
{
	mat[0][n] = from;
	dep[n] = d;
	for (int ne : t[n])
	{
		if (ne != from)
		{
			dfs(ne, n, d+1);
		}
	}
}

int main()
{
	int N, Q;
	cin >> N >> Q;
	while(1<<mp <= N)
	{
		mp++;
	}
	mat.resize(mp, vector < int > (N));
	t.resize(N);
	dep.resize(N);
	
	mat[0][0] = -1;
	for (int i = 1; i < N; i++)
	{
		int a, b;
		cin >> a >> b;
		a--; b--;
		
		t[a].push_back(b);
		t[b].push_back(a);
	}
	
	dfs(0, -1, 0);
	
	for (int p = 1; p < mp; p++)
	{
		for (int i = 0; i < N; i++)
		{
			int temp = mat[p-1][i];
			if (temp != -1)
			{
				temp = mat[p-1][temp];
			}
			mat[p][i] = temp;
		}
	}
	
	while(Q--)
	{
		int a, b;
		cin >> a >> b;
		a--; b--;
		int aa = a, bb = b;
		a = anc(a, max(0, dep[a] - dep[b]));
		b = anc(b, max(0, dep[b] - dep[a]));
		for (int p = mp-1; p >= 0; p--)
		{
			int na, nb;
			na = mat[p][a];
			nb = mat[p][b];
			if (na != nb)
			{
				a = na; b = nb;
			}

		}
		if (a != b)
		{
			a = anc(a, 1);
		}
		cout << dep[aa] - dep[a] + dep[bb] - dep[a] << "\n"; 
	}
}



