/*
Task:              2216 Collecting Numbers
Sender:            franfill
Submission time:   2021-07-02 22:38:45
Language:          C++11
Result:            ACCEPTED
/*
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
