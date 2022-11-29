#include<bits/stdc++.h>
using namespace std;

int main()
{
	int N;
	cin >> N;

	if (N == 1)
	{
		cout << 1;
		return 0;
	}
	if (N <= 3)
	{
		cout << "NO SOLUTION";
		return 0;
	}

	for (int i = 1; i*2 <= N; i++)
		cout << i*2 << " ";
	for (int i = 1; i*2-1 <= N; i++)
		cout << i*2-1 << " ";
}

