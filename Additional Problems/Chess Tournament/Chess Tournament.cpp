#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector < int > x(n);
	priority_queue < pair < int , int > > pq;
	int sum = 0, z = 0;
	for (int i = 0; i < n; i++)
	{
		int e;
		cin >> e;
		x[i] = e;
		z += x[i] == 0;
		pq.emplace(e, i);
		sum += e;
	}
	for (auto &e : x)
		if (e > n-1-z)
		{
			cout << "IMPOSSIBLE\n";
			return 0;
		}
	if (sum % 2)
	{
		cout << "IMPOSSIBLE\n";
		return 0;
	}
	cout << sum/2 << "\n";

	while(pq.size())
	{
		auto [e, i] = pq.top();
		pq.pop();
		vector < pair < int , int > > to_add;
		while(e--)
		{
			auto [e2, i2] = pq.top();
			pq.pop();
			cout << i+1 << " " << i2+1 << "\n";
			if (--e2)
				to_add.emplace_back(e2, i2);
		}
		for (auto [e, i] : to_add)
			pq.emplace(e, i);
	}
}

