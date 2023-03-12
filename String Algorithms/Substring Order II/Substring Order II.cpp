/*
Task:              2109 Substring Order II
Sender:            franfill
Submission time:   2023-03-12 15:38:43
Language:          C++17
Result:            ACCEPTED
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

vector < int > suffix_array(string s)
{
	s += ('a'-1);
	int n = s.size();
	int alph = 27;
	vector < int > cla(n), ord(n);

	{
		vector < int > cnt(alph);
		iota(ord.begin(), ord.end(), 0);
		for (int i = 0; i < n; i++)
			cla[i] = s[i]-'a'+1;
		for (int i = 0; i < n; i++)
			cnt[cla[i]]++;
		for (int i = 1; i < alph; i++)
			cnt[i] += cnt[i-1];
		for (int i = n-1; i >= 0; i--)
			ord[--cnt[cla[i]]] = i;
		alph = 1;
		vector < int > ncla(n);
		ncla[ord[0]] = 0;
		for (int i = 1; i < n; i++)
		{
			if (cla[ord[i]] != cla[ord[i-1]])
				alph++;
			ncla[ord[i]] = alph-1;
		}
		cla = ncla;
	}

	for (int p = 0; 1<<p < n; p++)
	{
		int st = 1<<p;
		vector < int > nord(n);
		for (int i = 0; i < n; i++)
			nord[i] = (ord[i] - st + n) % n;
		vector < int > cnt(alph);
		for (int i = 0; i < n; i++)
			cnt[cla[i]]++;
		for (int i = 1; i < alph; i++)
			cnt[i] += cnt[i-1];
		for (int i = n-1; i >= 0; i--)
			ord[--cnt[cla[nord[i]]]] = nord[i];
		alph = 1;
		vector < int > ncla(n);
		for (int i = 1; i < n; i++)
		{
			if (make_pair(cla[ord[i-1]], cla[(ord[i-1]+st)%n]) <
					make_pair(cla[ord[i  ]], cla[(ord[i  ]+st)%n]))
				alph++;
			ncla[ord[i]] = alph-1;
		}
		cla = ncla;
	}
	ord.erase(ord.begin());
	return ord;
}

int main()
{
	string s;
	cin >> s;
	int n = s.size();
	auto v = suffix_array(s);

	vector < ll > sum(n+1, 0);
	for (int i = 1; i <= n; i++)
		sum[i] = sum[i-1] + n - v[i-1];


	auto find_first = [&] (int l, int r, int i, char c)
	{
		assert(l < v.size());
		if (s[v[l] + i] >= c)
			return l;
		while(l < r-1)
		{
			int m = (l+r)/2;
			if (s[v[m] + i] >= c)
				r = m;
			else
				l = m;
		}
		return r;
	};

	ll k;
	cin >> k;
	k--;
	string prefix = "";
	int l = 0, r = n;
	auto get_sum = [&] (int a, int b)
	{
		return sum[b] - sum[a] - (b-a) * prefix.size();	
	};
	while(true)
	{
		assert(l < r);
		int nl=l, nr=r;
		for (char c = 'a'; c <= 'z'; c++)
		{
			int fp = find_first(l, r, prefix.size(), c);
			if (get_sum(l, fp) > k)
			{
				nr = fp;
				break;
			}
			nl = fp;
		}
		k -= get_sum(l, nl);
		l = nl, r = nr;
		prefix += s[v[l]+prefix.size()];
		if (r-l > k)
		{
			cout << prefix << "\n";
			return 0;
		}
		k -= r-l;
	}
}
