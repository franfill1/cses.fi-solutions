/*
Task:              1076 Sliding Median
Sender:            franfill
Submission time:   2021-07-17 15:06:33
Language:          C++11
Result:            ACCEPTED
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct medianset
{
	multiset < ll > l;
	multiset < ll > h;
	ll k;

	void print()
	{
		cout << "med: ";
		for (ll e : l) cout << e << " ";
		for (ll e : h) cout << e << " "; 
		cout << "\n";
	}
	
	medianset(ll m, ll ik) : k(ik)
	{
		l.insert(m);
	}

	void add(ll v)
	{
		if (v <= *prev(l.end()))
		{
			l.insert(v);
			if (l.size() > (k+1)/2)
			{
				h.insert(*prev(l.end()));
				l.erase(prev(l.end()));
			}
		}
		else
		{
			h.insert(v);
			if (h.size() > k/2)
			{
				l.insert(*h.begin());
				h.erase(h.begin());
			}
		}
	}

	void remove(ll v)
	{
		if (h.count(v))
		{
			h.erase(h.find(v));
		}
		else
		{
			l.erase(l.find(v));
			if (l.empty())
			{
				l.insert(*h.begin());
				h.erase(h.begin());
			}
		}
	}

	ll get()
	{
		return *prev(l.end());
	}
};


int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	
	vector < ll > v(n);
	for (int i = 0; i < n; i++) cin >> v[i];

	medianset m(v[0], k);
	for (int i = 1; i < k; i++)
	{
		m.add(v[i]);
	}
	cout << m.get() << " ";

	for (int i = k; i < n; i++)
	{
		if (k == 1)
		{
			m.add(v[i]);
			m.remove(v[i-k]);
		}
		else
		{
			m.remove(v[i-k]);
			m.add(v[i]);
		}
		cout << m.get() << " ";
	}
}
