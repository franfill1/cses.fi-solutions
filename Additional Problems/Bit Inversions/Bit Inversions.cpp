/*
Task:              1188 Bit Inversions
Sender:            franfill
Submission time:   2023-02-23 20:45:14
Language:          C++17
Result:            ACCEPTED
*/
#include<bits/stdc++.h>
 
using namespace std;
 
struct segtree
{
	struct node
	{
		int val = 0, pre = 0, suf = 0, size = 1;
		node(bool x) : val(x) , pre(x), suf(x)
		{
		}
		node() 
		{
		}
	};
	void merge(node& c, node a, node b)
	{
		c.val = max(max(a.val, b.val), a.suf + b.pre);
		c.pre = (a.size == a.pre) ? a.size + b.pre : a.pre;
		c.suf = (b.size == b.suf) ? b.size + a.suf : b.suf;
		c.size = a.size + b.size;
	}
	
	int n;
	vector < node > T;
	
	segtree(vector < bool > &v)
	{
		for (n = 1; n < v.size(); n <<= 1);
		T.resize(n*2);
		for (int i = 0; i < v.size(); i++)
			T[n+i] = node(v[i]);
		for (int k = n-1; k; k--)
			merge(T[k], T[k*2], T[k*2+1]);
	}
	
	void update(int i, bool v)
	{
		int k = i + n;
		T[k] = node(v);
		for (k >>= 1; k; k >>= 1)
			merge(T[k], T[k*2], T[k*2+1]);
	}
	
	int get()
	{
		return T[1].val;
	}
};
 
main()
{
	string s;
	cin >> s;
	int n = s.size();
	vector < bool > v1(n), v2(n);
	for (int i = 0; i < n; i++)
	{
		if (s[i] == '0')
			v1[i] = 0, v2[i] = 1;
		else
			v1[i] = 1, v2[i] = 0;
	}
	segtree s1(v1), s2(v2);
	int q;
	cin >> q;
	while(q--)
	{
		int i;
		cin >> i;
		i--;
		v1[i] = !v1[i];
		s1.update(i, v1[i]);
		v2[i] = !v2[i];
		s2.update(i, v2[i]);
		cout << max(s1.get(), s2.get()) << " ";
	}
}
