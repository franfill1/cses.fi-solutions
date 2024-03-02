/*
Task:              Sliding Window Cost
Sender:            franfill
Submission time:   2021-07-17 15:14:30 +0300
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
	ll a = 0, b = 0;
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
		a = m;
	}

	void add(ll v)
	{
		if (v <= *prev(l.end()))
		{
			l.insert(v);
			a += v;
			if (l.size() > (k+1)/2)
			{
				a -= *prev(l.end());
				b += *prev(l.end());
				h.insert(*prev(l.end()));
				l.erase(prev(l.end()));
			}
		}
		else
		{
			b += v;
			h.insert(v);
			if (h.size() > k/2)
			{
				a += *h.begin();
				b -= *h.begin();
				l.insert(*h.begin());
				h.erase(h.begin());
			}
		}
	}

	void remove(ll v)
	{
		if (h.count(v))
		{
			b -= v;
			h.erase(h.find(v));
		}
		else
		{
			a -= v;
			l.erase(l.find(v));
			if (l.empty())
			{
				a += *h.begin();
				b -= *h.begin();
				l.insert(*h.begin());
				h.erase(h.begin());
			}
		}
	}

	ll get()
	{
		return b - a + ((k%2) * (*prev(l.end())));
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
