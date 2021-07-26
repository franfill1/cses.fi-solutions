#include<bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	cin >> s;
	unordered_map < char , int > cnt;
	for (char c : s) cnt[c]++;
	int i = 0;
	if (s.length() % 2) s[(s.length()-1)/2] = ' ';
	for (auto v : cnt)
	{
		while(v.second >= 2)
		{
			v.second -= 2;
			s[i] = v.first;
			s[s.length() - i - 1] = v.first;
			i++;
		}
		if (v.second && (s.length() % 2 == 0 || s[(s.length()-1)/2] != ' '))
		{
			cout << "NO SOLUTION";
			return 0;
		}
		else if (v.second)
			s[(s.length()-1)/2] = v.first;
	}
	cout << s;

}
