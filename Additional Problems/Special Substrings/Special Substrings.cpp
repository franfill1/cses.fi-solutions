/*
Task:              2186 Special Substrings
Sender:            franfill
Submission time:   2023-03-13 10:46:44
Language:          C++17
Result:            ACCEPTED
*/
#include<vector>
#include<map>
#include<iostream>
using namespace std;
using ll = long long;

int main()
{
	string s;
	cin >> s;
	int n = s.size();
	vector < int > v;
	map < char , int > m;
	for (char c : s)
	{
		if (!m.count(c))
			m[c] = m.size();
		v.emplace_back(m[c]);
	}
	int k = m.size();
	map < vector < int > , int > dp;
	vector < int > cur(k-1, 0);
	dp[cur] = 1;
	ll ans = 0;
	for (int x : v)
	{
		if (x < k-1)
			cur[x]++;
		else
			for (int &y : cur)
				y--;
		ans += dp[cur]++;
	}
	cout << ans << "\n";
}

