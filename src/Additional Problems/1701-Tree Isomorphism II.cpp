/*
Task:              1701 Tree Isomorphism II
Sender:            franfill
Submission time:   2023-03-23 11:40:45
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
 
string calc(vector<vector<int>> &t, int root)
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
	dfs(root, -1, dfs);
	string r = "";
	while(d[root].size())
	{
		r += d[root].front();
		d[root].pop_front();
	}
	return r;
}

int calc_size(int x, int p, vector < vector < int > > &t, vector < int > &s)
{
	s[x] = 1;
	for (int y : t[x])
		if (y != p)
			s[x] += calc_size(y, x, t, s);
	return s[x];
}

pair < int , int > find_centroid(int x, int p, vector < vector < int > > &t, vector < int > &s)
{
	for (int y : t[x])
		if (y != p)
		{
			if (s[y] > s[0]/2)
				return find_centroid(y, x, t, s);
			else if (s[y] == s[0]/2)
				return make_pair(x, y);
		}
	return make_pair(x, -1);
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
	
	vector < int > s1(n), s2(n);
	calc_size(0, -1, t1, s1);
	calc_size(0, -1, t2, s2);
	pair < int , int > c1 = find_centroid(0, -1, t1, s1);
	pair < int , int > c2 = find_centroid(0, -1, t2, s2);
	if (calc(t1, c1.first) == calc(t2, c2.first))
		cout << "YES\n";
	else if(c1.second != -1 && calc(t1, c1.second) == calc(t2, c2.first))
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
