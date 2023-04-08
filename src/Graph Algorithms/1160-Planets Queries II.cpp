/*
Task:              1160 Planets Queries II
Sender:            franfill
Submission time:   2021-07-26 19:59:18
Language:          C++11
Result:            ACCEPTED
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct lifting
{
	int n, P = 33;
	vector < vector < int > > anc;

	vector < int > state;
	vector < int > H;
	vector < int > Po;
	vector < int > L;
	vector < int > R;

	void findCycle(int x)
	{
		if (state[x] == 2) return;
		else if (state[x] == 1)
		{
			setCycle(x, 0);
		}
		else
		{
			state[x] = 1;
			findCycle(anc[0][x]); 
			state[x] = 2;
		}
	}

	int setCycle(int x, int v)
	{
		if (state[x] == 2) return v;
		state[x] = 2;
		Po[x] = v;
		R[x] = x;
		return L[x] = setCycle(anc[0][x], v+1);
	}

	int calcH(int x)
	{
		if (H[x] != -1) return H[x];
		if (L[x] != -1) return H[x] = 0;
		return H[x] = calcH(anc[0][x])+1;
	}
	
	int calcR(int x)
	{
		if (R[x] != -1) return R[x];
		return R[x] = calcR(anc[0][x]);
	}

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

		state.resize(n, 0);
		H.resize(n, -1);
		L.resize(n, -1);
		R.resize(n, -1);
		Po.resize(n, -1);
		for (int x = 0; x < n; x++)
		{
			findCycle(x);
		}
		for (int x = 0; x < n; x++)
		{
			calcH(x);
			calcR(x);
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

	int rootCheck(int a, int b)
	{
		ll g = Po[a] - Po[b];
		if (g < 0) g += L[a];
		
		if (lift(a, g) == b) return g;
		else
		{
			g = Po[b] - Po[a];
			if (g < 0) g += L[b];
			if (lift(a, g) == b) return g;
		}
		return -1;
	}

	int check(int a, int b)
	{
		if (R[a] == a && R[b] == b)
		{
			return rootCheck(a, b);	
		}
		else if (R[b] != b)
		{
			ll g = H[a] - H[b];
			if (g >= 0 && lift(a, g) == b) return g;
		}
		else
		{
			ll ra = R[a];
			ll d = rootCheck(ra, b);
			if (d != -1) return d + H[a];
		}	
		return -1;
	}
};

int main()
{
	int n, q;
	cin >> n >> q;
	vector < int > next(n);
	for (int i = 0; i < n; i++)
	{
		cin >> next[i]; next[i]--;
	}
	
	lifting calc(next);

	while(q--)
	{
		int a, b;
		cin >> a >> b; a--; b--;
		cout << calc.check(a, b) << "\n";
	}
}
