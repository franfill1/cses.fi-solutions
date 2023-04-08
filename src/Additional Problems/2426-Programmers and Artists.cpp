/*
Task:              2426 Programmers and Artists
Sender:            franfill
Submission time:   2023-03-14 11:52:28
Language:          C++17
Result:            ACCEPTED
*/
#include<algorithm>
#include<vector>
#include<iostream>
#include<queue>
using namespace std;
using ll = long long;

int main()
{
	int a, b, n;
	cin >> a >> b >> n;
	vector < int > va(n), vb(n);
	vector < int > p(n);
	for (int i = 0; i < n; i++)
	{
		cin >> va[i] >> vb[i];
		p[i] = i;
	}
	sort(p.begin(), p.end(), [&] (int i, int j)
			{
				return va[i] - vb[i] > va[j] - vb[j];
			});
	vector < ll > sa(n+1, 0), sb(n+1, 0);
	priority_queue < int > pq;
	for (int j = 0; j < a; j++)
	{
		int i = p[j];
		sa[a] += va[i];
		pq.emplace(-va[i]);
	}
	for (int j = a; j < n-b; j++)
	{
		int i = p[j];
		sa[j+1] = sa[j]+va[i];
		pq.emplace(-va[i]);
		sa[j+1] += pq.top();
		pq.pop();
	}
	while(pq.size())
		pq.pop();
	for (int j = n-1; j >= n-b; j--)
	{
		int i = p[j];
		sb[n-b] += vb[i];
		pq.emplace(-vb[i]);
	}
	for (int j = n-b-1; j >= a; j--)
	{
		int i = p[j];
		sb[j] = sb[j+1]+vb[i];
		pq.emplace(-vb[i]);
		sb[j] += pq.top();
		pq.pop();
	}
	ll ans = 0;
	for(int j = a; j <= n-b; j++)
		ans = max(ans, sa[j] + sb[j]);
	cout << ans << "\n";
}
