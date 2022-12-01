/*
Task:              1073 Towers
Sender:            franfill
Submission time:   2021-07-02 23:55:16
Language:          C++11
Result:            ACCEPTED
/*
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;

	multiset < int > b;
	while(n--)
	{
		int k; cin >> k;
		auto it = b.upper_bound(k);
		if (it != b.end())
			b.erase(it);
		b.insert(k);
	}
	
	cout << b.size();
}
