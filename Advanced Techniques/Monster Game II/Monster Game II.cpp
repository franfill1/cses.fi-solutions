/*
Task:              2085 Monster Game II
Sender:            franfill
Submission time:   2022-10-20 21:01:03
Language:          C++17
Result:            ACCEPTED
/*
#include<bits/stdc++.h>
using namespace std;

using ll=long long;
using db=long double;

const ll inf = 1ll<<60;

struct line
{
	//y = mx + q
	ll m, q;
	//additional info
	mutable ll x = -inf>>1;
	bool test = false;

	line(ll x_) : x(x_) , test(true)
	{
	}

	line(ll m_, ll q_) : m(m_) , q(q_) , test(false)
	{
	}

	bool operator == (const line oth) const
	{
		return m == oth.m && q == oth.q;
	}

	bool operator < (const line oth) const
	{
		if (oth.test)
			return x < oth.x;
		else
			return m < oth.m;
	}

	ll eval(ll x) const
	{
		return m*x + q;
	}
};

ostream& operator << (ostream& os, line l)
{
	os << "{" << l.m << "x + " << l.q << "} ";
	return os;
}

struct upper_hull
{
	multiset < line > hull;
	upper_hull()
	{
	}

	bool good(set<line>::iterator l)
	{
		auto n = next(l);
		if (l == hull.begin())
		{
			if (n == hull.end())
				return true;
			return l->m != n->m || l->q > n->q;
		}
		auto p = prev(l);
		if (n == hull.end())
			return l->m != p->m || l->q > p->q;

		//mp * x2 + qp = mn * x2 + qn
		//x2 * (mp - mn) = qn - qp
		//x2 = (qn - qp) / (mp - mn)
		//x1 = (ql - qp) / (mp - ml)
		//x1 < x2
		//(ql - qp) / (mp - ml) < (qn - qp) / (mp - mn)
		//(ql - qp) * (mp - mn) < (qn - qp) * (mp - ml)
		return ((l->q - p->q) * (p->m - n->m) <= (n->q - p->q) * (p->m - l->m));
	}

	void insert(ll m, ll q)
	{
		line l(m, q);

		auto it = hull.insert(l);
		if (!good(it))
		{
			//cerr << "BAD :(\n";
			hull.erase(it);
			return;
		}
		while(it != hull.begin() && !good(prev(it)))
		{
			hull.erase(prev(it));
			it = hull.find(l);
		}
		while(it != prev(hull.end()) && !good(next(it)))
		{
			hull.erase(next(it));
			it = hull.find(l);
		}
		assert(it != hull.end() && *it == l);
		
		//x1 = (ql - qp) / (mp - ml)
		if (it != hull.begin())
		{
			auto p = prev(it);
			it->x = floor(db(q - p->q) / db(p->m - m));
			//cerr << it->x << "!!!\n";
		}
		if (it != prev(hull.end()))
		{
			auto n = next(it);
			n->x = floor(db(q - n->q) / db(n->m - m));
			//cerr << n->x << "(n)!!!\n";
		}
		//cerr << *it << "inserted\n";
	}

	ll eval(ll x)
	{
		//cerr << hull.size() << "\n";
		//for (auto l : hull)
			//cerr << l << "\n";
		line t(x);
		auto it = prev(hull.lower_bound(t));
		assert(it != hull.end());
		//cerr << *it << "\n";
		return it->eval(x);
	}
};

int main()
{
	upper_hull h;
	int n, st;
	cin >> n >> st;
	vector < ll > s(n), d(n);
	for (int i = 0; i < n; i++)
		cin >> s[i];
	for (int i = 0; i < n; i++)
		cin >> d[i];

	h.insert(-s.back(), 0);

	ll ans = -h.eval(st);
	for (int i = n-2; i >= 0; i--)
	{
		ll x = -h.eval(d[i]);
		//cerr << x << "\n";
		ans = min(ans, s[i]*st + x);
		h.insert(-s[i], -x);
	}
	cout << ans << "\n";
}
