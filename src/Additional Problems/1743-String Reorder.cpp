/*
Task:              1743 String Reorder
Sender:            franfill
Submission time:   2023-03-12 19:26:01
Language:          C++17
Result:            ACCEPTED
*/
#include<bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	cin >> s;
	vector < int > cnt(26);
	set < pair < int , int > > occ;
	set < int > let;
	for (int i = 0; i < s.size(); i++)
		cnt[s[i]-'A']++;
	for (int i = 0; i < 26; i++)
		if (cnt[i] != 0)
		{
			occ.insert(make_pair(-cnt[i], i));
			let.insert(i);
		}

	int n = s.size();
	if (-occ.begin()->first > n - n/2)
	{
		cout << -1 << "\n";
		return 0;
	}
	vector < int > ans;
	int last = -1;
	for (int i = 0; i < s.size(); i++)
	{
		int left = s.size()-i;
		int chosen = last == *let.begin() ? *next(let.begin()) : *let.begin();
		if (left % 2 && -occ.begin()->first == left - left/2)
			chosen = occ.begin()->second;

		ans.emplace_back(chosen);
		occ.erase(make_pair(-cnt[chosen], chosen));
		if(--cnt[chosen] == 0)
			let.erase(chosen);
		else
			occ.insert(make_pair(-cnt[chosen], chosen));
		last = chosen;
	}
	for (int i : ans)
		cout << char(i + 'A');
	cout << "\n";
}
