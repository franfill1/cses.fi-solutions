#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N, Q;
	cin >> N >> Q;
	int mp = 0;
	while(1<<mp <= N)
	{
		mp++;
	}
	vector < vector < int > > mat(mp, vector < int > (N));
	
	mat[0][0] = -1;
	for (int i = 1; i < N; i++)
	{
		cin >> mat[0][i];
		mat[0][i]--;
	}
	
	for (int p = 1; p < mp; p++)
	{
		for (int i = 0; i < N; i++)
		{
			int temp = mat[p-1][i];
			if (temp != -1)
			{
				temp = mat[p-1][temp];
			}
			mat[p][i] = temp;
		}
	}
	
	while(Q--)
	{
		int x, k;
		cin >> x >> k;
		x--;
		
		int p = mp;
		while(k > 0 && x != -1)
		{
			while(1<<p > k)
			{
				p--;
			}
			k -= 1<<p;
			x = mat[p][x];
		}
		cout << x + (x >= 0) << "\n";
	}
}

