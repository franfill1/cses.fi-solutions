#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
	int n, m, q;
	cin >> n >> m >> q;

	vector < vector < ll > > D(n, vector < ll > (n, 1ll<<60));
	for (int i = 0; i < n; i++) D[i][i] = 0;	

	for (int i = 0; i < m; i++)
	{
		int a, b; cin >> a >> b; a--; b--;
		ll c;
		cin >> c;
		D[a][b] = D[b][a] = min(D[a][b], c);
	}
	
	for (int h = 0; h < n; h++)
	{
		for (int a = 0; a < n; a++)
		{
			for (int b = 0; b < n; b++)
			{
				if (D[a][h] + D[h][b] < D[a][b])
				{
					D[a][b] = D[b][a] = D[a][h] + D[h][b];
				}
			}
		}
	}
	
	while(q--)
	{
		int a, b; cin >> a >> b; a--; b--;
		cout << (D[a][b] == 1ll<<60 ? -1 : D[a][b])<< "\n";;
	}
}

