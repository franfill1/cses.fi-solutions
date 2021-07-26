#include<bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	cin >> s;
	sort(s.begin(), s.end());
	vector < string > sol;
	sol.push_back(s);
	unordered_set < string > v;
	v.insert(s);
	while(next_permutation(s.begin(), s.end()))
	{
		if (!v.count(s))sol.push_back(s);
		v.insert(s);
	}

	cout << sol.size() << "\n";
	for (string c : sol) cout << c << "\n";
}
