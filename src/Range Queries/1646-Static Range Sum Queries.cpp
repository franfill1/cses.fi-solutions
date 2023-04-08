/*
Task:              1646 Static Range Sum Queries
Sender:            franfill
Submission time:   2021-07-31 12:40:45
Language:          C++11
Result:            ACCEPTED
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct pSumArray
{
	int n;
	vector < ll > V;

	pSumArray(vector < ll > &A) : n(A.size()+1)
	{
		V.resize(n, 0);
		for (int i = 1; i < n; i++) V[i] = V[i-1] + A[i-1];
	}
	
	ll get(int a, int b)
	{
		return (V[b] - V[a]);
	}
};

int main()
{
	int n, q;
	cin >> n >> q;

	vector < ll > V(n);
	for (ll &v : V) cin >> v;

	pSumArray ps(V);

	while(q--)
	{
		int a, b;
		cin >> a >> b; a--;
		cout << ps.get(a, b) << "\n";
	}
}
