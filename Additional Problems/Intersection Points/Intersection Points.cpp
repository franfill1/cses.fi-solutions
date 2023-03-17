/*
Task:              1740 Intersection Points
Sender:            franfill
Submission time:   2023-03-13 23:22:04
Language:          C++17
Result:            ACCEPTED
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

struct fenwick
{
	int n;
	vector < int > t;
	fenwick(int n_) : n(n_+1), t(n_+1)
	{
	}

	void add(int k, int x)
	{
		for (k++; k < n; k += k&-k)
			t[k] += x;
	}

	int get(int k)
	{
		int ans = 0;
		for (; k > 0; k -= k&-k)
			ans += t[k];
		return ans;
	}

	int get_range(int l, int r)
	{
		return get(r) - get(l);
	}
};

int main()
{
	int n;
	cin >> n;
	fenwick fen(2000001);
	vector < pair < int , pair < int , int > > > upd;
	vector < pair < int , pair < int , int > > > quer;	
	for (int i = 0; i < n; i++)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		y1 += 1000000;
		y2 += 1000000;
		if (x1 == x2)
		{
			if (y1 > y2)
				swap(y1, y2);
			quer.emplace_back(x1, make_pair(y1, y2));
		}
		else 
		{
			upd.emplace_back(x1, make_pair(y1, 1));	
			upd.emplace_back(x2, make_pair(y2, -1));
		}
	}

	sort(upd.begin(), upd.end());
	sort(quer.begin(), quer.end());

	ll ans = 0;
	int i = 0, j = 0;
	while (j != quer.size())
	{
		if (i == upd.size() || quer[j].first <= upd[i].first)
		{
			auto [y1, y2] = quer[j].second;
			ans += fen.get_range(y1, y2);
			j++;
		}
		else 
		{
			auto [y, c] = upd[i].second;
			fen.add(y, c);
			i++;
		}
	}
	cout << ans << "\n";
}
