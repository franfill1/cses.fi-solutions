/*
Task:              2072 Cut and Paste
Sender:            franfill
Submission time:   2022-10-20 11:57:42
Language:          C++17
Result:            ACCEPTED
/*
#include <bits/stdc++.h>
using namespace std;

struct treap
{
	treap *l = nullptr, *r = nullptr;
	char val = 'a';
	int size = 1;
	bool reverse = false;
	
	int priority = 0;
	treap(char val_) : val(val_) , priority(rand()){};
	
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
	}
};

ostream& operator << (ostream& os, treap * T)
{
	if (!T)
		return os;
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
	string S;
	cin >> S;
	treap * root = new treap(S[0]);
	for (int i = 1; i < N; i++)
		root = merge(root, new treap(S[i]));
	while(Q--)
	{
		int a, b;
		cin >> a >> b;
		a--;
		auto [L, r] = split(root, a);
		auto [m, R] = split(r, b-a);
		root = merge(L, R);
		root = merge(root, m);
	}
	cout << root << "\n";
}


