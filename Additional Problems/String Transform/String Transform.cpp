/*
Task:              1113 String Transform
Sender:            franfill
Submission time:   2023-03-14 16:11:42
Language:          C++17
Result:            ACCEPTED
*/
#include<bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	cin >> s;
	int n = s.size();
	
	vector < char > en(n), st(n);
	for (int i = 0; i < n; i++)
		en[i] = st[i] = s[i];
	sort(st.begin(), st.end());
	
	vector < int > p(n);
	iota(p.begin(), p.end(), 0);
	sort(p.begin(), p.end(), [&] (int i, int j)
			{
				pair < char, char > pi = make_pair(en[i], st[i]), pj = make_pair(en[j], st[j]);
				if (pi != pj)
					return pi < pj;
				else
					return i < j;
			});

	vector < int > ip(n);
	for (int i = 0; i < n; i++)
		ip[p[i]] = i;

	int x = 0;
	string res = "";
	for (int i = 0; i < n-1; i++)
	{
		res += en[x];
		x = ip[x];
	}
	for (int i = n-2; i >= 0; i--)
		cout << res[i];
	cout << "\n";
}
