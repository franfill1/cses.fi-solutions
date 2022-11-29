#include<bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	cin >> s;
	int N = s.size();
	
	vector < int > Z(N,0), P(N);
	{
		int l=0, r=0;
		for (int i = 1; i < N; i++)
		{
			if (i+Z[i-l]>=r)
			{
				l = i, r = max(r, i);
				while(s[r] == s[r-l])
					r++;
				Z[i] = r-l;
			}
			else
				Z[i] = Z[i-l];
		}
	}

	{
		P[0] = 0;
		for (int i = 1; i < N; i++)
		{
			int k = P[i-1];
			while (k != 0 && s[k] != s[i])
				k = P[k-1];
			P[i] = (s[i]==s[k])?k+1:0;
		}
	}

	for (auto x : Z)
		cout << x << " ";
	cout << "\n";
	for (auto x : P)
		cout << x << " ";
	cout << "\n";
	
}

