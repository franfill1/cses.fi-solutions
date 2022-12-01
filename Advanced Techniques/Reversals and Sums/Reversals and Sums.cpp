/*
Task:              2074 Reversals and Sums
Sender:            franfill
Submission time:   2022-10-20 14:02:10
Language:          C++17
Result:            ACCEPTED
*/
#include <vector>
#include<iostream>
using namespace std;
using ll=long long;
 
struct treap
{
	treap *l = nullptr, *r = nullptr;
	ll val = 0, sum=0;
	int size = 1;
	bool reverse = false;
	
	int priority = 0;
	treap(ll val_) : val(val_) , priority(rand()){};
	
	int lsize()
	{
		return l?(l->size):0;
	}	
	
	int rsize()
	{
		return r?(r->size):0;
	}
	
	void propagate()
	{
		size = lsize() + rsize()+1;
		sum = val + (l?l->sum:0) + (r?r->sum:0);
		if (reverse)
		{
			if (l) 
				l->reverse = !l->reverse;
			if (r)
				r->reverse = !r->reverse;
			swap(l, r);
			reverse = false;
		}
	}
};
 
ostream& operator << (ostream& os, treap * T)
{
	if (!T)
		return os;
	T->propagate();
	os << T->l;
	os << T->val;
	os << T->r;
	return os;
}
 
pair < treap* , treap* > split(treap* T, int i)
{
	//i : primo elemento della seconda met�
	if (!T)
		return {nullptr, nullptr};
	T->propagate();
 
	if (i == T->lsize())
	{
		auto L = T->l;
		T->l = nullptr;
		T->propagate();
		return {L, T};
	}
	else if (i < T->lsize())
	{
		auto [L, r] = split(T->l, i);
		T->l = r;
		T->propagate();
		return {L, T};
	}
	else
	{
		auto [l, R] = split(T->r, i - T->lsize() - 1);
		T->r = l;
		T->propagate();
		return {T, R};
	}
}
 
treap * merge(treap* a, treap* b)
{
	if (!a)
		return b;
	if (!b)
		return a;
	a->propagate();
	b->propagate();
	if (a->priority > b->priority)
	{
		a->r = merge(a->r, b);
		a->propagate();
		return a;
	}
	else
	{
		b->l = merge(a, b->l);
		b->propagate();
		return b;
	}
}
 
 
 
int main()
{
	int N, Q;
	cin >> N >> Q;
	int x;
	cin >> x;
	treap * root = new treap(x);
	for (int i = 1; i < N; i++)
	{
		cin >> x;
		root = merge(root, new treap(x));
	}
	while(Q--)
	{
		int t;
		cin >> t;
		int a, b;
		cin >> a >> b;
		a--;
		auto [L, r] = split(root, a);
		auto [m, R] = split(r, b-a);
		if (t == 1)
			m->reverse = !m->reverse;
		else
			cout << m->sum << "\n";
		root = merge(L, m);
		root = merge(root, R);
	}
}

