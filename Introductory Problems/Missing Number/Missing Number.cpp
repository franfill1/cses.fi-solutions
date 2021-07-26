#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
	int N;
	cin >> N;
	int r = N % 4;
	int X = (r == 0 ? N : (r == 1 ? 1 : (r == 2 ? N + 1 : 0)));
	
	for (int i = 1; i < N; i++)
	{
		int el;
		cin >> el;
		X ^= el;
	}
	cout << X << "\n";
}
