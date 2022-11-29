#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long N;
	cin >> N;

	long long sum = N*(N+1) /2;
	if (sum % 2)
		cout << "NO";
	else
	{
		cout << "YES\n";
		sum /= 2;
		long long temp = 0;
		long long i;
		for (i = 1; temp < sum; i++)
			temp += i;

		cout << i - 1 - (temp - sum != 0) << "\n";
		for (long long j = 1; j < i; j++)
			if (j != temp - sum) cout << j << " ";

		cout << "\n" << (N - i + 1 + (temp - sum != 0)) << "\n";
		for (long long j = 1; j <= N; j++)
			if (j >= i || j == temp - sum) cout << j << " ";
	}
}

