#include<vector>
#include<iostream>
using namespace std;
typedef long long ll;


int main()
{
	int n;
	cin >> n;
	vector < ll > v(n);
	ll sum = 0;
	ll ma = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
		sum += v[i];
		ma = max(ma, v[i]);
	}
	
	cout << max(ma*2, sum);
}

