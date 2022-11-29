#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct scapeGoatTree
{
	struct node
	{
		node *par = NULL, *l = NULL, *r = NULL;
		ll key;
		int siz, cnt, sub;

		node(ll k, int c=1, int s=1, int u=1) : key(k) , siz(c) , cnt(c) , sub(u){}
		~node()
		{
			if (l) delete l;
			if (r) delete r;
		}
	};

	node *root = NULL;
	const double a;
	int s;

	scapeGoatTree(double ia) : a(ia) {}

	scapeGoatTree(vector < ll > v, double ia) : a(ia) 
	{
		map < ll , int > m;
		for (ll &x : v) m[x]++;
		vector < pair < ll , int > > p;
		for (pair < ll , int > x : m) p.push_back(x);

		root = build(p);
	}

	node* build(vector < pair < ll , int > > &v, int a = 0, int b = -1)
	{
		if (b == -1) b = v.size();
		if (a == b) return NULL;

		int m = (a+b)/2;
		node *n = new node(v[m].first, v[m].second);
		
		n->l = build(v, a, m);
		if (n->l)
		{
			n->l->par = n;
			n->siz += n->l->siz;
			n->sub += n->l->sub;
		}

		n->r = build(v, m+1, b);
		if (n->r)
		{
			n->r->par = n;
			n->siz += n->r->siz;
			n->sub += n->r->sub;
		}

		return n;
	}

	void update(node* n)
	{
		n->siz = n->cnt;	
		n->sub = 1;
		if (n->l)
		{
			n->siz += n->l->siz;
			n->sub += n->l->sub;
		}
		if (n->r) 
		{
			n->siz += n->r->siz;
			n->sub += n->r->sub;
		}

		if (n->par) update(n->par);
	}

	node* add(ll k)
	{
		if (!root)
		{
			root = new node(k);
			return root;
		}

		node *n = find(k);
		if (n->key == k) 
		{
			n->cnt++;
			update(n);
		}
		else
		{
			node* x = new node(k);
			if (k < n->key) n->l = x;
			else n->r = x;
			x->par = n;
			n = x;
			update(n);

			s = max(s, root->sub);
			
			x = findGoat(n);
			if (x) rebuild(x);
		}
		return n;
	}

	node* find(ll k)
	{
		if (!root) return NULL;
		return _find(root, k);
	}

	node* _find(node* n, ll k)
	{
		if (k == n->key) return n;
		else if (k < n->key)
		{
			if (n->l) return _find(n->l, k);
			else return n;
		}
		else
		{
			if (n->r) return _find(n->r, k);
			else return n;
		}
	}

	void remove(ll k)
	{
		node* n = find(k);
		if (n->key == k)
		{
			n->cnt--;
			if (n->cnt) update(n);
			else _remove(n);
		}
	}

	void _remove(node* n)
	{
		node *x = NULL;	
		if (n->l) x = findByOrder(n->l, n->l->siz);
		else if (n->r) 
		{
			x = findByOrder(n->r, 1);
		}

		if (x)
		{
			n->key = x->key;
			n->cnt = x->cnt;
			_remove(x);
		}
		else
		{
			_destroy(n);
		}
	}

	void _destroy(node* n)
	{
		if (n == root)
		{
			root = NULL;
		}
		else
		{
			node* x = n->par;
			if (x->l == n) x->l = NULL;
			else x->r = NULL;
			update(x);
		}
		delete n;
		if ((double)root->sub < a*a*s)
		{
			rebuild(root);
			s = root->sub;
		}
	}

	node* findByOrder(ll o)
	{
		if (root->siz < o) return NULL;
		return findByOrder(root, o);
	}

	node* findByOrder(node *n, ll o)
	{
		int ls = 0;
		if (n->l) ls = n->l->siz;

		if (ls >= o) return findByOrder(n->l, o);
		else if (ls + n->cnt >= o) return n;
		else return findByOrder(n->r, o - ls - n->cnt);
	}

	int orderOfKey(ll k)
	{
		return orderOfKey(root, k);
	}

	int orderOfKey(node *n, ll k)
	{
		if (k < n->key)
		{
			if (n->l) return orderOfKey(n->l, k);
			else return 0;
		}
		else 
		{
			int ls = 0;
			if (n->l) ls = n->l->siz;

			int ans = ls + n->cnt; 
			if (k > n->key && n->r) ans += orderOfKey(n->r, k);
			return ans;
		}
	}

	node* findGoat(node* n)
	{
		node *x = NULL;
		if (n != root) x = findGoat(n->par);
		if (!x)
		{
			if (n->l && (double)n->l->sub > a * (double)n->sub) x = n;
			else if (n->r && (double)n->r->sub > a * (double)n->sub) x = n;
		}
		return x;
	}

	void collect (node *n, vector < pair < ll , int > > &v)
	{
		if (n->l) collect(n->l, v);
		v.push_back({n->key, n->cnt});
		if (n->r) collect(n->r, v);
	}

	void rebuild(node* n)
	{
		vector < pair < ll , int > > v; 
		collect(n, v);
		node* x = build(v);
		if (n == root)
		{
			root = x;
		}
		else if (n->par->l == n)
		{
			n->par->l = x;
			x->par = n->par;
		}
		else
		{
			n->par->r = x;
			x->par = n->par;
		}
		delete n;
	}
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector < ll > P(n);

	for (int i = 0; i < n; i++)
	{
		cin >> P[i];
	}

	scapeGoatTree tree(P, 0.66);

	while(m--)
	{
		char q;
		cin >> q;
		if (q == '!')
		{
			int k; ll x;
			cin >> k >> x;
			k--;
			tree.remove(P[k]);
			tree.add(x);
			P[k] = x;
		}
		else
		{
			int a, b;
			cin >> a >> b;
			cout << tree.orderOfKey(b) - tree.orderOfKey(a-1) << "\n";
		}
	}
}

