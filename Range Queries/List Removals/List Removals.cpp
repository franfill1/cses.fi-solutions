#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct bst
{
	struct node
	{
		node *par, *l, *r;
		int key, size;

		node(int ki, int si) : key(ki) , size(si) {}
	};

	node *root;

	bst(ll n)
	{
		root = build(0, n);	
	}

	node* build(int a, int b)
	{
		if (a == b) return NULL;

		int m = (a+b)/2;
		node* n = new node(m, b-a);
		
		n->l = build(a, m);
		if (n->l) n->l->par = n;

		n->r = build(m+1, b);
		if (n->r) n->r->par = n;

		return n;
	}

	node* findByOrder(node *n, int o)
	{
		if(n->size < o) return NULL;

		int lsize = 0;
		if (n->l) lsize = n->l->size;

		if (lsize >= o) return findByOrder(n->l, o);
		else if (o == lsize + 1) return n;
		else return findByOrder(n->r, o - lsize - 1);
	}

	void remove(node *n)
	{
		node *x = NULL;
		
		if (n->l) x = findByOrder(n->l, n->l->size);
		else if (n->r) x = findByOrder(n->r, 1);

		if (x)
		{
			n->key = x->key;
			remove(x);
		}
		else destroy(n);
	}

	void destroy(node *n)
	{
		if (n != root)
		{
			if (n->par->l == n) n->par->l = NULL;
			if (n->par->r == n) n->par->r = NULL;
		}

		while(n = n->par)
		{
			n->size--;
		}
	}

	int query(int o)
	{
		node* n = findByOrder(root, o);
		ll k = n->key;
		remove(n);
		return k;
	}
};

int main()
{
	int n;
	cin >> n;

	vector < ll > V(n);
	for (ll &x : V) cin >> x;

	bst tree(n);

	while(n--)
	{
		int o; 
		cin >> o;
		cout << V[tree.query(o)] << " ";
	}
}
