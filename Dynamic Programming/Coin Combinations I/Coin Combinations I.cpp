#include<bits/stdc++.h>
using namespace std;

const int modulo = 1000000000 + 7;
int n, ans = 0;
vector < int > c;
vector < long long > memo;

long long solve (int x) {
	if (x < 0) {
		return 0;
	}
	
	if (x == 0) {
		return 1;
	}
	if (memo[x] != -1) return memo[x];
	
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		ans += solve(x - c[i]);
		ans %= modulo;
	}
	return memo[x] = ans;
}

int main () {
	
	int x;
	cin >> n >> x;
	
	memo.resize(x+1, -1);
	c.resize(n);
	
	for (int i = 0; i < n; i++) {
		cin >> c[i];
	}
    
    sort(c.begin(), c.end());
    
    cout << solve(x);
    
return 0;
}

