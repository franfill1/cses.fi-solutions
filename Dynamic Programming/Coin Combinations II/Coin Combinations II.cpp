#include <bits/stdc++.h>
#define M 1000000007

using namespace std;

vector < int > coins;

int main()
{
	int N, X, C;
	cin >> N >> X;
	
	vector < int > V (X+1, 0);
	V[0] = 1;
	
	while(N--)
	{
		cin >> C;
		for (int x = 1; x <= X; x++)
		{
			if (x - C >= 0)
			{
				V[x] += V[x - C];
				V[x] %= M;
			}
		}
	}
	cout << V[X];
}

