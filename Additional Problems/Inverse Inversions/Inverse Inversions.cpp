/*
Task:              2214 Inverse Inversions
Sender:            franfill
Submission time:   2022-12-02 19:32:53
Language:          C++17
Result:            ACCEPTED
*/
#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long n, k, i;
	cin >> n >> k;
	vector < int > p(n, -1);
	for (i = 0; i < n; i++)
	{
		if (k > (n-i-1))
			p[n-i-1] = i, k -= n-i-1;
		else
		{
			p[k] = i++;
			break;
		}
	}
	for (int j = 0; j < n; j++)
		if (p[j] == -1)
			p[j] = i++;
	for (auto x : p)
		cout << x+1 << " ";
	cout << "\n";
	assert(i == n);
}
