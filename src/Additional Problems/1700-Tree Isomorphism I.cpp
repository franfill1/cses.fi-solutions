/*
Task:              1700 Tree Isomorphism I
Sender:            franfill
Submission time:   2023-03-21 10:32:30
Language:          C++17
Result:            ACCEPTED
*/
#include<vector>
#include<numeric>
#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

bool operator < (deque<char> &a, deque<char> &b)
{
	deque<char> ar, br;
	while(a.size() && b.size() && a.front() == b.front())
	{
		ar.push_back(a.front());
		br.push_back(b.front());
		a.pop_front();
		b.pop_front();
	}
	bool ans = false;
	if (!br.size())
		ans = false;
	else if (!ar.size())
		ans = true;
	else if (a.front() < b.front())
		ans = true;
	else
		ans = false;
	while(ar.size())
	{
		a.push_front(ar.back());
		b.push_front(br.back());
		ar.pop_back();
		br.pop_back();
	}
	return ans;
}

string calc(vector<vector<int>> &t)
{
	int n=t.size();
	vector<deque<char>> d(n);
	auto dfs = [&](int x, int p, auto dfs) ->void
	{
		for (int y: t[x])
			if (y != p)
				dfs(y, x, dfs);
		vector < int > o(t[x].size());
		iota(o.begin(), o.end(), 0);
		sort(o.begin(), o.end(), [&] (int i, int j)
				{
					if (d[t[x][i]].size() != d[t[x][j]].size())
						return d[t[x][i]].size() > d[t[x][j]].size();
					return d[t[x][i]] < d[t[x][j]];
				});
		swap(d[x], d[t[x][o[0]]]);
		for (int i : o)
			while(d[t[x][i]].size())
			{
				d[x].push_back(d[t[x][i]].front());
				d[t[x][i]].pop_front();
			}
		d[x].push_front('(');
		d[x].push_back(')');
	};
	dfs(0, 0, dfs);
	string r = "";
	while(d[0].size())
	{
		r += d[0].front();
		d[0].pop_front();
	}
	return r;
}

void solve()
{
	int n;
	cin >> n;
	vector<vector<int>> t1(n), t2(n);
	for (int i = 0; i < n-1; i++)
	{
		int a, b;
		cin >> a >> b;
		a--, b--;
		t1[a].emplace_back(b);
		t1[b].emplace_back(a);
	}
	for (int i = 0; i < n-1; i++)
	{
		int a, b;
		cin >> a >> b;
		a--, b--;
		t2[a].emplace_back(b);
		t2[b].emplace_back(a);
	}

	if (calc(t1) == calc(t2))
		cout << "YES\n";
	else
		cout << "NO\n";
}

int main()
{
	int t;
	cin >> t;
	while(t--)
		solve();
}
