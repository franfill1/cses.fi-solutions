/*
Task:              2163 Josephus Problem II
Sender:            franfill
Submission time:   2021-07-03 13:11:33
Language:          C++11
Result:            ACCEPTED
/*
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;

int main()
{
	int n, k;
	cin >> n >> k;

	indexed_set s;
	for (int i = 0; i < n; i++) s.insert(i);

	int p = k%n;
	while(n--)
	{
		auto b = s.find_by_order(p);
		cout << *b + 1 << " ";
		s.erase(b);
		if (n) p = (p + k) % n;
	}
}
