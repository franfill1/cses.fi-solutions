#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct segtree
{
	struct node
	{
		ll val=0;
		int x, y;
		node *l=NULL, *r=NULL;
		node(vector < ll > &V, int a, int b) : x(a) , y(b) 
		{
			if (a == b - 1) val = V[a];
			else
			{
				int m = (a+b)/2;
				l = new node(V, a, m);
				r = new node(V, m, b);
				val = l->val + r->val;
			}
		}

		node(int a, int b) : x(a) , y(b) {}
		node(node* n)
		{
			val = n->val;
			x = n->x; y = n->y;
			l = n->l; r = n->r;
		}
		
		node* update(int k, ll v)
		{
			node* n = new node(this);
			if (x == y-1) n->val = v;
			else
			{
				int m = (x+y)/2;
				if (k < m) n->l = l->update(k, v);
				else n->r = r->update(k, v);
				n->val = n->l->val + n->r->val;
			}

			return n;
		}

		ll query(int a, int b)
		{
			if (a <= x && y <= b) return val;
			else if (b <= x || y <= a) return 0;
			else return l->query(a, b) + r->query(a, b);
		}
	};

	vector < node* > roots;
	int n;

	segtree(vector < ll > &V)
	{
		n = 1;
		while(n < V.size()) n*=2;
		V.resize(n, 0);
		roots.push_back(new node(V, 0, n));
	}

	void update(int k, int a, ll x)
	{
		roots.push_back(roots[k]->update(a, x));
	}

	ll query(int k, int a, int b)
	{
		return roots[k]->query(a, b);
	}
	
	void copy(int k)
	{
		assert(k < roots.size());
		roots.push_back(new node(roots[k]));
	}
};

int main()
{
	int n, q;
	cin >> n >> q;

	vector < ll > V(n);
	for (ll &x : V) cin >> x;

	segtree seg(V);
	vector < int > id;
	id.push_back(0);

	while(q--)
	{
		int t; cin >> t;
		if (t == 1)
		{
			int k, a; ll x;
			cin >> k >> a >> x; k--; a--;
			assert(k < id.size());
			seg.update(id[k], a, x);
			id[k] = seg.roots.size() - 1;
		}
		else if (t == 2)
		{
			int k, a, b; 
			cin >> k >> a >> b; k--; a--;
			assert(k < id.size());
			cout << seg.query(id[k], a, b) << "\n";
		}
		else
		{
			int k; cin >> k; k--;
			assert(k < id.size());
			seg.copy(id[k]);
			id.push_back(seg.roots.size()-1);
		}
	}
}
