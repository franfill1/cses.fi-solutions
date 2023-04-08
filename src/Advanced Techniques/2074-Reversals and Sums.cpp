/*
Task:              2074 Reversals and Sums
Sender:            franfill
Submission time:   2023-04-04 12:18:01
Language:          C++17
Result:            ACCEPTED
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
 
struct treap 
{
	int size = 1, prio;
	ll val, sum;
	bool lazy = true;
 
	treap *left = nullptr, *right = nullptr;
 
	treap(ll val_) : size(1) , prio(rand()), val(val_) , sum(val_)
	{
	}
	
	~treap()
	{
		delete left;
		delete right;
	}
 
	void recalc()
	{
		if (lazy)
		{
			swap(left, right);
			if (left)
				left->lazy = !left->lazy;
			if (right)
				right->lazy = !right->lazy;
			lazy = false;
		}
		int lsize = 0, rsize = 0;
		ll lsum = 0, rsum = 0;;
		if (left)
			lsize = left->size, lsum = left->sum;
		if (right)
			rsize = right->size, rsum = right->sum;
		size = lsize + rsize + 1;
		sum = lsum + rsum + val;
	}
};
 
ostream& operator << (ostream &os, treap* t)
{
	if (t->left)
		os << t->left;
	os << t->val << ", ";
	if (t->right)
		os << t->right;
	return os;
}
 
pair < treap* , treap* > split(treap *t, int k)
{
	if (!t)
		return make_pair(nullptr, nullptr);
	t->recalc();
	int lsize = t->left ? t->left->size : 0;
	if (k <= lsize)
	{
		auto [L, r] = split(t->left, k);
		t->left = r;
		t->recalc();
		return make_pair(L, t);
	}
	else
	{
		auto [l, R] = split(t->right, k-lsize-1);
		t->right = l;
		t->recalc();
		return make_pair(t, R);
	}
}
 
treap* merge(treap *l, treap*r)
{
	if (!l)
		return r;
	if (!r)
		return l;
	l->recalc();
	r->recalc();
	if (l->prio > r->prio)
	{
		l->right = merge(l->right, r);
		l->recalc();
		return l;
	}
	else
	{
		r->left = merge(l, r->left);
		r->recalc();
		return r;
	}
}
 
ll get_sum(treap *&t, int a, int b)
{
	auto [l, R] = split(t, b);
	auto [L, M] = split(l, a);
	ll s = M ? M->sum : 0;
	t = merge(merge(L, M), R);
	return s;
}
 
void reverse(treap *&t, int a, int b)
{
	auto [l, R] = split(t, b);
	auto [L, M] = split(l, a);
	if (M)
		M->lazy = true;
	t = merge(merge(L, M), R);
}
 
int main()
{
	int n, m;	
	cin >> n >> m;
	ll val;
	cin >> val;
	auto t = new treap(val);
	for (int i = 1; i < n; i++)
	{
		cin >> val;
		t = merge(t, new treap(val));
	}
 
	while(m--)
	{
		int T, a, b;
		cin >> T >> a >> b;
		a--;
		if (T == 1)
			reverse(t, a, b);
		else
			cout << get_sum(t, a, b) << "\n";
	}
}
