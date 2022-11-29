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

