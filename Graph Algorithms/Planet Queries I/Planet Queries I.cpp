#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct lifting
{
	int n, P = 33;
	vector < vector < int > > anc;

	lifting(vector < int > next) : n(next.size())
	{
		anc.resize(P, vector < int > (n));
		anc[0] = next;

		for (int p = 1; p < P; p++)
		{
			for (int x = 0; x < n; x++)
			{
				anc[p][x] = anc[p-1][anc[p-1][x]];
			}
		}
	}

	int lift(int x, ll k)
	{
		for (int p = 0; p < P; p++)
		{
			if((1ll<<p) & k)
			{
				x = anc[p][x];
			}
		}
		return x;
	}
};

int main()
{
	int n, q;
	cin >> n >> q;

	vector < int > next(n);
	for (int i = 0; i < n; i++) 
	{
		cin >> next[i];
		next[i]--;
	}
	
	lifting calc(next);

	while(q--)
	{
		int x; ll k; 
		cin >> x >> k; x--;
		cout << calc.lift(x, k)+1 << "\n";
	}
}
