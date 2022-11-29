#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct funcGraph
{
	int n;
	vector < int > next;

	vector < int > state;
	vector < int > H;
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
			findCycle(next[x]); 
			state[x] = 2;
		}
	}

	int setCycle(int x, int v)
	{
		if (state[x] == 2) return v;
		state[x] = 2;
		R[x] = x;
		return L[x] = setCycle(next[x], v+1);
	}

	int calcH(int x)
	{
		if (H[x] != -1) return H[x];
		if (L[x] != -1) return H[x] = 0;
		return H[x] = calcH(next[x])+1;
	}
	
	int calcR(int x)
	{
		if (R[x] != -1) return R[x];
		return R[x] = calcR(next[x]);
	}

	funcGraph(vector < int > inext) : n(inext.size()) , next(inext)
	{
		state.resize(n, 0);
		H.resize(n, -1);
		R.resize(n, -1);
		L.resize(n, -1);
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
	
	int cycLen(int x)
	{
		return H[x] + L[R[x]];
	}
};

int main()
{
	int n;
	cin >> n;
	vector < int > next(n);
	for (int i = 0; i < n; i++) 
	{
		cin >> next[i];
		next[i]--;
	}
	funcGraph g(next);
	for (int i = 0; i < n; i++) cout << g.cycLen(i) << " ";
}

