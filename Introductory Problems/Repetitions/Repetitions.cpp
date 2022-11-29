#include<bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	cin >> s;
	int rep;
	int ans = 0;
	char l = ' ';
	for (char c : s)
	{
		if (c != l)
			rep = 0;
		rep++;
		ans = max(ans, rep);
		l = c;
	}
	cout << ans;
}

