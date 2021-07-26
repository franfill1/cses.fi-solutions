#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
	int n;
	cin >> n;

	stack < pair < ll , ll > > s;
	s.push({0, 0});

	for (int i = 0; i < n; i++)
	{
		ll el;
		cin >> el;
		while(s.top().first >= el) s.pop();
		
		cout << s.top().second << " ";
		s.push({el, i+1});
	}
}
