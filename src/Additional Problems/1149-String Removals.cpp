/*
Task:              1149 String Removals
Sender:            franfill
Submission time:   2023-03-14 18:15:23
Language:          C++17
Result:            ACCEPTED
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int mod = 1000000007;

int main()
{
	string s;
	cin >> s;
	vector < int > lst('z' - 'a' + 1);

	ll cur = 0;
	for (int i = s.size()-1; i >= 0; i--)
	{
		ll x = cur+1;
		cur = (cur + x - lst[s[i]-'a']) % mod;
		lst[s[i]-'a'] = x;
	}
	cout << (cur + mod) % mod << "\n";
}
