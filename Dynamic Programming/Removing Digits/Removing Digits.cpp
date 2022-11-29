#include <bits/stdc++.h>

using namespace std;

int INF = 1<<30;

int main()
{
	int N;
	cin >> N;
	
	vector < int > memo(N+1);
	
	memo[0] = 0;
	
	for (int i = 1; i <= N; i++)
	{
		int n = i;
		memo[i] = INF;
		while(n)
		{
			if (i >= (n % 10))
			{
				memo[i] = min(memo[i], memo[i - (n%10)] + 1);
			}
			n /= 10;
		}
	}
	
	cout << memo[N];
}


