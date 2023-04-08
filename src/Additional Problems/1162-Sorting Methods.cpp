/*
Task:              1162 Sorting Methods
Sender:            franfill
Submission time:   2023-03-13 23:06:57
Language:          C++17
Result:            ACCEPTED
*/
#include <algorithm>
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

struct fenwick 
{
	bool qmax;
	int n;
	vector < ll > t;

	fenwick(int n_, bool max_=false) : n(n_+1) , t(n_+1, 0), qmax(max_)
	{
	}

	void add(int k, ll x)
	{
		for (k++; k < n; k += k&-k)
			if (qmax)
				t[k] = max(t[k], x);
			else
				t[k] = t[k] + x;;
	}

	ll get(int k)
	{
		ll ans = 0;
		for (k++; k > 0; k -= k&-k)
			if (qmax)
				ans = max(t[k], ans);
			else
			 	ans += t[k];
		return ans;
	}
};

ll count_adjacent(vector < int > p)
{
	int n = p.size();
	fenwick fen(n);
	ll ans = 0;
	for (int i = n-1; i >= 0; i--)
	{
		ans += fen.get(p[i]);
		fen.add(p[i], 1);
	}
	return ans;
}

int count_swap(vector < int > p)
{
	int n = p.size();
	int ans = n;
	vector < bool > vis(n, false);
	for (int i = 0; i < n; i++)
		if (!vis[i])
		{
			vis[i] = true;
			ans--;
			int x = p[i];
			while(x != i)
			{
				vis[x] = true;
				x = p[x];
			}
		}
	return ans;
}

int count_move(vector < int > p)
{
	int n = p.size();
	int ans = 0;
	fenwick fen(n, true);
	for (int i = 0; i < n; i++)
	{
		int x = fen.get(p[i]);
		ans = max(ans, x+1);
		fen.add(p[i], x+1);
	}
	return n-ans;
}

int count_front(vector < int > p)
{
	int n = p.size();
	int s = n-1;
	for (int i = n-1; i >= 0; i--)
	{
		if (p[i] == s)
			s--;
	}
	return s+1;
}

int main()
{
	int n;
	cin >> n;
	vector < int > p(n);
	for (auto &x : p)
	{
		cin >> x;
		x--;
	}
	cout << count_adjacent(p) << " " << count_swap(p) << " " << count_move(p) << " " << count_front(p) << "\n";

}
