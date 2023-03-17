/*
Task:              1747 Pyramid Array
Sender:            franfill
Submission time:   2023-03-14 19:50:52
Language:          C++17
Result:            ACCEPTED
*/
#include<bits/stdc++.h>
using namespace std;
 
struct fenwick
{
	int n;
	vector < int > t;
 
	fenwick(int n_) : n(n_+1), t(n_+1, 0)
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
};
 
int main()
{
	int n;
	cin >> n;
	vector < int > p(n);
	map < int , int > m;
	for (int &x : p)
	{
		cin >> x;
		x--;
		if (!m.count(x))
			m[x] = 0;
	}
	int c = 0;
	for (auto &[a, b] : m)
		b = c++;
	for (int &x : p)
		x = m[x];
 
	fenwick f(n);
	long long ans = 0;
	for (int i = 0; i < n; i++)
	{
		int l = i - f.get(p[i]);
		int r = n-p[i]-l-1;
		ans += min(l, r);
		f.add(p[i], 1);
	}
	cout << ans << "\n";
}
