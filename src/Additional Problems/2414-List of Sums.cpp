/*
Task:              2414 List of Sums
Sender:            franfill
Submission time:   2023-04-17 00:06:52
Language:          C++17
Result:            ACCEPTED
*/
#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	int m = n*(n-1)/2;
	vector < int > v(m);
	for (auto &x : v)
		cin >> x;

	vector < int > ans;
	auto test = [&] (int id) ->  bool
	{
		ans.resize(0);
		int s = v[0] + v[1] + v[id];
		if (s % 2)
			return false;
		s /= 2;
		ans.push_back(v[0] + v[1] - s);
		ans.push_back(s - v[1]);
		ans.push_back(s - v[0]);
		priority_queue < int , vector < int > , greater < int > > pq;
		for (int i = 2; i < m; i++)
		{
			if (i == id)
				continue;
			if (!pq.empty() && v[i] == pq.top())
				pq.pop();
			else
			{
				int x = v[i] - ans[0];
				for (int i = 1; i < ans.size(); i++)
					pq.emplace(x+ans[i]);
				ans.push_back(x);
				if (ans.size() > n)
					break;
			}
		}
		if (pq.empty())
			return true;
		else
			return false;
	};

	for (int i = 2; i < m; i++)
		if (test(i))
			break;

	assert(ans.size() == n);
	for (auto &x : ans)
		cout << x << " ";
	cout << "\n";
}
