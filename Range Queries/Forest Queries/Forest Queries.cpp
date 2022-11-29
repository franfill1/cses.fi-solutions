#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct pSumMat
{
	int n;
	vector < vector < ll > > M;

	pSumMat(vector < vector < ll > > &A) : n(A.size()+1)
	{
		M.resize(n, vector < ll > (n, 0));	
		for (int i = 1; i < n; i++)
		{
			for (int j = 1; j < n; j++)
			{
				M[i][j] = A[i-1][j-1] + M[i-1][j] + M[i][j-1] - M[i-1][j-1];
			}
		}
	}

	ll get(int ra, int ca, int rb, int cb)
	{
		return M[rb][cb] - M[rb][ca] - M[ra][cb] + M[ra][ca];
	}
};

int main()
{
	int n, q;
	cin >> n >> q;
	vector < vector < ll > > M(n, vector < ll > (n));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			char c;
			cin >> c;
			M[i][j] = (c == '*');
		}
	}
	pSumMat pS(M);

	while(q--)
	{
		int ra, ca, rb, cb;
		cin >> ra >> ca >> rb >> cb;
		ra--; ca--;
		cout << pS.get(ra, ca, rb, cb) << "\n";
	}
}

