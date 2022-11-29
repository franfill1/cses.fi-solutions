#include<vector>
#include<algorithm>
#include<iostream>
#define M 1000000007
using namespace std;
typedef long long ll;

int main()
{
	int n;
	cin >> n;
	ll a=1, b=0;
	for (int i = 0; i < n; i++)
	{
		a = (i+1)*((a+b)%M);
		a %= M;
		swap(a, b);
	}
	cout << a << "\n";
}

