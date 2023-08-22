/*
Task:              2075 Reversal Sorting
Sender:            franfill
Submission time:   2023-06-13 20:39:06 +0300
Language:          C++17
Result:            ACCEPTED
*/
#include<bits/stdc++.h>
using namespace std;

struct treap
{
	int val, siz, pri, min;
	treap *l = nullptr, *r = nullptr;
	bool rev = false;

	treap(int val) : val(val), siz(1), pri(rand()), min(val)
	{
	};

	~treap()
	{
		delete l;
		delete r;
	}

	void pull()
	{
		siz = 1 + (l?l->siz:0) + (r?r->siz:0);
		min = val;
		if (l)
			min = std::min(min, l->min);
		if (r)
			min = std::min(min, r->min);
	}

	void push()
	{
		if (rev)
		{
			swap(l, r);
			if (l)
				l->rev = !l->rev;
			if (r)
				r->rev = !r->rev;
			rev = false;
		}
	}
};

pair < treap*, treap* > split(treap* t, int k)
{
	if (!t)
		return make_pair(nullptr, nullptr);
	t->push();
	int lsiz = t->l?t->l->siz:0;
	if (lsiz >= k)
	{
		auto [L, r] = split(t->l, k);
		t->l = r;
		t->pull();
		return make_pair(L, t);
	}
	else
	{
		auto [l, R] = split(t->r, k - lsiz - 1);
		t->r = l;
		t->pull();
		return make_pair(t, R);
	}
}

treap* merge(treap* l, treap* r)
{
	if (!l)
		return r;
	if (!r)
		return l;
	l->push();
	r->push();

	if (l->pri > r->pri)
	{
		l->r = merge(l->r, r);
		l->pull();
		return l;
	}
	else
	{
		r->l = merge(l, r->l);
		r->pull();
		return r;
	}
}

int find_min(treap* t)
{
	assert(t);
	t->push();
	int lsiz = t->l?t->l->siz:0;
	if (t->val == t->min)
		return lsiz;
	if (t->l && t->l->min == t->min)
		return find_min(t->l);
	assert(t->r->min == t->min);
	return lsiz + 1 + find_min(t->r);
}

void reverse(treap* t, int a, int b)
{
	if (a == b)
		return;
	auto [l, R] = split(t, b);
	auto [L, m] = split(l, a);
	assert(m);
	m->rev = true;
	t = merge(L, m);
	t = merge(t, R);
}

int main()
{
	int n;
	cin >> n;
	vector < int > a(n);
	for (auto &x : a)
		cin >> x;

	treap *t = new treap(a[0]);
	for (int i = 1; i < n; i++)
		t = merge(t, new treap(a[i]));

	cout << n-1 << "\n";
	for (int i = 0; i < n-1; i++)
	{
		assert(t);
		int p = find_min(t);
		cout << i+1 << " " << p+i+1 << "\n";
		reverse(t, 0, p+1);
		treap *del;
		tie(del, t) = split(t, 1);
		delete del;
	}
	delete t;
}
