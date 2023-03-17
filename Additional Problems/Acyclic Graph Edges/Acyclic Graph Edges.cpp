/*
Task:              1756 Acyclic Graph Edges
Sender:            franfill
Submission time:   2022-12-01 16:50:58
Language:          C++17
Result:            ACCEPTED
*/
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		if (a > b)
			swap(a, b);
		cout << a << " " << b << "\n";
	}
}
