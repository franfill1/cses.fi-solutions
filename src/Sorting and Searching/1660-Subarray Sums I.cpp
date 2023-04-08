/*
Task:              1660 Subarray Sums I
Sender:            franfill
Submission time:   2021-11-03 15:29:18
Language:          C++17
Result:            ACCEPTED
*/
#include<iostream>
using namespace std;

int main()
{
 	int n, x;
 	cin >> n >> x;
 	int t[n];
 	for (int i = 0; i < n; i++)
 	{
 		cin >> t[i];
	}
	
	long long sum = 0;
	int ans = 0;
	int i = 0;
	for (int j = 0; j < n; j++)
	{
		sum += t[j];
		while(sum > x)
		{
			sum -= t[i];
			i++;
		}
		if (sum == x)
		{
			ans++;
		}
	}
	cout << ans << "\n";
}

