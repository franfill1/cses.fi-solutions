#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	
	int s[n];
	for (int i = 0; i < n; i++) s[i] = (i+1)%n;
	
	int p = 0;
	for (p = 0; p != s[p]; p = s[p] = s[s[p]])
		cout << s[p] + 1 << " ";
	cout << p+1;
}
