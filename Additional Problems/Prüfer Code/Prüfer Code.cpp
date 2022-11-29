#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector < int > p(n-2), cnt(n, 0);
	for (auto &x: p)
	{
		cin >> x;
		x--;
		cnt[x]++;
	}
	priority_queue < int , vector < int > , greater < int > > pq;
	for (int i = 0; i < n; i++)
		if (cnt[i] == 0)
			pq.emplace(i);

	for (auto &x : p)
	{
		cout << pq.top()+1 << " " << x+1 << "\n";
		pq.pop();
		if (--cnt[x] == 0)
			pq.emplace(x);
	}
	int x = pq.top();
	pq.pop();
	cout << pq.top()+1 << " " << x+1 << "\n";
}

