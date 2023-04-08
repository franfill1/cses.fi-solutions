/*
Task:              1643 Maximum Subarray Sum
Sender:            franfill
Submission time:   2021-11-03 15:19:37
Language:          C++17
Result:            ACCEPTED
*/
#include<iostream>
using namespace std;

int main()
{
 	int n;
 	cin >> n;
 	int x[n];
 	for (int i = 0; i < n; i++)
 	{
 		cin >> x[i];
	}
	
	long long sum = x[0];
	long long ans = sum;
	for (int i = 1; i < n; i++)
	{
		if (sum < 0)
		{
			sum = 0;
		}
		sum += x[i];
		if (sum > ans)
		{
			ans = sum;
		}
	}
	cout << ans << "\n";
}

