/*
Task:              1145 Increasing Subsequence
Sender:            franfill
Submission time:   2022-04-30 18:25:27
Language:          C++17
Result:            ACCEPTED
*/
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int N;
	cin >> N;

	vector < int > be(N, 1<<30);

	int ans = 0;
	for (int i = 0; i < N; i++)
	{
		int v;
		cin >> v;
		auto it = lower_bound(be.begin(), be.end(), v);
		*it = min(*it, v);
		ans = max(ans, int(it - be.begin()));
	}
	cout << ans+1 << "\n";
}
