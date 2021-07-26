#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int x, n;
	cin >> x >> n;

	set < int > t {0, x};
	multiset < int > a {x};
	while(n--)
	{
		int p;
		cin >> p;
		auto it = t.upper_bound(p);
		int r = *(it--);
		int l = *it;
		
		a.erase(a.find(r-l));
		a.insert(p-l); a.insert(r-p);
		t.insert(p);

		it = a.end();
		cout << *(--it) << " ";
	}
}
