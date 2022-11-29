#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct pXorArray
{
	int n;
	vector < ll > V;

	pXorArray(vector < ll > &A) : n(A.size()+1)
	{
		V.resize(n, 0);
		for (int i = 1; i < n; i++) V[i] = V[i-1] ^ A[i-1];
	}

	ll get(int a, int b)
	{
		return V[a] ^ V[b];
	}
};

int main()
{
	int n, q;
	cin >> n >> q;
	vector < ll > V(n);
	for (ll &v : V) cin >> v;

	pXorArray px(V);

	while(q--)
	{
		int a, b;
		cin >> a >> b; a--;
		cout << px.get(a, b) << "\n";
	}
}

