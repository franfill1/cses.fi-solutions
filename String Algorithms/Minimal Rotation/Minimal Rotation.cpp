/*
Task:              1110 Minimal Rotation
Sender:            franfill
Submission time:   2022-01-30 19:47:02
Language:          C++17
Result:            ACCEPTED
/*
#include<bits/stdc++.h>
using namespace std;
 
int main()
{
	string s;
	cin >> s;
	s += s;
	int n = s.size();

	int ans = 0;
	int i = 0;
	while(i < n/2)
	{
		ans = i;
		int j = i, k;
		for(k = i+1; k < n && s[k] >= s[j]; k++)
		{
			if (s[k] == s[j]) j++;
			else j = i;
		}
		while(i <= j) i += k-j;
	}
	cout << s.substr(ans, n/2) << "\n";
}
