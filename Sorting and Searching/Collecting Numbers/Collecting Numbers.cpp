#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;

	vector < int > pos(n);
	for (int i = 0; i < n; i++)
	{
		int el;
		cin >> el; el--;
		pos[el] = i;
	}

	int l = -1, ans = 1;
	for (int i = 0; i < n; i++)
	{
		if (pos[i] < l) ans++;
		l = pos[i];
	}

	cout << ans;
}

