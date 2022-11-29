#include <bits/stdc++.h>

using namespace std;

struct segtree
{
	int N;
	vector < int > V;
	
	segtree (){};
	
	segtree (vector < int > Vi)
	{
		N = 1;
		while(N <= Vi.size()) N<<=1;
		V.resize(N*2, INT_MIN);
		for (int i = 0; i < N; i++)
		{
			V[i+N] = Vi[i];
		}
		for (int i = N-1; i; i--)
		{
			V[i] = max(V[2*i], V[2*i+1]);
		}	
	};
	
	void set(int i, int val)
	{
		i += N;
		V[i] = val;
		i /= 2;
		while(i)
		{
			V[i] = max(V[i*2], V[i*2+1]);
			i /= 2;
		}
	};
	
	int get(int a, int b, int val = INT_MIN, int k=1, int x = 0, int y = -1)
	{
		if (y == -1) y = N;
		if (y <= a || b <= x) return INT_MIN;
		if (a <= x && y <= b || V[k] <= val) return V[k];
		int piv = (x+y)/2;
		val = max(val, get(a, b, val, k*2, x, piv));
		val = max(val, get(a, b, val, k*2+1, piv, y));
		return val;
	};
};

struct lca
{
	int N, P, R;
	vector < vector < int > > anc;
	vector < int > D;
	
	lca () {};
	
	lca(vector < int > &V, vector < vector < int > > &g) : N(V.size())
	{
		P = 0; while(1<<P < N) P++; P++;
		anc.resize(P, vector < int > (N));
		for (int i = 0; i < N; i++)
		{
			anc[0][i] = V[i];
			if (V[i] == i) R = i;
		}
		
		for (int p = 1; p < P; p++)
		{
			for (int i = 0; i < N; i++)
			{
				anc[p][i] = anc[p-1][anc[p-1][i]];
			}
		}
		
		D.resize(N); D[R] = 0;
		queue < int > q; q.push(R);
		while(!q.empty())
		{
			int n = q.front(); q.pop();
			for (int ne : g[n])
			{
				if (ne != V[n])
				{
					D[ne] = D[n]+1;
					q.push(ne);
				}
			}
		}
	};
	
	int lift (int n, int x)
	{
		for (int p = 0; p < P; p++)
		{
			if (1<<p & x)
			{
				n = anc[p][n];
			}
		}
		return n;
	};
	
	int operator () (int a, int b)
	{
		if (D[a] > D[b]) swap(a, b);
		b = lift(b, D[b] - D[a]);
		if (a == b) return a;
		for (int p = P-1; p >= 0; p--)
		{
			if (anc[p][a] != anc[p][b])
			{
				a = anc[p][a];
				b = anc[p][b];
			}
		}
		return anc[0][a];
	};
};

struct HLD
{
	int N;
	vector < int > dad;
	vector < vector < int > > g;
	vector < int > val;
	vector < int > tm;
	vector < int > begin;
	segtree S;
	lca L;
	
	HLD(vector < vector < int > > &gi, vector < int > &vi) : g(gi) , val(vi) , N(gi.size())
	{
		dad.resize(N); dad[0] = 0;
		begin.resize(N); tm.resize(N);
		queue < int > q; q.push(0);
		while(!q.empty())
		{
			int n = q.front(); q.pop();
			for (int ne : g[n])
			{
				if (ne != dad[n])
				{
					dad[ne] = n;
					q.push(ne);
				}
			} 
		}
		dfs1(); dfs2();
		vector < int > V(N, 0);
		for (int i = 0; i < N; i++)
		{
			if (begin[i] != i)
			{
				V[tm[i]] = val[i]; 
			}
		}
		S = segtree(V);
		L = lca(dad, g);
	};
	
	int dfs1(int n = 0)
	{
		int siz = 1;
		int b = 0, s = 0;
		for (int i = 0; i < g[n].size(); i++)
		{
			if (g[n][i] != dad[n])
			{
				int temp = dfs1(g[n][i]);
				if (temp > s)
				{
					b = i;
					s = temp;
				}
				siz += temp;
			}
		}
		swap(g[n][0] , g[n][b]);
		return siz;
	};
	
	int dfs2(int n = 0, int t = 0, int beg = 0)
	{
		int siz = 1;
		tm[n] = t;
		begin[n] = beg;
		
		if (n == 0 || g[n].size() > 1) siz += dfs2(g[n][0], t+siz, beg);
		for (int i = 1; i < g[n].size(); i++)
		{
			if (g[n][i] != dad[n])
			{
				siz += dfs2(g[n][i], t+siz, g[n][i]);
			}
		}
		return siz;
	};
	
	int update(int n, int v)
	{
		//cout << n << " " << tm[n] << "!\n";
		val[n] = v;
		if (begin[n] != n)
		{
			S.set(tm[n], v);
		}
	};
	
	int upto (int n, int l)
	{
		//cout << "upto" << n << " " << l << "\n";
		int ans = INT_MIN;
		while(n != l)
		{
			if (begin[n] == n)
			{
				ans = max(ans, val[n]);
				n = dad[n];
			}
			else
			{
				int b = max(tm[begin[n]], tm[l]);
				//cout << b+1 << " " << tm[n]+1 << "!!\n";
				ans = max(ans, S.get(b+1, tm[n]+1));
				if (tm[begin[n]] < tm[l])
				{
					n = l;
				}
				else
				{
					n = begin[n];
				}
			}
		}
		return ans;
	};
	
	int operator () (int a, int b)
	{
		int l = L(a, b);
		int ans = max(upto(a, l), upto(b, l));
		ans = max(ans, val[l]);
		return ans;
	};
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int N, Q;
	cin >> N >> Q;
	vector < int > V(N);
	for (int i = 0; i < N; i++) cin >> V[i];
	vector < vector < int > > g(N);
	for (int i = 0; i < N-1; i++)
	{
		int a, b;
		cin >> a >> b; a--; b--;
		g[a].push_back(b); g[b].push_back(a);
	}
	HLD H(g, V);
	while(Q--)
	{
		int q; cin >> q;
		if (--q)
		{
			int a, b; cin >> a >> b; a--; b--;
			cout << H(a, b) << " ";
		}
		else
		{
			int s, x; cin >> s >> x; s--;
			H.update(s, x);
		}
	}
}


