#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
struct centroid_dec
{
	int N, R, K, md; ll ans;
	vector < int > dad;
	vector < int > siz;
	vector < bool > isCe;
	vector < vector < int > > g;
	
	vector < int > D;
	
	centroid_dec(vector < vector < int > > &gi, int Ki) : g(gi) , N(gi.size()) , K(Ki)
	{
		dad.resize(N);
		siz.resize(N);
		isCe.resize(N);
		D.resize(K+1, 0);
		D[0] = 1;
		ans = 0;
		decompose();
	}
	
	int sizcalc (int n, int p)
	{
		siz[n] = 1;
		for (int ne : g[n])
		{
			if (!isCe[ne] && ne != p)
			{
				siz[n] += sizcalc(ne, n);
			}
		}
		return siz[n];
	}
	
	void depthCalc (int n, int p, int d, bool f)
	{
		md = max(d, md);
		if (!f) ans += D[K-d];
		else D[d]++;
		if (d < K)
		{
			for (int ne : g[n])
			{
				if (!isCe[ne] && ne != p)
				{
					depthCalc(ne, n, d+1, f);
				}
			}
		}
	}
	
	int centroid (int n, int p, int csz)
	{
		for (int ne : g[n])
		{
			if (!isCe[ne] && ne != p)
			{
				if (siz[ne] > csz/2) return centroid(ne, n, csz);
			}
		}
		return n;
	}
	
	void decompose (int n = 0, int p = -1)
	{
		sizcalc(n, n);
		int c = centroid(n, n, siz[n]);
		if (p == -1)
		{
			R = c;
			p = R;
		}
		dad[c] = p;
		isCe[c] = true;
		md = 0;
		for (int ne : g[c])
		{
			if (!isCe[ne])
			{
				depthCalc(ne, c, 1, false);
				depthCalc(ne, c, 1, true);
			}
		}
		fill(D.begin() + 1, D.begin() + md + 1, 0);
		for (int ne : g[c])
		{
			if (!isCe[ne])
			{
				decompose(ne, c);
			}
		}
	}
};
 
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int N, K;
	cin >> N >> K;
	vector < vector < int > > g(N);
	for (int i = 0; i < N-1; i++)
	{
		int a, b;
		cin >> a >> b;
		a--; b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	
	centroid_dec C(g, K);
	
	cout << C.ans << "\n";
}
