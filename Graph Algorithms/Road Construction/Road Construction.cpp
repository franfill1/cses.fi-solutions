#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct dsu
{
	int n;
	vector < int > pa;
	vector < int > siz;

	dsu(int in) : n(in)
	{
		pa.resize(n);
		for (int i = 0; i < n; i++) pa[i] = i;
		siz.resize(n, 1);
	}

	int getR(int x)
	{
		if (x == pa[x]) return x;
		else return pa[x] = getR(pa[x]);
	}

	void unite(int a, int b)
	{
		a = getR(a); b = getR(b);
		if (siz[a] < siz[b]) swap(a, b);

		pa[b] = a;
		siz[a] += siz[b];
	}

	bool same(int a, int b) 
	{
		return getR(a) == getR(b);
	}

	int getSiz(int x)
	{
		return siz[getR(x)];
	}
};

int main()
{
	int n, m;
	cin >> n >> m;
	
	dsu s(n);

	int cnt = n;
	int siz = 1;

	while(m--)
	{
		int a, b;
		cin >> a >> b; a--; b--;
		if (!s.same(a, b))
		{
			s.unite(a, b);
			cnt--;
			siz = max(siz, s.getSiz(a));
		}
		cout << cnt << " " << siz << "\n";
	}
}
