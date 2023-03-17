/*
Task:              1655 Maximum Xor Subarray
Sender:            franfill
Submission time:   2022-12-04 19:08:48
Language:          C++17
Result:            ACCEPTED
*/
#include<bits/stdc++.h>
using namespace std;
constexpr int inf = numeric_limits<int>::max();
int main()
{
	int n;
	cin >> n;
	vector < int > x(1, 0);
	for (int i = 0; i < n; i++)
	{
		int e;
		cin >> e;
		x.emplace_back(x.back()^e);
	}
	sort(x.begin(), x.end());

	auto solve2 = [&] (int p, int i1, int j1, int i2, int j2, auto solve2) -> int
	{
		if(i1 >= j1 || i2 >= j2)
			return -1;
		if (p < 0)
			return x[i1] ^ x[i2];
		int piv1 = (x[i1] & ~((1<<p)-1)) | (1<<p);
		int piv2 = (x[i2] & ~((1<<p)-1)) | (1<<p);
		int m1 = lower_bound(x.begin()+i1, x.begin()+j1, piv1) - x.begin();
		int m2 = lower_bound(x.begin()+i2, x.begin()+j2, piv2) - x.begin();
		int ans1 = solve2(p-1, i1, m1, m2, j2, solve2);
		int ans2 = solve2(p-1, m1, j1, i2, m2, solve2);
		int ans = max(ans1, ans2);
		if (ans == -1)
			ans = solve2(p-1, i1, j1, i2, j2, solve2);
		return ans;
	};

	auto solve1 = [&] (int p, int i, int j, auto solve1, auto solve2) -> int
	{
		if (p < 0)
			return x[i] ^ x[j-1];
		int piv = (x[i] & ~((1<<p)-1)) | (1<<p);
		int m = lower_bound(x.begin()+i, x.begin()+j, piv) - x.begin();
		int ans;
		if (m != i && m != j)
			ans = solve2(p-1, i, m, m, j, solve2);
		else
			ans = solve1(p-1, i, j, solve1, solve2);
		return ans;
	};
	cout << solve1(30, 0, n+1, solve1, solve2) << "\n";
}
