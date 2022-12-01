/*
Task:              1096 Throwing Dice
Sender:            franfill
Submission time:   2021-11-30 22:52:48
Language:          C++17
Result:            ACCEPTED
/*
#include<bits/stdc++.h>
#define M 1000000007
using namespace std;
typedef long long ll;

struct matrix
{
	vector < vector < ll > > m;

	matrix(vector < vector < ll > > _m) : m(_m) {}

	matrix operator * (matrix oth)
	{
		assert(oth.m.size() != 0);
		vector < vector < ll > > ans(m.size(), vector < ll > (oth.m[0].size()));
		for (int i = 0; i < ans.size(); i++)
		{
			for (int j = 0; j < ans[i].size(); j++)
			{
				assert(m[i].size() == oth.m.size());
				for (int k = 0; k < m[i].size(); k++)
				{
					ans[i][j] += (m[i][k] * oth.m[k][j])%M;
					ans[i][j] %= M;
				}
			}
		}
		return matrix(ans);
	}

	vector < ll >& operator [] (int i)
	{
		return m[i];
	}
};

matrix id({{1, 0}, {0, 1}});

matrix modpow(matrix b, ll e)
{
	if (e == 1) return b;
	matrix t = modpow(b, e/2);
	t = t * t;
	if (e % 2) t = t * b;
	return t;
}

int main()
{
	ll n;
	cin >> n;
	matrix b({{1, 1, 1, 1, 1, 1}, 
			  {1, 0, 0, 0, 0, 0},
			  {0, 1, 0, 0, 0, 0},
			  {0, 0, 1, 0, 0, 0},
			  {0, 0, 0, 1, 0, 0},
			  {0, 0, 0, 0, 1, 0}
			  });
	b = modpow(b, n+1);
	cout << b[0][5] << "\n";
}
