/*
Task:              1702 Tree Traversals
Sender:            franfill
Submission time:   2023-03-12 19:49:50
Language:          C++17
Result:            ACCEPTED
*/
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector < pair < int , int > > g(n, (make_pair(-1, -1)));
	vector < int > pre(n), in(n);
	for (auto &x : pre)
	{
		cin >> x;
		x--;
	}
	for (auto &x : in)
	{
		cin >> x;
		x--;
	}

	vector < int > state(n, 0);
	int r;
	int x = r = pre[0];
	int i = 0;
	for (int t : in)
	{
		assert(state[t] != 2);
		if (state[t] == 1)
			x = t;
		else
		{
			while(x != t)
			{
				i++;
				assert(state[x] != 1);
				if (state[x] == 2)
					g[x].second = pre[i];	
				else
				 	g[x].first = pre[i];
				state[x] = 1;
				x = pre[i];
			}
		}
		state[x] = 2;
	}
	auto print = [&] (int x, auto print) -> void
	{
		if (g[x].first != -1)
			print(g[x].first, print);
		if (g[x].second != -1)
			print(g[x].second, print);
		cout << x+1 << " ";
	};
	print(r, print);
	cout << "\n";
}
